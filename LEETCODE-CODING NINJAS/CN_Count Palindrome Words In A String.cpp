#include <bits/stdc++.h> 
int checkpalindrome(string str){
	int start = 0;
	int end = str.length()-1;
	while(start<=end){
		if(toupper(str[start]) != toupper(str[end])){
			return 0;
		}
		start++;
		end--;
	}
	return 1;
}
int countNumberOfPalindromeWords(string s)
{
	int count = 0; //to count the palindrome words
	string word = ""; // to store the words
	//traverse through the string
	for(int i = 0; i < s.length();i++){
		//if character is space then check the previous word is palindrome or not
			if(s[i] == ' '){
				//before check word it should not be empty
				if(!word.empty()){
					if(checkpalindrome(word)){
						count++; //if palindrome increment count
					}
					word = ""; //reset the word to empty string
				}
			}
			//else add the character to the word string
			else{
				word = word + s[i];
			}
		}
		//check for the last word
		if(!word.empty()){
			if(checkpalindrome(word)){
				count++;
			}
		}
		//return final count
	return count;
}