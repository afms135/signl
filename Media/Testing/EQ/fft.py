import numpy as np
import sys
from scipy.fftpack import fft
from scipy.io import wavfile
from scipy.signal import find_peaks

'''This file is used to create FFTs of the test data created by the EQ plugin'''

#Read in .wav file
fs, data = wavfile.read('./'+sys.argv[1])
#Keep the first three seconds
data = data[:144000]
#Take the fft
freq = np.fft.fft(data)
#convert to dB
freq = 20*np.log10(abs(freq))
#smooth
freq = np.convolve(freq,np.ones(32)/32)
#Generate the x axis
frqLabel = np.fft.rfftfreq(data.size, d=1./fs)

#Write the outputs to a file
f = open(sys.argv[1][:-4]+'_FFT', "w")
#for i in maxima:
for i in range(len(frqLabel)):
    f.write("{} {}\n".format(frqLabel[i], freq[i]))

f.close()
