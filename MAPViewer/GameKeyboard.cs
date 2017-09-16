using Microsoft.Xna.Framework.Input;
using MonoGameConsole;

namespace MAPViewer
{
    public class GameKeyboard
    {
        public KeyboardState previousState;
        public Camera camera;
        private Map map;
        public GameConsole console;

        public GameKeyboard(Camera camera, Map map)
        {
            this.camera = camera;
            this.map = map;
        }


        public void Update()
        {
            KeyboardState state = Keyboard.GetState();
            Keys[] pressedKeys = state.GetPressedKeys();

            for (int i = 0; i < pressedKeys.Length; i++)
            {
                switch (pressedKeys[i])
                {
                    case Keys.Left:
                        if (camera.moveableXLeft && !console.Opened)
                            camera.xOffset -= 1 * camera.speed;
                        break;
                    case Keys.Right:
                        if (camera.moveableXRight && !console.Opened)
                            camera.xOffset += 1 * camera.speed;
                        break;
                    case Keys.Up:
                        if (camera.moveableYTop && !console.Opened)
                            camera.yOffset -= 1 * camera.speed;
                        break;
                    case Keys.Down:
                        if (camera.moveableYDown && !console.Opened)
                            camera.yOffset += 1 * camera.speed;
                        break;
                }
            }
            previousState = state;
        }
    }
}
