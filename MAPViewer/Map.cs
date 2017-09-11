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
            return new Point((int)(Math.Floor(pt.X / (double)tileWidth + pt.Y / (double)tileHeight)),
                -(int)(Math.Floor(pt.X / (double)tileWidth - pt.Y / (double)tileHeight)));
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
                List<Tile> visibleTiles = map.Tiles.FindAll(item => (
                               calcIsoX(item.Position.X, item.Position.Y) + tileWidth
                                        > camera.width + camera.xOffset - camera.width &&
                               calcIsoX(item.Position.X, item.Position.Y) - tileWidth
                                                       < camera.width + camera.xOffset) &&
                              (calcIsoY(item.Position.X, item.Position.Y) + 2 * tileHeight
                                        > camera.height + camera.yOffset - camera.height &&
                               calcIsoY(item.Position.X, item.Position.Y) - 2 * tileHeight
                                                       < camera.height + camera.yOffset));

                foreach (Tile tile in visibleTiles)
                {
                    Point isoCoords = calcIsoXY(tile.Position.X, tile.Position.Y);
                    isoCoords.X -= camera.xOffset;
                    isoCoords.Y -= camera.yOffset;

                    Texture2D renderTexture;

                    if (tile.Texture >= 234 && tile.Texture <= 250)
                        tile.Texture -= 119;
                    switch (tile.Texture)
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
                            if (tile.Texture < 202 || tile.Texture >= 218)
                            {
                                if (tile.Texture >= 227 && tile.Texture < 232)
                                {
                                    renderTexture = textureList[textureList.FindIndex(item => item.type.Equals("rock02")) +
                                        tile.Texture - 227].getTexture2D();
                                    break;
                                }
                                else if (tile.Texture >= 98 && tile.Texture < 114)
                                {
                                    renderTexture = textureList.Find(texture => texture.type.Equals("rockrim")
                                        && texture.id == tile.Texture - 98).getTexture2D();
                                    break;
                                }
                            }
                            else tile.Texture = 0;

                            renderTexture = textureList.Find(texture => texture.type.Equals("maptile")
                                && texture.id == tile.Texture).getTexture2D();
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

                string mousecoords = string.Format(" {0},{1} ", selectedTile.X, selectedTile.Y);
                spriteBatch.DrawString(spriteFont, mousecoords, new Vector2(
                    mousePosition.X + 16, mousePosition.Y - 14), Color.Black);
                spriteBatch.DrawString(spriteFont, mousecoords, new Vector2(
                    mousePosition.X + 15, mousePosition.Y - 15), Color.White);

                // drawing tile ptr
                Tile tile_selected = map.Tiles.Find(_tile => _tile.Position.X == (float)selectedTile.X
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
                foreach (Tile tile in visibleTiles)
                {
                    Point isoCoords = calcIsoXY((int)tile.Position.X, (int)tile.Position.Y);
                    isoCoords.X -= camera.xOffset;
                    isoCoords.Y -= camera.yOffset;

                    if (tile.IsObject != 0)
                    {
                        Texture2D renderTexture = textureList.Find(texture => texture.type.Equals("doogle")
                            && texture.id == mark_object_id).getTexture2D();
                        spriteBatch.Draw(renderTexture, new Vector2(
                            isoCoords.X + (tileWidth / 2 - renderTexture.Width / 2),
                            isoCoords.Y - (tileWidth / 2 - renderTexture.Width / 2)), Color.White);
                    }
                }
            }


        }

        public void load(ContentManager content, GraphicsDevice graphicsDevice, SpriteBatch spriteBatch, SpriteFont spriteFont, SpriteFont spriteFontBig)
        {
            this.spriteBatch = spriteBatch;
            this.graphicsDevice = graphicsDevice;

            this.spriteFont = spriteFont;
            this.spriteFontBig = spriteFontBig;
            this.content = content;
            this.textureList = new List<GameTextures2D>();

            map = new MAPFile(@"D:\2017_Remake\game\savegam0.sav");

            video = new BOXFile(@"D:\2017_Remake\game\VIDEO.BOX");
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
        }


        public void LoadTexturesFromMFB(string name)
        {
            MFBFile mfb = new MFBFile(video.Entries.Find(
                    item => item.filename == name).data);
            for (int i = 0; i < mfb.Entries.Count; i++)
                textureList.Add(new GameTextures2D(GetTexture2DFromBitmap(new System.Drawing.Bitmap(mfb.Entries[i])), name.Replace(".mfb", null), i));
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