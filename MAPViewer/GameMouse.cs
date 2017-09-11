using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;

namespace MAPViewer
{
    public class GameMouse
    {
        public MouseState state;
        private Point windowSize;
        public int drawMouse;
        public Camera camera;

        bool CursorOnLeft() { return (state.Position.X <= 100 && camera.moveableXLeft); }
        bool CursorOnRight() { return (state.Position.X >= windowSize.X - 100 && camera.moveableXRight);  }
        bool CursorOnTop() { return state.Position.Y <= 100 && camera.moveableYTop; }
        bool CursorOnDown() { return state.Position.Y >= windowSize.Y - 100 && camera.moveableYDown; }

        public GameMouse(Point size) { windowSize = size; }

        public void updateCursor()
        {
            if ((state.Position.X > 0 && state.Position.X < windowSize.X)
                && (state.Position.Y > 0 && state.Position.Y < windowSize.Y))
            {
                if (CursorOnLeft()) camera.xOffset -= 1 * camera.speed;
                if (CursorOnRight()) camera.xOffset += 1 * camera.speed;
                if (CursorOnTop()) camera.yOffset -= 1 * camera.speed;
                if (CursorOnDown()) camera.yOffset += 1 * camera.speed;
            }
       }

        public void handleMouse()
        {
            if (state.RightButton == ButtonState.Pressed)
            {
                
            }
        }
    }
}