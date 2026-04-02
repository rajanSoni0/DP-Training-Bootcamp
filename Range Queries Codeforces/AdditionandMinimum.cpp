#include<bits/stdc++.h>
using namespace std;

vector<long long> lazy;
vector<long long> st;

long long query(int start, int end, int i, int l, int r) {
    if (lazy[i] != 0) {
        st[i] += lazy[i];
        if (l != r) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    if (l > end || r < start) return LLONG_MAX;

    if (l >= start && r <= end) return st[i];

    int mid = l + (r - l) / 2;
    return min(query(start, end, 2*i+1, l, mid),
               query(start, end, 2*i+2, mid+1, r));
}

void update(int i, int l, int r, int start, int end, int val) {
    if (lazy[i] != 0) {
        st[i] += lazy[i];
        if (l != r) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    if (l > end || r < start) return;

    if (start <= l && r <= end) {
        st[i] += val;
        if (l != r) {
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        return;
    }

    int mid = l + (r - l) / 2;
    update(2*i+1, l, mid, start, end, val);
    update(2*i+2, mid+1, r, start, end, val);
    st[i] = min(st[2*i+1], st[2*i+2]);
}

int main() {
    int n, q;
    cin >> n >> q;

    st.assign(4*n, 0);
    lazy.assign(4*n, 0);

    while (q--) {
        int q_type;
        cin >> q_type;
        if (q_type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            update(0, 0, n - 1, l, r - 1, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(l, r - 1, 0, 0, n - 1) << endl;
        }
    }
    return 0;
}