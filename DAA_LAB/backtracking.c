// N-Queens Check
bool isSafe(int board[N][N], int row, int col) {
    // Check left row
    // Check upper diagonal
    // Check lower diagonal
}

bool solveNQ(int board[N][N], int col) {
    if(col >= N) return true;
    
    for(int i=0; i<N; i++) {
        if(isSafe(board, i, col)) {
            board[i][col] = 1;
            if(solveNQ(board, col+1)) return true;
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}
// Backtracking: Recursive trial-error with state reset
