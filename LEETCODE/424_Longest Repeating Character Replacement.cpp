class Solution {
public:
    int characterReplacement(string s, int k){
    //variable to store the frequency of character that how many times it appeared
    vector<int> freq(26,0);
    //variable to store the maxlen and maxfreq
    int maxlen = 0;
    int maxfreq = 0;
    //sliding window start
    int left = 0;
    for(int right = 0; right < s.length(); right++){
        //increase the frequency of the current Uppercase character
        freq[s[right]-'A']++;
        //update the maxfreq in the window 
        maxfreq = max(maxfreq, freq[s[right]-'A']);
        //if the different char in window replacement limit is reached that is k 
        //move window from left 
        while((right-left+1) - maxfreq > k){
            freq[s[left] - 'A']--;
            left++;
        }
        //update the maxlen
        maxlen = max(maxlen, right-left+1);
    }
    return maxlen;
    }
};