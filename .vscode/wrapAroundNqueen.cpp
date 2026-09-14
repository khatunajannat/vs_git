/// Variant 3: Toroidal (wrap-around) N-Queens
/// A tougher but still approachable twist — the board wraps around like a cylinder, so diagonals that go "off the edge" reappear on the other side.
///  A queen attacks diagonally using wrapped column distance too.
#include <iostream>
#include <cstdlib>
using namespace std;

int n;
int board[20];
int solutionCount = 0;

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int placedCol = board[i];

        if (placedCol == col)
            return false;

        int colDiff = abs(placedCol - col);
        int rowDiff = abs(i - row);
        int wrappedColDiff = n - colDiff;

        if (colDiff == rowDiff || wrappedColDiff == rowDiff)
            return false;
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
    if (solutionCount == 0)
        cout << "No solution exists (toroidal board)." << endl;
    else
        cout << "Total solutions: " << solutionCount << endl;
    return 0;
}