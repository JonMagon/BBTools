using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace SpriteViewer
{
    class Sprite
    {
        Image _img;
        long _offset;
        int _length;
        bool _RLE;

        public Image SpriteImage
        {
            get
            {
                return _img;
            }
            set
            {
                _img = value;
            }
        }

        public long Offset
        {
            get
            {
                return _offset;
            }
            set
            {
                _offset = value;
            }
        }

        public int Length
        {
            get
            {
                return _length;
            }
            set
            {
                _length = value;
            }
        }

        public bool RLE
        {
            get
            {
                return _RLE;
            }
            set
            {
                _RLE = value;
            }
        }
    }
}
