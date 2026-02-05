#include <bits/stdc++.h> 
vector<string> arrangeAuthors(vector<vector<string> > &s)
{
    //variable to maintain the count of the Author and ch for A_B_C...and so on
    int authorCount = 1;

    //String to store the answer
    vector<string> ans;

    //iterate the given string vector
    for(int i = 0; i < s.size(); i++){
        //add author name in it with the count and the name string
        ans.push_back(to_string(authorCount)+". "+s[i][0]);
        char ch = 'A';
        //iterate through inner loop to add books
        for(int j = 1; j < s[i].size(); j++){
            ans.push_back("\t"+string(1, ch)+". "+s[i][j]);
            ch++; //move character forward
        }
        //increase the author count
        authorCount++;
    }
    //return final string ans
    return ans;
}