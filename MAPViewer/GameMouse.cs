using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace MAPViewer
{
    public class GameMouse
    {
        public Camera camera;
        public int drawMouse;
        public MouseState state;
        private Point windowSize;

        public GameMouse(Point size)
        {
            windowSize = size;
        }

        private bool CursorOnLeft()
        {
            return state.Position.X <= 100 && camera.moveableXLeft;
        }

        private bool CursorOnRight()
        {
            return state.Position.X >= windowSize.X - 100 && camera.moveableXRight;
        }

        private bool CursorOnTop()
        {
            return state.Position.Y <= 100 && camera.moveableYTop;
        }

        private bool CursorOnDown()
        {
            return state.Position.Y >= windowSize.Y - 100 && camera.moveableYDown;
        }

        public void updateCursor()
        {
            if (state.Position.X > 0 && state.Position.X < windowSize.X && state.Position.Y > 0 &&
                state.Position.Y < windowSize.Y)
            {
                if (CursorOnLeft()) camera.XOffset -= 1 * camera.speed;
                if (CursorOnRight()) camera.XOffset += 1 * camera.speed;
                if (CursorOnTop()) camera.YOffset -= 1 * camera.speed;
                if (CursorOnDown()) camera.YOffset += 1 * camera.speed;
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