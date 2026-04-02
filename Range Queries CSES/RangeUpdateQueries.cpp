#include<iostream>
#include<vector>
using namespace std;

void update(vector<long long> &bit, int id, long long val, int n) {
    while(id <= n) {
        bit[id] += val;
        id += (id & -id);
    }
}

long long query(vector<long long> &bit, int id) {
    long long sum = 0;
    while(id > 0) {
        sum += bit[id];
        id -= (id & -id);
    }
    return sum;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> bit(n + 1, 0);

    while(q--) {
        int q_type;
        cin >> q_type;

        if(q_type == 1) {
            int a, b;
            long long u;
            cin >> a >> b >> u;
            update(bit, a, u, n);
            update(bit, b + 1, -u, n);
        }
        else {
            int k;
            cin >> k;

            long long ans = arr[k - 1] + query(bit, k);
            cout << ans << endl;
        }
    }

    return 0;
}