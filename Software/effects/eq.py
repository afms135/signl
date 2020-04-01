import numpy as np
import scipy.signal as signal
import matplotlib.pyplot as plt

#Constants
RATE = 48000
POINTS = 10000
ORDER = 1
F1 = 150
F2 = 150
F3 = 300
F4 = 300
F5 = 3000
F6 = 3000

#Create filters
fil = [None, None, None, None]
fil[0] = signal.butter(ORDER*2, F1/RATE*2, btype='low', output='sos')
fil[1] = signal.butter(ORDER, [F2/RATE*2, F3/RATE*2], btype='band', output='sos')
fil[2] = signal.butter(ORDER, [F4/RATE*2, F5/RATE*2], btype='band', output='sos')
fil[3] = signal.butter(ORDER*2, F6/RATE*2, btype='high', output='sos')

#Calculate frequency response
h = []
for i in range(4):
	_, v = signal.sosfreqz(fil[i], worN = POINTS)
	h.append(np.abs(v))

#Ignore divisions by zero in log10
np.seterr(divide = 'ignore')

#Plot response in dB
for i in range(4):
	plt.plot(np.linspace(0, RATE//2, POINTS), 20*np.log10(h[i]))

#Plot summed response
plt.plot(np.linspace(0, RATE//2, POINTS), 20*np.log10(h[0]+h[1]+h[2]+h[3]), '--')

#Log frequency scale
plt.xscale('log')
#Set dB limit
plt.ylim(-20, 10)
#Display plot
plt.show()

#Print coefficients
print(fil[0])
print(fil[1])
print(fil[2])
print(fil[3])
