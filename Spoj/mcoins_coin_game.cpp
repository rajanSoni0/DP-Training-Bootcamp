#include<iostream>
#include<vector>
#include<string>
using namespace std;

void buildDp(vector<bool> &dp, int k, int l) {
    dp[0] = false;
    dp[1] = dp[k] = dp[l] = true;
    for(int i = 2; i <= 1000000; i++) {
        if(dp[i]) continue;
        
        if(i - l >= 0) {
            dp[i] = !(dp[i - 1] && dp[i - l] && dp[i - k]);
        }
        else if(i - k >= 0) {
            dp[i] = !(dp[i - 1] && dp[i - k]);
        }
        else {
            dp[i] = !dp[i - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k, l, m;
    cin >> k >> l >> m;
    vector<bool> dp (1000001, false);
    buildDp(dp, k, l);
    string ans;
    while(m--) {
        int n;
        cin >> n;
        if(dp[n]) {
            ans.push_back('A');
        }
        else {
            ans.push_back('B');
        }
    }
    cout << ans << endl;
    return 0;
}