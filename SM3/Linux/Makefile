Target:= sm3
Target2:= sm3_cc
CC=gcc
CXX=g++
CFLAGS=-g -Wall -std=c99
#CFLAGS=-g -O0 -D_DEBUG -std=c++11
#CFLAGS=-g -Wall -O0 -D_DEBUG -std=c99
CXXFLAGS=-g -Wall -O0 -D_DEBUG -std=c++11
objs=sm3.o sm3test.o
objs2=sm3.oo sm3test.oo

cins=sm3.c sm3test.c

head=sm3.h

all:$(Target) $(Target2)
	@echo " make done!"

$(Target):$(objs)
	$(CC) $(CFLAGS) $^ -o $@
$(Target2):$(objs2)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o:%.c $(head)
	$(CC) $(CFLAGS) -c $< -o $@

%.oo:%.c $(head)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(Target) $(Target2) $(objs) $(objs2)
