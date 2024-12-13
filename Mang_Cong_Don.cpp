#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 1e4 + 4;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long S[N_MAX] = {0};
    int a[N_MAX];
    int n;
    int Q;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        S[i] += S[i - 1] + a[i];
    }

    cin >> Q;
    int u, v;

    for (int i = 0; i < Q; ++i) {
        cin >> u >> v;

        long long sum = S[v] - S[u - 1];
        cout << sum << endl;
    }
}
