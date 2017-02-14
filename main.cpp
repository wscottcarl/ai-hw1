
#include <iostream>
#include <stdlib.h>
#include "problem.h"
#include "node.h"
#include "tree.h"
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>


// should accept cmd line options
// -t N 	generates N random test cases and solutions
// -i 		asks for input to generate board
// NOTE: -i and -t are mutually exclusive
// -p 		prints solution output 
//		** when N exceeds 10, print to results.txt **

using namespace std;
Problem* board;
Node* node;

int main(int argc, char *argv[]) {

// if -i option ticked, ask for board input
	if(argc != 1) 
	{
		if(!strcmp(argv[1],"-i"))
		{
			int arr[9];
			cout << "Enter your puzzle: " << endl;
			for(int i=0;i<9;i++)
			{
				int temp;
				cin >> temp;
				if(cin.fail())
				{ 
					cout << "Only integers are valid input. Exiting \n ";
					return 0; 
				}
				else if(temp > 8 or temp < 0) 
				{ 
					cout << "Integer values outside of [0,8] invalid. Exiting\n";
					return 0; 
				}
				else arr[i] = temp;
			}
			board = new Problem(arr);
			board->showBoard();
			board = board->up();
			board->showBoard();
			cout << "Solved: " << board->isSolved() << endl;
		}

// if -f option ticked, read from file where filename is provided
		else if(!strcmp(argv[1],"-f"))
		{
			cout << "File option ticked\n";
			string line;
			ifstream infile(argv[2]);
			int n;
			int v[9];
			while(getline(infile,line)){
				istringstream iss(line);
				for(int i=0;i<9;i++)
				{
					iss >> n;
					v[i] = n;
				}
//				board = new Problem(v,0,0);
				node = new Node(new Problem(v), 0, 0, NULL, 0);
			}
		}
	}
	Tree* tree = new Tree(node);
	tree->solve();
	node->getState()->showBoard();
// at this point you should have a board or a selection of boards ready for testing
// call A*(board)

/*	int board[] = {0,1,2,3,4,5,6,7,8,9};
	for(int i=0;i<10;i++) {
		cout << "At index " << i << ": " << board[i] << "\n";
	}
*/
	//board->solve();

	return 0;
}
/*
Solution* aStarSearch(Problem *prob)
{
	return bestFirstSearch(prob, g+h);
}

Solution* bestFirstSearch(Problem *prob, evalFunction())
{
	// update the priority queue of nodes
	return generalSearch(prob, queueingFunction());
}

Solution* generalSearch(Problem *prob, queueingFunction()) 
{
	if(prob->up()) 
	while(!stack.isEmpty())
	{
		Problem *top = stack.pop();
		if(top->isSolved()) return top;
		
	}
	return solution;
}

*/
