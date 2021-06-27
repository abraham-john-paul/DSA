#include <vector>

enum class CellDirection {
    Up,
    Down,
    Left,
    Right,
    DiagonalUpLeft,
    DiagonalUpRight,
    DiagonalDownLeft,
    DiagonalDownRight
};

class Cell;

class Board {
    int boardSize;
    std::vector<std::vector<Cell>> cells;
    protected:
    bool checkBoardBoundaryCondn(int pos);
    public:
    Board(int t_boardSize, std::vector<std::vector<Cell>> t_cells);

    Cell* getCell(const Cell* cur_cell, CellDirection direction);
    
    Cell* getCellAllocation(int x, int y);
};