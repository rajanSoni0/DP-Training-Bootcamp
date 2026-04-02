#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &v1, vector<int> &v2) {
    if(v1[0] == -1) return v2;
    if(v2[0] == -1) return v1;

    map<int, int> freq;

    freq[v1[0]] += v1[1];
    if(v1[2] != -1) freq[v1[2]] += v1[3];

    freq[v2[0]] += v2[1];
    if(v2[2] != -1) freq[v2[2]] += v2[3];

    auto it = freq.rbegin();

    int first_max = it->first;
    int first_freq = it->second;
    it++;

    int second_max = -1;
    int second_freq = 0;

    if(it != freq.rend()) {
        second_max = it->first;
        second_freq = it->second;
    }

    return {first_max, first_freq, second_max, second_freq};
}


void buildTree(vector<vector<int>> &st, vector<int> &arr, int i , int l, int r) {
    if(l == r) {
        st[i] = {arr[l], 1, -1, 0};
        return;
    }

    int mid = l + (r - l) / 2;

    buildTree(st, arr, 2*i+1, l, mid);
    buildTree(st, arr, 2*i+2, mid + 1, r);

    auto v1 = st[2*i+1], v2 = st[2*i+2];

    vector<int> temp = merge(v1, v2);
    st[i] = temp;

}

vector<int> query(vector<vector<int>> &st, int ql, int qr, int i, int l, int r) {
    if(l > qr || r < ql) return {-1, 0, -2, 0};
    if(l >= ql && r <= qr) return st[i];

    int mid = l + (r - l) / 2;

    auto v1 = query(st, ql, qr, 2*i+1, l, mid);
    auto v2 = query(st, ql, qr, 2*i+2, mid + 1, r);

    return merge(v1, v2);
}

void update(vector<vector<int>> &st, int idx, int val, int i, int l, int r) {
    if(l == r) {
        st[i] = {val, 1, -1, 0};
        return;
    }

    int mid = l + (r - l) / 2;
    if(idx <= mid) {
        update(st, idx, val, 2*i+1, l, mid);
    }
    else {
        update(st, idx, val, 2*i+2, mid + 1, r);
    }

    auto v1 = st[2*i+1], v2 = st[2*i+2];

    vector<int> temp = merge(v1, v2);
    st[i] = temp;

}


int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> st(4 * n, {-1, 0, -2, 0});
    buildTree(st, arr, 0, 0, n - 1);
    while(q--) {
        int q_type;
        cin >> q_type;
        if(q_type == 1) {
            int p, x;
            cin >> p >> x;
            update(st, p - 1, x, 0, 0, n - 1);
        }
        else {
            int ql, qr;
            cin >> ql >> qr;
            cout << query(st, ql - 1, qr - 1, 0, 0, n - 1)[3] << endl;
        }
    }
    return 0;
}