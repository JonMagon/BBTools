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

        public List<MapTile> Tiles { get; private set; } = new List<MapTile>();
        public List<MapObject> Objects { get; private set; } = new List<MapObject>();

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
                    int size = binr.ReadInt32();
                    byte[] data = unRLE0(binr.ReadBytes(size), Size.Y * 0xC);

                    for (int y = 0; y < Size.Y; y++)
                    {
                        int ptr = y * 12;

                        MapTile tile = new MapTile(new Point(y, x));
                        tile.Texture = data[ptr + 0];
                        tile.Road = data[ptr + 1];
                        tile.Player = data[ptr + 2];
                        tile.Mask1 = BitConverter.ToInt32(data, ptr + 3);
                        tile.Unk1 = data[ptr + 7];
                        tile.Mask2 = BitConverter.ToInt32(data, ptr + 8);

                        Tiles.Add(tile);
                    }
                }

                // objects

                int ptr_to_some_global_arr = binr.ReadInt32(),
                    ptr_to_smth2_arr = binr.ReadInt32(),
                    sizeof_smth2_arr = binr.ReadInt32();

                for (int i = 0; i < sizeof_smth2_arr; i++)
                {
                    if (binr.ReadByte() != 0)
                    {
                        int size = binr.ReadInt32();
                        byte[] data = unRLE0(binr.ReadBytes(size), 0x13A);
                        if (BitConverter.ToInt32(data, 236) != 0)
                        {
                            Array.Copy(binr.ReadBytes(data[0xF0]), 0, data, 236, data[0xF0]);
                        }

                        if (data[212] == 98)
                        {
                            Array.Copy(binr.ReadBytes(32), 0, data, 0x3C, 32);
                        }

                        if (BitConverter.ToInt32(data, 56) != 0)
                        {
                            Array.Copy(binr.ReadBytes(2), 0, data, 0x38, 2);
                        }

                        byte[] indexbytes = BitConverter.GetBytes(i);
                        Array.Copy(indexbytes, 0, data, 142, 4);

                        MapObject map_object = new MapObject(new Point(data[0xD8], data[0xD9]));
                        map_object.Class = data[0xD4];
                        map_object.Frame = data[0xEA];
                        Objects.Add(map_object);

                        //Console.WriteLine("{0} {1} {2} {3} {4} {5} {6} {7} {8}", data[0xD8], data[0xD9], data[0xEC], data[0xD4], data[0x38], data[0xF2], data[0xA0], data[0xA1], data[0xF2]);

                        if (data[0xD4] == 2)
                            Console.WriteLine("{0} {1}", BitConverter.ToInt32(data, 0x120), BitConverter.ToInt32(data, 0x124));

                        /*if (data[0xD4] == 103)
                        {
                            foreach (byte b in data) Console.Write("{0:X2} ", b);
                            Console.WriteLine();
                        }*/

                        //if (data[0xD8] == 89 && data[0xD9] == 64)
                        //    File.WriteAllBytes("villager4.bin", data);
                    }
                }
            }
        }

        static byte[] unRLE0(byte[] input, int size)
        {
            byte[] data = new byte[size];
            byte temp;
            uint j = 0;
            uint k = 0;

            while (j < input.Length)
            {
                temp = input[j++];
                if (temp != 0)
                {
                    data[k] = temp;
                    k++;
                }
                else
                {
                    int length = input[j++];
                    for (int t = 0; t < length; t++)
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
        public Point Position { get; private set; }

        public byte Class { get; set; }
        public byte Frame { get; set; }

        public MapObject(Point position)
        {
            this.Position = position;
        }
    }

    public class MapTile
    {
        public Point Position { get; private set; }

        public byte Texture { get; set; }
        public byte Road { get; set; }
        public byte Player { get; set; }
        public int Mask1 { get; set; }
        public byte Unk1 { get; set; }
        public int Mask2 { get; set; }


        public MapTile(Point position)
        {
            this.Position = position;
        }
    }
}
