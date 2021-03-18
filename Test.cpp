/************************************************************************************
 * C++ course, Ariel university.
 * Assignment number 2.
 *
 * AUTHORS: Eyal Levi
 * https://github.com/LeviEyal
 * Date: 2021-03
 ***********************************************************************************/

#include <iostream>
#include "doctest.h"
#include "Board.hpp"
using namespace ariel;
using ariel::Direction;

#include <stdexcept>
#include <string>
using namespace std;


// int boardRows(Board b){
//     int i = 0;
//     while(true){
//         try{
//             b.read(i, 0, Direction::Vertical, 1);
//         }
//         catch(const std::exception& e) {
//             return i;
//         }
//         i++;
//     }
// }

// TEST_CASE("check colums resizing"){
//     Board board;
//     che
// }

TEST_CASE("check columns resizing"){
    // ariel::Board board;
	// board.post(/*row=*/0, /*column=*/0, Direction::Horizontal, "Alon");
    // board.show();
    Board b;
    // b.post(5, 5, Direction::Horizontal,"abcd");
    // b.show();
    // cout << boardRows(b) << endl;
    CHECK_NOTHROW(b.post(5,5,Direction::Vertical,"abcd"));
    CHECK_THROWS(string s = b.read(20,0,Direction::Horizontal,2));
}

// TEST_CASE("check rows resizing"){

// }

// TEST_CASE("check rows & columns resizing"){

// }

// TEST_CASE("check text overiding"){

// }

// TEST_CASE("check text overiding"){

// }

// TEST_CASE("check posting in upper border"){

// }

// TEST_CASE("check posting in lower border"){

// }

// TEST_CASE("check posting in right border"){

// }

// TEST_CASE("check posting in left border"){

// }
