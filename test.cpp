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
		REQUIRE( db.get_vec_size() == 200);
		entry ele1("Dummy","Data","Element");
		db + ele1;
		std::cout << db[200] << std::endl;

		db - ele1;

		std::cout << db[199] << std::endl;
    }
}

