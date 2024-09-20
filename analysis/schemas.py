from dotmap import DotMap
import aeon.schema.core as stream
from aeon.schema.streams import Device
from aeon.schema import foraging, octagon

exp = DotMap([
    Device("SessionSettings", stream.Metadata)
])