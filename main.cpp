
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "problem.h"
#include <fstream>

// should accept cmd line options
// -t N 	generates N random test cases and solutions
// -i 		asks for input to generate board
// NOTE: -i and -t are mutually exclusive
// -p 		prints solution output 
//		** when N exceeds 10, print to results.txt **

using namespace std;
Problem* board;

int main(int argc, char* argv[]) {

// if -t option ticked
// create an Nx10 table
// for N rows, fillBoard(t[i])


// if -i option ticked, ask for 10 characters
// also prompt user to indicate blank space using 0 int
// if any input isnt an int that's [0,9], retry (unless 'q', then quit)
// also, if any input repeated, retry (unless 'q', then quit)
	if(argc != 1) 
	{
		if(strcmp(argv[0], "-i"))
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
			board = board->update(arr);
			board->showBoard();
			cout << "Solved: " << board->isSolved() << endl;
		}
	}

// if -f option ticked
// open FILE and read until end
/*	if(argc != 1)
	{
		if(strcmp(argv[0],"-f"))
		{
			int dig;
			FILE f = fopen(argv[1], "r");
			if(f == NULL) perror ("Error opening file");
			else dig = getint(f);
			
		}
	}*/

// -p handled elsewhere

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
