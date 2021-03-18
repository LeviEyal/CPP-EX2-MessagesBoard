/************************************************************************************
 * C++ course, Ariel university.
 * Assignment number 2.
 *
 * AUTHORS: Eyal Levi
 * https://github.com/LeviEyal
 * Date: 2021-03
 ***********************************************************************************/

#include <iostream>
#include "Board.hpp"
using namespace std;

namespace ariel {

    void Board::post(uint row, uint column, Direction direction, string message) {
        bool flag = (direction == Direction::Horizontal);
        /* posting: */
        for(char ch: message){
            this->board[row][column].val = ch;
            flag? column++ : row++;
            this->rows = std::max(this->rows, row+1);
            this->cols = std::max(this->cols, column+1);
        }
    }
//--------------------------------------------------------------------------------------------------
    string Board::read(uint row, uint column, Direction direction, uint length) {
        string ans;
        bool flag = (direction == Direction::Horizontal);
        for(uint i=0; i<length; i++){
            ans += this->board[row][column].val;
            flag? column++ : row++;
        }
        return ans;
    }
//--------------------------------------------------------------------------------------------------
    void Board::show() {
        cout << "The board: \nrows: " << this->rows << " cols: " << this->cols << "\n\n";
        for (uint i = 0; i < this->rows; i++) {
            for (uint j = 0; j < this->cols; j++) {
                cout << this->board[i][j].val << " ";
            }
            cout << "\n\n";
        }
    }
}
