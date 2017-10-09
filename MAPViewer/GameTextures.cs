using BBData;
using System.Collections.Generic;
using Microsoft.Xna.Framework.Graphics;
using System.Drawing;
using System.Runtime.InteropServices;
using System;

namespace MAPViewer
{
    public class GameTextures
    {
        private GraphicsDevice graphicsDevice;
        private BOXFile BOX;
        private List<GameTexture2D> textureList = new List<GameTexture2D>();

        public GameTextures(GraphicsDevice graphicsDevice, string boxname)
        {
            this.graphicsDevice = graphicsDevice;
            this.BOX = new BOXFile(boxname);
        }

        public GameTexture2D this[string name, int frame]
        {
            get {
                GameTexture2D texture = textureList.Find(item => item.type.Equals(name) && item.id == frame);
                if (texture == null)
                {
                    BOXFile.Entry entry;
                    if ((entry = BOX.Entries.Find(item => item.filename == name + ".mfb")) == null)
                        throw new Exception(String.Format("Texture (name: {0}) doesn't exists.", name + ".mfb"));

                    MFBFile mfb = new MFBFile(entry.data);

                    for (int i = 0; i < mfb.Entries.Count; i++)
                    {
                        GameTexture2D item = new GameTexture2D(
                            GetTexture2DFromBitmap(new System.Drawing.Bitmap(mfb.Entries[i])),
                            mfb.Offset,
                            name.Replace(".mfb", null),
                            i
                            );
                        textureList.Add(item);
                        if (i == frame) texture = item;
                    }
                }

                if (texture == null)
                    throw new Exception(String.Format("{0}: frame {1} doesn't exists.", name + ".mfb", frame));

                return texture;
            }
        }

        // modified https://stackoverflow.com/a/2870399
        private Texture2D GetTexture2DFromBitmap(System.Drawing.Bitmap bitmap)
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
    }

    public class GameTexture2D
    {
        public Texture2D texture;
        public Point offset;
        public string type;
        public int id;

        public GameTexture2D(Texture2D texture, Point offset, string type, int id)
        {
            this.texture = texture;
            this.offset = offset;
            this.type = type;
            this.id = id;
        }

        public Texture2D getTexture2D()
        {
            return texture;
        }
    }
}
