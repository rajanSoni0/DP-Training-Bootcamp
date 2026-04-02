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


int min_query(int start, int end, int i, int l, int r, vector<int> &st) {
    if(l > end || r < start) {
        return INT_MAX;
    }

    if(l >= start && r <= end) {
        return st[i];
    }

    int mid = l + (r - l) / 2;

    int leftmin = min_query(start, end, 2 * i + 1, l, mid, st);
    int rightmin = min_query(start, end, 2 * i + 2, mid + 1, r, st);

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
        int l, r;
        cin >> l >> r;
        int mini = min_query(l - 1, r - 1, 0, 0, n - 1, st);
        cout << mini << endl;
    }
    return 0;
}