class Solution {
public:
    int fib(int n) {
        //base case conditions
        if(n == 0){
            return 0;
        }
        //condtion 2
        if(n == 1){
            return 1;
        }
        //Recursive call
        int answer = fib(n-1) + fib(n-2);
        return answer;
    }
};


