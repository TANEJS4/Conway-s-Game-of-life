
#include "GameBoard.h"

#include "Print.h"
using namespace std;

int main()
{

	string inputFile;
	Board a = Board();
	Print f = Print();
	cout << "Start of game" << endl;
	cout << "Normal game -> use test0.txt" << endl;
	cout << "Complex game -> use test1.txt" << endl;
	cin >> inputFile;
	a.createBoard(inputFile);
	f.printBoard(a);
	cout << "Press any key to start" << endl;
	string in;
	cin >> in;
	while (!(in == "end" || in == "quit"))
	{

		a.copy();
		a.state();

		if (a.prevState())
		{
			break;
		}
		f.printBoard(a);
		cout << "Press any key to continue" << endl;

		cin >> in;
	}
	cout << "Do you have saved the game, yes/no" << endl;
	cin >> in;
	if(in == "yes"){
		cout << "Do you want to delete that game , yes" << endl;
		cin >> in;
		if (in == "yes")
		{
			a.removeSaved();
		}
		

	}
	cout << "Do you want to save the game at log/log/txt , yes" <<endl;
	cin >> in;
	if (in =="yes"){
		a.saveGame();
	}

	cout << "End of game" << endl;

	return 0;
}
