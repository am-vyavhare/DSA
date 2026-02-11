#include <bits/stdc++.h> 
string reverseString(string str)
{
	//initialize two variable from start and end index of string
	int start = 0;
	int end = str.length()-1;
	//traverse until they cross each other and swap their position
	while(start<=end){
		char ch = str[start];
		str[start] = str[end];
		str[end] = ch;
		start++;
		end--;
	}
	return str;
}