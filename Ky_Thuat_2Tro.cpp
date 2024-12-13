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

    //sort(a + 1, a + n + 1);

    long long cnt = 0;
    long long i = 1, j = n;

    while (i < j) {
        if (a[i] + a[j] == Q) {
            cnt++;
            i++;
            j--;
        } else if (a[i] + a[j] > Q) {
            j--;
        } else {
            i++;
        }
    }

    cout << cnt;
}
