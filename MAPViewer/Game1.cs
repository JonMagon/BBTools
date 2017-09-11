using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;

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

        SpriteFont spriteFont;
        private SpriteFont spriteFontBig;

        private Map gameMap;
        private Camera camera;
        private GameMouse gameMouse;

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

            base.Initialize();
        }

        protected override void LoadContent()
        {
            spriteBatch = new SpriteBatch(GraphicsDevice);

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

            gameMouse.state = Mouse.GetState();
            gameMouse.camera = this.camera;

            gameMouse.updateCursor();
            gameMouse.handleMouse();

            gameMap.handleMouse(gameMouse, camera);
            base.Update(gameTime);
        }

        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.Black);
            spriteBatch.Begin();

            gameMap.drawMap(camera);

            spriteBatch.End();

            base.Draw(gameTime);
        }
    }
}
