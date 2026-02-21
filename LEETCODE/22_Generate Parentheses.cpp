class Solution {
public:
    //Step 1 - helper function for backtracking
    void generate(int n, int open, int close, 
                  string current, vector<string>& result){

        //Step 2 - base case: if string length becomes 2*n
        if(current.length() == 2 * n){
            result.push_back(current);
            return;
        }

        //Step 3 - if we can still add '('
        if(open < n){
            generate(n, open + 1, close, 
                     current + "(", result);
        }

        //Step 4 - if we can add ')'
        //only allowed when close < open
        if(close < open){
            generate(n, open, close + 1, 
                     current + ")", result);
        }
    }
    vector<string> generateParenthesis(int n) {
         //Step 5 - create result vector
        vector<string> result;

        //Step 6 - start recursion with empty string
        generate(n, 0, 0, "", result);

        return result;
    }
};