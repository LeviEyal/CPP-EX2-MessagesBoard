/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
#include <vector>
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

void printVector(vector<vector<char>> vec){
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j];
		}
		cout << endl;
	}
}

int main() {
	ariel::Board board;
	board.post(/*row=*/0, /*column=*/1, Direction::Horizontal, "Alon");
	// cout << board.read(/*row=*/1, /*column=*/20, Direction::Vertical, /*length=*/3) << endl;  
	// 	// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	board.post(/*row=*/0, /*column=*/30, Direction::Vertical, "Fines");
	// cout << board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/6) << endl;  
	// 	// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).
	// board.post(/*row=*/1, /*column=*/9, Direction::Horizontal, "is");
	// board.post(/*row=*/1, /*column=*/12, Direction::Vertical, "the");
	// board.post(/*row=*/4, /*column=*/13, Direction::Horizontal, "gayest");

	board.show(); // shows the board in a reasonable way. For example:
		//    98:  _________
		//    99:  ____x____
		//    100: __abyd___
		//    101: ____z____
		//    102: _________


	// int n=5, m=4;
	// vector<vector<char>> vec( n , vector<char> (m, '_'));
	// vec[2][0] = 'p';
	// vec[2][1] = 'q';
	// vec[2][2] = 'w';
	// vec[2][3] = 'r';
	// printVector(vec);
	// cout << endl;
	// vec.resize(n+3);
	// for (int i = 0; i < n+3; ++i)
	// 		vec[i].resize(m+3, '_');
	// printVector(vec);
}

