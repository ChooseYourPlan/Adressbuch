# Files
SOURCES += test.cpp entry.cpp database.cpp
HEADERS += catch.hpp entry.h database.h TextTable.h

# C++14
CONFIG += c++18
QMAKE_CXX = g++-8
QMAKE_LINK = g++-8
QMAKE_CC = gcc-8
QMAKE_CXXFLAGS += -std=c++18

# Compile with high warning levels, a warning is an error
QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Weffc++ -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
