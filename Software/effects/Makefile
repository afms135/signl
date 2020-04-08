#C++ Sources
SRCS := $(wildcard *.cpp)
SRCS += FFTConvolver/Utilities.cpp FFTConvolver/AudioFFT.cpp FFTConvolver/FFTConvolver.cpp FFTConvolver/TwoStageFFTConvolver.cpp
OBJS = $(SRCS:%.cpp=%.so)

#C++ compiler options
CXXFLAGS += -O3 -std=c++14
CXXFLAGS += -Wall -Wextra -Wpedantic -Wno-unused-parameter
CXXFLAGS += -fPIC -shared -lm

.PHONY: all clean

all: $(OBJS)

%.so: %.cpp effect.h
	@echo '[C++] $@'
	@$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJS)
