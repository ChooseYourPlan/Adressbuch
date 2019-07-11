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

	entry(const std::string& fname_,const std::string& nname_,const std::string& phone_);
	friend std::ostream& operator<<(std::ostream& stream,const entry& k_ausg);
};
