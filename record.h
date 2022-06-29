#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <fstream>
#include <iostream>

class Record : public std::string
{
public:
    // default (1)
    Record();
    // copy (2)
    Record(const std::string& str);
    // substring (3)
    Record(const std::string& str, size_t pos, size_t len = npos);
    // from c-string (4)
    Record(const char* s);
    // from sequence (5)
    Record(const char* s, size_t n);
    // fill (6)
    Record(size_t n, char c);

    ~Record();

    Record* split(char delimeter);
  //Record* split(char delimeter = ',');

    int getSize() const { return length; };
    int getMax() const { return max; };


    Record& upper();
    Record& lower();


    friend std::istream& operator>>(std::istream& iss, Record& record); //input from console overload
    friend std::ifstream& operator>>(std::ifstream& ifs, Record& record); //input from file overload

private:
    Record* fields;
    int length;
    int max;


};


#endif