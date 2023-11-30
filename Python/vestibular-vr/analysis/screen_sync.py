import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as signal

# load raw data
# data_path_1 = 'C:/VestibularVRData/benchmarks/ScreenSync/Data2023_09_20_17_23_49/PhotoDiode1.bin'
# data_path_2 = 'C:/VestibularVRData/benchmarks/ScreenSync/Data2023_09_20_17_23_49/PhotoDiode2.bin'
# data_path_1 = 'C:/VestibularVRData/benchmarks/ScreenSync_MatroxOnly/Data2023_11_30_11_43_44/PhotoDiode1.bin'
# data_path_2 = 'C:/VestibularVRData/benchmarks/ScreenSync_MatroxOnly/Data2023_11_30_11_43_44/PhotoDiode2.bin'
data_path_1 = 'C:/VestibularVRData/benchmarks/ScreenSync_MatroxOnly/Data2023_11_30_12_33_27/PhotoDiode1.bin'
data_path_2 = 'C:/VestibularVRData/benchmarks/ScreenSync_MatroxOnly/Data2023_11_30_12_33_27/PhotoDiode2.bin'
fs = 100000.0
window = 90000000

with open(data_path_1, 'rb') as f:
    photo_diode_1 = np.fromfile(f, dtype=np.int16).astype(np.single)[0:window]

with open(data_path_2, 'rb') as f:
    photo_diode_2 = np.fromfile(f, dtype=np.int16).astype(np.single)[0:window]

# binarise signal
pd1_thresh = np.mean(photo_diode_1[np.where(photo_diode_1 < 200)]) \
             + np.std(photo_diode_1[np.where(photo_diode_1 < 200)])
pd2_thresh = np.mean(photo_diode_2[np.where(photo_diode_2 < 200)]) \
             + np.std(photo_diode_2[np.where(photo_diode_2 < 200)])

photo_diode_1[np.where(photo_diode_1 <= pd1_thresh)] = 0
photo_diode_1[np.where(photo_diode_1 > pd1_thresh)] = 1
photo_diode_2[np.where(photo_diode_2 <= pd2_thresh)] = 0
photo_diode_2[np.where(photo_diode_2 > pd2_thresh)] = 1

# get peaks
pd1_peaks, pd1_props = signal.find_peaks(photo_diode_1, prominence=1, width=20000)
pd2_peaks, pd2_props = signal.find_peaks(photo_diode_2, prominence=1, width=20000)

t_offsets = (pd2_peaks - pd1_peaks) / fs

plt.figure()
plt.plot(photo_diode_1, 'b')
plt.plot(pd1_props['left_bases'], photo_diode_1[pd1_peaks], 'bx')
plt.plot(photo_diode_2, 'r')
plt.plot(pd2_props['left_bases'], photo_diode_2[pd2_peaks], 'rx')

plt.figure()
plt.hist(t_offsets)
plt.xlabel('sync offset (s)')
plt.ylabel('frequency')
plt.title('mean={mean:.5f}, sd={sd:.5f}'.format(mean=np.mean(t_offsets), sd=np.std(t_offsets)))

plt.show()
