using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace MAPViewer
{
    public class GameMouse
    {
        public GameCamera Camera;
        public int DrawMouse;
        public MouseState State;
        private Vector2 WindowSize;

        public GameMouse(Vector2 size)
        {
            WindowSize = size;
        }

        private bool CursorOnLeft()
        {
            return State.Position.X <= 100 && Camera.moveableXLeft;
        }

        private bool CursorOnRight()
        {
            return State.Position.X >= WindowSize.X - 100 && Camera.moveableXRight;
        }

        private bool CursorOnTop()
        {
            return State.Position.Y <= 100 && Camera.moveableYTop;
        }

        private bool CursorOnDown()
        {
            return State.Position.Y >= WindowSize.Y - 100 && Camera.moveableYDown;
        }

        public void UpdateCursor()
        {
            if (State.Position.X > 0 && State.Position.X < WindowSize.X && State.Position.Y > 0 &&
                State.Position.Y < WindowSize.Y)
            {
                if (CursorOnLeft()) Camera.XOffset -= 1 * Camera.speed;
                if (CursorOnRight()) Camera.XOffset += 1 * Camera.speed;
                if (CursorOnTop()) Camera.YOffset -= 1 * Camera.speed;
                if (CursorOnDown()) Camera.YOffset += 1 * Camera.speed;
            }
        }

        public void HandleMouse()
        {
            if (State.RightButton == ButtonState.Pressed)
            {
            }
        }
    }
}