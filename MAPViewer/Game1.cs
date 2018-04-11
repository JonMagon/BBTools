using System;
using System.Windows.Forms;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using MonoGameConsole;

namespace MAPViewer
{
    /// <summary>
    ///     This is the main Type for your game.
    /// </summary>
    public class Game1 : Game
    {
        public static int WINDOW_WIDTH = 1200;
        public static int WINDOW_HEIGHT = 600;
        private readonly GraphicsDeviceManager graphics;
        private GameCamera camera;

        private float elapsedTime;
        private float elapsedTimeAnimate;

        private GameMap gameMap;
        private GameMouse gameMouse;
        private GameKeyboard keyboard;
        private SpriteBatch spriteBatch;

        private SpriteFont spriteFont;
        private SpriteFont spriteFontBig;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this)
            {
                PreferredBackBufferWidth = WINDOW_WIDTH,
                PreferredBackBufferHeight = WINDOW_HEIGHT
            };
            IsMouseVisible = true;
            Content.RootDirectory = "Content";
        }

        /// <summary>
        ///     Allows the game to perform any initialization it needs to before starting to run.
        ///     This is where it can query for any required services and load any non-graphic
        ///     related content.  Calling base.Initialize will enumerate through any components
        ///     and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here
            gameMap = new GameMap(spriteBatch, graphics);
            camera = new GameCamera(WINDOW_WIDTH, WINDOW_HEIGHT);
            gameMouse = new GameMouse(new Vector2(WINDOW_WIDTH, WINDOW_HEIGHT));

            keyboard = new GameKeyboard(camera, gameMap);
            
            base.Initialize();
        }

        protected override void LoadContent()
        {
            try
            {
                spriteBatch = new SpriteBatch(GraphicsDevice);

                Services.AddService(typeof(SpriteBatch), spriteBatch);

                var console = new GameConsole(this, spriteBatch, new GameConsoleOptions
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
                    if (a.Length != 2 || !(int.TryParse(a[0], out int x) && int.TryParse(a[1], out int y)))
                        return "ERROR: Illegal arguments";
                    if (x < 0 || x > 192 || y < 0 || y > 192)
                        return "ERROR: Arguments x and y must be both positive and less than 192";
                    camera.XOffset = gameMap.CalcIsoX(x, y) - WINDOW_WIDTH / 2;
                    camera.YOffset = gameMap.CalcIsoY(x, y) - WINDOW_HEIGHT / 2;
                    return $"SUCCESS: New position is {x} {y}";
                }, "Set new position. Arguments: x y");

                keyboard.console = console;

                spriteFont = Content.Load<SpriteFont>("font");
                spriteFontBig = Content.Load<SpriteFont>("fontBig");

                gameMap.Load(Content, GraphicsDevice, spriteBatch, spriteFont, spriteFontBig);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message,
                    "Exception: LoadContent", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        /// <summary>
        ///     UnloadContent will be called once per game and is the place to unload
        ///     game-specific content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        protected override void Update(GameTime gameTime)
        {
            if (!IsActive) return;

            elapsedTime += gameTime.ElapsedGameTime.Milliseconds;
            elapsedTimeAnimate += gameTime.ElapsedGameTime.Milliseconds;

            gameMouse.State = Mouse.GetState();
            gameMouse.Camera = camera;

            // temp
            if (elapsedTimeAnimate > 100f)
            {
                elapsedTimeAnimate -= 100f;
                GameMap.mark_object_id = (GameMap.mark_object_id + 1) % 7;
            }

            gameMouse.UpdateCursor();
            gameMouse.HandleMouse();

            gameMap.HandleMouse(gameMouse, camera);

            keyboard.Update();

            base.Update(gameTime);
        }

        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.Black);
            spriteBatch.Begin();

            try
            {
                gameMap.DrawMap(camera);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"{ex.Message}{Environment.NewLine}This application will be terminated.",
                    "Exception", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Exit();
            }

            spriteBatch.End();

            base.Draw(gameTime);
        }
    }
}