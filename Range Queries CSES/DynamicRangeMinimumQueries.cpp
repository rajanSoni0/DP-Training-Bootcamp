#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void buildTree(vector<int> &st, int i, int l, int r, vector<int> &arr) {
    if(l == r) {
        st[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;

    buildTree(st, 2 * i + 1, l, mid, arr);
    buildTree(st, 2 * i + 2, mid + 1, r, arr);

    st[i] = min(st[2 * i + 1], st[2 * i + 2]);
}

void updateQuery(vector<int> &st, int i, int l, int r, int x, int val) {
    if(l == r) {
        st[i] = val;
        return;
    }

    int mid = l + (r - l) / 2;
    if(x <= mid) {
        updateQuery(st, 2 * i + 1, l, mid, x, val);
    }
    else {
        updateQuery(st, 2 * i + 2, mid + 1, r, x, val);
    }

    st[i] = min(st[2 * i + 1], st[2 * i + 2]);
}

int getmin(int start, int end, int i, int l, int r, vector<int> &st) {
    if(l > end || r < start) {
        return INT_MAX;
    }

    if(l >= start && r <= end) {
        return st[i];
    }

    int mid = l + (r - l) / 2;

    int leftmin = getmin(start, end, 2 * i + 1, l, mid, st);
    int rightmin = getmin(start, end, 2 * i + 2, mid + 1, r, st);

    return min(leftmin, rightmin);
}


int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[i] = num;
    }
    vector<int> st(4 * n, INT_MAX);

    buildTree(st, 0, 0, n - 1, arr);


    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 2) {
            cout << getmin(b - 1, c - 1, 0, 0, n - 1, st) << endl;
        }
        else {
            updateQuery(st, 0, 0, n - 1, b - 1, c);
        }
    }
    return 0;
}