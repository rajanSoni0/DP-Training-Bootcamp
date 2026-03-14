#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    int mod = 1e9 + 7;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            grid[i][j] = ch;
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    if(grid[n - 1][n - 1] == '*' || grid[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    }
    dp[n - 1][n - 1] = 1;

    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(i == n - 1 && j == n - 1) continue;
            if(grid[i][j] == '*') {
                dp[i][j] = 0;
            }
            else {
                long long down = (i + 1 < n) ? dp[i + 1][j] : 0;
                long long right = (j + 1 < n) ? dp[i][j + 1] : 0;
                dp[i][j] = (down + right) % mod;
            }
        }
    }
    cout << dp[0][0] << endl;
}