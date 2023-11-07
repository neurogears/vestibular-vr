import numpy as np
import matplotlib.pyplot as plt

# load raw data
data_path_1 = 'C:/VestibularVRData/benchmarks/ScreenSync/Data2023_09_20_17_23_49/PhotoDiode1.bin'
data_path_2 = 'C:/VestibularVRData/benchmarks/ScreenSync/Data2023_09_20_17_23_49/PhotoDiode2.bin'

with open(data_path_1, 'rb') as f:
    photo_diode_1 = np.fromfile(f, dtype=np.uint16)

with open(data_path_2, 'rb') as f:
    photo_diode_2 = np.fromfile(f, dtype=np.uint16)

plt.figure()
plt.plot(photo_diode_1)
plt.plot(photo_diode_2)
plt.show()
