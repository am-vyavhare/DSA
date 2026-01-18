#include <bits/stdc++.h> 
int findMinimumCost(string str){
  //check whether the String length is odd if odd then impossible to make valid then return -1
  if(str.length()%2 != 0){
    return -1;
  }
  //Stack to store braces
  stack<char> stk;
  
  for(int i = 0; i < str.length() ; i++){
    //if the char is opening brace store and push in stack
    char ch = str[i];
    if(ch == '{'){
      stk.push(ch);
    }
    //if the char is closing check whether opening found then pop valid pair otherwise if top not contains opening then store
    else{
      //check the top of stack is not empty and opening brace at top if found pop 
      if(!stk.empty() && stk.top() == '{'){
        stk.pop();
      }
      //else push the brace (ch)
      else{
        stk.push(ch);
      }
    }
  }

  int a = 0;  // opening brace count
  int b = 0;  //closing brace count
  
  while(!stk.empty()){
        if(stk.top() == '{'){
          a++;
        }
        else{
          b++;
        }
        stk.pop();
  }
  //variable to store cost to make string valid
  int cost = (a+1)/2 + (b+1)/2;
  return cost;
}