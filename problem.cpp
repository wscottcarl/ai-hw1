

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

Problem* Problem::swap(int current, int target)
{
	this->board[current] = this->board[target];
	this->board[target] = 0;
	return this;
}

void Problem::showBoard()
{
	std::cout << this->board[0] << " " << this->board[1] << " "  << this->board[2] << "\n";
	std::cout << this->board[3] << " " << this->board[4] << " "  << this->board[5] << "\n";
	std::cout << this->board[6] << " " << this->board[7] << " "  << this->board[8] << "\n";
}

bool Problem::isSolved()
{
	if(this->board[0] != 1) return false;
	if(this->board[1] != 2) return false;
	if(this->board[2] != 3) return false;
	if(this->board[3] != 4) return false;
	if(this->board[4] != 5) return false;
	if(this->board[5] != 6) return false;
	if(this->board[6] != 7) return false;
	if(this->board[7] != 8) return false;
	if(this->board[8] != 0) return false;
	return true;
}
/*
void Problem::printStats()
{
	std::cout << "Total depth of solution: " << this->depth << std::endl;
	std::cout << "Total expansions: " << this->branch << std::endl;
}*/

int Problem::findBlank()
{
	for(int i=0;i<9;i++)
		if(this->board[i] == 0) return i;
	return -1;
}

Problem* Problem::up()
{
	int index = this->findBlank();
	if(index == 3) return this->swap(3, 0);
	else if(index == 4) return this->swap(4, 1);
	else if(index == 5) return this->swap(5, 2);
	else if(index == 6) return this->swap(6, 3);
	else if(index == 7) return this->swap(7, 4);
	else if(index == 8) return this->swap(8, 5);
	else std::cout << "Cannot move up\n";
	return NULL;
}

Problem* Problem::down()
{ 
	int index = this->findBlank();
	if(index == 0) return this->swap(0, 3);
	else if(index == 1) return this->swap(1, 4);
	else if(index == 2) return this->swap(2, 5);
	else if(index == 3) return this->swap(3, 6);
	else if(index == 4) return this->swap(4, 7);
	else if(index == 5) return this->swap(5, 8);
	else std::cout << "Cannot move down\n";
	return NULL;
}

Problem* Problem::right()
{ 
	int index = this->findBlank();
	if(index == 0) return this->swap(0, 1);
	else if(index == 1) return this->swap(1, 2);
	else if(index == 3) return this->swap(3, 4);
	else if(index == 4) return this->swap(4, 5);
	else if(index == 6) return this->swap(6, 7);
	else if(index == 7) return this->swap(7, 8);
	else std::cout << "Cannot move right\n";
	return NULL;
}

Problem* Problem::left()
{ 
	int index = this->findBlank();
	if(index == 1) return this->swap(1, 0);
	else if(index == 2) return this->swap(2, 1);
	else if(index == 4) return this->swap(4, 3);
	else if(index == 5) return this->swap(5, 4);
	else if(index == 7) return this->swap(7, 6);
	else if(index == 8) return this->swap(8, 7);
	else std::cout << "Cannot move left\n";
	return NULL;
}

int Problem::outOfRow()
{
	int sum = 0;
	if(board[0] != 1 and board[1] != 1 and board[2] != 1) sum++;
	if(board[0] != 2 and board[1] != 2 and board[2] != 2) sum++;
	if(board[0] != 3 and board[1] != 3 and board[2] != 3) sum++;
	if(board[3] != 4 and board[4] != 4 and board[5] != 4) sum++;
	if(board[3] != 5 and board[4] != 5 and board[5] != 5) sum++;
	if(board[3] != 6 and board[4] != 6 and board[5] != 6) sum++;
	if(board[6] != 7 and board[7] != 7 and board[8] != 7) sum++;
	if(board[6] != 8 and board[7] != 8 and board[8] != 8) sum++;
	if(board[6] != 0 and board[7] != 0 and board[8] != 0) sum++;
	return sum;
}

int Problem::outOfCol()
{
	int sum = 0;
	if(board[0] != 1 and board[3] != 1 and board[6] != 1) sum++;
	if(board[1] != 2 and board[4] != 2 and board[7] != 2) sum++;
	if(board[2] != 3 and board[5] != 3 and board[8] != 3) sum++;
	if(board[0] != 4 and board[3] != 4 and board[6] != 4) sum++;
	if(board[1] != 5 and board[4] != 5 and board[7] != 5) sum++;
	if(board[2] != 6 and board[5] != 6 and board[8] != 6) sum++;
	if(board[0] != 7 and board[3] != 7 and board[6] != 7) sum++;
	if(board[1] != 8 and board[4] != 8 and board[7] != 8) sum++;
	if(board[2] != 0 and board[5] != 0 and board[8] != 0) sum++;
	return sum;
}
