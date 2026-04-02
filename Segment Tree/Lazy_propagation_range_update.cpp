#include <bits/stdc++.h>
using namespace std;

vector<long long> segTree;
vector<long long> lazyTree;

class Solution {
public:
    int bit_count(int x) {
        int count = 0;
        while(x > 0) {
            count++;
            x = x >> 1;
        }
        return count;
    }

    int rangeBitwiseAnd(int left, int right) {

        if(bit_count(left) != bit_count(right)) return 0;

        long long ans = left;

        for(long long i = (long long)left + 1; i <= right; i++) {
            ans &= i;
            if(ans == 0) break;
        }
        
        return ans;
    }
};

void build(vector<int>& arr, int i, int l, int r) {
    if(l == r) {
        segTree[i] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(arr, 2*i+1, l, mid);
    build(arr, 2*i+2, mid+1, r);
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

void updateRange(int start, int end, int i, int l, int r, int val) {
    if (lazyTree[i] != 0) {
        segTree[i] += (r - l + 1) * lazyTree[i];
      
        if (l != r) {
            lazyTree[i * 2 + 1] += lazyTree[i];
            lazyTree[i * 2 + 2] += lazyTree[i];
        }
        lazyTree[i] = 0;
    }

    if (l > end || r < start || l > r)
        return;

    if (l >= start && r <= end) {
        segTree[i] += (r - l + 1) * val;
        if (l != r) {
            lazyTree[i * 2 + 1] += val;
            lazyTree[i * 2 + 2] += val;
        }
        return;
    }

    int mid = (l + r) / 2;
    updateRange(start, end, 2*i+1, l, mid, val);
    updateRange(start, end, 2*i+2, mid+1, r, val);
    segTree[i] = segTree[i * 2 + 1] + segTree[i * 2 + 2];
}

long long query(int start, int end, int i, int l, int r) {
    if (lazyTree[i] != 0) {
        segTree[i] += (r - l + 1) * lazyTree[i];
        if (l != r) {
            lazyTree[i * 2 + 1] += lazyTree[i];
            lazyTree[i * 2 + 2] += lazyTree[i];
        }
        lazyTree[i] = 0;
    }

    if (l > end || r < start || l > r)
        return 0;

    if (l >= start && r <= end)
        return segTree[i];

    int mid = (l + r) / 2;
    return query(start, end, 2*i+1, l, mid) +
           query(start, end, 2*i+2, mid+1, r);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    segTree.resize(4*n, 0);
    lazyTree.resize(4*n, 0);

    build(arr, 0, 0, n-1);

    // Example usage:
    // update range [l, r] with value val
    int l, r, val;
    cin >> l >> r >> val;
    updateRange(l, r, 0, 0, n-1, val);

    // query sum in range [l, r]
    cin >> l >> r;
    cout << query(l, r, 0, 0, n-1) << endl;

    // rangeBitwiseAnd example
    Solution obj;
    int left, right;
    cin >> left >> right;
    cout << obj.rangeBitwiseAnd(left, right) << endl;

    return 0;
}