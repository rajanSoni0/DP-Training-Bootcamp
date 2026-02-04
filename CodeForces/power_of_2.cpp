#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<long long, long long> cnt;
    cnt.reserve(n * 2);
    for (long long x : a) {
        cnt[x]++;
    }

    sort(a.begin(), a.end(), greater<long long>());

    long long kept = 0;

    for (long long x : a) {
        if (cnt[x] == 0) continue;

        bool paired = false;

        for (int k = 0; k <= 31; k++) {
            long long power = 1LL << k;
            if (power <= x) continue;

            long long y = power - x;
            if (!cnt.count(y)) continue;

            if (y == x) {
                if (cnt[x] >= 2) {
                    cnt[x] -= 2;
                    kept += 2;
                    paired = true;
                }
            } else {
                if (cnt[y] > 0) {
                    cnt[x]--;
                    cnt[y]--;
                    kept += 2;
                    paired = true;
                }
            }

            if (paired) break;
        }
    }

    cout << n - kept - 1 << "\n";
    return 0;
}
