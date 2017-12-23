CXX=g++
RM=rm -f
SRCS=generic_linked_list.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
CPPFLAGS=-Wall -Werror -std=c++11

all: generic_linked_list

generic_linked_list: $(OBJS)
	$(CXX) $(CPPFLAGS) -o generic_linked_list $(OBJS)

clean:
	$(RM) $(OBJS)

distclean:
	$(RM) generic_linked_list
