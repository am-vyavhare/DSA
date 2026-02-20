class Solution {
public:
    string minWindow(string s, string t){
        //check if t is bigger than s then no possible window
        if(t.length() > s.length()){
            return "";
        }
        //char of string 2 with its fequency that is need to check in string1 
        unordered_map<char, int> need;
        //add all the elements of the 2nd string in the map
        for(char ch:t){
            need[ch]++;
        }
        //count of char we need to make valid substring 
        int needcount = need.size();
        //char we have currently
        int have = 0;
        int start = 0; //start of current smallest window
        //map to maintain the chars in the moving window
        //create two pointer to check the valid string in window present 
        unordered_map<char, int> window;
        int left = 0;
        int minlen = INT_MAX;
        
        for(int right = 0 ; right < s.length(); right++){
            //add current char or increase frequency if present
            char ch = s[right];
            window[ch]++;
            //check if frequency of current char is matches with what we need
            if(need.count(ch) && need[ch] == window[ch]){
                have++; 
            }
            //shrink window if valid if have count is equal to needcount
            while(have == needcount){
                int windowlen = right - left + 1;
                if(windowlen < minlen){
                    minlen = windowlen;
                    start = left;
                }
                //decrease the window starting char frequency
                window[s[left]]--;

                //if current left char frequency does not satisfy the need then
                //decrease the elements we have
                if(need.count(s[left]) && window[s[left]]< need[s[left]])
                    have--;
            //move forward for next window
            left++;
            }
        }
        //if minlength still 0 then return empty string
        if(minlen == INT_MAX){
            return "";
        }
        //return the substring from the start to end
        return s.substr(start, minlen);
    }
};