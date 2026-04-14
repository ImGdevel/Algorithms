#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

char arr[31][31][31];
bool visited[31][31][31];

struct Node
{
    int r, c, l, count;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (true)
    {
        int L, R, C;
        cin >> L >> R >> C;

        if(L == 0 && R == 0 && C == 0) return 0;

        int sr, sc, sl;

        for(int i=0; i<L; i++){
            for(int j=0; j < R ; j++){
                for(int k =0 ;k < C ; k ++){
                    cin >> arr[i][j][k];
                    visited[i][j][k] = false;
                    if(arr[i][j][k] == 'S'){
                        sr = j; sc = k; sl = i;
                    }
                }
            }
        }
        int answer = 0;
        bool find = true;

        queue<Node> q;
        int d[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
        visited[sr][sc][sl] = true;
        q.push({sr,sc,sl,0});
        bool es = false;

        while (!q.empty())
        {
            Node n = q.front();
            q.pop();

            if(arr[n.l][n.r][n.c] == 'E'){
                cout << "Escaped in "<< n.count << " minute(s)." << endl;
                es = true;
                break;
            }
            
            for(int i=0; i<6; i++){
                int r = n.r + d[i][0];
                int c = n.c + d[i][1];
                int l = n.l + d[i][2];
                
                if(l < L && l >= 0 && r < R && r >= 0 && c < C && c >= 0 
                    && !visited[l][r][c] && arr[l][r][c] != '#'){
                        visited[l][r][c] = true;
                        q.push({r,c,l, n.count + 1});
                }
            }
        }

        if(!es){
            cout << "Trapped!" << endl;
        }
    }
    
    return 0;
}