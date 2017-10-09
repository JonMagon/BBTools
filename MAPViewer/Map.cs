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

        private GameTextures Textures;
        public Point mousePosition;

        private int tilesX = 192;
        private int tilesY = 192;
        public Point selectedTile;

        private int tileWidth = 78;
        private int tileHeight = 40;

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
                    calcIsoX(item.Position.X, item.Position.Y) +  tileWidth
                        > camera.width + camera.xOffset - camera.width &&
                    calcIsoX(item.Position.X, item.Position.Y) -  tileWidth
                        < camera.width + camera.xOffset) &&
                    (calcIsoY(item.Position.X, item.Position.Y) +  tileHeight
                        > camera.height + camera.yOffset - camera.height &&
                    calcIsoY(item.Position.X, item.Position.Y) -  tileHeight
                        < camera.height + camera.yOffset));

                foreach (MapTile tile in visibleTiles)
                {
                    Point isoCoords = calcIsoXY(tile.Position.X, tile.Position.Y);
                    isoCoords.X -= camera.xOffset;
                    isoCoords.Y -= camera.yOffset;

                    Texture2D renderTexture = null;

                    int tile_id_texture = tile.Texture;

                    if (tile_id_texture >= 234 && tile_id_texture <= 250)
                        tile_id_texture -= 119;
                    switch (tile_id_texture)
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
                            if (tile_id_texture < 202 || tile_id_texture >= 218)
                            {
                                if (tile_id_texture >= 227 && tile_id_texture < 232)
                                {
                                    renderTexture = Textures["rock" +
                                        (2 + tile_id_texture - 227).ToString("#0#"), 0].getTexture2D();
                                    break;
                                }
                                else if (tile_id_texture >= 98 && tile_id_texture < 114)
                                {
                                    renderTexture = Textures["rockrim", tile_id_texture - 98].getTexture2D();
                                    break;
                                }
                            }
                            else tile_id_texture = 0;

                            renderTexture = Textures["maptile", tile_id_texture].getTexture2D();
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

                    tilesDrawed++;
                }

                // mouse
                Point mouse_pos = mousePosition;
                mouse_pos.X += camera.xOffset;
                mouse_pos.Y += camera.yOffset;
                selectedTile = getTileCoordinates(mouse_pos);

                MapObject map_object_1 = map.Objects.Find(item => item.Position.X == selectedTile.X &&
                        item.Position.Y == selectedTile.Y);

                string mousecoords = string.Format(" {0},{1} {2}", selectedTile.X, selectedTile.Y,
                    (map_object_1 != null ? map_object_1.Class.ToString() : "null"));
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

                    Texture2D renderTexture = Textures["tileptr", 12].getTexture2D();
                    spriteBatch.Draw(renderTexture, new Vector2(
                        isoCoords.X - (renderTexture.Width - tileWidth),
                        isoCoords.Y - (renderTexture.Height - tileHeight / 2)), Color.White);
                }
                //end mouse

                // drawing object
                // now just draw red arrow

                List<MapObject> visibleObjects = map.Objects.FindAll(item => (
                    calcIsoX(item.Position.X, item.Position.Y) + 5 * tileWidth
                        > camera.width + camera.xOffset - camera.width &&
                    calcIsoX(item.Position.X, item.Position.Y) - 5 * tileWidth
                        < camera.width + camera.xOffset) &&
                    (calcIsoY(item.Position.X, item.Position.Y) + 5 * tileHeight
                        > camera.height + camera.yOffset - camera.height &&
                    calcIsoY(item.Position.X, item.Position.Y) - 5 * tileHeight
                        < camera.height + camera.yOffset));

                foreach (MapObject map_object in visibleObjects)
                {
                    Point isoCoords = calcIsoXY(map_object.Position.X, map_object.Position.Y);
                    isoCoords.X -= camera.xOffset;
                    isoCoords.Y -= camera.yOffset;


                    if (map_object != null)
                    {
                        string texture_name = "doogle";
                        int frame = 0;
                        switch (map_object.Class)
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
                                frame = map_object.State;
                                break;
                            case 103:
                                texture_name = "villager";
                                break;
                            case 58:
                                switch (map_object.Field_F2)
                                {
                                    case 0x1B:
                                        switch (map_object.State)
                                        {
                                            case 1:
                                            default:
                                                texture_name = "d_male";
                                                break;
                                            case 2:
                                                texture_name = "d_fema";
                                                break;
                                            case 3:
                                                texture_name = "d_prie";
                                                break;
                                            case 4:
                                                texture_name = "d_buil";
                                                break;
                                            case 5:
                                                texture_name = "d_taxm";
                                                break;
                                            case 6:
                                                texture_name = "d_pike";
                                                break;
                                            case 7:
                                                texture_name = "d_foot";
                                                break;
                                            case 8:
                                                texture_name = "d_knig";
                                                break;
                                            case 9:
                                                texture_name = "d_wiza";
                                                break;
                                            case 10:
                                                texture_name = "d_oldm";
                                                break;
                                            case 11:
                                                texture_name = "d_oldw";
                                                break;
                                            case 12:
                                                texture_name = "d_kidm";
                                                break;
                                            case 13:
                                                texture_name = "d_kidf";
                                                break;
                                            case 16:
                                                texture_name = "d_cava";
                                                break;
                                            case 19:
                                                texture_name = "d_arch";
                                                break;
                                            case 20:
                                                texture_name = "d_jest";
                                                break;
                                            case 32:
                                                texture_name = "d_groom";
                                                break;
                                            case 33:
                                                texture_name = "d_bride";
                                                break;
                                        }
                                        frame = map_object.Frame >> 2;
                                        break;
                                }
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
                                throw new Exception(String.Format("Unhandled class id: {0}", map_object.Class));
                        }
                        DrawTexture(isoCoords, Textures[texture_name, frame]);
                    }
                }
            }
        }

        public void DrawTexture(Point isoCoords, GameTexture2D texture)
        {
            spriteBatch.Draw(texture.getTexture2D(), new Vector2(
                isoCoords.X - texture.offset.X + tileWidth / 2,
                isoCoords.Y - texture.offset.Y), Color.White);
        }

        public void load(ContentManager content, GraphicsDevice graphicsDevice,
            SpriteBatch spriteBatch, SpriteFont spriteFont, SpriteFont spriteFontBig)
        {
            this.spriteBatch = spriteBatch;
            this.graphicsDevice = graphicsDevice;

            this.spriteFont = spriteFont;
            this.spriteFontBig = spriteFontBig;
            this.content = content;

            map = new MAPFile(@"D:\beasts\savegam0.sav");

            Textures = new GameTextures(graphicsDevice, @"D:\beasts\VIDEO.BOX");
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