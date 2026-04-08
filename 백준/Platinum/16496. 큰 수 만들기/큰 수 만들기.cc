#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool comp(const string& a, const string& b){
    return a + b > b + a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end(), comp);

    if(arr[0] == "0"){
        cout << "0";
        return 0;
    }

    for(string s : arr){
        cout << s;
    }

    return 0;
}