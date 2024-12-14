#include <bits/stdc++.h>
using namespace std;

int n, K, c_min = 1e5;
const int N_MAX = 12;
int d[2 * N_MAX][2 * N_MAX];
int visited[2 * N_MAX] = {0};
int x[2 * N_MAX], load = 0, f = 0, f_min = 1e5;

int check(int v, int k) {
    if (visited[v]) return 0;
    if (v > n) {
        if (!visited[v - n]) return 0;
    } else {
        if (load + 1 > K) return 0;
    }

    return 1;
}

void result() {
    f_min = min(f_min, f + d[x[2 * n]][0]);
}
void Try(int k) {
    for (int v = 1; v <= 2 * n; ++v) {
        if (check(v, k)) {
            x[k] = v;
            visited[v] = 1;
            f += d[x[k-1]][x[k]];

            if (v <= n) load++;
            else load--;
            if (k == 2*n) {
                result();
            } else {
                if (f + c_min * (2 * n - k + 1) < f_min)
                    Try(k + 1);
            }
            if (v <= n) load--;
            else load++;

            visited[v] = 0;
            f -= d[x[k-1]][x[k]];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> K;
    for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 0; j <= 2 * n; ++j) {
            cin >> d[i][j];

            if (i != j)
                c_min = min(d[i][j], c_min);
        }
    }
    x[0] = 0;
    Try(1);
    cout << f_min;
}
