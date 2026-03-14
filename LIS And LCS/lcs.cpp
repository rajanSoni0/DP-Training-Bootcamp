#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            else {
                int exc1 = dp[i][j + 1];
                int exc2 = dp[i + 1][j];
                dp[i][j] = max(exc1, exc2);
            }
        }
    }

    return dp[0][0];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << lcs(s1, s2) << endl;

    return 0;
}
