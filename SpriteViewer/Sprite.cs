using System.Drawing;

namespace SpriteViewer
{
    internal class Sprite
    {
        public Image SpriteImage { get; set; }

        public long Offset { get; set; }

        public int Length { get; set; }

        public bool RLE { get; set; }
    }
}