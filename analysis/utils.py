import harp
import pandas as pd
from glob import glob
from pathlib import Path
import os
import json
from dotmap import DotMap
from aeon.io.reader import Reader, Csv, Harp
import aeon.io.api as api
import numpy as np


class SessionData(Reader):
    """Extracts metadata information from a settings .jsonl file."""

    def __init__(self, pattern):
        super().__init__(pattern, columns=["metadata"], extension="jsonl")

    def read(self, file):
        """Returns metadata for the specified epoch."""
        with open(file) as fp:
            metadata = [json.loads(line) for line in fp] 

        data = {
            "metadata": [DotMap(entry['value']) for entry in metadata]
        }
        timestamps = [api.aeon(entry['seconds']) for entry in metadata]

        return pd.DataFrame(data, index=timestamps, columns=self.columns)
    

class TimestampedCsvReader(Csv):
    def __init__(self, pattern, columns):
        super().__init__(pattern, columns, extension="csv")
        self._rawcolumns = ["Time"] + columns

    def read(self, file):
        data = pd.read_csv(file, header=0, names=self._rawcolumns)
        data["Seconds"] = data["Time"]
        data["Time"] = data["Time"].transform(lambda x: api.aeon(x))
        data.set_index("Time", inplace=True)
        return data
    

class PhotometryReader(Csv):
    def __init__(self, pattern):
        super().__init__(pattern, columns=["Time", "Events", "CH1-410", "CH1-470", "CH1-560", "U"], extension="csv")
        self._rawcolumns = self.columns

    def read(self, file):
        data = pd.read_csv(file, header=1, names=self._rawcolumns)
        data.set_index("Time", inplace=True)
        return data
    

class Video(Csv):
    def __init__(self, pattern):
        super().__init__(pattern, columns = ["HardwareCounter", "HardwareTimestamp", "FrameIndex", "Path", "Epoch"], extension="csv")
        self._rawcolumns = ["Time"] + self.columns[0:2]

    def read(self, file):
        data = pd.read_csv(file, header=0, names=self._rawcolumns)
        data["FrameIndex"] = data.index
        data["Path"] = os.path.splitext(file)[0] + ".avi"
        data["Epoch"] = file.parts[-3]
        data["Time"] = data["Time"].transform(lambda x: api.aeon(x))
        data.set_index("Time", inplace=True)
        return data
    

def load(reader: Reader, root: Path) -> pd.DataFrame:
    root = Path(root)
    pattern = f"{root.joinpath(reader.pattern).joinpath(reader.pattern)}_*.{reader.extension}"
    data = [reader.read(Path(file)) for file in glob(pattern)]
    return pd.concat(data)

def load_json(reader: SessionData, root: Path) -> pd.DataFrame:
    root = Path(root)
    pattern = f"{root.joinpath(reader.pattern).joinpath(reader.pattern)}_*.{reader.extension}"
    data = [reader.read(Path(file)) for file in glob(pattern)]
    return pd.concat(data)

def load_csv(reader: Csv, root: Path) -> pd.DataFrame:
    root = Path(root)
    pattern = f"{root.joinpath(reader.pattern).joinpath(reader.pattern)}_*.{reader.extension}"
    data = pd.concat([reader.read(Path(file)) for file in glob(pattern)])
    return data

def load_harp(reader: Harp, root: Path) -> pd.DataFrame:
    root = Path(root)
    pattern = f"{root.joinpath(root.name)}_{reader.register.address}_*.bin"
    data = [reader.read(file) for file in glob(pattern)]
    return pd.concat(data)

def load_photometry(reader: PhotometryReader, root: Path) -> pd.DataFrame:
    root = Path(root)
    pattern = f"{root.joinpath(reader.pattern)}.{reader.extension}"
    data = [reader.read(Path(file)) for file in glob(pattern)]
    return data

def read_onix_analog_data(root: Path, pattern: str, dtype: np.dtype):
    root = Path(root)
    search_pattern = f"{root.joinpath(pattern).joinpath(pattern)}_*.bin"
    data = [np.reshape(np.fromfile(file, dtype=dtype), (-1, 12)) for file in glob(search_pattern)]
    return np.concatenate(data, axis=0)

def read_onix_analog_clock(root: Path, pattern: str, dtype: np.dtype):
    root = Path(root)
    search_pattern = f"{root.joinpath(pattern).joinpath(pattern)}_*.bin"
    data = [np.fromfile(file, dtype=dtype) for file in glob(search_pattern)]
    return np.concatenate(data, axis=0)
