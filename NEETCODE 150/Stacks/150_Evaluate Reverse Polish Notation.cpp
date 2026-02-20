#include <cctype>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    //create one stack to store the integer token of the array
    stack<int> s;
    //traverse the vector and add digit and if symbol then evaluate and return
    //the result at the top
    for(string token : tokens){
        //if operator found take two operator variable and update stack with result 
        if(token == "+"|| token == "-" || token == "*" || token == "/"){
            int b = s.top(); //pop second operand
            s.pop();
            int a = s.top();    //pop first operand
            s.pop();
            //calculate result according to the symbol found
            int result;
            if(token == "+"){
                result = a+b;
            }
            else if(token == "-"){
                result = a - b;
            } 
            else if(token == "*"){
                result = a * b;
            }
            else{
                result = a/b;
            }
            //push the result on the top of stack
            s.push(result);
        }
        else{
            //when digit found in stack then push it
            s.push(stoi(token));
        }
    }
    return s.top();
}
};