#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;
int helper(vector<int> &arr, int len, vector<int> &dp) {
    if(len == 0) return 0;
    if(dp[len] != -1) return dp[len];
    int ans = -1e9;
    for(int i = 0; i < 3; i++) {
        if(len - arr[i] >= 0)
            ans = max(ans, helper(arr, len - arr[i], dp) + 1);
    }
    return dp[len] = ans;
}
int main() {
    int n;
    cin >> n;
    vector<int>arr(3, 0);
    vector<int> dp(n + 1, -1);
    for(int i = 0; i < 3; i++) {
        int num;
        cin >> num;
        arr[i] = num;
    }

    cout << helper(arr, n, dp) << endl;
}