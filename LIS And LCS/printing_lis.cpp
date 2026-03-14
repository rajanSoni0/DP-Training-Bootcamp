#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> printLis(vector<int> &arr) {
    int n = arr.size();
    int max_len = 1;
    int lastIndex = 0;
    vector<int> dp(n, 1);
    vector<int> parent(n, -1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if(dp[i] > max_len) {
            max_len = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> lis;
    while(lastIndex != -1) {
        lis.push_back(arr[lastIndex]);
        lastIndex = parent[lastIndex];
    }

    reverse(lis.begin(), lis.end());
    return lis;
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
    vector<int> ans = printLis(arr);
    for(int num : ans) {
        cout << num << " ";
    }
    return 0;
}