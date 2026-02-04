#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    void helper(int n, int i, string &str, vector<string> & ans) {
        if(i >= n) {
            ans.push_back(str);
            return;
        }
        
        str.push_back('0');
        helper(n, i + 1, str, ans);
        str.pop_back();
        
        str.push_back('1');
        helper(n, i + 1, str, ans);
        str.pop_back();
        
    }
    vector<string> binstr(int n) {
        vector<string> ans;
        string str = "";
        helper(n, 0, str, ans);
        return ans;
    }
};