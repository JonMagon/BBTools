using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;
using System.Collections.Generic;
using Microsoft.Xna.Framework.Input;
using BBData;
using System.Runtime.InteropServices;

namespace MAPViewer
{
    public class Map
    {
        private SpriteBatch spriteBatch;
        private GraphicsDeviceManager graphics;
        private SpriteFont spriteFont;
        private ContentManager content;
        private SpriteFont spriteFontBig;
        private GraphicsDevice graphicsDevice;
        public int tilesDrawed;

        private List<GameTextures2D> textureList;
        public Point mousePosition;

        private int tilesX = 192;
        private int tilesY = 192;
        public Point selectedTile;

        private int tileWidth = 78;
        private int tileHeight = 40;

        private BOXFile video;
        private MAPFile map;

        public Map(SpriteBatch spriteBatch, GraphicsDeviceManager graphics)
        {
            this.spriteBatch = spriteBatch;
            this.graphics = graphics;
        }

        public Point getTileCoordinates(Point pt)
        {
            return new Point((int)(Math.Floor(pt.X / (float)tileWidth + pt.Y / (float)tileHeight)),
                -(int)(Math.Floor(pt.X / (float)tileWidth - pt.Y / (float)tileHeight)));
        }

        public static int mark_object_id = 0;

        public void drawMap(Camera camera)
        {
            if (spriteBatch != null)
            {
                // drawing tiles

                Point camera_tile = getTileCoordinates(new Point(camera.xOffset + camera.width / 2,
                    camera.yOffset + camera.height / 2));

                if (camera_tile.X < 0 || tilesY - camera_tile.Y < 0) camera.moveableXLeft = false;
                else camera.moveableXLeft = true;
                if (camera_tile.X < 0 || camera_tile.Y < 0) camera.moveableYTop = false;
                else camera.moveableYTop = true;
                if (camera_tile.Y < 0 || tilesX - camera_tile.X < 0) camera.moveableXRight = false;
                else camera.moveableXRight = true;
                if (tilesX - camera_tile.X < 0 || tilesY - camera_tile.Y < 0) camera.moveableYDown = false;
                else camera.moveableYDown = true;

                tilesDrawed = 0;
                List<MapTile> visibleTiles = map.Tiles.FindAll(item => (
                    calcIsoX(item.Position.X, item.Position.Y) + tileWidth
                        > camera.width + camera.xOffset - camera.width &&
                    calcIsoX(item.Position.X, item.Position.Y) - tileWidth
                        < camera.width + camera.xOffset) &&
                    (calcIsoY(item.Position.X, item.Position.Y) + 2 * tileHeight
                        > camera.height + camera.yOffset - camera.height &&
                    calcIsoY(item.Position.X, item.Position.Y) - 2 * tileHeight
                        < camera.height + camera.yOffset));

                foreach (MapTile tile in visibleTiles)
                {
                    Point isoCoords = calcIsoXY(tile.Position.X, tile.Position.Y);
                    isoCoords.X -= camera.xOffset;
                    isoCoords.Y -= camera.yOffset;

                    Texture2D renderTexture;

                    int tile_id_texture = tile.Texture;

                    if (tile_id_texture >= 234 && tile_id_texture <= 250)
                        tile_id_texture -= 119;
                    switch (tile_id_texture)
                    {
                        case 225:
                            renderTexture = textureList.Find(texture => texture.type.Equals("tester")).getTexture2D();
                            break;
                        case 226:
                            renderTexture = textureList.Find(texture => texture.type.Equals("tester2")).getTexture2D();
                            break;
                        case 200:
                            renderTexture = textureList.Find(texture => texture.type.Equals("forest1")).getTexture2D();
                            break;
                        case 201:
                            renderTexture = textureList.Find(texture => texture.type.Equals("forest2")).getTexture2D();
                            break;
                        default:
                            if (tile_id_texture < 202 || tile_id_texture >= 218)
                            {
                                if (tile_id_texture >= 227 && tile_id_texture < 232)
                                {
                                    renderTexture = textureList[textureList.FindIndex(item => item.type.Equals("rock02")) +
                                        tile_id_texture - 227].getTexture2D();
                                    break;
                                }
                                else if (tile_id_texture >= 98 && tile_id_texture < 114)
                                {
                                    renderTexture = textureList.Find(texture => texture.type.Equals("rockrim")
                                        && texture.id == tile_id_texture - 98).getTexture2D();
                                    break;
                                }
                            }
                            else tile_id_texture = 0;

                            renderTexture = textureList.Find(texture => texture.type.Equals("maptile")
                                && texture.id == tile_id_texture).getTexture2D();
                            break;
                    }

                    spriteBatch.Draw(renderTexture, new Vector2(
                        isoCoords.X - (renderTexture.Width - tileWidth),
                        isoCoords.Y - (renderTexture.Height - tileHeight / 2)), Color.White);

                    if (tile.Road != 0)
                    {
                        renderTexture = textureList.Find(texture => texture.type.Equals("roads")
                            && texture.id == tile.Road - 1).getTexture2D();
                        spriteBatch.Draw(renderTexture, new Vector2(
                            isoCoords.X - (renderTexture.Width - tileWidth),
                            isoCoords.Y - (renderTexture.Height - tileHeight / 2)), Color.White);
                    }

                    tilesDrawed++;
                }

                // mouse
                Point mouse_pos = mousePosition;
                mouse_pos.X += camera.xOffset;
                mouse_pos.Y += camera.yOffset;
                selectedTile = getTileCoordinates(mouse_pos);

                MapObject map_object_1 = map.Objects.Find(item => item.Position.X == selectedTile.X &&
                        item.Position.Y == selectedTile.Y);

                string mousecoords = string.Format(" {0},{1} {2}", selectedTile.X, selectedTile.Y, (map_object_1 != null ? map_object_1.ClassID.ToString() : "null"));
                spriteBatch.DrawString(spriteFont, mousecoords, new Vector2(
                    mousePosition.X + 16, mousePosition.Y - 14), Color.Black);
                spriteBatch.DrawString(spriteFont, mousecoords, new Vector2(
                    mousePosition.X + 15, mousePosition.Y - 15), Color.White);

                // drawing tile ptr
                MapTile tile_selected = map.Tiles.Find(_tile => _tile.Position.X == (float)selectedTile.X
                    && _tile.Position.Y == (float)selectedTile.Y);
                if (tile_selected != null)
                {
                    Point isoCoords = calcIsoXY((int)tile_selected.Position.X, (int)tile_selected.Position.Y);
                    isoCoords.X -= camera.xOffset;
                    isoCoords.Y -= camera.yOffset;

                    Texture2D renderTexture = textureList.Find(texture => texture.type.Equals("tileptr")
                        && texture.id == 12).getTexture2D();
                    spriteBatch.Draw(renderTexture, new Vector2(
                        isoCoords.X - (renderTexture.Width - tileWidth),
                        isoCoords.Y - (renderTexture.Height - tileHeight / 2)), Color.White);
                }
                //end mouse

                // drawing object
                // now just draw red arrow
                foreach (MapTile tile in visibleTiles)
                {
                    Point isoCoords = calcIsoXY(tile.Position.X, tile.Position.Y);
                    isoCoords.X -= camera.xOffset;
                    isoCoords.Y -= camera.yOffset;

                    MapObject map_object = map.Objects.Find(item => item.Position.X == tile.Position.X &&
                        item.Position.Y == tile.Position.Y);

                    if (map_object != null)
                    {
                        string texture_name = "doogle";
                        switch (map_object.ClassID)
                        {
                            case 0:
                                texture_name = "bigfir";
                                break;
                            case 2:
                                texture_name = "peashut";
                                break;
                            case 5:
                                texture_name = "tree02";
                                break;
                            case 6:
                                texture_name = "tree10";
                                break;
                            case 83:
                                texture_name = "poison";
                                break;
                            case 103:
                                texture_name = "villager";
                                break;
                            case 58:
                                texture_name = "d_male";
                                break;
                            case 69:
                                texture_name = "toolshed"; // здание билдеров
                                break;
                            case 111:
                                texture_name = "chikfeld";
                                break;
                            case 98:
                                texture_name = "owner";
                                break;
                            case 143:
                                texture_name = "campfire";
                                break;
                            case 144:
                                texture_name = "crate";
                                break;
                            case 110:
                                texture_name = "cowwalk";
                                break;
                            case 159:
                                texture_name = "gob_silv";
                                break;
                            case 171:
                                texture_name = "crate";
                                break;
                            default:
                                throw new Exception(String.Format("Unhandled class id: {0}", map_object.ClassID));
                                break;
                        }
                        GameTextures2D gameTexture = textureList.Find(texture => texture.type.Equals(texture_name));
                        if (gameTexture != null)
                            spriteBatch.Draw(gameTexture.getTexture2D(), new Vector2(
                                isoCoords.X - gameTexture.offset.X + tileWidth / 2,
                                isoCoords.Y - gameTexture.offset.Y), Color.White);
                    }
                }
            }


        }

        public void load(ContentManager content, GraphicsDevice graphicsDevice,
            SpriteBatch spriteBatch, SpriteFont spriteFont, SpriteFont spriteFontBig)
        {
            this.spriteBatch = spriteBatch;
            this.graphicsDevice = graphicsDevice;

            this.spriteFont = spriteFont;
            this.spriteFontBig = spriteFontBig;
            this.content = content;
            this.textureList = new List<GameTextures2D>();

            map = new MAPFile(@"D:\beasts\savegam0.sav");

            video = new BOXFile(@"D:\beasts\VIDEO.BOX");
            LoadTexturesFromMFB("maptile.mfb");
            LoadTexturesFromMFB("roads.mfb");
            LoadTexturesFromMFB("tester.mfb");
            LoadTexturesFromMFB("tester2.mfb");
            LoadTexturesFromMFB("forest1.mfb");
            LoadTexturesFromMFB("forest2.mfb");
            LoadTexturesFromMFB("rockrim.mfb");
            LoadTexturesFromMFB("rock02.mfb");
            LoadTexturesFromMFB("rock03.mfb");
            LoadTexturesFromMFB("rock04.mfb");
            LoadTexturesFromMFB("rock05.mfb");
            LoadTexturesFromMFB("rock06.mfb");
            LoadTexturesFromMFB("doogle.mfb");
            LoadTexturesFromMFB("tileptr.mfb");

            LoadTexturesFromMFB("bigfir.mfb");
            LoadTexturesFromMFB("tree10.mfb");
            LoadTexturesFromMFB("poison.mfb");
            LoadTexturesFromMFB("villager.mfb");
            LoadTexturesFromMFB("d_male.mfb");
            LoadTexturesFromMFB("tree02.mfb");
            LoadTexturesFromMFB("toolshed.mfb");
            LoadTexturesFromMFB("chikfeld.mfb");
            LoadTexturesFromMFB("peashut.mfb");
            LoadTexturesFromMFB("owner.mfb");
            LoadTexturesFromMFB("campfire.mfb");
            LoadTexturesFromMFB("crate.mfb");
            LoadTexturesFromMFB("cowwalk.mfb");
            LoadTexturesFromMFB("gob_silv.mfb");
        }


        public void LoadTexturesFromMFB(string name)
        {
            MFBFile mfb = new MFBFile(video.Entries.Find(
                    item => item.filename == name).data);
            for (int i = 0; i < mfb.Entries.Count; i++)
                textureList.Add(
                    new GameTextures2D(
                        GetTexture2DFromBitmap(new System.Drawing.Bitmap(mfb.Entries[i])),
                        mfb.Offset,
                        name.Replace(".mfb", null),
                        i
                        )
                    );
        }

        // modified https://stackoverflow.com/a/2870399
        public Texture2D GetTexture2DFromBitmap(System.Drawing.Bitmap bitmap)
        {
            Texture2D tex = new Texture2D(graphicsDevice, bitmap.Width, bitmap.Height, true, SurfaceFormat.Bgra32);

            System.Drawing.Imaging.BitmapData data = bitmap.LockBits(new System.Drawing.Rectangle(0, 0, bitmap.Width, bitmap.Height), System.Drawing.Imaging.ImageLockMode.ReadOnly, bitmap.PixelFormat);

            int bufferSize = data.Height * data.Stride;

            //create data buffer 
            byte[] bytes = new byte[bufferSize];

            // copy bitmap data into buffer
            Marshal.Copy(data.Scan0, bytes, 0, bytes.Length);

            // copy our buffer to the texture
            tex.SetData(bytes);

            // unlock the bitmap data
            bitmap.UnlockBits(data);

            return tex;
        }

        public void handleMouse(GameMouse mouse, Camera camera)
        {
            mousePosition = mouse.state.Position;
        }

        public int calcIsoX(int x, int y)
        {
            return (x - y) * (tileWidth / 2);
        }

        public int calcIsoY(int x, int y)
        {
            return (x + y) * (tileHeight / 2);
        }

        public Point calcIsoXY(int x, int y)
        {
            return new Point(calcIsoX(x, y), calcIsoY(x, y));
        }

    }
}