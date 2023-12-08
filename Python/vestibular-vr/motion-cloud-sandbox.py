import MotionClouds as mc
import numpy as np

# define Fourier domain
fx, fy, ft = mc.get_grids(mc.N_X, mc.N_Y, mc.N_frame * 2)
# define an envelope
envelope = mc.envelope_gabor(fx, fy, ft,
    V_X=1., V_Y=0., B_V=.1,
    sf_0=.15, B_sf=.1,
    theta=0., B_theta=np.pi/8, alpha=1.)

movie = mc.random_cloud(envelope)
movie = mc.rectif(movie)

mc.anim_save(movie, 'test-movie/test-movie', display=False, verbose=True, vext='.mp4')
