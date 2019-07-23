#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include "TextTable.h"
#include "entry.h"
#include "database.h"

database::database(std::string _filename) : filename(_filename) {
		this->lines = 0;
}

void database::read() {
		infile.open(filename.c_str(), std::ifstream::in);

		if(!infile.is_open())
				return;
		if (infile.peek() == std::ifstream::traits_type::eof())
				return;
		lines = get_line_count();

		std::string buffer;
		getline(infile, buffer, ';');

		for (unsigned int i = 0; i < lines; i++) {
				entry pb;

				getline(infile, buffer, ';');
				pb.num = std::stoi(buffer);

				getline(infile, buffer, ';');
				pb.fname = buffer;

				getline(infile, buffer, ';');
				pb.nname = buffer;

				getline(infile, buffer, ';');
				buffer.pop_back();
				pb.phone = buffer;

				entrys.push_back(pb);
		}
}

entry& database::operator[](unsigned int index) {
        return get_ele(index);
}

std::string database::get_last_line() {
		std::ifstream counter;
		counter.open(filename.c_str(), std::ifstream::in);

		counter.seekg(-2, std::ios_base::end); //-1 war der Bug

		for (unsigned int i = counter.tellg(); i > 0; i--) {
				if (counter.peek() == '\n') {
						counter.get();
						break;
				}
				counter.seekg(i, std::ios_base::beg);
		}

		std::string lastline;
		getline(counter, lastline);
		return lastline;
}

int database::get_line_count() {
		std::stringstream lline(get_last_line());
		std::string buffer;
		getline(lline, buffer, ';');
		getline(lline, buffer, ';');
		return std::stoi(buffer);
}

void database::operator+(entry & obj) {
		this->insert(obj);
}

void database::print() {
		TextTable t('-', '|', '+');
				
				t.add("Nummer");
				t.add("Vorname");
				t.add("Nachname");
				t.add("Telfonnummer");
				t.endOfRow();

		for (std::vector<entry>::iterator it = entrys.begin(); it != entrys.end(); ++it)
		{
				t.add(std::to_string(it->num));
						t.add(it->fname);
						t.add(it->nname);
						t.add(it->phone);
						t.endOfRow();
		}
		t.setAlignment(1, TextTable::Alignment::LEFT);
				std::cout << t;
}

void database::insert(entry& ele) {
		lines++;
		ele.num = lines;

		entrys.push_back(ele);
}

template< class T>
void database::operator-(T& obj) {
       del_entry(obj);
}


void database::del_entry(int index) {
		lines--;
		entrys.erase(entrys.begin()+index);
}

void database::del_entry(entry& obj) {
		lines--;
		entrys.erase(std::remove(entrys.begin(), entrys.end(), obj), entrys.end());
}

std::vector<entry> database::search(const std::string& sstring) {
		std::vector<entry> rv;
		for (std::vector<entry>::iterator it = entrys.begin(); it < entrys.end() - 1; ++it) {
				if (it->fname == sstring || it->nname == sstring || it->phone == sstring) 
						rv.push_back(*it);
		}
			return rv;
}

void database::write() {
		outfile.open(filename.c_str());

		for (std::vector<entry>::iterator it = entrys.begin(); it < entrys.end()-1; ++it) {
				int index = std::distance(entrys.begin(), it);
						it->num = index+1;
						
						outfile << ';' << it->num << ';' << it->fname << ';' << it->nname << ';' << it->phone << '\n';
						
						if (it + 2 == entrys.end()) {
								++it;
								int index = std::distance(entrys.begin(), it);
								it->num = index + 1;
								outfile << ';' << it->num << ';' << it->fname << ';' << it->nname << ';' << it->phone << ' ';
						}
		}
}

void database::change(int index,const entry& ch) {
	entrys[index] = ch;	
}

int database::get_vec_size() {
   return entrys.size();
}

entry& database::get_ele(int index) { 
   return entrys[index];
}

template void database::operator-<entry>(entry&);
template void database::operator-<int>(int&);
