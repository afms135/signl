#Name of binary
NAME = signl

#C++ Sources
SRCS  = main.cpp signl.cpp jack.cpp effect_manager.cpp
SRCS += gui/gui.cpp
SRCS += hw/gpio.cpp hw/spi.cpp hw/lcd.cpp hw/debounce.cpp hw/adc.cpp

#Include directories
INCS = -I.

#Compiler defines
DEFS =

#Warnings
WARNS = -Wall -Wextra -Wpedantic -Wno-unused-parameter

#C++ compiler options
CPP_OPTS = -O3 -g3 -std=c++14

################################################################################

#Variable expansion
OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)
CPPFLAGS += $(CPP_OPTS) $(WARNS) $(DEFS) $(INCS)

.PHONY: all clean effects

all: $(NAME)

$(NAME): $(OBJS)
	@echo '[LINK] $@'
	@g++ -o $@ $^ `pkg-config --cflags --libs jack` -ldl

%.o: %.cpp
	@echo '[C++ ] $@'
	@g++ $(CPPFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

effects:
	make -C ./effects

clean:
	rm -f $(OBJS) $(DEPS) $(NAME)
