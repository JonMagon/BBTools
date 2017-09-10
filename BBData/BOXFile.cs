using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace BBData
{
    public class BOXFile
    {
        public List<Entry> Entries { get; private set; }

        // https://stackoverflow.com/a/1403542
        private string TrimFromZero(string input)
        {
            int index = input.IndexOf('\0');
            if (index < 0)
                return input;

            return input.Substring(0, index);
        }

        public BOXFile() { Entries = new List<Entry>(); }

        public BOXFile(string filename) : this()
        {
            using (BinaryReader binr = new BinaryReader(File.OpenRead(filename), Encoding.ASCII))
            {
                if (!binr.ReadChars(3).SequenceEqual("BOX"))
                    throw new Exception("Resource archive is corrupted. Bad signature.");

                binr.BaseStream.Seek(5, SeekOrigin.Current);

                int size;
                while (binr.PeekChar() != -1)
                    Entries.Add(
                        new Entry(
                            TrimFromZero(new string(binr.ReadChars(256))).ToLower(),
                            TrimFromZero(new string(binr.ReadChars(256))),
                            new EntryTime(
                                binr.ReadUInt16(),
                                binr.ReadUInt16(),
                                binr.ReadUInt16(),
                                binr.ReadUInt16(),
                                binr.ReadUInt16(),
                                binr.ReadUInt16(),
                                binr.ReadUInt16(),
                                binr.ReadUInt16()
                                ),
                            (size = binr.ReadInt32()),
                            binr.ReadBytes(size)
                            )
                        );
            }
        }

        public class Entry
        {
            public string filename;
            public string path;
            public EntryTime time;
            public int size;
            public byte[] data;

            public Entry(string filename, string path, EntryTime time, int size, byte[] data)
            {
                this.filename = filename;
                this.path = path;
                this.time = time;
                this.size = size;
                this.data = data;
            }
        }

        public class EntryTime
        {
            public ushort year;
            public ushort month;
            public ushort dayofweek;
            public ushort day;
            public ushort hour;
            public ushort minute;
            public ushort second;
            public ushort milliseconds;

            public EntryTime(ushort year, ushort month, ushort dayofweek,
                ushort day, ushort hour, ushort minute, ushort second, ushort milliseconds)
            {
                this.year = year;
                this.month = month;
                this.dayofweek = dayofweek;
                this.day = day;
                this.hour = hour;
                this.minute = minute;
                this.second = second;
                this.milliseconds = milliseconds;
            }
        }
    }
}
