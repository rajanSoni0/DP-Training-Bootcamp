#include<iostream>
#include<vector>
using namespace std;

void buildTree(vector<int> &st, vector<int> &arr, int i, int l, int r) {
    if(l == r) {
        st[i] = l;
        return;
    }

    int mid = (l + r) / 2;
    buildTree(st, arr, 2*i + 1, l, mid);
    buildTree(st, arr, 2*i + 2, mid + 1, r);

    int left = st[2*i + 1];
    int right = st[2*i + 2];

    st[i] = (arr[left] >= arr[right] ? left : right);
}

int query(int i, int l, int r, int val, vector<int> &st, vector<int> &arr) {
    if (arr[st[i]] < val) return -1;

    if (l == r) return l;

    int mid = (l + r) / 2;

    int leftIdx = st[2*i + 1];

    if (arr[leftIdx] >= val)
        return query(2*i + 1, l, mid, val, st, arr);
    else
        return query(2*i + 2, mid + 1, r, val, st, arr);
}

void update(vector<int> &st, vector<int> &arr, int i, int l, int r, int idx, int val) {
    if (l == r) {
        arr[idx] -= val;
        st[i] = idx;
        return;
    }

    int mid = (l + r) / 2;

    if (idx <= mid)
        update(st, arr, 2*i + 1, l, mid, idx, val);
    else
        update(st, arr, 2*i + 2, mid + 1, r, idx, val);

    int left = st[2*i + 1];
    int right = st[2*i + 2];

    st[i] = (arr[left] >= arr[right] ? left : right);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> st(4*n);
    buildTree(st, arr, 0, 0, n-1);

    while(m--) {
        int room;
        cin >> room;

        int idx = query(0, 0, n-1, room, st, arr);

        if(idx == -1) {
            cout << 0 << " ";
        } else {
            cout << idx + 1 << " ";
            update(st, arr, 0, 0, n-1, idx, room);
        }
    }

    return 0;
}