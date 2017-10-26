using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;

namespace BBData
{
    public class MAPFile
    {
        /// <summary>
        ///     Load map from file.
        /// </summary>
        /// <param name="filename">Path to .sav or .mis file</param>
        public MAPFile(string filename)
        {
            using (var binr = new BinaryReader(File.OpenRead(filename), Encoding.ASCII))
            {
                if (!binr.ReadChars(3).SequenceEqual("MAP"))
                    throw new Exception("Map file is corrupted. Bad signature.");

                var version = new string(binr.ReadChars(5));
                Name = TrimFromZero(new string(binr.ReadChars(64)));

                Size = new Point(binr.ReadByte(), binr.ReadByte());

                for (var y = 0; y < Size.Y; y++)
                {
                    var size = binr.ReadInt32();
                    var data = UnpackRLE0(binr.ReadBytes(size), Size.X * 0xC);

                    for (var x = 0; x < Size.X; x++)
                    {
                        var ptr = x * 12;

                        var tile = new MapTile(new Point(x, y))
                        {
                            Texture = data[ptr + 0],
                            Road = data[ptr + 1],
                            Player = data[ptr + 2],
                            Mask1 = BitConverter.ToInt32(data, ptr + 3),
                            Unk1 = data[ptr + 7],
                            Mask2 = BitConverter.ToInt32(data, ptr + 8)
                        };

                        Tiles.Add(tile);
                    }
                }

                // objects

                int ptr_to_some_global_arr = binr.ReadInt32(),
                    ptr_to_smth2_arr = binr.ReadInt32(),
                    sizeof_smth2_arr = binr.ReadInt32();

                for (var i = 0; i < sizeof_smth2_arr; i++)
                    if (binr.ReadByte() != 0)
                    {
                        var size = binr.ReadInt32();
                        var data = UnpackRLE0(binr.ReadBytes(size), 0x13A);
                        if (BitConverter.ToInt32(data, 236) != 0)
                            Array.Copy(binr.ReadBytes(data[0xF0]), 0, data, 236, data[0xF0]);

                        if (data[212] == 98)
                            Array.Copy(binr.ReadBytes(32), 0, data, 0x3C, 32);

                        if (BitConverter.ToInt32(data, 56) != 0)
                            Array.Copy(binr.ReadBytes(2), 0, data, 0x38, 2);

                        var indexbytes = BitConverter.GetBytes(i);
                        Array.Copy(indexbytes, 0, data, 142, 4);

                        var mapObject = new MapObject(new Point(data[0xD8], data[0xD9]))
                        {
                            Class = data[0xD4],
                            State = data[0xEA],
                            Field_F2 = data[0xF2],
                            Frame = data[0xF9],
                            OwnerPlayer = data[0xF7],
                            Sex = data[0xF4],
                            IsFleeing = data[0x106] != 0,
                            GenPeriod = data[0xE5],
                            IsGoing = data[0x11D] != 0
                        };
                        Objects.Add(mapObject);

                        if (data[0x8E] == 52)
                            File.WriteAllBytes("villager52_1.bin", data);
                    }
            }
        }

        public string Name { get; }
        public Point Size { get; }

        public List<MapTile> Tiles { get; } = new List<MapTile>();
        public List<MapObject> Objects { get; private set; } = new List<MapObject>();

        // https://stackoverflow.com/a/1403542
        private string TrimFromZero(string input)
        {
            var index = input.IndexOf('\0');
            if (index < 0)
                return input;

            return input.Substring(0, index);
        }

        private static byte[] UnpackRLE0(byte[] input, int size)
        {
            var data = new byte[size];
            uint j = 0;
            uint k = 0;

            while (j < input.Length)
            {
                var temp = input[j++];
                if (temp != 0)
                {
                    data[k] = temp;
                    k++;
                }
                else
                {
                    int length = input[j++];
                    for (var t = 0; t < length; t++)
                    {
                        if (k == size) break;
                        data[k] = 0;
                        k++;
                    }
                }
            }

            return data;
        }
    }

    public class MapObject
    {
        public MapObject(Point position)
        {
            Position = position;
        }

        public Point Position { get; }

        public byte Class { get; set; }
        public byte State { get; set; }
        public byte Field_F2 { get; set; }
        public byte Frame { get; set; }
        public byte OwnerPlayer { get; set; }
        public byte Sex { get; set; }
        public bool IsFleeing { get; set; }
        public byte GenPeriod { get; set; }
        public bool IsGoing { get; set; }
    }

    public class MapTile
    {
        public MapTile(Point position)
        {
            Position = position;
        }

        public Point Position { get; }

        public byte Texture { get; set; }
        public byte Road { get; set; }
        public byte Player { get; set; }
        public int Mask1 { get; set; }
        public byte Unk1 { get; set; }
        public int Mask2 { get; set; }
    }
}