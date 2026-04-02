#include<iostream>
#include<vector>
using namespace std;
void buildTree(vector<long long> &st, vector<long long> &arr, int i, int l, int r) {
    if(l == r) {
        st[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildTree(st, arr, 2 * i + 1, l, mid);
    buildTree(st, arr, 2 * i + 2, mid + 1, r);

    long long left = st[2 * i + 1], right = st[2 * i + 2];
    st[i] = left ^ right;
}

long long getSum(int start, int end, int i, int l, int r, vector<long long> &st) {
    if(l > end || r < start) {
        return 0;
    }

    if(l >= start && r <= end) {
        return st[i];
    }

    int mid = l + (r - l) / 2;
    long long left = getSum(start, end, 2 * i + 1, l, mid, st);
    long long right = getSum(start, end, 2 * i + 2, mid + 1, r, st);

    return left ^ right;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        arr[i] = num;
    }

    vector<long long> st(4 * n, 0);
    buildTree(st, arr, 0, 0, n - 1);

    while(q--) {
        int l, r;
        cin >> l >> r;

        cout << getSum(l - 1, r - 1, 0, 0, n - 1, st) << endl;
    }
    return 0;
}