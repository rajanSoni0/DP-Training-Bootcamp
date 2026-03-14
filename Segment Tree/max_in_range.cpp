#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
vector<int> st;
void buildTree(vector<int> &arr, int low, int high, int idx) {
    if(low == high) {
        st[idx] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    buildTree(arr, low, mid, idx * 2 + 1);
    buildTree(arr, mid + 1, high, idx * 2 + 2);

    st[idx] = max(st[idx * 2 + 1], st[idx * 2 + 2]);
}

int getMax(vector<int> st, int i, int low, int high, int &l, int &r) {
    if(l > high || r < low) return INT_MIN;
    if(low >= l && high <= r) return st[i];
    int mid = low + (high - low) / 2;

    int leftMax = getMax(st, i * 2 + 1, low, mid, l, r);
    int rightMax = getMax(st, i * 2 + 2, mid + 1, high, l, r);
    return max(leftMax, rightMax);

}

int main() {
    vector<int> arr = {4, 1, 2, 8, 6, 4, 9, 3};
    int n = arr.size();
    st.assign(4 * n, 0);
    buildTree(arr, 0, n - 1, 0);
    int t;
    cin >> t;
    while(t--) {
        cout << endl << "Enter low and high: ";
        int l, r;
        cin >> l >> r;
        cout << getMax(st, 0, 0, n - 1, l, r);
    }
}