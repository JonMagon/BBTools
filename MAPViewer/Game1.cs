using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using MonoGameConsole;
using System;
using System.Windows.Forms;

namespace MAPViewer
{
    /// <summary>
    /// This is the main type for your game.
    /// </summary>
    public class Game1 : Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        float elapsedTime = 0f;
        float elapsedTimeAnimate = 0f;

        public static int WINDOW_WIDTH = 1200;
        public static int WINDOW_HEIGHT = 600;

        private SpriteFont spriteFont;
        private SpriteFont spriteFontBig;

        private Map gameMap;
        private Camera camera;
        private GameMouse gameMouse;
        private GameKeyboard keyboard;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            graphics.PreferredBackBufferWidth = WINDOW_WIDTH;
            graphics.PreferredBackBufferHeight = WINDOW_HEIGHT;
            IsMouseVisible = true;
            Content.RootDirectory = "Content";
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here
            gameMap = new Map(spriteBatch, graphics);
            camera = new Camera(WINDOW_WIDTH, WINDOW_HEIGHT);
            gameMouse = new GameMouse(new Point(WINDOW_WIDTH, WINDOW_HEIGHT));

            keyboard = new GameKeyboard(camera, gameMap);

            base.Initialize();
        }

        protected override void LoadContent()
        {
            spriteBatch = new SpriteBatch(GraphicsDevice);

            Services.AddService(typeof(SpriteBatch), spriteBatch);

            GameConsole console = new GameConsole(this, spriteBatch, new GameConsoleOptions
            {
                ToggleKey = 192,
                Height = 250,
                Font = Content.Load<SpriteFont>("fontBig"),
                FontColor = Color.LawnGreen,
                Prompt = ">",
                PromptColor = Color.White,
                CursorColor = Color.White,
                BackgroundColor = new Color(Color.Black, 150),
                PastCommandOutputColor = Color.Aqua,
                BufferColor = Color.White
            });

            console.AddCommand("goto", a =>
            {
                int x, y;
                if (a.Length != 2 || !(int.TryParse(a[0], out x) && int.TryParse(a[1], out y)))
                    return "ERROR: Illegal arguments";
                if (x < 0 || x > 192 || y < 0 || y > 192)
                    return "ERROR: Arguments x and y must be both positive and less than 192";
                camera.xOffset = gameMap.calcIsoX(x, y) - WINDOW_WIDTH / 2;
                camera.yOffset = gameMap.calcIsoY(x, y) - WINDOW_HEIGHT / 2;
                return string.Format("SUCCESS: New position is {0} {1}", x, y);
            }, "Set new position. Arguments: x y");

            keyboard.console = console;

            spriteFont = Content.Load<SpriteFont>("font");
            spriteFontBig = Content.Load<SpriteFont>("fontBig");

            gameMap.load(Content, GraphicsDevice, spriteBatch, spriteFont, spriteFontBig);
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// game-specific content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        protected override void Update(GameTime gameTime)
        {
            elapsedTime += gameTime.ElapsedGameTime.Milliseconds;
            elapsedTimeAnimate += gameTime.ElapsedGameTime.Milliseconds;

            gameMouse.state = Mouse.GetState();
            gameMouse.camera = this.camera;

            // temp
            if (elapsedTimeAnimate > 100f)
            {
                elapsedTimeAnimate -= 100f;
                Map.mark_object_id++;
                if (Map.mark_object_id > 3) Map.mark_object_id = 0;
            }

            gameMouse.updateCursor();
            gameMouse.handleMouse();

            gameMap.handleMouse(gameMouse, camera);

            keyboard.Update();

            base.Update(gameTime);
        }

        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.Black);
            spriteBatch.Begin();

            try
            {
                gameMap.drawMap(camera);
            } catch (Exception ex)
            {
                MessageBox.Show(ex.Message + Environment.NewLine +
                    "This application will be terminated.", "Exception", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Exit();
            }

            //drawConsole(spriteBatch, spriteFont);

            spriteBatch.End();

            base.Draw(gameTime);
        }
    }
}
