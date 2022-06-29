/*
Andrew Crandall
CSC 161
02 / 14 / 2022
Title : Hangman Project #1
*/


#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <fstream>
#include <iostream>

class Player
{
private:
	std::string name;
	int score;

public:
	Player(); // Constructor of Player Class
	Player(std::string nameInput, int scoreInput);

	void setScore(int num); //set function for score
	void setName(std::string word); //set function for name
	int getScore() const; //get function for score
	std::string getName() const; //get function for name

	std::string toString() const; //converts name and score to a string, this is for CONSOLE output
	std::string toFileString() const; //converts name and score to a string, this is for FILE (CSV)

	friend std::ostream& operator<<(std::ostream& os, const Player& player); //output to console overload
	friend std::istream& operator>>(std::istream& is, Player& player); //input from console overload


	friend std::ofstream& operator<<(std::ofstream& ofs, const Player& player); //output to file overload
	friend std::ifstream& operator>>(std::ifstream& ifs, Player& player); //input from file overload

	friend bool operator==(const Player& playerObj1, const Player& playerObj2);
	friend bool operator!=(const Player& playerObj1, const Player& playerObj2);
	friend bool operator>(const Player& playerObj1, const Player& playerObj2);
	friend bool operator>=(const Player& playerObj1, const Player& playerObj2);
	friend bool operator<(const Player& playerObj1, const Player& playerObj2);
	friend bool operator<=(const Player& playerObj1, const Player& playerObj2);


};


#endif