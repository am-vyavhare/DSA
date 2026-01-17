#include <bits/stdc++.h>
bool findRedundantBrackets(string &s)
{
    //Declare stack to store operator and opening brace
    stack<char> st;
    
    //Traverse the each char of String to check whether redundant brace found or not
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        //if opening brace or any operator then push to stack
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(s[i]);
        }
        //else handle the closing brace or any lowercase letter
        else{
            //variable to use as a flag for redundant or not initially true
            bool isRedundant = true;
            //check if ch is ')' yes then check that here must be any
            //operator in stack instead of opening brace if brace then it is redundant
            if(ch == ')'){
                while(st.top() != '('){
                    char top = st.top();
                    //check if top consist any operator is yes then not redundant there is valid brace pair
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    //pop operator
                    st.pop();
                }
                if(isRedundant == true){
                    return true;
                }
                //pop brace
                st.pop(); 
            }
        }
    }
    return false;
}
