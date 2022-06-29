#include "record.h"

#include <fstream>


// default (1)
Record::Record() : std::string() {
	fields = nullptr;
	length = max = 0;
}
// copy (2)
Record::Record(const std::string& str) : std::string(str) {
	fields = nullptr;
	length = max = 0;
}
Record::Record(const std::string& str, size_t pos, size_t len) : std::string(str, pos, len)
{
	fields = nullptr;
	length = max = 0;
}
// substring (3)

// from c-string (4)
Record::Record(const char* s) : std::string(s) {
	fields = nullptr;
	length = max = 0;
}
// from sequence (5)
Record::Record(const char* s, size_t n) : std::string(s, n) {
	fields = nullptr;
	length = max = 0;
}
// fill (6)
Record::Record(size_t n, char c) : std::string(n, c) {
	fields = nullptr;
	length = max = 0;
}


Record::~Record()
{
	if (fields != nullptr) {
		delete[] fields;
		fields = nullptr;
	}
}


Record* Record::split(char delimeter)
{
	
	Record str = *this;

	max = 1;
	length = 0;
  fields = new Record[max];
	int endIndex = str.find(delimeter);

	while (endIndex != std::string::npos) {
		Record* tmp = new Record[++max];

		for (int i = 0; i < length; i++) {
			tmp[i] = fields[i];
		}
		delete[] fields;
		fields = tmp;
		fields[length++] = str.substr(0, endIndex);
		endIndex = endIndex + 1;
		str.erase(0, endIndex);
		endIndex = str.find(delimeter);

	}
	fields[length++] = str;

	return fields;
}





Record& Record::upper() {

	for (int i = 0; i < this->size(); i++)
		this->at(i) = toupper(this->at(i));
	return *this;

}


Record& Record::lower() {

	for (int i = 0; i < this->size(); i++)
		this->at(i) = tolower(this->at(i));
	return *this;

}



std::istream& operator>>(std::istream& iss, Record& record)
{
	if(iss.peek() == '\n' ){
		iss.ignore(1);
	}
	std::getline(iss, record);

	return iss;
}

std::ifstream& operator>>(std::ifstream& ifs, Record& record)
{
	if (ifs.peek() == '\n') {
		ifs.ignore(1);
	}
	std::getline(ifs, record);

	return ifs;
}


