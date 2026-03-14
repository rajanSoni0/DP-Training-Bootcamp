#include <iostream>
#include <vector>
using namespace std;

int LongestBitonicSequence(int n, vector<int> &nums) {
    vector<int> dp1(n, 1), dp2(n, 1);
    int maxi = 0;

    for(int i = 0; i < n; i++) {
        for(int prev = 0; prev < i; prev++) {
            if(nums[prev] < nums[i] && dp1[prev] + 1 > dp1[i]) {
                dp1[i] = dp1[prev] + 1;
            }
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int prev = n - 1; prev > i; prev--) {
            if(nums[prev] < nums[i] && dp2[prev] + 1 > dp2[i]) {
                dp2[i] = dp2[prev] + 1;
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    return maxi;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << LongestBitonicSequence(n, nums) << endl;

    return 0;
}
