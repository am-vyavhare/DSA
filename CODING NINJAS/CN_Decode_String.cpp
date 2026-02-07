#include <bits/stdc++.h>
string decodeString(string s) {
    //create stack to store the current string and the repeat count
    stack<pair<string, int>> st;
    string currStr = ""; // for final answer
    int num = 0; // for count

    //traverse through the input string 
    for (char c : s) {
        // If digit, build the number (handles multi-digit) update the count and move to next char
        if (isdigit(c)) {
            num = num * 10 + (c - '0');  //to handle ascii - '0' is taken
        }

        // If '[', push current state - current string and the number that we need to repeat
        else if (c == '[') {
            st.push({currStr, num});
            currStr = ""; // reset current string to empty after push
            num = 0; // reset num also
        }

        // If ']', decode current block if closing found means one block
        // is completed so we need to create the string for that block
        else if (c == ']') {
            auto top = st.top(); //store pair of string and the num before pop
            st.pop();

            //get the current string in previous string and build new string using count
            string prevStr = top.first;
            int repeatCount = top.second;
            
            //repeat the string until the previous count number
            string temp = "";
            for (int i = 0; i < repeatCount; i++) {
                temp += currStr;
            }
            //update the current string with the prev with new generated
            currStr = prevStr + temp;
        }

        // If character, add to current string 
        else {
            currStr += c;
        }
    }
    return currStr;
}
