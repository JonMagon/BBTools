using Microsoft.Xna.Framework;

namespace MAPViewer
{
    public class GameCamera
    {
        public Vector2 cameraPosition;
        public int height;

        public bool moveableXLeft = true;
        public bool moveableXRight = true;
        public bool moveableYDown = true;
        public bool moveableYTop = true;
        public int speed = 5;
        public int width;

        public int XOffset = 0;
        public int YOffset = 0;

        public GameCamera(int width, int height)
        {
            this.width = width;
            this.height = height;
            cameraPosition = new Vector2(0, 0);
        }
    }
}