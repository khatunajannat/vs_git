/// Queens behave like rooks — only same row/column matters, diagonals are totally ignored.
#include <iostream>
using namespace std;

int n;
int board[20];
int solutionCount = 0;

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col)
            return false;
        // ---- CHANGED ----
        // Diagonal check removed entirely — only column conflicts matter now.
        // -----------------
    }
    return true;
}

void printBoard()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << (board[i] == j ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

void solve(int row)
{
    if (row == n)
    {
        solutionCount++;
        cout << "Solution " << solutionCount << ":" << endl;
        printBoard();
        return;
    }
    for (int col = 0; col < n; col++)
        if (isSafe(row, col))
        {
            board[row] = col;
            solve(row + 1);
        }
}

int main()
{
    cout << "Enter the value of N: ";
    cin >> n;
    if (n <= 0 || n > 20)
    {
        cout << "Please enter a value between 1 and 20." << endl;
        return 1;
    }
    solve(0);
    cout << "Total solutions: " << solutionCount << endl;
    return 0;
}
