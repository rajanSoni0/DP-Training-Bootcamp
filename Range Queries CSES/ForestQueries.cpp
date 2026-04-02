#include<iostream>
#include<vector>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> grid(n + 1, vector<int> (n + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            if(ch == '*') {
                grid[i][j] = 1;
            }
        }
    }

    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i][j];
        }
    }

    while(q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int ans = dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1];
        cout << ans << endl;
    }
    return 0;

}