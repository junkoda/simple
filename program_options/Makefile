#
# Boost Program Options
#

EXEC      = options
DIRS      = /opt/local

all: $(EXEC)

INCLDIRS  = $(foreach dir, $(DIRS), -I$(dir)/include)
LIBDIRS   = $(foreach dir, $(DIRS), -L$(dir)/lib) 
CXXFLAGS := $(INCLDIRS)

OBJS1 = options.o
LIBS1 = $(LIBDIRS) -lboost_program_options

options: $(OBJS1)
	$(CXX) $(OBJS1) $(LIBS1) -o $@

.PHONY: clean
clean :
	rm -f $(EXEC) $(OBJS1)
