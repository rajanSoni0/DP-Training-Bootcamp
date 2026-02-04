#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int helper(vector<int> &skill, vector<int> &time, int t, int idx, int k) {
    if(t < 0 || k < 0 || (idx >= skill.size() && k > 0)) return -1e9;
    if(k == 0) return 0;
    int gain = 0;
    
    gain = max(gain, helper(skill, time, t - time[idx], idx + 1, k - 1) + skill[idx]);
    gain = max(gain, helper(skill, time, t, idx + 1, k));
    
    return gain;
}

int main() {
    vector<int> skill = {5,2,1,4,3};
    vector<int> time = {3,4,2,6,2};
    int t = 5, k = 2;
    cout << helper(skill, time, t, 0, k);
}