#define CATCH_CONFIG_ENABLE_BENCHMARKING
#define CATCH_CONFIG_MAIN

#include "../TextTable.h"
#include "../catch.hpp"
#include "TTT.cpp"
#include <functional>


TEST_CASE("WINS/DRAWS") {
		TTT g1;
		SECTION("CHECK") {
				for(int i = 0; i < 100; i++)
						CHECK(g1.game(false) < 1);
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

TEST_CASE("COUT CHECKS") {
		TTT g1;
		SECTION("DRAW() Function") {
		    auto test = [](auto &g1) { g1.game(true); };
		    cout_handler(test,g1);
		}
}

TEST_CASE("BENCHMARKS") {

		TTT g1;

		SECTION("Benchmark Minimax") {
				BENCHMARK("Game") {
						return g1.game(false);
				};
		}
}
