#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int solve(int n) {
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    vector<int> digits;
    int temp = n;
    while(temp) {
        digits.push_back(temp % 10);
        temp /= 10;
    }
    int moves = INT_MAX;
    for(int digit : digits) {
        if(digit == 0) continue;
        moves = min(moves, 1 + solve(n - digit));
    }
    return dp[n] = moves;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    dp.assign(n + 1, -1);
    cout << solve(n) << endl;
    
}