using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Drawing;

namespace BBData
{
    public class MAPFile
    {
        public string Name { get; private set; }
        public Point Size { get; private set; }

        public List<Tile> Tiles { get; private set; } = new List<Tile>();

        // https://stackoverflow.com/a/1403542
        private string TrimFromZero(string input)
        {
            int index = input.IndexOf('\0');
            if (index < 0)
                return input;

            return input.Substring(0, index);
        }

        public MAPFile(string filename)
        {
            using (BinaryReader binr = new BinaryReader(File.OpenRead(filename), Encoding.ASCII))
            {
                if (!binr.ReadChars(3).SequenceEqual("MAP"))
                    throw new Exception("Map file is corrupted. Bad signature.");

                string version = new string(binr.ReadChars(5));
                Name = TrimFromZero(new string(binr.ReadChars(64)));

                Size = new Point(binr.ReadByte(), binr.ReadByte());

                for (int x = 0; x < Size.X; x++)
                {
                    uint size = binr.ReadUInt32();
                    byte[] data = new byte[Size.X * 0xC];
                    byte temp;
                    uint j = 0;
                    uint k = 0;

                    // uncompress RLE-0
                    while (j < size)
                    {
                        temp = binr.ReadByte(); j++;
                        if (temp != 0)
                        {
                            data[k] = temp;
                            k++;
                        }
                        else
                        {
                            int length = binr.ReadByte(); j++;
                            for (int t = 0; t < length; t++)
                            {
                                if (k == Size.X * 0xC) break;
                                data[k] = 0;
                                k++;
                            }
                        }
                    }
                    for (int y = 0; y < Size.Y; y++)
                    {
                        int ptr = y * 12;

                        Tile tile = new Tile(new Point(y, x));
                        tile.Texture = data[ptr + 0];
                        tile.Road = data[ptr + 1];
                        tile.Player = data[ptr + 2];
                        tile.Unk2 = data[ptr + 3];
                        tile.Entity = data[ptr + 4];
                        tile.Unk3 = data[ptr + 5];
                        tile.IsObject = data[ptr + 6];
                        tile.Unk6 = BitConverter.ToInt32(new byte[] { data[ptr + 8],
                            data[ptr + 9], data[ptr + 10], data[ptr + 11] }, 0);

                        Tiles.Add(tile);
                    }
                }
            }
        }
    }

    public class Tile
    {
        public Point Position { get; private set; }

        public int Texture { get; set; }
        public byte Road { get; set; }
        public byte Player { get; set; }
        public byte Unk2 { get; set; }
        public byte Entity { get; set; }
        public byte Unk3 { get; set; }
        public byte IsObject { get; set; }
        public byte Unk5 { get; set; }
        public int Unk6 { get; set; }


        public Tile(Point position)
        {
            this.Position = position;
        }
    }
}
