#include <bits/stdc++.h>
using namespace std;

const long long N_MAX = 1e5 + 4;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, Q;
    long long a[N_MAX];

    cin >> n >> Q;

    for (long long i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    long long cnt = 0, sum = 0;

    long long L = 1;

    for (long long R = 1; R <= n; ++R) {
        sum += a[R];

        while (sum > Q) {
            sum -= a[L];
            L++;
        }
        cnt = max(cnt, R - L + 1);
    }

    cout << cnt;
}
