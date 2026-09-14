/// N queens all possible solution... Right diagonal acceptable
#include <iostream>
#include <cstdlib> // for abs()
using namespace std;

int n;
int board[20];
int solutionCount = 0; // counts total solutions

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int placedCol = board[i];

        // Check same column
        if (placedCol == col)
            return false;

        if ((i - placedCol) == (row - col))
            return false;
        // -----------------
    }
    return true;
}

// Function to print the board when a solution is found
void printBoard()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// Backtracking function to solve N-Queens
void solve(int row)
{
    // If all queens are placed, print the solution
    if (row == n)
    {
        solutionCount++;
        cout << "Solution " << solutionCount << ":" << endl;
        printBoard();
        return;
    }

    // Try placing queen in each column of this row
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col; // place queen
            solve(row + 1);   // move to next row
            // no need to "remove" queen, it gets overwritten next time
        }
    }
}

int main()
{
    cout << "Enter the value of N: ";
    cin >> n;

    // Input validation to prevent buffer overrun on board[20]
    if (n <= 0 || n > 20)
    {
        cout << "Please enter a value between 1 and 20." << endl;
        return 1;
    }

    solve(0);

    if (solutionCount == 0)
        cout << "No solution exists." << endl;
    else
        cout << "Total solutions: " << solutionCount << endl;

    return 0;
}
