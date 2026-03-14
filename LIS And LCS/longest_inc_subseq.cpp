#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int lis(vector<int> &arr) {
    int n = arr.size();
    int max_len = 1;
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1); 
            }
        }
        max_len = max(max_len, dp[i]);
    }
    return max_len;
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

    cout << lis(arr) << endl;

}