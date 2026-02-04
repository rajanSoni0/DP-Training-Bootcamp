#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> dp;
    long long helper(vector<long long>& arr, int i, int n) {
        if(i == n - 1) return arr[i];
        if(i == n - 2) return max(arr[i], arr[i + 1]);
        if(dp[i] != -1) return dp[i];
        long long money2 = helper(arr, i + 2, n) + arr[i];
        long long money1 = helper(arr, i + 1, n);

        return dp[i] = max(money1, money2);
    }

long long solve(vector<int>&nums) {
    int n = nums.size();
    int max_ele = *max_element(nums.begin(), nums.end());
    vector<long long> arr(max_ele + 1, 0);
    for (int num : nums) {
        arr[num] += num;
    }
    dp.assign(max_ele + 1, -1);
    return helper(arr, 0, max_ele + 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums[i] = num;
    }
    cout << solve(nums);
}