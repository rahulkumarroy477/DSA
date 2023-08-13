#include<bits/stdc++.h>
using namespace std;

// Function to print the solution.
void printSolution(char **board, int N){
    // It is similar to printing the 2-d array.
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if it is safe to place 
// queen in the cell (row, col) such that 
// it does not attack any other queen.
bool isSafe (char **board, int row, int col, int N){
    // Defining and initializing i and j with row 
    // and col respectively.
    int i = row, j = col;

    // Checking if the left (main) diagonal has 
    // any queen.
    while (i > -1 && j > -1){
        // If a queen is found, return 'false'
        // that means it is not safe to place a queen.
        if (board[i][j] == 'Q')
            return false;

        // Updating values of i and j
        i--;
        j--;
    }

    i = row;
    j = col;
    // Checking if the right (secondary) diagonal has 
    // any queen.
    while (i > -1 && j < N){
        // If a queen is found, return 'false'
        // that means it is not safe to place a queen.
        if (board[i][j] == 'Q')
            return false;

        // Updating values of i and j
        i--;
        j++;
    }

    i = row;
    j = col;
    // Checking if the columns (col) has 
    // any queen.
    while (i > -1){
        // If a queen is found, return 'false'
        // that means it is not safe to place a queen.
        if (board[i][j] == 'Q')
            return false;

        // Updating values of i and j
        i--;
    }
    // If we have reached here, it means it is safe
    // to place the queen in the cell (row, col);
    // Hence, returning true
    return true;
}

// Function to check whether solution exists
// for N queen problem, for the provided N.
// board -> Chess Board of dimensions N*N
// N -> Size of the chess board
// row -> Row number in which we will try to place 
//      the queen. It's value ranges from [0, N-1].
bool solutionExists(char **board, int N, int row){
    // If we have placed a queen in all
    // the rows, it means solution exists.
    if (row >= N)
        return true;
    
    // Trying to place the queen in every possible
    // cell in the 'row th' row.
    for (int col = 0; col < N; col++){
        // Using a function to check if it is
        // possible to place a queen in the cell
        // (row, col) such that it does not attack
        // any other queen.
        if(isSafe(board, row, col, N)){
            // If found true, place a queen in the 
            // cell (row, col) and recur for the
            // next row.
            board[row][col] = 'Q';
            
            if (solutionExists(board, N, row + 1))
                return true;

            // This statement will execute only if placing queen in cell (row, col) do not 
            // form any solution. Hence, we will consider
            // to leave this cell empty.
            board[row][col] = '.';
        }
    }

    // Returning false if we do not find any valid
    // Solution.
    return false;
}


// Function to Solve the NQueen Problem
void solveNQueenProblem(int N){
    // Defining the board, that will be used to print
    // the result if a solution exists
    char **board = new char*[N];
    // Initializing all its cells to be empty
    // at first.
    for(int i = 0; i < N; i++){
        board[i] = new char[N];
        // '.' Represents empty cell
        for (int j = 0; j < N; j++) 
            board[i][j] = '.';
    }
    // If the solution do not exists
    if(!solutionExists(board, N, 0)){
        cout << "No solution exists for N = " << N << endl;
    } 
    // Otherwise, if the solution exists.
    else{
        cout << "One of the possible solution for N = " 
                        << N << " is - " << endl;
        printSolution(board, N);
    }
}
int main() {
    int N ;
    // Defining the dimension of square board.
    cout<<"Enter the value of N : ";
    cin>>N;
    // Calling function to solve the
    // N queen problem for the given N.
    solveNQueenProblem(N);
}
