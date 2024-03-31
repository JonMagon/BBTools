import argparse
import os
from dataclasses import dataclass
import struct
from prettytable import PrettyTable
import time
from datetime import datetime
import glob

@dataclass
class EntryTime:
    year: int
    month: int
    dayofweek: int
    day: int
    hour: int
    minute: int
    second: int
    milliseconds: int

class BoxFile:
    def __init__(self, filename):
        self.entries = []
        self.filename = filename
        if os.path.exists(self.filename):
            self.read_file()

    def trim_from_zero(self, input_str):
        zero_index = input_str.find('\0')
        return input_str[:zero_index] if zero_index != -1 else input_str

    def read_file(self):
        with open(self.filename, 'rb') as f:
            if f.read(3) != b'BOX':
                raise ValueError("Resource archive is corrupted. Bad signature.")
            f.seek(5, 1)  # Skip 5 bytes
            while True:
                try:
                    name = self.trim_from_zero(f.read(256).decode('latin-1'))
                    path = self.trim_from_zero(f.read(256).decode('latin-1'))
                    time_data = struct.unpack('8H', f.read(16))
                    time = EntryTime(*time_data)
                    size = struct.unpack('i', f.read(4))[0]
                    data = f.read(size)
                    self.entries.append({'filename': name, 'path': path, 'time': time, 'data': data})
                except struct.error:
                    # Reached the end of the file
                    break

    def extract_files(self, output_dir):
        if not os.path.exists(output_dir):
            os.makedirs(output_dir, exist_ok=True)

        for entry in self.entries:
            file_path = os.path.join(output_dir, entry['filename'])
            with open(file_path, 'wb') as f:
                f.write(entry['data'])

            entry_time = entry['time']
            dt = datetime(entry_time.year, entry_time.month, entry_time.day,
                        entry_time.hour, entry_time.minute, entry_time.second)

            epoch_time = time.mktime(dt.timetuple())

            os.utime(file_path, (epoch_time, epoch_time))

        print(f"Extracted {len(self.entries)} files to {output_dir}")

    def archive_files_from_directory(self, directory):
        for root, _, files in os.walk(directory):
            for name in files:
                filepath = os.path.join(root, name)
                absolute_path = os.path.abspath(filepath)
                modification_time = os.path.getmtime(filepath)
                local_time = datetime.fromtimestamp(modification_time)
                time_tuple = local_time.timetuple()
                time_data = EntryTime(year=time_tuple.tm_year, month=time_tuple.tm_mon, dayofweek=time_tuple.tm_wday,
                                    day=time_tuple.tm_mday, hour=time_tuple.tm_hour, minute=time_tuple.tm_min,
                                    second=time_tuple.tm_sec, milliseconds=0)
                with open(filepath, 'rb') as f:
                    data = f.read()

                self.entries = [entry for entry in self.entries if entry['filename'] != name]

                self.entries.append({'filename': name, 'path': absolute_path, 'time': time_data, 'data': data})

    def save_to_file(self):
        with open(self.filename, 'wb') as f:
            f.write(b'BOX')
            f.write(b'\0\0\0\0\0')
            for entry in self.entries:
                time_data = entry['time']
                f.write(struct.pack('256s256s8Hi', entry['filename'].encode('latin-1'), entry['path'].encode('latin-1'),
                                    time_data.year, time_data.month, time_data.dayofweek, time_data.day,
                                    time_data.hour, time_data.minute, time_data.second, time_data.milliseconds,
                                    len(entry['data'])))
                f.write(entry['data'])

    def list_files(self):
        table = PrettyTable(field_names=["Filename", "Path", "Size", "Date"])
        for entry in self.entries:
            time = entry['time']
            formatted_time = f"{time.year:04}-{time.month:02}-{time.day:02} {time.hour:02}:{time.minute:02}:{time.second:02}"
            table.add_row([entry['filename'], entry['path'], len(entry['data']), formatted_time])
        print(table)

def main():
    parser = argparse.ArgumentParser(description="Manipulate BOX archive.")
    parser.add_argument("boxfile", help="Path to the BOX file.")
    parser.add_argument("--extract", help="Directory to extract files to.")
    parser.add_argument("--archive", help="Directory from which files are added to the BOX file.")
    parser.add_argument("--list", action='store_true', help="List all files in the archive.")
    args = parser.parse_args()

    boxfile = BoxFile(args.boxfile)
    if args.archive:
        boxfile.archive_files_from_directory(args.archive)
        boxfile.save_to_file()
    elif args.extract:
        boxfile.extract_files(args.extract)
    elif args.list:
        boxfile.list_files()

if __name__ == "__main__":
    main()
