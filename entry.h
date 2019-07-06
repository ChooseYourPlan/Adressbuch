#pragma once
#include <fstream>
#include <string>

class entry
{
public: 
	size_t num;
	std::string fname;
	std::string nname;
	std::string phone;

	entry();

    bool operator==(const entry& other) const;

	entry(std::string fname_, std::string nname_, std::string phone_);
	friend std::ostream& operator<<(std::ostream& stream, entry& k_ausg);
};
