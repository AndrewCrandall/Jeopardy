/*
Andrew Crandall
CSC 161
02 / 14 / 2022
Title : Hangman Project #1
*/

#include "contestants.h"

int Contestants::getSize()
{
	//returns size as const
	return size;
}

int Contestants::getMaxSize()
{
	// returns max size as const
	return MAX_SIZE;
}

bool Contestants::append(Player& playerObj)
{
	if (size < MAX_SIZE) {
		data[size] = playerObj;
		size = size + 1;
		return true;
	}
	return false;
}

bool Contestants::removeItem(Player& playerObj)
/*
removeItem, removes specific player object that is passed through
for loop iterates through each data object until size,
if data at i is equal to object, it is overwrited by the last object in data
return true
else return false
*/

{
	for (int i = 0; i < size; i++) {
		if (data[i] == playerObj) {
			size = size - 1;
			data[i] = data[size];
			return true;
		}
	}
	return false;
}

bool Contestants::removeByIndex(int index)
{
	/*
	removeByIndex, removes value at data[index] as long as index is greater than -1 and less than size of data
	overwrite data[index] with size, and decrease size by one, allowing for another append
	return true

	if parameters are not met, return false
	*/
	if (index < size && index > -1) {
		size = size - 1;
		data[index] = data[size];
		return true;
	}
	return false;
}

void Contestants::clearAll()
{
	//size is set to 0, essential allowing for size to append up to 3 more players
	size = 0;
}

int Contestants::findPlayer(Player& playerObj)
{
	/*
	findPlayer, takes in player object returns int
	loops through each iteration of data
	if found, return the value at that index i
	if not found return -1
	*/
	for (int i = 0; i < size; i++) {
		if (data[i] == playerObj)
			return i;
	}
	return -1;
}

Player& Contestants::atIndex(int index)
{
	if (index >= 0 && index < size) {
		return data[index];
	}
	else {
		Player dummy("Error", 0);
		return dummy;
	}
}

Player& Contestants::operator[](int position)
{
	if (position >= 0 && position < size) {
		return data[position];
	}
	else {
		Player dummy("Error", 0);
		return dummy;
	}
}

bool Contestants::readFile(std::string fileName)
{
	/*
	creates ifstream file,
	opens file with name provided
	if file is not able to be opened, return false
	else insert each object
	check to make sure the name size is greater than 0 to ensure the object is valid (again)
	output the object to the console
	return true once completed.
	*/
	std::ifstream file;
	file.open(fileName);

	if (!file)
		return false;

	else {
		Player object;

		while (!file.eof()) {
			file >> object;
			append(object);
		}
		return true;
	}
	return false;
}

bool Contestants::writeFile(std::string fileName)
{
	/*
	creates ofstream, file
	opens file with name provided
	if fine is unable to be opened, return false breaks from function
	else iterate through each object in the bag data
	once done close file and return true
	*/
	std::ofstream file;

	file.open(fileName);

	if (!file)
		return false;
	else {
		for (int i = 0; i < size; i++) {
			file << data[i] << std::endl;
		}
		file.close();
		return true;
	}
}