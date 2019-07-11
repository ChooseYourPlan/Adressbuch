#include "entry.h"
#include <iostream>
#include <vector>

entry::entry() { }

entry::entry(const std::string& fname_,const std::string& nname_,const std::string& phone_) 
: fname(fname_), nname(nname_), phone(phone_) { }

bool entry::operator==(const entry& other) const {
        return true ? (this->fname == other.fname &&
				       this->nname == other.nname &&
				       this->phone == other.phone) : false;
}

std::ostream& operator<<(std::ostream& stream, entry& ausg) {
		std::cout << ausg.num	<< "  " <<
				     ausg.fname << "  " <<
				     ausg.nname << "  " <<
				     ausg.phone;
		return stream;
}
