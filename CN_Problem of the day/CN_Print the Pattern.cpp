#include <bits/stdc++.h> 
vector<string> printPattern(int n)
{
	//output string vector
	vector<string> result(n);
	//variable to maintain the num
	int num = 1;
	//as the pattern tells each row is added like first to
	//start then next to bottom then again start .. 
	//again bottom like that so main top and bottom
	int top = 0;
	int bottom = n - 1;
	for(int i = 1; i <= n ; i++){
		//traverse for the internal string generation
		string str = "";
		for(int j = 1; j <= n; j++){
			str += to_string(num++);
			if(j != n) //add single space when the element is not last
				str+=" ";
		}
		//if this is odd move then add to top
		if(i%2!=0){
			result[top++] = str;
		}
		else{ //even move at the bottom
			result[bottom--] = str;
		}
		}
		//return result
	return result;
}