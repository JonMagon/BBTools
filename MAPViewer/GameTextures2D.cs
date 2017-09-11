using Microsoft.Xna.Framework.Graphics;

namespace MAPViewer
{
    public class GameTextures2D
    {
        public Texture2D texture;
        public string type;
        public int id;

        public GameTextures2D(Texture2D texture, string type, int id)
        {
            this.texture = texture;
            this.type = type;
            this.id = id;
        }

        public Texture2D getTexture2D()
        {
            return texture;
        }
    }
}