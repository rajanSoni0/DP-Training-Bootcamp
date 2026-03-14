#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int lis(vector<int> &arr) {
    int n = arr.size();
    int max_len = 1;
    vector<int> dp;
    for(int i = 0; i < n; i++) {
        if(dp.empty() || dp.back() < arr[i]) {
            dp.push_back(arr[i]);
        }
        else {
            int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[idx] = arr[i];
        }
    }
    return dp.size();
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