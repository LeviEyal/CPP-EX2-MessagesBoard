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

    void Board::resizeBoard(int r, int c){        
        this->rows = r;
        this->cols = c;
        this->board.resize(r);
        for (int i = 0; i < r ; i++){
            this->board[i].resize(c, '_');
        }
    }

    void Board::post(int row, int column, Direction direction, string message) {
        int msg_len = message.size();
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
        for(int i=0; i<msg_len; i++){
            this->board[row][column] = message[i];
            flag? column++ : row++;
        }    
    }
//--------------------------------------------------------------------------------------------------
    string Board::read(int row, int column, Direction direction, int length) {
        string ans;
        bool flag = (direction == Direction::Horizontal);
        try {
            for(int i=0; i<length; i++){
                ans += this->board.at(row).at(column);
                flag? column++ : row++;
            }
        }
        catch(const std::exception& e) {
            cout << "out of the the board!" << endl;
        }
        return ans;
    }
//--------------------------------------------------------------------------------------------------
    void Board::show() {
        cout << "The board: \nrows: " << this->rows << " cols: " << this->cols << "\n\n"; 
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                cout << this->board[i][j] << " ";
            }
            cout << "\n\n";
        }
        cout << "\n";
    }
}
