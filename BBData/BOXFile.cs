using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace BBData
{
    public class BOXFile
    {
        /// <summary>
        ///     Open BOX archive.
        /// </summary>
        /// <param name="filename">Path to BOX file.</param>
        public BOXFile(string filename)
        {
            using (var binr = new BinaryReader(File.OpenRead(filename), Encoding.ASCII))
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
                            size = binr.ReadInt32(),
                            binr.ReadBytes(size)
                        )
                    );
            }
        }

        public List<Entry> Entries { get; } = new List<Entry>();

        // https://stackoverflow.com/a/1403542
        private string TrimFromZero(string input)
        {
            var index = input.IndexOf('\0');
            if (index < 0)
                return input;

            return input.Substring(0, index);
        }

        public class Entry
        {
            public byte[] Data;
            public string Filename;
            public string Path;
            public int Size;
            public EntryTime Time;

            public Entry(string filename, string path, EntryTime time, int size, byte[] data)
            {
                Filename = filename;
                Path = path;
                Time = time;
                Size = size;
                Data = data;
            }
        }

        public class EntryTime
        {
            public ushort Day;
            public ushort Dayofweek;
            public ushort Hour;
            public ushort Milliseconds;
            public ushort Minute;
            public ushort Month;
            public ushort Second;
            public ushort Year;

            public EntryTime(ushort year, ushort month, ushort dayofweek,
                ushort day, ushort hour, ushort minute, ushort second, ushort milliseconds)
            {
                Year = year;
                Month = month;
                Dayofweek = dayofweek;
                Day = day;
                Hour = hour;
                Minute = minute;
                Second = second;
                Milliseconds = milliseconds;
            }
        }
    }
}