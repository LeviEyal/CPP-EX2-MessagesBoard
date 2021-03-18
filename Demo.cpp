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
	board.post(/*row=*/5, /*column=*/5, Direction::Horizontal, "Alon");
	board.post(/*row=*/0, /*column=*/7, Direction::Vertical, "Finneshtein");
	board.post(/*row=*/2, /*column=*/9, Direction::Horizontal, "is");
	board.post(/*row=*/3, /*column=*/12, Direction::Vertical, "the");
	board.post(/*row=*/5, /*column=*/15, Direction::Horizontal, "gayest");
	board.post(/*row=*/10, /*column=*/11, Direction::Horizontal, "in");
	board.post(/*row=*/10, /*column=*/16, Direction::Vertical, "the");
	board.post(/*row=*/10, /*column=*/19, Direction::Vertical, "world!");

	board.show();

	// cout << board.read(/*row=*/5, /*column=*/15, Direction::Horizontal, /*length=*/6) << endl;  
}

