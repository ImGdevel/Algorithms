// 
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> arr(N + 2, vector<int>(M + 2, 0));
    for(int i=1; i <= N; i++){
        for(int j=1; j <= M; j++){
            cin >> arr[i][j];
        }
    }

    int sp_count = N * M * 2;
    for(int i=0; i <= N; i++){
        for(int j=0; j <= M; j++){
            sp_count += abs(arr[i][j] - arr[i][j + 1]);
            sp_count += abs(arr[i][j] - arr[i + 1][j]);
        }
    }

    cout << sp_count << endl;

}