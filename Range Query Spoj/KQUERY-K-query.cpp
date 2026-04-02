#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<vector<int>> st;
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    int l = 0, r = 0;
    int n = left.size(), m = right.size();

    vector<int> res;
    res.reserve(n + m);

    while (l < n && r < m) {
        if (left[l] <= right[r]) {
            res.push_back(left[l]);
            l++;
        } else {
            res.push_back(right[r]);
            r++;
        }
    }

    while (l < n) {
        res.push_back(left[l]);
        l++;
    }

    while (r < m) {
        res.push_back(right[r]);
        r++;
    }

    return res;
}

void buildTree(int i, int l, int r) {
    if(l == r) {
        st[i] = {arr[l]};
        return;
    }

    int mid = l + (r - l) / 2;
    buildTree(2*i+1, l, mid);
    buildTree(2*i+2, mid + 1, r);

    st[i] = merge(st[2*i+1], st[2*i+2]);
}

int query(int ql, int qr, int k, int i, int l, int r) {
    if(l > qr || r < ql) return 0;

    if(l >= ql && r <= qr) {
        int sz = st[i].size();
        int smaller_count = upper_bound(st[i].begin(), st[i].end(), k) - st[i].begin();
        return sz - smaller_count;
    }

    int mid = l + (r - l) / 2;

    return query(ql, qr, k, 2*i+1, l, mid) +
           query(ql, qr, k, 2*i+2, mid + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    st.resize(4 * n);
    buildTree(0, 0, n - 1);

    int q;
    cin >> q;
    while(q--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << query(i - 1, j - 1, k, 0, 0, n - 1) << endl;
    }

    return 0;
}