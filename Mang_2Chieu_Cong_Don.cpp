#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1e2 + 2;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    int Q;

    cin >> n >> m;
    int a[n + 1][m + 1];
    long long S[n + 1][m + 1];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
        S[i][0] = 0;
    for (int j = 0; j < m; ++j)
        S[0][j] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        long long sum = S[c][d] - S[c][b - 1] - S[a - 1][d] + S[a - 1][b - 1];
        cout << sum << endl;
    }
}
