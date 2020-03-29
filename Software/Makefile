#Name of binary
NAME = signl

#C++ Sources
SRCS  = main.cpp signl.cpp gui.cpp jack.cpp effect_manager.cpp
SRCS += assets/font.cpp assets/sprites.cpp
SRCS += hw/gpio.cpp hw/spi.cpp hw/lcd.cpp hw/debounce.cpp hw/adc.cpp

#Include path directories
INCS =

#Compiler defines
DEFS =

#Warnings
WARNS = -Wall -Wextra -Wpedantic -Wno-unused-parameter

#C++ compiler options
CXX_OPTS = -MMD -MP -O3 -g3 -std=c++11

#Linker flags
LDFLAGS =

#Libaries (JACK, dynamic loader)
LDLIBS = `pkg-config --cflags --libs jack` -ldl

################################################################################

#Variable expansion
OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)
CXXFLAGS += $(CXX_OPTS) $(WARNS) $(DEFS) $(INCS)

.PHONY: all clean effects

all: $(NAME) effects

$(NAME): $(OBJS)
	@echo '[LINK] $@'
	@$(CXX) $(LDFLAGS) $^ -o $@ $(LDLIBS)

%.o: %.cpp
	@echo '[C++] $@'
	@$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

effects:
	@$(MAKE) --no-print-directory -C ./effects

clean:
	$(RM) $(OBJS) $(DEPS) $(NAME)
	@$(MAKE) --no-print-directory -C ./effects clean
