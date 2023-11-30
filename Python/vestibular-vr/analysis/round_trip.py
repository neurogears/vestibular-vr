import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as signal

# load raw data
# data_path_1 = 'C:/VestibularVRData/benchmarks/RoundTrip/Data2023_09_21_18_07_32/PhotoDiode1.bin'
# data_path_2 = 'C:/VestibularVRData/benchmarks/RoundTrip/Data2023_09_21_18_07_32/PhotoDiode2.bin'
# data_path_1 = 'C:/VestibularVRData/benchmarks/RoundTrip_MatroxOnly/Data2023_11_30_11_40_25/PhotoDiode1.bin'
# data_path_2 = 'C:/VestibularVRData/benchmarks/RoundTrip_MatroxOnly/Data2023_11_30_11_40_25/PhotoDiode2.bin'
data_path_1 = 'C:/VestibularVRData/benchmarks/RoundTrip_MatroxOnly/Data2023_11_30_12_29_42/PhotoDiode1.bin'
data_path_2 = 'C:/VestibularVRData/benchmarks/RoundTrip_MatroxOnly/Data2023_11_30_12_29_42/PhotoDiode2.bin'
fs = 100000.0
window = 7000000

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
pd1_peaks, pd1_props = signal.find_peaks(photo_diode_1, prominence=1, width=1000)
pd2_peaks, pd2_props = signal.find_peaks(photo_diode_2, prominence=1, width=1000)

pd1_peaks = pd1_props['left_bases']
pd2_peaks = pd2_props['left_bases']

pd1_diffs = np.diff(pd1_peaks) / fs
pd2_diffs = np.diff(pd2_peaks) / fs

plt.figure()
plt.plot(photo_diode_1, 'b')
plt.plot(pd1_peaks, (photo_diode_1[pd1_peaks]*0)+1, 'bx')
plt.plot(photo_diode_2, 'r')
plt.plot(pd2_peaks, (photo_diode_2[pd2_peaks]*0)+1, 'rx')

plt.figure()
plt.hist(pd2_diffs / 2)
plt.xlabel('round trip time (s)')
plt.ylabel('frequency')
plt.title('mean={mean:.5f}, sd={sd:.5f}'.format(mean=np.mean(pd2_diffs / 2), sd=np.std(pd2_diffs / 2)))

plt.show()
