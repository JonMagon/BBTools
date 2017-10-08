using Microsoft.Xna.Framework.Graphics;
using System.Drawing;

namespace MAPViewer
{
    public class GameTextures2D
    {
        public Texture2D texture;
        public Point offset;
        public string type;
        public int id;

        public GameTextures2D(Texture2D texture, Point offset, string type, int id)
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