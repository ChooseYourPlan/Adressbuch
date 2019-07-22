#define CATCH_CONFIG_ENABLE_BENCHMARKING
#define CATCH_CONFIG_MAIN

#include "../TextTable.h"
#include "../catch.hpp"
#include "TTT.cpp"
#include <functional>


TEST_CASE("WINS/DRAWS") {
		feld TTT;
		SECTION("CHECK") {
				for(int i = 0; i < 1000; i++)
						CHECK(TTT.game(false) < 1);
		}
}

TEST_CASE("BENCHMARKS") {

		feld TTT;

		SECTION("Benchmark Minimax") {
				BENCHMARK("Game") {
						return TTT.game(false);
				};
		}
}

template <class T, class ... Param>
void cout_handler(T& func, Param&... param) {		
		std::cout.setstate(std::ios_base::failbit);
		
		if constexpr(sizeof...(param) <= 0) {
		   INFO("LOG:" << func); }
		else if  constexpr(sizeof...(param) > 0) {
		    func(param...); }

		std::cout.clear();
}
