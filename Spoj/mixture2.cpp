#include <iostream>
#include <vector>
#include <climits>
#include<cstring>
using namespace std;

int dp[101][101];
int smokeCal[101][101];
int solve(vector<int> &arr, int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left = solve(arr, i, k);
        int right = solve(arr, k + 1, j);
        int smoke = smokeCal[i][k] * smokeCal[k + 1][j] + left + right;
        ans = min(ans, smoke);
    }

    return dp[i][j] = ans;
}

int main()
{
    int n;
    while (cin >> n)
    {
        memset(dp, -1, sizeof(dp));
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < n; i++) {
            int curr_sum = 0;
            for(int j = i; j < n; j++) {
                curr_sum = (curr_sum + arr[j]) % 100;
                smokeCal[i][j] = curr_sum;
            }
        }
        cout << solve(arr, 0, n - 1) << endl;
    }
    return 0;
}
