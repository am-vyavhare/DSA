#include <bits/stdc++.h> 

void solve(string str, int index, string output, vector<string>& ans){
        if(index >= str.length()){
			if(output.length()>0)
            ans.push_back(output);
            return;
        }
        //call of excluding the element
        solve(str, index+1, output, ans);
        //call of including the element 
        output.push_back(str[index]);
        solve(str, index+1, output, ans);
    }

vector<string> subsequences(string str){
	
	// Write your code here
	vector <string> ans;
    string output = "";
    // int index = 0;
    solve(str, 0 , output, ans);
    return ans;
	
}
