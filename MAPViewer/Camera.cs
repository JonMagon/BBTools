using Microsoft.Xna.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework.Input;

namespace MAPViewer
{
    public class Camera
    {
        public Point cameraPosition;
        public int width;
        public int height;
        public int speed = 5;

        public int xOffset = 0;
        public int yOffset = 0;

        public bool moveableXLeft = true;
        public bool moveableXRight = true;
        public bool moveableYTop = true;
        public bool moveableYDown = true;

        public Camera(int width, int height)
        {
            this.width = width;
            this.height = height;
            this.cameraPosition = new Point(0, 0);
        }
    }
}
