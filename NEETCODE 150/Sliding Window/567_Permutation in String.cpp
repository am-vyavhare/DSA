class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    //if s1 is bigger in size then s2 cannot contain its permuation
    if(s1.length() > s2.length()){
        return false;
    }
    //create 2 vector to store the character frequency of the char in string
    vector<int> freq1(26,0);
    vector<int> freq2(26,0);
    //length of string 1 to use as window and to traverse initially to get char ferquency
    int len1 = s1.length();
    //add character frequency of s1 string
    for(int i = 0; i < len1; i++){
        freq1[s1[i] - 'a']++; //all lowercase so - 'a' to align - (a-z) with (0-26)
        freq2[s2[i] - 'a']++;
    }
    //check first window if match
    if(freq1 == freq2){
        return true;
    }
//check the next window in the s2 string for the permutation of s1 (slide over s2)
    for(int i = len1; i < s2.length(); i++){
        //add new character frequency in freq2
        freq2[s2[i] - 'a']++;

        //remove the old character frequency to shring the window from back
        freq2[s2[i-len1] - 'a']--;

        //check if array equal
        if(freq1 == freq2){
            return true;
        }
    }
    //otherwise no permutation found
    return false;
    }
};