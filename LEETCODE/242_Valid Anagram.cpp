class Solution {
public:
    bool isAnagram(string s, string t) {
        //if length is not equal return false
        if(s.length() != t.length()){
            return false;
        }
        //array to store count of each character of string
        int frequency[26] = {0};
        for(int i = 0; i < s.length(); i++){
            //all lowercase so correct index according to ASCII is - 97
            int position = s[i] - 97; 
            frequency[position]++; 
        }
        //traverse string 2 for checking anagram
        for(int i = 0; i < t.length(); i++){
            int position = t[i] - 97;
            //if the given character index have 0 frequency means they are not anagram
            if(frequency[position] == 0){
                return false;
            }else{
                //otherwise decrement frequency
                frequency[position]--;
            }
        }
        return true;
}
};