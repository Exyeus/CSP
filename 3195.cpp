#include <bits/stdc++.h>

typedef unsigned long long ll;

#define MOD 1000000009

using namespace std;

int main() {

    ll n;

    cin >> n;

    /**
     * 先计算放置 0 和 1.
     * 它们不能放在第一位, 否则矛盾
     * 按照 k 从 2 到 n-2
     * 选择位置: C_(n-1)^k
     * 在 k 个 0 1 之中, 按照 0 的数量从 1 到 k-1 枚举
     * 接着对于 2 和 3, 在剩下的位置, 一共 n - k 个, 按照 2 的数量
     * 从 1 枚举到 n - k - 1.
     */

    ll result = 0;

    for (int k = 2; k < n - 1; k++) {
        ll p1 = 1;
        for (int i = 1; i < k + 2; i++) {
            p1 *= (n - i) % MOD;
        }
        ll p2 = 1;
        for (int j = 1; j < k - 1; j++) {
            p2 *= j % MOD;
        }
        p2 *= k;

        result += (p1 / p2) % MOD;

    }

    cout << (result % MOD) << "\n";

    return 0;
}