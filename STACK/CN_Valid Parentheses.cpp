//Solition with one valid brace and balanced parentheses
bool isValidParenthesis(string s)
{
    //stack to store the opening braces
    stack<char> parenthesis_stack;

    //traverse until end of the string
    for(int i = 0; i < s.length(); i++){
        
        //check whether is opening then push
        if(s[i] == '{' || s[i] == '(' || s[i] == '['){
            parenthesis_stack.push(s[i]);
        }

        //else the brace is closing check whether it is valid then pop otherwise return false
        else{
            //if stack empty not balanced return false
            if(parenthesis_stack.empty()){
                return false;
            }
            //brace found check for matching
            else{
            //take top and string char in variable to compare
            char ch = s[i];
            char top = parenthesis_stack.top();
            //check whether any matching combination found
            if((ch == '}' && top == '{') || (ch == ')' && top == '(') || (ch == ']' && top == '[')){
                        parenthesis_stack.pop();    
                }
                else{
                    return false;
                }
            }
        }
    }
    //if after all operation stack is empty then braces are balanced so return true otherwise false
    if(parenthesis_stack.empty()){
        return true;
    }
    else{
        return false;
    }
}


//Solution 2 without checking valid brace but balanced parenthesis
/*
bool isValidParenthesis(string s)
{
    stack<char> parenthesis_stack;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '{' || s[i] == '(' || s[i] == '['){
            parenthesis_stack.push(s[i]);
        }
        else{
            if(parenthesis_stack.empty()){
                return false;
            }
            parenthesis_stack.pop();    
        }
    }
    if(parenthesis_stack.empty()){
        return true;
    }
    else{
        return false;
    }
}
*/