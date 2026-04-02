#include <bits/stdc++.h>
using namespace std;

#define int long long


struct segtree {
    int n;
    vector<int> tree;

    segtree(int n) {
        this->n = n;
        tree.resize(4*n, 0);
    }

    void update(int idx, int val, int node, int l, int r) {
        if(l == r) {
            tree[node] += val;
            return;
        }
        int mid = (l + r)/2;

        if(idx <= mid) update(idx, val, 2*node, l, mid);
        else update(idx, val, 2*node+1, mid+1, r);

        tree[node] = tree[2*node] + tree[2*node+1];
    }

    int query(int ql, int qr, int node, int l, int r) {
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return tree[node];

        int mid = (l + r)/2;
        return query(ql, qr, 2*node, l, mid) +
               query(ql, qr, 2*node+1, mid+1, r);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    // collect all values
    vector<int> comp;
    for(auto x : p) comp.push_back(x);

    vector<pair<char, pair<int,int>>> queries;

    for(int i = 0; i < q; i++) {
        char type;
        cin >> type;

        if(type == '!') {
            int k, x;
            cin >> k >> x;
            k--;
            queries.push_back({type, {k, x}});
            comp.push_back(x);
        } else {
            int a, b;
            cin >> a >> b;
            queries.push_back({type, {a, b}});
            comp.push_back(a);
            comp.push_back(b);
        }
    }

    // compression
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    auto get = [&](int x) {
        return lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;
    };

    int m = comp.size();
    segtree st(m);

    // initial build
    for(int i = 0; i < n; i++) {
        st.update(get(p[i]), 1, 1, 1, m);
    }

    // process queries
    for(auto &qq : queries) {
        if(qq.first == '!') {
            int k = qq.second.first;
            int x = qq.second.second;

            // remove old
            st.update(get(p[k]), -1, 1, 1, m);

            // add new
            p[k] = x;
            st.update(get(p[k]), 1, 1, 1, m);

        } else {
            int a = qq.second.first;
            int b = qq.second.second;

            int l = lower_bound(comp.begin(), comp.end(), a) - comp.begin() + 1;
            int r = upper_bound(comp.begin(), comp.end(), b) - comp.begin();

            if(l > r) cout << 0 << '\n';
            else cout << st.query(l, r, 1, 1, m) << '\n';
        }
    }
}