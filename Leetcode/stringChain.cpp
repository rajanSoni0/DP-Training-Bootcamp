#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkPossible(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)
        {
            return false;
        }
        else
        {
            int first = 0, second = 0;
            while (first < s1.size())
            {
                if (s1[first] == s2[second])
                {
                    first++;
                    second++;
                }
                else
                {
                    first++;
                }
            }
            if (first == s1.size() && second == s2.size())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    static bool cmp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        sort(arr.begin(), arr.end(), cmp);
        for (int i = 1; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (checkPossible(arr[i], arr[prev]) && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};