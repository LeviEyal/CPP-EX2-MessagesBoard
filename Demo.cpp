/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	ariel::Board board;
	board.post(/*row=*/0, /*column=*/0, Direction::Horizontal, "Alon");
	board.post(/*row=*/0, /*column=*/7, Direction::Vertical, "Finneshtein");
	board.post(/*row=*/2, /*column=*/9, Direction::Horizontal, "is");
	board.post(/*row=*/3, /*column=*/12, Direction::Vertical, "the");
	// board.post(/*row=*/5, /*column=*/1, Direction::Horizontal, "jehonathan");
	// cout << board.read(/*row=*/1, /*column=*/20, Direction::Vertical, /*length=*/3) << endl;  
	// 	// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	board.post(/*row=*/5, /*column=*/15, Direction::Horizontal, "gayest");
	// cout << board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/6) << endl;  
	// 	// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).
	board.post(/*row=*/10, /*column=*/11, Direction::Horizontal, "in");
	board.post(/*row=*/10, /*column=*/16, Direction::Vertical, "the");
	board.post(/*row=*/10, /*column=*/19, Direction::Vertical, "world!");
	// board.post(/*row=*/4, /*column=*/13, Direction::Horizontal, "gayest");

	// board.show();
}

