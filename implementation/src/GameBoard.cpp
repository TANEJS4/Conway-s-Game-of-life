#include "GameBoard.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <unistd.h>
#include <stdexcept>
using namespace std;

static int ROW = 25;
static int COL = 25;

Board::Board(){
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			this->board[i][j] = false;
				}
	}
}
void Board::saveGame() {
		system("mkdir log");

	ifstream f("log/log.txt");
	if (f.good()){
		f.clear();
	}
	ofstream save("log/log.txt");
	if(save.is_open()){
		for (int i = 1; i < ROW; i++)
		{
			for (int j = 1; j < COL; j++)
			{
				if (this->board[i][j])
				{
					save << i << " " << j << "\n";
				}
			}
		}
	}
	save.close();
}
void Board::removeSaved()
{
	system("rm log/log.txt");
}
void Board::createBoard(string file)
{
	ifstream f(file);
	if (f.is_open()){
		string line;
		string XX;
		string YY;
		while (getline(f, line))
		{
			stringstream streams(line);

			getline(streams, XX, ' ');
			getline(streams, YY, ' ');

			int x = stoi(XX);
			int y = stoi(YY);
			if(x==0 || y ==0 || x > 24 || y > 24 ){
				throw invalid_argument("Input cant be at 0th row or 0th column");
			}

			this->board[x][y] = true;
		}
	}
	else
	{
		cout << " \n \n No such file, try again.\n \n" << endl;
		exit(1);
	}

}
void Board::compare()
{
	for (int a = 0; a < 25;a++){
		for (int b = 0; b < 25; b++)
		{
			this->board2[a][b] = this->board[a][b];
		}
	}
}
void Board::state(){
	compare();

	for (int i = 1; i < ROW;i++){
		for (int j = 1; j < ROW; j++){
			int al = 0;
			for (int k = -1; k < 2;k++){
				for (int z = -1; z < 2; z++)
				{
					if (this->board2[i+k][j+z]){
						al = al + 1;
					}
					else{
						al = al + 0;
					}
				}
			}
			if (board[i][j]){
				al = al - 1;
			}
			else{
				al = al - 0;
			}
			neighbourStateChange(al, i, j);
		}
	}
}
void Board::neighbourStateChange(int input,int i, int j){

	if (input < 2)
	{

		this->board[i][j] = false;
	}
	else if (input == 3)
	{
		this->board[i][j] = true;
	}
	else if (input > 3)
	{
		this->board[i][j] = false;
	}
	return;
}
void Board::copy()
{
	for (int a = 0; a < ROW; a++)
	{
		for (int b = 0; b < ROW; b++)
		{
			this->temp[a][b] = this->board[a][b];
		}
	}
}
bool Board::prevState(){
	bool res ;
	for (int a = 0; a < ROW; a++)
	{
		for (int b = 0; b < ROW; b++)
		{
			if(this->temp[a][b] == this->board[a][b]){
				res = true;
			}
			else {
				return false;
			}
		}
	}
	return res;
}

vector<vector<bool>> Board::printState(){
	vector<vector<bool>> res;
	for (int i = 0; i < ROW;i++){
		vector<bool> temp;
		for (int j = 0; j < ROW;j++){
			temp.push_back(this->board[i][j]);
		}
		res.push_back(temp);
	}
	return res;
}
