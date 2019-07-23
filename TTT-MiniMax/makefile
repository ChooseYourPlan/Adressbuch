src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
DEPS = catch.hpp

CXXFLAGS = -Wall -Wextra --coverage -std=c++17
LDFLAGS := --coverage -Wall -std=c++17 -Wextra

myprog: $(obj)
		g++ -o TTT test.cpp -O3 -Wno-write-strings $(LDFLAGS)

.PHONY: clean
clean:
		rm -f *.o $@
fullclean:
		rm -f *.o *.gcno *.gcda *.gcov coverage.info myprog
