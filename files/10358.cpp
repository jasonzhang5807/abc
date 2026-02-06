//为了写这个代码，学了一个小时生成函数，算了半小时排列组合，调了半小时--zhangxinyu
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long fra[400010];
inline long long inv(long long a) {
    long long res = 1, b = mod - 2;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
    int n;
    cin >> n;
    if (n == 0) {
        cout << 1;
        return 0;
    }
    fra[0] = 1;
    int maxn = 2 * n;
    for (int i = 1; i <= maxn; ++i) 
        fra[i] = fra[i - 1] * i % mod;
    long long ans = 0;
    for (int k = n; k <= maxn; k++) {
        if ((k + n) % 2 != 0) continue;
        int east = (k + n) / 2;
        int west = k - east;
        long long comb = fra[k] * inv(fra[east]) % mod * inv(fra[west]) % mod;
        ans = (ans + n * inv(k) % mod * comb) % mod;
    }
    cout << ans;
    return 0;
}
