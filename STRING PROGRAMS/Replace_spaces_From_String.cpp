#include <bits/stdc++.h> 
string replaceSpaces(string &str){
		// Write your code here.
	string answer = "";
	for(int i=0; i < str.length() ; i++){
		if(str[i]==' '){
			answer.push_back('@');
			answer.push_back('4');
			answer.push_back('0');
		}
		else{
			answer.push_back(str[i]);
		}
	}   
	return answer;
}