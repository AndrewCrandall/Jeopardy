/*
Andrew Crandall
CSC 161
02 / 14 / 2022
Title : Hangman Project #1
*/

#include "player.h"



Player::Player()
{

	/*
	Player constructor
	sets name to "Empty"
	Sets score to 0
	*/

	name = "Empty";
	score = 0;
}

Player::Player(std::string nameInput, int scoreInput) {
	name = nameInput;
	score = scoreInput;
}


int Player::getScore() const
{

	/*
	returns score
	*/

	return score;
}



std::string Player::getName() const
{
	/*
	Returns name
	*/
	return name;
}



void Player::setScore(int num)
{
	/*
	Does checks, if it is true, sets score to the value that is being passed through, num
	*/
	score = num;
}



void Player::setName(std::string word)
{
	/*
	Does checks, if it is true, sets name to value of word;
	*/

	name = word;
}


std::string Player::toString() const
{
	/*
	keeps player object as constant to ensure we are just changing format, not the value
	creates string strPlayer
	formats the string to where the name, followed by a space, then score (converted to string), and new line
	returns strPlayer (new string)
	*/
	std::string strPlayer;
	strPlayer = name + "  " + std::to_string(score) + "\n";
	return strPlayer;
}


std::string Player::toFileString() const
{
	/*
	keeps player object as constant to ensure values arent changed, just csv format
	creates new string, strPlayer
	changes score to string, concationates name with coma and score new line
	returns string
	*/
	std::string strPlayer;
	strPlayer = name + ',' + std::to_string(score);
	return strPlayer;
}


std::ostream& operator <<(std::ostream& os, const Player& player) {
	/*
	creates string, objectToString
	calls on the toString function
	assigns objectToString to that call
	states to output objectToString
	returns os
	*/
	os << player.toString();
	return os;
}



std::ofstream& operator <<(std::ofstream& ofs, const Player& player) {

	/*
	overloads << for file output
	keeps player as const to ensure values aren't changed
	declares new string, objectToFile
	objectToFile is assigned to toFileString function called through player object
	ofs (output file stream) is assigned to the csv formatted object
	returns ofs
	*/
	ofs << player.toFileString();
	return ofs;

}

std::istream& operator>>(std::istream& is, Player& player) {
	/*
	input from console
	prompts user to enter name
	stores input into string word
	sets name to word
	returns is
	*/

	std::cout << "Enter your name " << std::endl; // output to console, guiding for name input
	std::string word; // obtains input, stores in word
	is >> word;
	player.setName(word); // calls on set function, to assign name

	std::cout << "Enter your score " << std::endl;
	std::string score;
	is >> score;
	int numScore;
	numScore = std::stoi(score);
	player.setScore(numScore);

	return is;
}


std::ifstream& operator >>(std::ifstream& ifs, Player& player)
{

	/*
	operator >> overloaded for file input, specifically files (name,score'\n')
	declares string strName
	declares int strScore
	getline to obtaine name, until ','
	inserts next data point which is score
	calls on setName and setScore
	returns ifs
	*/

	std::string strName;
	std::string strScore;

	std::getline(ifs, strName, ',');
	std::getline(ifs, strScore);
  
	if (strScore == "")
		return ifs;

	else {
		int intScore = std::stoi(strScore);

		player.name = strName;
		player.score = intScore;
	}

	return ifs;
}


bool operator==(const Player& playerObj1, const Player& playerObj2) {
	/*
	operator overloading for ==
	checks the two objects scores
	if they are the same, it is true
	if not false
	*/
	if (playerObj1.score == playerObj2.score)
		return true;
	return false;
}

bool operator!=(const Player& playerObj1, const Player& playerObj2) {

	/*
	overloading for !=
	if the objects scores are not equal, return true
	else return false
	*/
	if (playerObj1.score != playerObj2.score)
		return true;
	return false;
}

bool operator>(const Player& playerObj1, const Player& playerObj2) {
	/*
	overloading for >
	if player1 score is less than player2 score return false
	else return true
	*/

	if (playerObj1.score > playerObj2.score)
		return true;
	return false;
}

bool operator>=(const Player& playerObj1, const Player& playerObj2) {
	/*
	Overload for >=

	checks to see if the first object is greater or equal to the second object
	this is by comparing score
	returns bool
	*/


	if (playerObj1.score > playerObj2.score)
		return true;
	if (playerObj1.score == playerObj2.score)
		return true;
	else
		return false;
}

bool operator<(const Player& playerObj1, const Player& playerObj2) {
	/*
		overload for <
		keeps constant to ensure data doesnt change
		if player1 score is less than player 2 score, return true
		else return false
	*/
	if (playerObj1.score < playerObj2.score)
		return true;
	return false;
}

bool operator<=(const Player& playerObj1, const Player& playerObj2) {

	/*
	if player1 score is less than or equal to player 2 score, it is true
	else return false
	*/
	if (playerObj1.score < playerObj2.score)
		return true;
	if (playerObj1.score == playerObj2.score)
		return true;
	else
		return false;
}