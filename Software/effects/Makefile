#C++ Sources
SRCS := $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.so)

#Warnings
WARNS = -Wall -Wextra -Wpedantic -Wno-unused-parameter

#C++ compiler options
CPP_OPTS = -O3 -std=c++14 -fPIC -shared -lm

.PHONY: all clean

all: $(OBJS)

%.so: %.cpp
	@echo '[C++] $@'
	@g++ $(CPP_OPTS) $(WARNS) -c $< -o $@

clean:
	rm -f $(OBJS)
