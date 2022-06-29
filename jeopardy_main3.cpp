/*
Andrew Crandall
CSC 161
02/14/2022
Title : Hangman Project #1
Summary : Create three different players, assign each player
		  object to the three different ascii arts,
		  write contestants to player.dat file

Credit: Ascii code picture idea to student, Dustin McDowell, Fall 2020
*/

#include <iostream>	
#include <string>
#include <iomanip>
#include <cstdlib> 
#include <ctime>

#include "player.h"
#include "contestants.h"
#include "record.h"
#include "linklist.h"
#include "bintree.h"
#include "question.h"
#include "htmlfunc.h"

void drawContestants(Contestants players);
std::string getContestant1();
std::string getContestant2();
std::string getContestant3();
std::string getContestant4();

int main()
{
  srand(time(nullptr)); 

	LinkList<Record> allCategories;
	if(!allCategories.readFile("assets/categories.csv"))
      std::cout << "\nError categories.csv file\n";
  

	LinkList<Record> boardCategories;

	int size = 1; // boardCategories.getSize();


  
	BinTree<Question> categorySet1;
	BinTree<Question> categorySet2;
	BinTree<Question> categorySet3;
	BinTree<Question> categorySet4;
	BinTree<Question> categorySet5;
	BinTree<Question> categorySet6;

  //Record next = "Chess.csv";
  //Record* next2; 
  //next2 = next.split('.');
  //boardCategories.append(next2[0]);



  
	while (size <= 6) {
    Record next = allCategories.getRandomItem();
    std::cout << (size) << ". " << next << "\n";

		Record* next2;
		next2 = next.split('.');

		if (boardCategories.find(next2[0]) == false) {
		  boardCategories.append(next2[0]);
      size++;
    }
  }
  
	if(!categorySet1.readFile("Categories/" + boardCategories.at(1) + ".csv" ))
        std::cout << "\nError categorySet1 file\n";
	if (!categorySet2.readFile("Categories/" + boardCategories.at(2) + ".csv" ))
      std::cout << "\nError categorySet2 file\n";
	if (!categorySet3.readFile("Categories/" + boardCategories.at(3) + ".csv" ))
        std::cout << "\nError categorySEt3 file\n";
	if (!categorySet4.readFile("Categories/" + boardCategories.at(4) + ".csv" ))
        std::cout << "\nError categorySet4 file\n";
	if (!categorySet5.readFile("Categories/" + boardCategories.at(5) + ".csv" ))
			std::cout << "\nError category 5 file\n";
	if (!categorySet6.readFile("Categories/"+ boardCategories.at(6) + ".csv" ))
        std::cout << "\nError category6 file\n";

  printHTMLindex(boardCategories);
	printHTMLpages(categorySet1, 1);
	printHTMLpages(categorySet2, 2);
	printHTMLpages(categorySet3, 3);
	printHTMLpages(categorySet4, 4);
	printHTMLpages(categorySet5, 5);
	printHTMLpages(categorySet6, 6);

	std::cout << "WELCOME TO JEOPARDY!" << std::endl
		<< std::endl;
	std::cout << "The six categories of your game are: " << std::endl
		<< std::endl;
	boardCategories.printQuestions();

  
	Contestants players;

	players.readFile("player.dat");							// Get the players from the file.	

	drawContestants(players);

	players.clearAll();

	Player p1, p2, p3;
	p1.setName(getContestant1());
	p2.setName(getContestant2());
	p3.setName(getContestant3());

	players.append(p1);
	players.append(p2);
	players.append(p3);

	drawContestants(players);


	players.writeFile("player.dat");
  

	

	return 0;
}

void drawContestants(Contestants players) {
	std::cout << "\n" <<
		"    .xxxx.     " << "    \\\\||//    " << "    \\|||||/     \n" <<
		"   |(o)(o)|    " << "    ~ .. '~     " << "  ( ~  ~ )     \n" <<
		"  (  (__)  )   " << "    (  \\  )    " << "  @( 0  0 )@    \n" <<
		"    | __ |     " << "     \\ c /     " << "   (   C  )     \n" <<
		"     \\__/     " << "    __\\ /__    " << "     \\ \\_//    \n" <<
		"   ___||___    " << "   /       \\   " << "  ___|  |___    \n" <<
		"  /        \\  " << "    |       |   " << "  /        \\   \n";
	std::cout << "_______________________________________________\n";

	std::cout << "| ";
	for (int i = 0; i < players.getSize(); i++)
		std::cout << " " <<
		std::left << std::setw(13) << players[i].getName() << " ";
	std::cout << "|\n";
	std::cout << "''''''''''''''''''''''''''''''''''''''''''''''''\n";
	std::cout << "\n\n";
}

/*Thank you for visiting https ://asciiart.website/
	This ASCII pic can be found at
	https ://asciiart.website/index.php?art=people/faces
*/
std::string getContestant1() {
	std::cout << "\n" <<
		"\n    .xxxx." <<
		"\n   |(o)(o)|" <<
		"\n  (  (__)  )" <<
		"\n    | __ |" <<
		"\n     \\__/ " <<
		"\n   ___||___" <<
		"\n  /        \\";
	std::cout << "\nEnter name of contestant 1: ";
	std::string name;
	std::cin >> name;
	std::cout << "\n\n";
	return name;
}

/* https://www.asciiart.eu/people/occupations/artists */
std::string getContestant2() {
	std::cout << "\n" <<
		"\n    \\\\||//" <<
		"\n    ~ .. '~" <<
		"\n    (  \\  )" <<
		"\n     \\ c /" <<
		"\n    __\\ /__" <<
		"\n   /       \\"
		"\n   |        |";
	std::cout << "\nEnter name of contestant 3: ";
	std::string name;
	std::cin >> name;
	std::cout << "\n\n";
	return name;
}

/*Thank you for visiting https://asciiart.website/
This ASCII pic can be found at
https://asciiart.website/index.php?art=people/faces
*/
std::string getContestant3() {
	std::cout << "\n" <<
		"\n    \\|||||/" <<
		"\n    ( ~  ~ )" <<
		"\n   @( 0  0 )@" <<
		"\n    (   C  )" <<
		"\n     \\ \\_//" <<
		"\n   ___|  |___" <<
		"\n   /        \\  ";
	std::cout << "\nEnter name of contestant 2: ";
	std::string name;
	std::cin >> name;
	std::cout << "\n\n";
	return name;
}

/* https://www.asciiart.eu/people/women */
std::string getContestant4() {
	std::cout << "\n" <<
		"\n     ____" <<
		"\n  /((   ))" <<
		"\n  ( )6  6( )" <<
		"\n  (_)  l (_)" <<
		"\n    \\ <> )" <<
		"\n_____)  (_____" <<
		"\n( \\         / )";
	std::cout << "\nEnter name of contestant 4: ";
	std::string name;
	std::cin >> name;
	std::cout << "\n\n";
	return name;
}

