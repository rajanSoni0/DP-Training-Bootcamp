#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> dp;
int solve(vector<vector<int>> &arr, int last, int i, int n) {
    if(i == n) return 0;

    if(dp[i][last] != -1) return dp[i][last];

    if(last == 0) {
        return dp[i][last] = max(solve(arr, 1, i + 1, n) + arr[i][1], solve(arr, 2, i + 1, n) + arr[i][2]);
    }
    if(last == 1) {
        return dp[i][last] = max(solve(arr, 0, i + 1, n) + arr[i][0], solve(arr, 2, i + 1, n) + arr[i][2]);
    }

    if(last == 2) {
        return dp[i][last] = max(solve(arr, 1, i + 1, n) + arr[i][1], solve(arr, 0, i + 1, n) + arr[i][0]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int> (3, 0));
    dp.assign(n, vector<int> (3, -1));
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i][0] = a;
        arr[i][1] = b;
        arr[i][2] = c;
    }
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        ans = max(ans,  solve(arr, i, 1, n) + arr[0][i]);
    }
    cout << ans << endl;
}