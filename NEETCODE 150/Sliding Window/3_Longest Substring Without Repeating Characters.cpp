class Solution {
public:
    int lengthOfLongestSubstring(string s){
        //declare variable to store the maxlen and set to store the unique char
        int maxlen = 0;
        unordered_set<char> unique;
        //create one sliding window that will move from left to right by keeping the unique char
        //substring in it
        int left = 0;
        for(int right = 0; right < s.length();right++){
            //if character found then move the left border of window until the left border
            // touch the valid window again 
            while(unique.find(s[right]) != unique.end()){
                unique.erase(s[left]);
                left++;
            }
            //add the current element in the set
            unique.insert(s[right]);
            //calculate the length and store maximum from them
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};