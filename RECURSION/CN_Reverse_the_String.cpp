#include <bits/stdc++.h> 

void reverse_string(string& str, int start, int end){
	
	if(start>end){
		return;
	}

	swap(str[start],str[end]);
	start++;
	end--;
	reverse_string(str,start,end);
}


string reverseString(string str)
{// Write your code here.
	
	reverse_string(str, 0, str.length()-1);
	return str;	
}

6