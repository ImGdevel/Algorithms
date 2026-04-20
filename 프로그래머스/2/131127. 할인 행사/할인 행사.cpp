#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int N = discount.size();

    unordered_map<string, int> target;
    for (int i = 0; i < want.size(); i++) {
        target[want[i]] = number[i];
    }

    for (int start = 0; start <= N - 10; start++) {
        unordered_map<string, int> current;

        for (int j = start; j < start + 10; j++) {
            current[discount[j]]++;
        }

        bool ok = true;
        for (int i = 0; i < want.size(); i++) {
            if (current[want[i]] != number[i]) {
                ok = false;
                break;
            }
        }

        if (ok) answer++;
    }

    return answer;
}