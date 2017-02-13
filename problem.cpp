

#include "problem.h"
#include <iostream>

Problem::Problem() 
{

	this->board[0] = 0;
	this->board[1] = 1;
	this->board[2] = 2;
	this->board[3] = 3;
	this->board[4] = 4;
	this->board[5] = 5;
	this->board[6] = 6;
	this->board[7] = 7;
	this->board[8] = 8;
}

Problem::Problem(int arr[9]) 
{
	this->board[0] = arr[0];
	this->board[1] = arr[1];
	this->board[2] = arr[2];
	this->board[3] = arr[3];
	this->board[4] = arr[4];
	this->board[5] = arr[5];
	this->board[6] = arr[6];
	this->board[7] = arr[7];
	this->board[8] = arr[8];
}

Problem* Problem::update(int *arr) 
{
	Problem *tmp = new Problem(arr);
	return tmp;
}

void Problem::showBoard()
{
	std::cout << this->board[0] << " " << this->board[1] << " "  << this->board[2] << "\n";
	std::cout << this->board[3] << " " << this->board[4] << " "  << this->board[5] << "\n";
	std::cout << this->board[6] << " " << this->board[7] << " "  << this->board[8] << "\n";
}

bool Problem::isSolved()
{
	if(this->board[0] != 0) return false;
	if(this->board[1] != 1) return false;
	if(this->board[2] != 2) return false;
	if(this->board[3] != 3) return false;
	if(this->board[4] != 4) return false;
	if(this->board[5] != 5) return false;
	if(this->board[6] != 6) return false;
	if(this->board[7] != 7) return false;
	if(this->board[8] != 8) return false;
	return true;
}
