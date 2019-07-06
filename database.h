#pragma once
#include <vector>

class database final
{
private:
	std::ofstream outfile;
	std::ifstream infile;
	std::vector<entry> entrys;
	size_t lines;
	const std::string filename;
	const size_t max_size = 10000;

public:
	database(std::string _filename);

	void read();
		
    entry& operator[]( unsigned int);

    void operator+(entry& obj);
    
    template < class T >
    void operator-(T& obj);

	std::string get_last_line();

	int get_line_count();

	void print();

	void insert(entry& ele);

	void del_entry(int index);

    void del_entry(entry& obj);

	void write();
 
	void search(std::string sstring);

    void change(int index, entry ch);

	int get_vec_size();

    entry& get_ele(int index);
};
