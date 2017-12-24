CXX=g++
RM=rm -f
SRCS=generic_linked_list.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
CPPFLAGS=-Wall -Werror -std=c++11

all: generic_linked_list memory_efficient_dbl

generic_linked_list: generic_linked_list.cpp
	$(CXX) $(CPPFLAGS) -o generic_linked_list generic_linked_list.cpp

memory_efficient_dbl: memory_efficient_dbl.cpp
	$(CXX) $(CPPFLAGS) -o memory_efficient_dbl memory_efficient_dbl.cpp



clean:
	$(RM) $(OBJS)

distclean:
	$(RM) generic_linked_list
