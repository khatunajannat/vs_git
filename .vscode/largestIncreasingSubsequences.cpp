#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1); // every element is an LIS of length 1 by itself

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLen = 0;
    for (int i = 0; i < n; i++)
        maxLen = max(maxLen, dp[i]);

    return maxLen;
}

int main()
{
    vector<int> arr1 = {3, 10, 2, 1, 20};
    vector<int> arr2 = {6, 7, 1, 2, 3, 4, 5};

    cout << "LIS length: " << LIS(arr1) << endl; // Output: 3
    cout << "LIS length: " << LIS(arr2) << endl; // Output: 5

    return 0;
}