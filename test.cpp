#define CATCH_CONFIG_ENABLE_BENCHMARKING
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "entry.h"
#include "database.h"

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

		db + ele1;

    }

    SECTION("CHANGE") {
		entry ele1("Dummy", "Data", "Element");
		entry buffer = db.get_ele(100);
		REQUIRE(db.get_ele(100) == buffer);
		db.change(100, ele1);
		REQUIRE(db.get_ele(100) == ele1);
		REQUIRE_FALSE(db.get_ele(100) == buffer);
    }

    SECTION("BM") {
		entry ele1("Dummy","Data", "Element");
		BENCHMARK("INSERT") {
				return db + ele1;
		};
		BENCHMARK("DELETE") {
				return db - (db.get_vec_size()-1);
		};
    }
}
