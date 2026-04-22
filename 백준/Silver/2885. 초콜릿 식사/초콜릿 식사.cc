#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    int N = 1;
    while (N < K) {
        N *= 2;
    }

    int temp = K;
    int split = 0;

    while (temp % 2 == 0) {
        temp /= 2;
        split++;
    }

    int total = 0;
    int x = N;
    while (x > 1) {
        x /= 2;
        total++;
    }

    cout << N << ' ' << total - split << '\n';
    return 0;
}