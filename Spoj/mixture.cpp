#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<int, int> dp[101][101];
pair<int, int> solve(vector<int> &arr, int i, int j)
{
    if (i == j)
        return {arr[i], 0};

    if (dp[i][j].second != -1)
        return dp[i][j];

    pair<int, int> ans = {0, INT_MAX};

    for (int k = i; k < j; k++)
    {
        auto left = solve(arr, i, k);
        auto right = solve(arr, k + 1, j);

        int newColor = (left.first + right.first) % 100;
        int smoke = left.first * right.first + left.second + right.second;

        if (smoke < ans.second)
            ans = {newColor, smoke};
    }

    return dp[i][j] = ans;
}

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                dp[i][j] = {0, -1};
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << solve(arr, 0, n - 1).second << endl;
    }
    return 0;
}
