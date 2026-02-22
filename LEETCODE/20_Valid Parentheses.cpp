class Solution {
public:
    bool isValid(string s) {

        //Step 1 - create stack to store opening brackets
        stack<char> stk;

        //Step 2 - traverse through string
        for(char ch : s){

            //Step 3 - if opening bracket, push to stack
            if(ch == '(' || ch == '{' || ch == '['){
                stk.push(ch);
            }
            else{

                //Step 4 - if stack empty 
                if(stk.empty())
                    return false;

                char top = stk.top();

                //Step 5 - check matching pair and if valid closing not found → invalid
                if((ch == ')' && top == '(') ||
                   (ch == ']' && top == '[') ||
                   (ch == '}' && top == '{')){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
        //Step 6 - if stack empty → valid
        return stk.empty();
    }
};
