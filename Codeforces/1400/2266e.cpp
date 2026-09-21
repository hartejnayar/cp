#include <iostream>
using namespace std;

int a[200005];
int spf[200005];
long long cost[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Sieve for smallest prime factor
        for (int i = 0; i <= n; i++) spf[i] = i;
        for (int i = 2; i * i <= n; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        // DP
        for (int i = 0; i <= n; i++) cost[i] = 0;

        for (int x = k + 1; x <= n; x++) {
            long long best = 1000000000000000000LL;
            int temp = x;
            while (temp > 1) {
                int p = spf[temp];
                long long candidate = 1 + (long long)p * cost[x / p];
                if (candidate < best) best = candidate;
                while (temp % p == 0) temp /= p;
            }
            cost[x] = best;
        }

        long long answer = 0;
        for (int i = 0; i < n; i++) answer += cost[a[i]];

        cout << answer << "\n";
    }
    return 0;
}