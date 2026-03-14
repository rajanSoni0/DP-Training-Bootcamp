#include <iostream>
#include <vector>
#include <climits>
#include<cstring>
using namespace std;
long long costArray[401][401];
long long dp[401][401];
long long solve(int i, int j, vector<int> &arr) {
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    long long min_cost =  LLONG_MAX;
    for(int k = i; k < j; k++) {
        long long left = solve(i, k, arr);
        long long right = solve(k + 1, j, arr);
        long long cost = costArray[i][k] + costArray[k + 1][j] + left + right;
        min_cost = min(min_cost, cost);
    }
    return dp[i][j] = min_cost;

}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[i] = num;
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) {
        long long sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            costArray[i][j] = sum;
        }
    }
    cout<< solve(0, n - 1, arr);    
}