#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

vector<int> st;

void update(int i, int l, int r, int pos, int val) {
    if(l == r) {
        st[i] += val;
        return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid) update(2*i+1, l, mid, pos, val);
    else update(2*i+2, mid+1, r, pos, val);

    st[i] = st[2*i+1] + st[2*i+2];
}

int query(int i, int l, int r, int ql, int qr) {
    if(r < ql || l > qr) return 0;
    if(ql <= l && r <= qr) return st[i];

    int mid = (l + r) / 2;
    int left_sum = query(2*i+1, l, mid, ql, qr);
    int right_sum = query(2*i+2, mid+1, r, ql, qr);
    return left_sum + right_sum;
}

int main() {
    int m, q;
    cin >> m >> q;

    vector<int> arr(m);
    vector<int> comp;
    vector<vector<int>> queries(q, vector<int>(3));

    for(int i = 0; i < m; i++) {
        cin >> arr[i];
        comp.push_back(arr[i]);
    }

    for(int i = 0; i < q; i++) {
        char ch;
        int k, x;
        cin >> ch >> k >> x;

        if(ch == '!') {
            queries[i] = {0, k, x};
        } else {
            queries[i] = {1, k, x};
            
        }
        comp.push_back(k);
        comp.push_back(x);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    st.assign(4 * comp.size(), 0);

    for(int i = 0; i < m; i++) {
        int idx = lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin();
        update(0, 0, comp.size()-1, idx, 1);
    }

    for(auto &qr : queries) {
        if(qr[0] == 0) {
            int k = qr[1] - 1;
            int x = qr[2];

            int oldIdx = lower_bound(comp.begin(), comp.end(), arr[k]) - comp.begin();
            update(0, 0, comp.size()-1, oldIdx, -1);

            arr[k] = x;

            int newIdx = lower_bound(comp.begin(), comp.end(), x) - comp.begin();
            update(0, 0, comp.size()-1, newIdx, 1);

        } else {
            int a = qr[1];
            int b = qr[2];

            int left = lower_bound(comp.begin(), comp.end(), a) - comp.begin();
            int right = lower_bound(comp.begin(), comp.end(), b) - comp.begin();

            cout << query(0, 0, comp.size()-1, left, right) << endl;
        }
    }
}