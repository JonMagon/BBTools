using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Runtime.InteropServices;
using BBData;
using Microsoft.Xna.Framework.Graphics;

namespace MAPViewer
{
    public class GameTextures
    {
        private readonly BOXFile BOX;
        private readonly GraphicsDevice graphicsDevice;
        private readonly List<GameTexture2D> textureList = new List<GameTexture2D>();

        public GameTextures(GraphicsDevice graphicsDevice, string boxname)
        {
            this.graphicsDevice = graphicsDevice;
            BOX = new BOXFile(boxname);
        }

        public GameTexture2D this[string name, int frame]
        {
            get
            {
                var texture = textureList.FirstOrDefault(item => item.Type.Equals(name) && item.ID == frame);
                if (texture == null)
                {
                    BOXFile.Entry entry;
                    if ((entry = BOX.Entries.FirstOrDefault(item => item.Filename == name + ".mfb")) == null)
                        throw new Exception($"Texture (name: {name}.mfb) doesn't exists.");

                    var mfb = new MFBFile(entry.Data);

                    for (var i = 0; i < mfb.Entries.Count; i++)
                    {
                        var item = new GameTexture2D(
                            GetTexture2DFromBitmap(new Bitmap(mfb.Entries[i])),
                            mfb.Offset,
                            name.Replace(".mfb", null),
                            i
                        );
                        textureList.Add(item);
                        if (i == frame) texture = item;
                    }
                }

                if (texture == null)
                    throw new Exception($"{name}.mfb: frame {frame} doesn't exists.");

                return texture;
            }
        }

        // modified https://stackoverflow.com/a/2870399
        private Texture2D GetTexture2DFromBitmap(Bitmap bitmap)
        {
            var tex = new Texture2D(graphicsDevice, bitmap.Width, bitmap.Height, true, SurfaceFormat.Bgra32);

            var data = bitmap.LockBits(
                new Rectangle(0, 0, bitmap.Width, bitmap.Height),
                ImageLockMode.ReadOnly, bitmap.PixelFormat);

            var bufferSize = data.Height * data.Stride;

            //create data buffer 
            var bytes = new byte[bufferSize];

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
        public int ID;
        public Point Offset;
        public Texture2D texture;
        public string Type;

        public GameTexture2D(Texture2D texture, Point offset, string type, int id)
        {
            this.texture = texture;
            Offset = offset;
            Type = type;
            ID = id;
        }

        public Texture2D getTexture2D()
        {
            return texture;
        }
    }
}