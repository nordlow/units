# a very simple makefile to compile the examples of lego::units

CXX=g++
COMPILE=$(CXX) -std=c++11

all: boost_units.out lego_units.out test_rationals.out test_units.out

clean:
	rm -rf *.out

%.out: %.cpp
	$(COMPILE) -o $@ $<
