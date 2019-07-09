src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
DEPS = catch.hpp

CXXFLAGS = -Wall -Wextra --coverage 
LDFLAGS := --coverage

myprog: $(obj)
		g++ -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
		rm -f *.o $@
fullclean:
		rm -f *.o *.gcno *.gcda *.gcov coverage.info myprog
