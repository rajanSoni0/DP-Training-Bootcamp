#include<iostream>
#include<vector>
using namespace std;

int query(vector<int> &st, int start, int end, int i, int l, int r) {
    if(l > end || r < start) return 0;
    if(start <= l && r <= end) return st[i];

    int mid = l + (r - l) / 2;
    return query(st, start, end, 2*i+1, l, mid) + query(st, start, end, 2*i+2, mid+1, r);
}

void update(vector<int> &st, int i, int l, int r, int idx) {
    if(l == r) {
        st[i]++;
        return;
    }

    int mid = l + (r - l) / 2;
    if(idx <= mid) update(st, 2*i+1, l, mid, idx);
    else update(st, 2*i+2, mid+1, r, idx);

    st[i] = st[2*i+1] + st[2*i+2];
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> st(4 * n, 0);

    for(int i = 0; i < n; i++) {
        int res = 0;

        if(arr[i] < n) {
            res = query(st, arr[i] + 1, n, 0, 1, n);
        }

        cout << res << " ";
        update(st, 0, 1, n, arr[i]);
    }
}