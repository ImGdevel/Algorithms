#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, MAX = 0;
    cin >> T;
    vector<int> arr(T);
    
    for(int i=0; i<T; i++){
        cin >> arr[i];
        MAX = max(MAX, arr[i]);
    }

    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false; 
    for(int i=2; i * i <= MAX; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= MAX; j += i){
                isPrime[j] = false;
            }
        }    
    }

    for(int num : arr){
        int count = 0;
        for(int i=2; i <= num / 2; i++){
            if(isPrime[i] && isPrime[num - i]){
                count++;
            }
        }
        cout << count << "\n";
    }


    return 0;
}