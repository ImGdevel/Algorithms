#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<long long> t;

    SegTree(int sz) {
        n = sz;
        t.resize(2 * n);
    }

    void build(vector<long long>& a) {
        for (int i = 0; i < n; i++) t[n + i] = a[i];
        for (int i = n - 1; i > 0; i--) t[i] = t[i << 1] + t[i << 1 | 1];
    }

    void update(int p, long long v) {
        for (t[p += n] = v; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }

    long long query(int l, int r) {
        long long res = 0;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (!(r & 1)) res += t[r--];
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    SegTree seg(N);
    seg.build(arr);

    for (int i = 0; i < M + K; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        if (a == 1) {
            seg.update(b - 1, c);
        } else if (a == 2) {
            cout << seg.query(b - 1, (int)c - 1) << '\n';
        }
    }

    return 0;
}