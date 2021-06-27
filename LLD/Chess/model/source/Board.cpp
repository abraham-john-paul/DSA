#include <include/Board.hpp>

Board::Board(int t_boardSize, std::vector<std::vector<Cell>> t_cells): 
    boardSize {t_boardSize},
    cells {move(t_cells)} {}

Cell* Board::getCell(const Cell* cur_cell, CellDirection direction) {
    switch (direction) {
        case CellDirection::Up:
            return getCellAllocation(curr_cell->getX() + 1, curr_cell->getY());
    }
}

bool Board::checkBoardBoundaryCondn(int pos) {
    return (pos < boardSize) && (pos >= 0);
}

Cell* Board::getCellAllocation(int x, int y) {
    if(!checkBoardBoundaryCondn(x) || !checkBoardBoundaryCondn(y)) {
        return nullptr;
    }
    return &cells[x][y];
}