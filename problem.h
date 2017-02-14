

#ifndef PROB_H
#define PROB_H

class Problem
{
private: 
	int board[9];
public:
	int getIndex(int);
	void showBoard();
	bool isSolved();
	int findBlank();
	int outOfRow();
	int outOfCol();
	Problem* up();
	Problem* down();
	Problem* left();
	Problem* right();
	Problem* swap(int, int);
	Problem();
	Problem(int*);
};

#endif
