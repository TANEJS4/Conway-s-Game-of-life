#include "Print.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <unistd.h>
#include <stdexcept>
#include <vector>

using namespace std;

static int ROW = 25;
static int COL = 25;

Print::Print()
{}

void Print::printBoard(Board input)
{
	toBePrint = input.printState();

	for (int i = 1; i < ROW; i++)
	{
		for (int j = 1; j < COL; j++)
		{
			if (toBePrint[i][j] == false)
			{
				cout << " - ";
			}
			else {   
				cout << " O ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "\n";
}

