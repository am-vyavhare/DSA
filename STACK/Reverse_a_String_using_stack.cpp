#include<iostream>
#include<stack>
using namespace std;

int main(){
    //built in class string used to define string
    string s = "Aniket";

    //stack created
    stack<char> stk;

    //string characters are added inside stack
    for(int i = 0; i < s.length(); i++){
        stk.push(s[i]);
    }

    //define answer string
    string ans = "";

    //Loop to make answer string by traversing the stack
    while(!stk.empty()){
        char  ch = stk.top();
        ans.push_back(ch);  

        stk.pop();
    }

    cout<<"Reverse of String: "<<s<<" is : "<<ans<<endl;
    return 0;
}