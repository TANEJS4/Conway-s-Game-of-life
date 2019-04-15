#include "catch.h"
#include "GameBoard.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <unistd.h>
#include <stdexcept>

using namespace std;

TEST_CASE("Test for Empty/simple Gameboard", "[GameBoard]")
{
	SECTION("Test gameboard for 1 step game")
	{
		Board a = Board();
		a.createBoard("test0.txt");
		a.state();
		a.saveGame();

		ifstream f("log/log.txt");
		if(f.is_open()){
			string line, xx, yy;
			while(getline(f,line)){
				 REQUIRE(line == "");

					}
			}
			a.removeSaved();
	}

	SECTION("Test save state  in correct form")
	{
		Board a1 = Board();

		a1.createBoard("test0.txt");
		a1.saveGame();
		ifstream f1("log/log.txt");
		if (f1.is_open())
		{
			string line, xx, yy;
			while (getline(f1, line))
			{
				stringstream streams(line);

				getline(streams, xx, ' ');
				getline(streams, yy, ' ');
				int x = stoi(xx);
				int y = stoi(yy);
				REQUIRE(x == 1);
				REQUIRE(y == 1);
			}
		}

		a1.state();

		a1.saveGame();

		ifstream f2("log/log.txt");
		if (f2.is_open())
		{
			string line, xx, yy;
			while (getline(f2, line))
			{
				REQUIRE(line == "");
			}
		}
		a1.removeSaved();
   }
}

TEST_CASE("Test for COMPLEX Gameboard", "[GameBoard]"){

	// 4 6 5 5 5 7 6 5 6 7 7 6 
	
	SECTION("Test gameboard for compex game")
	{
		Board a1 = Board();
		vector<int> temp;
		a1.createBoard("test1.txt");
		a1.state();
		a1.state();
		a1.state();
		a1.state();
		a1.state();
		a1.state();
		a1.state();
		a1.state();
		a1.state();
		a1.state();

		a1.saveGame();
		ifstream f1("log/log.txt");
		if (f1.is_open())
		{
			string line, xx, yy;
			while (getline(f1, line))
			{
				stringstream streams(line);

				getline(streams, xx, ' ');
				getline(streams, yy, ' ');
				int x = stoi(xx);
				int y = stoi(yy);
				temp.push_back(x);
				temp.push_back(y);
			}
		}

		int res[] = {
			4, 6,5, 5 ,5 ,7, 6, 5 ,6, 7 ,7 ,6
		};
		int iter = 0;
		for (int x : res)
		{
			REQUIRE(temp[iter] == x);
			iter++;
		}
		a1.removeSaved();
	}
}
