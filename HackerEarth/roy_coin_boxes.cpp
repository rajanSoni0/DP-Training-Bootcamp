#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 2, 0);
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        arr[l]++;
        arr[r + 1]--;
    }

    for(int i = 1; i < n; i++) {
        arr[i] = arr[i] + arr[i - 1];
    }

    vector<int> c(10000005, 0);
    for(int i = 0; i <= n; i++) {
        c[arr[i]]++;
    }

    for(int i = c.size() - 2; i >= 0; i--) {
        c[i] = c[i] + c[i + 1];
    }
}