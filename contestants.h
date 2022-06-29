/*
Andrew Crandall
CSC 161
02 / 14 / 2022
Title : Hangman Project #1
*/

#ifndef CONTESTANTS_H
#define CONTESTANTS_H
#define MAX_SIZE 3

#include "player.h"
#include <fstream>
#include <iostream>
class Contestants
{
private:
	int size;
	Player data[MAX_SIZE];

public:
	Contestants() { size = 0; }; // Default Constructor
	int getSize();
	int getMaxSize();
	bool append(Player& playerObj);
	bool removeItem(Player& playerObj);
	bool removeByIndex(int index);
	void clearAll();
	int findPlayer(Player& playerObj);
	Player& atIndex(int index);

	Player& operator[](int position);

	bool readFile(std::string fileName);
	bool writeFile(std::string fileName);






};

#endif