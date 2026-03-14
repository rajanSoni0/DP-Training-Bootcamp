#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> lis(vector<int> &arr) {
    int n = arr.size();
    int max_len = 1;
    vector<int> dp;
    vector<int> temp(n);
    for(int i = 0; i < n; i++) {
        if(dp.empty() || dp.back() < arr[i]) {
            dp.push_back(arr[i]);
            temp[i] = dp.size() - 1;
        }
        else {
            int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[idx] = arr[i];
            temp[i] = idx;
        }
    }

    vector<int> ans;
    int len = dp.size() - 1;
    for(int i = n - 1; i >= 0; i--) {
        if(temp[i] == len) {
            ans.push_back(arr[i]);
            len--;
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
    
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
    vector<int> ans = lis(arr);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

}