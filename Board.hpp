#include <string>
#include <map>
#include "Direction.hpp"
using namespace std;
using eyal = ariel::Direction;

struct node{
    char val = '_';
};

namespace ariel {
    class Board {
        uint rows;
        uint cols;
        map<uint, map<uint, node> > board;
    public:
        Board() { rows = cols = 0; }
        ~Board() { }
        void post(uint row, uint column, Direction direction, string message);
        std::string read(uint row, uint column, Direction direction, uint length);
        void show();
    };
}