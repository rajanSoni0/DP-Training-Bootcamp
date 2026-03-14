#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

vector<vector<long long>> dp;
long long solve(vector<int> &arr, int i, int j) {
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(arr[i] == arr[j]) {
        return dp[i][j] = solve(arr, i + 1, j - 1) + 1;
    }
    return dp[i][j] = min(solve(arr, i + 1, j), solve(arr, i, j - 1)) + 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if(arr.empty() || arr.back() != num) {
            arr.push_back(num);
        }
    }
    dp.assign(arr.size(), vector<long long> (arr.size(), -1));
    cout << solve(arr, 0, arr.size() - 1);
}
