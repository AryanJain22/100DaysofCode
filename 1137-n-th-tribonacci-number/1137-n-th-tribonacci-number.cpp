class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        int a = 0, b = 1, c = 1;
        int sum = 0;
        for(int i = 0; i < n - 2; i++){
            sum = a + b + c;
            a = b;
            b = c;
            c = sum;
        }
        return sum;
    }
};