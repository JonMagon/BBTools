using Microsoft.Xna.Framework;

namespace MAPViewer
{
    public class Camera
    {
        public Point cameraPosition;
        public int height;

        public bool moveableXLeft = true;
        public bool moveableXRight = true;
        public bool moveableYDown = true;
        public bool moveableYTop = true;
        public int speed = 5;
        public int width;

        public int XOffset = 0;
        public int YOffset = 0;

        public Camera(int width, int height)
        {
            this.width = width;
            this.height = height;
            cameraPosition = new Point(0, 0);
        }
    }
}