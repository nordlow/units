# a very simple makefile to compile the examples of lego::units

CXX=g++
COMPILE=$(CXX) -std=gnu++1y -g -g3

all: lego_units.out boost_units.out test_rationals.out test_units.out

clean:
	rm -rf *.out

%.out: %.cpp *.hpp Makefile
	$(COMPILE) -o $@ $<
