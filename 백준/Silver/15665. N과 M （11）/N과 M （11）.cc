#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;
vector<int> seq;

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            if (i > 0) cout << ' ';
            cout << seq[i];
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        seq.push_back(nums[i]);
        dfs(depth + 1);
        seq.pop_back();
    }
}

int main() {
    cin >> N >> M;

    nums.resize(N);
    for (int i = 0; i < N; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    dfs(0);

    return 0;
}