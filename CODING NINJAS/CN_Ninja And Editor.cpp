#include <bits/stdc++.h> 
string editSentence(string &str)
{
	//string to store the answer
	string answer = "";
	//first char always without preceeding space
	answer +=(char)tolower(str[0]);
	//traverse and assign space for each uppercase char
	for(int i = 1; i < str.length(); i++){
		char ch = str[i];
		if(isupper(ch)){
			answer += ' ';
			answer += (char)tolower(ch);
		}
		else
			answer += ch;
	}
	return answer;
}