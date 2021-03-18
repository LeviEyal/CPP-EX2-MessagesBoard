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

    void Board::resizeBoard(uint r, uint c){        
        this->rows = r;
        this->cols = c;
        this->board.resize(r);
        for (uint i = 0; i < r ; i++){
            (this->board)[i].resize(c, '_');
        }
    }

    void Board::post(uint row, uint column, Direction direction, string message) {
        uint msg_len = message.size();
        bool flag = (direction == Direction::Horizontal);
        if(flag){
            resizeBoard(std::max(this->rows, row+1),
                        std::max(this->cols, column + msg_len +1));
        }
        else {
            resizeBoard(std::max(this->rows, row + msg_len + 1), 
                        std::max(this->cols, column + 1));
        }
        /* posting: */
        for(char ch: message){
            this->board[row][column] = ch;
            flag? column++ : row++;
        }    
    }
//--------------------------------------------------------------------------------------------------
    string Board::read(uint row, uint column, Direction direction, uint length) {
        string ans;
        bool flag = (direction == Direction::Horizontal);
        try {
            for(uint i=0; i<length; i++){
                ans += this->board.at(row).at(column);
                flag? column++ : row++;
            }
        }
        catch(const std::exception& e) {
            // cout << "out of the the board!" << endl;
            throw out_of_range("out of the the board!");
        }
        return ans;
    }
//--------------------------------------------------------------------------------------------------
    void Board::show() {
        cout << "The board: \nrows: " << this->rows << " cols: " << this->cols << "\n\n"; 
        for (uint i = 0; i < this->rows; i++) {
            for (uint j = 0; j < this->cols; j++) {
                cout << this->board[i][j] << " ";
            }
            cout << "\n\n";
        }
        cout << "\n";
    }
}
