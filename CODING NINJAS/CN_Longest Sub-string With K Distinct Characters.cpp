#include <bits/stdc++.h> 
int getLengthofLongestSubstring(string s, int k) {
    //Step 1 - we solve it using sliding window
    //create one vector to store the freq count of char
    vector<int> freq(26,0);
    int left =0;    //window start
    int maxlen = 0;
    int distince_count = 0;

    //move the window in a string from start
    for(int right = 0; right < s.length(); right++){
        //if the character is occured first time then increase count of distinct count
        if(freq[s[right]-'a'] == 0){
            distince_count++;
        }
        //otherwise increase frequency of that char 
        freq[s[right]-'a']++;
        //check if distinct elements exceeds the limit k
        while(distince_count > k){
            //reduce the count of char on left edge of window
            freq[s[left] - 'a']--;
            //if this char is only one time then distinct count is reduced
            //otherwise iterate until we reduce the distince count
            if(freq[s[left] - 'a'] == 0){
                distince_count--;
            }
            left++;
        }
        //update the maximum length
        maxlen = max(maxlen, right-left + 1);
    }
    return maxlen;  
}