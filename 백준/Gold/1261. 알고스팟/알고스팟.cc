#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int r, c, v;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> M >> N;

    vector<vector<char>> arr(N, vector<char>(M));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            //cout << arr[i][j];
        }    
        //cout << endl;
    }
    //cout << endl;

    deque<Node> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    q.push_back({0,0,0});
    visited[0][0] = true;

    while (!q.empty())
    {
        Node node = q.front();
        q.pop_front();
        //cout << node.r << " " << node.c << " " << node.v << endl;

        if(node.r == N - 1 && node.c == M - 1){
            cout << node.v;
            return 0;
        }

        for(int i=0; i<4; i++){
            int next_r = node.r + d[i][0];
            int next_c = node.c + d[i][1];

            if(next_r < N && next_c < M && next_r >= 0 && next_c >= 0
                && !visited[next_r][next_c]){
                if(arr[next_r][next_c] == '0'){
                    q.push_front({ next_r, next_c , node.v});
                }else{
                    q.push_back({next_r, next_c , node.v + 1});
                }
                visited[next_r][next_c] = true;
            }
        }
    }
    cout << -1;

    return 0;
}