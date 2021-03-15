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
        cout << "Successfully resizized to " << r << " x " << c << endl;
    }

    void Board::post(int row, int column, Direction direction, string message) {
        cout << "---------------------------------------------\n"; 
        cout << "\t\tposting: \"" << message << "\" in " << row <<"x" << column << "\n";
        int msg_len = message.size();
        if(direction == Direction::Horizontal){
            int r = std::max(this->rows, row+1);
            int c = std::max(this->cols, column + msg_len +1);
            resizeBoard(r, c);
            /* posting: */
            for(int i=0; i<msg_len; i++){
                this->board.at(row).at(column+i) = message[i];
            }
        }
        
        if(direction == Direction::Vertical){
            int r = std::max(this->rows, row + msg_len + 1);
            int c = std::max(this->cols, column + 1);
            resizeBoard(r, c);
            /* posting: */
            for(int i=0; i<msg_len; i++){
                this->board[row+i][column] = message[i];
                cout << this->board[row+i][column] << "\n";
            }    
        }
        cout << "Successfully posted: " << message << " in: " << row << " x " << column << endl;
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
                cout << this->board[i][j] << " ";
            }
            cout << "\n\n";
        }
        cout << "\n";
    }
}
