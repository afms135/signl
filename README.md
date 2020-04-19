<p align="center">
  <img src="https://raw.githubusercontent.com/afms135/signl/master/Media/Photo.jpg" width=50%>
</p>

# signl - An Open Source Real-Time Audio Effects Processor running on Raspberry Pi

[![Build Status](https://travis-ci.org/afms135/signl.svg?branch=master)](https://travis-ci.org/afms135/signl)

*signl* is an audio effects processor developed to provide an open-source (modifiable and extendable), real-time (no noticable playing latency), low-cost (Raspberry Pi based) standalone unit for musicians. Development started at the University of Glasgow for ENG5220: Real Time Embedded Programming 2019-2020.

The main features are:

* Mic or Line level in
* Line and Headphone out
* Up to five serial audio effects
* Real time parameter control of each effect
* Easy to understand GUI
* Half rack size

## Video Walkthrough

[![Walkthrough](https://github.com/afms135/signl/blob/master/Media/walthrough_icon.jpg)](https://youtu.be/WcyoIrp74zg)

## Documentation

See our [Github wiki](https://github.com/afms135/signl/wiki) for detailed instructions on how to reproduce the system, as well as information about the design of the system. Detailed software documentation can be found in the [Doxygen documentation](https://afms135.github.io/signl/).

## Social Media

- [Twitter](https://twitter.com/signlHW)
- [Youtube](https://www.youtube.com/channel/UChTp4nFLsnpuzNy29fdVIeA)

## Authors and Individual Contributions

- Alexander Strachan (afms135, 2173868s) - Software Architect:  wrote hardware/JACK interface code, effect plugin system and two effects (amplifier, overdrive).
- Robert Norris (robnorr, 2198915n) - Software: Wrote GUI code (including tuner), five effects (EQ, Noise Gate, Reverb, Saturation, Vinyl), performed tests and generated data for the wiki. Contributed to the social media promotion.
- Simon Ridley (ithinkitssimon, 2187742r) - Hardware: Designed electronics and mechanical aspects of project, wrote tremolo plugin, documented relevant aspects and contributed to social media of project.

## COVID-19

The project hardware was completed before the 15th of March, so this did not prevent completion of the project, however the full project enclosure could not be manufactured. The designs for this enclosure have been included.
