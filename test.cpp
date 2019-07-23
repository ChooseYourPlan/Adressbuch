#define CATCH_CONFIG_ENABLE_BENCHMARKING
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "entry.h"
#include "database.h"
#include <functional>

TEST_CASE("Database initialisation") {

    database db("sample.txt");
    db.read();

    REQUIRE( db.get_vec_size() == 200);

    SECTION("INSERT") {
        entry ele1("Dummy","Data","Element");
		db.insert(ele1);
		REQUIRE( db.get_vec_size() == 201);
		entry check = db[200];
		REQUIRE(check == ele1);
    }

    SECTION("DELETE") {
		entry ele1("Dummy","Data","Element");
		db + ele1;
		REQUIRE(db.get_vec_size() == 201);
		db - ele1;
		REQUIRE(db.get_vec_size() == 200);
    }

    SECTION("CHANGE") {
		entry ele1("Dummy", "Data", "Element");
		entry buffer = db.get_ele(100);
		REQUIRE(db.get_ele(100) == buffer);
		db.change(100, ele1);
		REQUIRE(db.get_ele(100) == ele1);
		REQUIRE_FALSE(db.get_ele(100) == buffer);
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

TEST_CASE("COUTS/PRINTS") {
		database db("sample.txt");
		db.read();
		SECTION("COUTS") {
				cout_handler(db[100]);
				auto test = [](auto &db) { db.print(); };
				cout_handler(test,db);				

		}
}

TEST_CASE("BENCHMARKS") {

    database db("sample.txt");
    db.read();


    SECTION("INSERT/DELETE/CHANGED") {
		entry ele1("Dummy","Data", "Element");
		BENCHMARK("INSERT") {
				return db + ele1;
		};
		BENCHMARK("DELETE") {
				return  db.del_entry(199);
		};
		BENCHMARK("CHANGED") {
				return db.change(100, ele1);
		};
     }
     SECTION("SEARCH") {
		entry ele1("Dummy","Data","Element");
		db.change(100,ele1);

		BENCHMARK("SEARCH") {
				return db.search(ele1.fname);
		};
    }
}