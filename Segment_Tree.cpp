#include <bits/stdc++.h>
using namespace std;

const long long N_MAX = 1e5 + 4;
const long long N_INF = -1e9;
long long a[N_MAX];
long long tree[4 * N_MAX];
long long n;

void buildTree(long long node, long long n_start, long long n_end) {
    if (n_start == n_end) {
        tree[node] = a[n_start];
    } else {
        long long mid = (n_start + n_end) / 2;
        buildTree(2 * node, n_start, mid);
        buildTree(2 * node + 1, mid + 1, n_end);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

long long GetMaxFromNode(long long id, long long L, long long R, long long i, long long j) {
    if (i > R || j < L)
        return N_INF;
    if (i <= L && j >= R) {
        return tree[id];
    }
    long long mid = (L + R) / 2;
    long long LC = 2 * id;
    long long RC = 2 * id + 1;
    long long maxLeft = GetMaxFromNode(LC, L, mid, i, j);
    long long maxRight = GetMaxFromNode(RC, mid + 1, R, i, j);
    return max(maxLeft, maxRight);
}

long long GetMax(long long i, long long j) {
    return GetMaxFromNode(1, 1, n, i, j);
}

void UpdateFromNode(long long id, long long L, long long R, long long index, long long value) {
    if (L > R) return;
    if (index < L || index > R) return;
    if (L == R) {
        tree[id] = value;
        return;
    }
    long long LC = 2 * id;
    long long RC = 2 * id + 1;
    long long mid = (L + R) / 2;
    UpdateFromNode(LC, L, mid, index, value);
    UpdateFromNode(RC, mid + 1, R, index, value);
    tree[id] = max(tree[2 * id], tree[2 * id + 1]);
}

void Update(long long i, long long v) {
    UpdateFromNode(1, 1, n, i, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (long long i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    buildTree(1, 1, n);
    int m;
    cin >> m;
    string s;
    for (int i = 0; i < m; ++i) {
        //fflush(rewind);
        cin >> s;
        long long u, v;
        if (s == "get-max") {
            cin >> u >> v;
            cout << GetMax(u, v) << endl;
        } else if (s == "update") {
            cin >> u >> v;
            Update(u, v);
        }
    }
}
