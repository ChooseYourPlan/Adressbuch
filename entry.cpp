#include "entry.h"
#include <iostream>
#include <vector>

entry::entry() { }

entry::entry(const std::string& fname_,const std::string& nname_,const std::string& phone_) {
		this->num = 0;
		this->fname = fname_;
		this->nname = nname_;
		this->phone = phone_;
}

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
