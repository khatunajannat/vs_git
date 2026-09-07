#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Global-ish tables passed by reference
void LCSLength(string X, string Y, vector<vector<int>> &c, vector<vector<char>> &b)
{
    int m = X.length();
    int n = Y.length();

    // Resize tables to (m+1) x (n+1), 1-indexed usage
    c.assign(m + 1, vector<int>(n + 1, 0));
    b.assign(m + 1, vector<char>(n + 1, ' '));

    // Base cases (row 0 and column 0 already 0 from assign)
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'D'; // Diagonal (was "\" arrow)
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U'; // Up
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L'; // Left
            }
        }
    }
}

void printLCS(vector<vector<char>> &b, string X, int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == 'D')
    {
        printLCS(b, X, i - 1, j - 1);
        cout << X[i - 1];
    }
    else if (b[i][j] == 'U')
    {
        printLCS(b, X, i - 1, j);
    }
    else
    {
        printLCS(b, X, i, j - 1);
    }
}

int main()
{
    string X, Y;
    cout << "Enter string X: ";
    cin >> X;
    cout << "Enter string Y: ";
    cin >> Y;

    vector<vector<int>> c;
    vector<vector<char>> b;

    LCSLength(X, Y, c, b);

    int m = X.length();
    int n = Y.length();

    cout << "Length of LCS: " << c[m][n] << endl;
    cout << "LCS: ";
    printLCS(b, X, m, n);
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Global-ish tables passed by reference
void LCSLength(string X, string Y, vector<vector<int>> &c, vector<vector<char>> &b)
{
    int m = X.length();
    int n = Y.length();

    // Resize tables to (m+1) x (n+1), 1-indexed usage
    c.assign(m + 1, vector<int>(n + 1, 0));
    b.assign(m + 1, vector<char>(n + 1, ' '));

    // Base cases (row 0 and column 0 already 0 from assign)
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'D'; // Diagonal (was "\" arrow)
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U'; // Up
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L'; // Left
            }
        }
    }
}

void printLCS(vector<vector<char>> &b, string X, int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == 'D')
    {
        printLCS(b, X, i - 1, j - 1);
        cout << X[i - 1];
    }
    else if (b[i][j] == 'U')
    {
        printLCS(b, X, i - 1, j);
    }
    else
    {
        printLCS(b, X, i, j - 1);
    }
}

int main()
{
    string X, Y;
    cout << "Enter string X: ";
    cin >> X;
    cout << "Enter string Y: ";
    cin >> Y;

    vector<vector<int>> c;
    vector<vector<char>> b;

    LCSLength(X, Y, c, b);

    int m = X.length();
    int n = Y.length();

    cout << "Length of LCS: " << c[m][n] << endl;
    cout << "LCS: ";
    printLCS(b, X, m, n);
    cout << endl;

    return 0;
}