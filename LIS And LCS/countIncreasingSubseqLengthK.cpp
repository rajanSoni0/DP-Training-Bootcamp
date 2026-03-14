#include <iostream>
#include <vector>
using namespace std;

long long countIncreasingSubseqLengthK(vector<int>& arr, int K) {
    int n = arr.size();

    vector<vector<long long>> dp(n, vector<long long>(K + 1, 0));

    for(int i = 0; i < n; i++) {
        dp[i][1] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                for(int l = 2; l <= K; l++) {
                    dp[i][l] += dp[j][l - 1];
                }
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += dp[i][K];
    }

    return ans;
}

int main() {
    int n, K;
    cin >> n >> K;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countIncreasingSubseqLengthK(arr, K) << endl;

    return 0;
}
