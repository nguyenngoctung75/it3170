#include <bits/stdc++.h>
using namespace std;

const long long N_MAX = 1e6 + 4;
const long long LOG = 20;

long long M[LOG][N_MAX];
long long a[N_MAX];

void processing(long long n) {
    for (long long i = 0; i < n; ++i)
        M[0][i] = i;
    for (long long j = 1; (1 << j) - 1 < n; ++j) {
        for (long long i = 0; i + (1 << j) - 1 < n; ++i) {
            if (a[M[j - 1][i]] < a[M[j - 1][i + (1 << (j - 1))]])
                M[j][i] = M[j - 1][i];
            else
                M[j][i] = M[j - 1][i + (1 << (j - 1))];
        }
    }
}

long long RMQ(long long i, long long j) {
    long long len = j - i + 1;
    long long k = log2(len);

    return a[M[k][i]] > a[M[k][j - (1 << k) + 1]] ? a[M[k][j - (1 << k) + 1]] : a[M[k][i]];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    for (long long i = 0; i < n; ++i)
        cin >> a[i];

    long long m, sum = 0;
    cin >> m;

    processing(n);

    for (long long k = 1; k <= m; ++k) {
        long long ik, jk;
        cin >> ik >> jk;

        sum += RMQ(ik, jk);
    }

    cout << sum;
}
