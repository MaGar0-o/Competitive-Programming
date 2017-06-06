import numpy as np
import pylab
import mahotas as mh

blood = mh.imread('train-0.jpg')
pylab.imshow(blood)
pylab.gray()
pylab.show()
