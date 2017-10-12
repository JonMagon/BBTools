using Microsoft.Xna.Framework.Input;
using MonoGameConsole;

namespace MAPViewer
{
    public class GameKeyboard
    {
        public Camera camera;
        public GameConsole console;
        private Map map;
        public KeyboardState previousState;

        public GameKeyboard(Camera camera, Map map)
        {
            this.camera = camera;
            this.map = map;
        }


        public void Update()
        {
            var state = Keyboard.GetState();
            var pressedKeys = state.GetPressedKeys();

            for (var i = 0; i < pressedKeys.Length; i++)
                switch (pressedKeys[i])
                {
                    case Keys.Left:
                        if (camera.moveableXLeft && !console.Opened)
                            camera.XOffset -= 1 * camera.speed;
                        break;
                    case Keys.Right:
                        if (camera.moveableXRight && !console.Opened)
                            camera.XOffset += 1 * camera.speed;
                        break;
                    case Keys.Up:
                        if (camera.moveableYTop && !console.Opened)
                            camera.YOffset -= 1 * camera.speed;
                        break;
                    case Keys.Down:
                        if (camera.moveableYDown && !console.Opened)
                            camera.YOffset += 1 * camera.speed;
                        break;
                }
            previousState = state;
        }
    }
}