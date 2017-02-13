

#ifndef PROB_H
#define PROB_H

class Problem
{
private: 
	int depth;
	int branch;
	int board[9];
public:
	int getIndex(int);
	void showBoard();
	bool isSolved();
	Problem* update(int*);
	Problem();
	Problem(int*);
};

#endif
