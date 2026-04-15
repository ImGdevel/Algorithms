class Solution {
    
    public int gcd(int a, int b){
        while(b != 0){
            int n = a % b;
            a = b;
            b = n;
        }
        return a;
    }
    
    
    public int solution(int[] arr) {
        int answer = 0;
        
        for(int i=0; i < arr.length - 1; i++){
            int a = arr[i];
            int b = arr[i + 1];
            
            int n = (a * b) / gcd(a, b);
            
            arr[i + 1] = n;
        }
        answer = arr[arr.length - 1];
        
        return answer;
    }
}