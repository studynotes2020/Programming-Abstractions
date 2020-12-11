/*

bool SolveSudoku(Grid<int> &grid) {
    int row, col;

    if (!FindUnassignedLocation(grid, row, col))
        return true; // all locations successfully assigned!

    for (int num = 1; num <= 9; num++) {
        if (NoConflicts(grid, row, col, num)) {  // options are 1-9
            grid(row, col) = num;                // try assign num
            if (SolveSudoku(grid)) return true;  // recur if succeed stop
            grid(row, col) = UNASSIGNED;         // undo & try again
        }
    }
    return false;  // this triggers backtracking from early decisions
}

*/