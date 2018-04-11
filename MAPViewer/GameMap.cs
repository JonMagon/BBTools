using System;
using System.Linq;
using System.Net;
using BBData;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;

namespace MAPViewer
{
    public class GameMap
    {
        public static int mark_object_id = 0;
        private readonly byte CurrentPlayer = 0;

        private readonly bool IsNight = false;
        private readonly int tileHeight = 40;

        private readonly int tilesX = 192;
        private readonly int tilesY = 192;

        private readonly int tileWidth = 78;
        private ContentManager content;
        private GraphicsDeviceManager graphics;
        private GraphicsDevice graphicsDevice;

        private MAPFile Map;
        private Point mousePosition;
        private Point selectedTile;
        private SpriteBatch spriteBatch;
        private SpriteFont spriteFont;
        private SpriteFont spriteFontBig;

        private GameTextures Textures;

        public GameMap(SpriteBatch spriteBatch, GraphicsDeviceManager graphics)
        {
            this.spriteBatch = spriteBatch;
            this.graphics = graphics;
        }

        private Point GetTileCoordinates(Point pt)
        {
            return new Point((int) Math.Floor(pt.X / (float) tileWidth + pt.Y / (float) tileHeight),
                -(int) Math.Floor(pt.X / (float) tileWidth - pt.Y / (float) tileHeight));
        }

        private byte GetFrameByDirection(byte dir, byte count)
        {
            return (byte) (count * (((dir + 16) % 32 + dir + 16) / 32));
        }

        public void DrawMap(GameCamera camera)
        {
            if (spriteBatch == null)
                throw new Exception("SpriteBatch is null.");

            var mousePos = mousePosition;
            mousePos.X += camera.XOffset;
            mousePos.Y += camera.YOffset;
            selectedTile = GetTileCoordinates(mousePos);

            // drawing tiles

            var cameraTile = GetTileCoordinates(new Point(camera.XOffset + camera.width / 2,
                camera.YOffset + camera.height / 2));

            if (cameraTile.X < 0 || tilesY - cameraTile.Y < 0) camera.moveableXLeft = false;
            else camera.moveableXLeft = true;
            if (cameraTile.X < 0 || cameraTile.Y < 0) camera.moveableYTop = false;
            else camera.moveableYTop = true;
            if (cameraTile.Y < 0 || tilesX - cameraTile.X < 0) camera.moveableXRight = false;
            else camera.moveableXRight = true;
            if (tilesX - cameraTile.X < 0 || tilesY - cameraTile.Y < 0) camera.moveableYDown = false;
            else camera.moveableYDown = true;

            var visibleTiles = Map.Tiles.Where(item =>
                CalcIsoX(item.Position.X, item.Position.Y) + tileWidth
                > camera.width + camera.XOffset - camera.width &&
                CalcIsoX(item.Position.X, item.Position.Y) - tileWidth
                < camera.width + camera.XOffset &&
                CalcIsoY(item.Position.X, item.Position.Y) + 2 * tileHeight
                > camera.height + camera.YOffset - camera.height &&
                CalcIsoY(item.Position.X, item.Position.Y) - 2 * tileHeight
                < camera.height + camera.YOffset);

            foreach (var tile in visibleTiles)
            {
                var isoCoords = CalcIsoXY(tile.Position.X, tile.Position.Y);
                isoCoords.X -= camera.XOffset;
                isoCoords.Y -= camera.YOffset;

                Texture2D renderTexture;

                int tileIdTexture = tile.Texture;

                if (tileIdTexture >= 234 && tileIdTexture <= 250)
                    tileIdTexture -= 119;

                switch (tileIdTexture)
                {
                    case 225:
                        renderTexture = Textures["tester", 0].getTexture2D();
                        break;
                    case 226:
                        renderTexture = Textures["tester2", 0].getTexture2D();
                        break;
                    case 200:
                        renderTexture = Textures["forest1", 0].getTexture2D();
                        break;
                    case 201:
                        renderTexture = Textures["forest2", 0].getTexture2D();
                        break;
                    default:
                        if (tileIdTexture < 202 || tileIdTexture >= 218)
                        {
                            if (tileIdTexture >= 227 && tileIdTexture < 232)
                            {
                                renderTexture = Textures[$"rock{tileIdTexture - 225:#0#}", 0]
                                    .getTexture2D();
                                break;
                            }
                            if (tileIdTexture >= 98 && tileIdTexture < 114)
                            {
                                renderTexture = Textures["rockrim", tileIdTexture - 98].getTexture2D();
                                break;
                            }
                        }
                        else
                        {
                            tileIdTexture = 0;
                        }

                        renderTexture = Textures["maptile", tileIdTexture].getTexture2D();
                        break;
                }

                spriteBatch.Draw(renderTexture, new Vector2(
                    isoCoords.X - (renderTexture.Width - tileWidth),
                    isoCoords.Y - (renderTexture.Height - tileHeight / 2)), Color.White);

                if (tile.Road != 0)
                {
                    renderTexture = Textures["roads", tile.Road - 1].getTexture2D();
                    spriteBatch.Draw(renderTexture, new Vector2(
                        isoCoords.X - (renderTexture.Width - tileWidth),
                        isoCoords.Y - (renderTexture.Height - tileHeight / 2)), Color.White);
                }
            }

            // drawing tile ptr
            var tileSelected = Map.Tiles.FirstOrDefault(tile => tile.Position.X == selectedTile.X
                                                                && tile.Position.Y == selectedTile.Y);
            if (tileSelected != null)
            {
                var isoCoords = CalcIsoXY(tileSelected.Position.X, tileSelected.Position.Y);
                isoCoords.X -= camera.XOffset;
                isoCoords.Y -= camera.YOffset;

                var renderTexture = Textures["tileptr", 12].getTexture2D();
                spriteBatch.Draw(renderTexture, new Vector2(
                    isoCoords.X - (renderTexture.Width - tileWidth),
                    isoCoords.Y - (renderTexture.Height - tileHeight / 2)), Color.White);
            }
            //end mouse

            // drawing object
            var visibleObjects = Map.Objects.Where(item =>
                CalcIsoX(item.Position.X, item.Position.Y) + 5 * tileWidth
                > camera.width + camera.XOffset - camera.width &&
                CalcIsoX(item.Position.X, item.Position.Y) - 5 * tileWidth
                < camera.width + camera.XOffset &&
                CalcIsoY(item.Position.X, item.Position.Y) + 5 * tileHeight
                > camera.height + camera.YOffset - camera.height &&
                CalcIsoY(item.Position.X, item.Position.Y) - 5 * tileHeight
                < camera.height + camera.YOffset).Reverse();

            foreach (var mapObject in visibleObjects)
            {
                var tile = CalcIsoXY(mapObject.Position.X, mapObject.Position.Y);
                tile.X -= camera.XOffset;
                tile.Y -= camera.YOffset;

                if (mapObject.IsGoing)
                {
                    var tile1 = CalcIsoXY(mapObject.GoingTo.X, mapObject.GoingTo.Y);
                    tile1.X -= camera.XOffset;
                    tile1.Y -= camera.YOffset;

                    Texture2D SimpleTexture = new Texture2D(graphicsDevice,  1, 1, false, SurfaceFormat.Color);

                    Int32[] pixel = {0xFFFFFF};
                    SimpleTexture.SetData<Int32>(pixel, 0, SimpleTexture.Width * SimpleTexture.Height);

                    var distance = Vector2.Distance(tile, tile1);
                    var angle = (float) Math.Atan2(tile1.Y - tile.Y, tile1.X - tile.X);

                    spriteBatch.Draw(SimpleTexture, new Rectangle((int)tile.X + tileWidth / 2, (int)tile.Y, (int)distance, 2),
                        null, Color.Blue, angle, new Vector2(0f, 0f), SpriteEffects.None, 1f);
                }

                var textureName = "doogle";
                var frame = 0;
                switch (mapObject.Class)
                {
                    case 0:
                        textureName = "bigfir";
                        break;
                    case 2:
                        textureName = "peashut";
                        break;
                    case 5:
                        textureName = "tree02";
                        break;
                    case 6:
                        textureName = "tree10";
                        break;
                    case 83:
                        textureName = "poison";
                        frame = mapObject.State;
                        break;
                    case 103:
                        switch (mapObject.Field_F2)
                        {
                            case 0:
                                if (IsNight && mapObject.OwnerPlayer == CurrentPlayer)
                                    DrawTexture(tile, Textures["lantern", 0]);
                                // TODO: Here is if ( v27 == 6 || v27 == 2 || v27 == 4 || v27 == 10 )
                                switch (mapObject.Sex)
                                {
                                    case 1:
                                        if (mapObject.IsFleeing)
                                        {
                                            textureName = "fleemale";
                                            frame = mapObject.State / 2 + GetFrameByDirection(mapObject.GenPeriod, 6);
                                        }
                                        else if (mapObject.IsGoing)
                                        {
                                            textureName = "villager";
                                            frame = mapObject.State / 2 + GetFrameByDirection(mapObject.GenPeriod, 6);
                                        }
                                        else
                                        {
                                            textureName = "m_still";
                                            frame = mapObject.State;
                                        }
                                        break;
                                    case 2:
                                        if (mapObject.IsFleeing)
                                        {
                                            textureName = "fleefema";
                                            frame = mapObject.State / 2 + GetFrameByDirection(mapObject.GenPeriod, 6);
                                        }
                                        else if (mapObject.IsGoing)
                                        {
                                            textureName = "woman";
                                            frame = mapObject.State / 2 + GetFrameByDirection(mapObject.GenPeriod, 6);
                                        }
                                        else
                                        {
                                            textureName = "f_still";
                                            frame = mapObject.State;
                                        }
                                        break;
                                }
                                break;
                        }
                        break;
                    case 58:
                        switch (mapObject.Field_F2)
                        {
                            case 0x1B:
                                switch (mapObject.State)
                                {
                                    default:
                                        textureName = "d_male";
                                        break;
                                    case 2:
                                        textureName = "d_fema";
                                        break;
                                    case 3:
                                        textureName = "d_prie";
                                        break;
                                    case 4:
                                        textureName = "d_buil";
                                        break;
                                    case 5:
                                        textureName = "d_taxm";
                                        break;
                                    case 6:
                                        textureName = "d_pike";
                                        break;
                                    case 7:
                                        textureName = "d_foot";
                                        break;
                                    case 8:
                                        textureName = "d_knig";
                                        break;
                                    case 9:
                                        textureName = "d_wiza";
                                        break;
                                    case 10:
                                        textureName = "d_oldm";
                                        break;
                                    case 11:
                                        textureName = "d_oldw";
                                        break;
                                    case 12:
                                        textureName = "d_kidm";
                                        break;
                                    case 13:
                                        textureName = "d_kidf";
                                        break;
                                    case 16:
                                        textureName = "d_cava";
                                        break;
                                    case 19:
                                        textureName = "d_arch";
                                        break;
                                    case 20:
                                        textureName = "d_jest";
                                        break;
                                    case 32:
                                        textureName = "d_groom";
                                        break;
                                    case 33:
                                        textureName = "d_bride";
                                        break;
                                }
                                frame = mapObject.Frame >> 2;
                                break;
                            case 0x25:
                                textureName = "skeleton";
                                break;
                            default:
                                throw new Exception($"Unhandled situation.");
                        }
                        break;
                    case 69:
                        textureName = "toolshed"; // здание билдеров
                        break;
                    case 111:
                        textureName = "chikfeld";
                        break;
                    case 98:
                        textureName = "owner";
                        break;
                    case 143:
                        textureName = "campfire";
                        //frame = map_object.Frame;
                        frame = mark_object_id;
                        break;
                    case 144:
                        textureName = "crate";
                        break;
                    case 110:
                        textureName = "cowwalk";
                        break;
                    case 159:
                        textureName = "gob_silv";
                        break;
                    case 171:
                        textureName = "crate";
                        break;
                    default:
                        throw new Exception($"Unhandled class id: {mapObject.Class}");
                }
                DrawTexture(tile, Textures[textureName, frame]);
            }

            var tileObjects = Map.Objects.FindAll(item => item.Position.X == selectedTile.X &&
                                                          item.Position.Y == selectedTile.Y);

            DrawText(new Vector2(mousePosition.X + 15, mousePosition.Y - 15), $"{selectedTile.X}, {selectedTile.Y}");

            Vector2 coords = new Vector2(10, 10);
            tileObjects?.ForEach(mapObject =>
            {
                coords.Y += 10;
                DrawText(coords, $"{mapObject.Class}");
            });

        }

        private void DrawTexture(Vector2 isoCoords, GameTexture2D texture)
        {
            spriteBatch.Draw(texture.getTexture2D(), new Vector2(
                isoCoords.X - texture.Offset.X + tileWidth / 2,
                isoCoords.Y - texture.Offset.Y), Color.White);
        }

        private void DrawText(Vector2 coords, string text)
        {
            spriteBatch.DrawString(spriteFont, text, new Vector2(
                coords.X + 1, coords.Y + 1), Color.Black);
            spriteBatch.DrawString(spriteFont, text, new Vector2(
                coords.X, coords.Y), Color.White);
        }

        public void Load(ContentManager content, GraphicsDevice graphicsDevice,
            SpriteBatch spriteBatch, SpriteFont spriteFont, SpriteFont spriteFontBig)
        {
            this.spriteBatch = spriteBatch;
            this.graphicsDevice = graphicsDevice;

            this.spriteFont = spriteFont;
            this.spriteFontBig = spriteFontBig;
            this.content = content;

            Map = new MAPFile(Environment.CurrentDirectory + @"\savegam0.sav");

            Textures = new GameTextures(graphicsDevice, Environment.CurrentDirectory + @"\VIDEO.BOX");
        }

        public void HandleMouse(GameMouse mouse, GameCamera camera)
        {
            mousePosition = mouse.State.Position;
        }

        public int CalcIsoX(int x, int y)
        {
            return (x - y) * (tileWidth / 2);
        }

        public int CalcIsoY(int x, int y)
        {
            return (x + y) * (tileHeight / 2);
        }

        private Vector2 CalcIsoXY(int x, int y)
        {
            return new Vector2(CalcIsoX(x, y), (x + y) * (tileHeight / 2));
        }
    }
}