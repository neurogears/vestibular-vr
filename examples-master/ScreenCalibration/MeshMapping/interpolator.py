# -*- coding: utf-8 -*-
"""
Created on Sun Aug  1 22:03:35 2021

@author: gonca
"""

import numpy as np
import matplotlib.pyplot as plt

##fname = 'C:/Users/edward.horrocks/PycharmProjects/AllenSDK/venv/MeshMap3dMatrix_1800.bin'
#fname = 'X:\ibn-vision\CODE\DEV\MeshMapping_3Dver\MeshMappingFiles\MeshMapping_matlabBin_211122_v6.bin'
##fname = 'X:/ibn-vision/CODE/DEV/MeshMapping_3Dver/MeshMappingFiles/MeshMap3dMatrix.bin'
##fname = 'X:\ibn-vision\CODE\DEV\MeshMapping_3Dver\MeshMappingFiles\MeshMap3dMatrix_211122.bin'
##fname = 'X:\ibn-vision\CODE\DEV\MeshMapping_3Dver\MeshMappingFiles\Tron_matlabOut_v3_120623.bin'

fname = 'X:\ibn-vision\CODE\DEV\BONSAI\Edd\Bonsai-0802\MeshMappingFiles\Tron_MeshMapping3D_MatlabOutput.bin'

data = np.fromfile(fname, dtype='float')
size = int(np.sqrt(len(data) // 3))
data = data.reshape((3,size,size)).T

export = data.reshape(-1)
export.astype('float32').tofile('Tron_MeshMap_py_hres.bin')

##export = np.ones(export.shape) * 255
##export.astype('uint8').tofile('meshmap_py_110821_8.bin')
