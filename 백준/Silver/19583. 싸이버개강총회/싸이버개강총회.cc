#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, E, Q;
    cin >> S >> E >> Q;

    unordered_set<string> enter;
    unordered_set<string> counted;

    string time, name;
    while (cin >> time >> name) {
        if (time <= S) {
            enter.insert(name);
        } 
        else if (E <= time && time <= Q) {
            if (enter.count(name)) {
                counted.insert(name);
            }
        }
    }

    cout << counted.size() << '\n';
    return 0;
}