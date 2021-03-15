#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;

namespace ariel {
    class Board {
        int rows;
        int cols;
        vector<vector<char>> board; 
    public:
        Board() {
            board = vector<vector<char>>(3 , vector<char> (3, '_'));
            rows = 3;
            cols = 3;
        }
        ~Board() { }
        void post(int row, int column, Direction direction, std::string message);
        std::string read(int row, int column, Direction direction, int length);
        void show();
        void resizeBoard(int r, int c);
    };
}