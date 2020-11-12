# Tracker Schematic v.2 02 November 2020

![](https://i.postimg.cc/FRRG9NV8/Tracker-V1.png)


This design implements the use of a single-chip 2.4 GHz transceiver ([datasheet](https://www.sparkfun.com/datasheets/Components/nRF24L01_prelim_prod_spec_1_2.pdf)) as a solution to the problems introduced by the third-order bandpass filter. 

# Tracker Schematic v.1 28 October 2020


![](https://i.postimg.cc/FRRG9NV8/Tracker-V1.png)

This design implements a passive third-order bandpass filter. The -3dB corner frequencies are at about 2.275GHz and 2.51GHz for a bandwidth of about 0.235GHz. Although the filter does achieve the desired peak at 2.4GHz, the system is extremely sensitive to component value changes. The order of magnitude of the inductor L2 directly alters the value of the Q point. As the order of magnitude of the value of L2 decreases, the Q point increases. At that point, the center frequency becomes unreasonably sensitive to the value for the capacitor, C1. The effect of the capacitor's component value is not within the tolerance of actual components.