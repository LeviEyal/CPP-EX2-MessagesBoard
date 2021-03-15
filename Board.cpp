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
        cout << "resizing to " << r << " x " << c << endl;
        this->board.resize(r);
        for (int i = 0; i < r ; ++i){
            this->board[i].resize(c, '_');
        }
    }

    void Board::post(int row, int column, Direction direction, string message) {
        int length = message.size();
        if(direction == Direction::Horizontal){
            int r = std::max(this->rows, row);
            int c = std::max(this->cols, column + length);
            resizeBoard(r, c);
            /* posting: */
            for(int i=0; i<length; i++){
                this->board[row][column+i] = message[i];
            }
        }
        
        if(direction == Direction::Vertical){
            int r = std::max(this->rows, row + length);
            int c = std::max(this->cols, column);
            resizeBoard(r, c);
            /* posting: */
            for(int i=0; i<length; i++){
                this->board[row+i][column] = message[i];
            }    
        }
        show();
    }
//--------------------------------------------------------------------------------------------------
    string Board::read(int row, int column, Direction direction, int length) {
        string ans;
        if(direction == Direction::Horizontal){
            if(column + length > this->cols || row > this->rows)
                throw out_of_range("out of the mesagges board!");

            for(int i=0; i<length; i++){
                ans += this->board[row][column+i];
            }
        }
        else if(direction == Direction::Vertical || column > this->cols){
            if(row + length > this->rows)
                throw out_of_range("out of the mesagges board!");

            for(int i=0; i<length; i++){
                ans += this->board[row+i][column];
            }
        }
        return ans;
    }
//--------------------------------------------------------------------------------------------------
    void Board::show() {
        cout << "The board: \n";
        cout << "rows: " << this->rows << " cols: " << this->cols << "\n\n"; 
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                cout << this->board[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
