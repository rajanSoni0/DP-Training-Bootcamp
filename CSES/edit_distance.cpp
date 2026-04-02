#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> dp;
int m, n;
int solve(string &s1, string &s2, int i, int j) {
    if(i == m) return n - j;
    if(j == n) return m - i;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]) return dp[i][j] = solve(s1, s2, i + 1, j + 1);
    // Insert
    int insert = solve(s1, s2, i, j + 1);
    // Delete
    int Delete = solve(s1, s2, i + 1, j);
    // Replace
    int replace = solve(s1, s2, i + 1, j + 1);

    return dp[i][j] = min({insert, Delete, replace}) + 1;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    m = s1.size();
    n = s2.size();
    dp.assign(m, vector<int>(n, -1));
    cout << solve(s1, s2, 0, 0) << endl;
}