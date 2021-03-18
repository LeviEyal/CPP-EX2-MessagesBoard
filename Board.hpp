#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;

namespace ariel {
    class Board {
        uint rows;
        uint cols;
        vector<vector<char>> board;
        void resizeBoard(uint r, uint c);
    public:
        Board() { }
        ~Board() { }
        void post(uint row, uint column, Direction direction, string message);
        std::string read(uint row, uint column, Direction direction, uint length);
        void show();
    };
}