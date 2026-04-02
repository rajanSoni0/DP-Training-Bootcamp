#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void buildTree(vector<pair<int, int>> &st, vector<int> &arr, int i, int l, int r) {
    if(l == r) {
        st[i] = {arr[l], 1};
        return;
    }
    int mid = l + (r - l) / 2;

    buildTree(st, arr, 2*i+1, l, mid);
    buildTree(st, arr, 2*i+2, mid + 1, r);
    int mini = min(st[2*i+1].first, st[2*i+2].first);
    int freq = st[2*i+1].first == st[2*i+2].first ? st[2*i+1].second + st[2*i+2].second : (st[2*i+1].first < st[2*i+2].first ? st[2*i+1].second : st[2*i+2].second);

    st[i] = {mini, freq};
}

pair<int, int> query(vector<pair<int, int>> &st, int start, int end, int i, int l, int r) {
    if(l > end || r < start) {
        return {INT_MAX, 0};
    }

    if(l >= start && r <= end) return st[i];

    int mid = l + (r - l) / 2;

    auto left = query(st, start, end, 2*i+1, l, mid);
    auto right = query(st, start, end, 2*i+2, mid+1, r);

    int mini = min(left.first, right.first);
    int freq = 0;

    if(left.first == right.first) {
        freq = left.second + right.second;
    } else if(left.first < right.first) {
        freq = left.second;
    } else {
        freq = right.second;
    }

    return {mini, freq};
}

void update(vector<pair<int, int>> &st, int i, int l, int r, int idx, int val) {
    if(l == r) {
        st[i] = {val, 1};
        return;
    }

    int mid = l + (r - l) / 2;

    if(idx <= mid) {
        update(st, 2*i+1, l, mid, idx, val);
    } else {
        update(st, 2*i+2, mid+1, r, idx, val);
    }

    int mini = min(st[2*i+1].first, st[2*i+2].first);
    int freq;

    if(st[2*i+1].first == st[2*i+2].first) {
        freq = st[2*i+1].second + st[2*i+2].second;
    } 
    else if(st[2*i+1].first < st[2*i+2].first) {
        freq = st[2*i+1].second;
    } 
    else {
        freq = st[2*i+2].second;
    }

    st[i] = {mini, freq};
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<pair<int, int>> st(4*n, {INT_MAX, 1});
    buildTree(st, arr, 0, 0, n - 1);
    while(m--) {
        int q_type;
        cin >> q_type;
        if(q_type == 1) {
            int idx, val;
            cin >> idx >> val;
            update(st, 0, 0, n - 1, idx, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            auto ans = query(st, l, r - 1, 0, 0, n - 1);
            cout << ans.first << " " << ans.second << endl;
        }
    }
    return 0;
}