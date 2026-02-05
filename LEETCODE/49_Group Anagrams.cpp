class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //Step 1 - create a unordered map to store 
        //the string key and vector of anagram strings
        unordered_map<string,vector<string>> mp;
        
        //Step 2 - Process each string from input using loop
        for(string s: strs){
            //Step 3 - create vector to store frequency of the each char from string
            vector<int> freq(26,0);

            //Step 4 - Process each char of String
            for(char ch : s){
                freq[ch - 'a']++; //- 'a' for coverting ascii from  97 -> 0
            }

            //Step 5 - generate key for each string freq like - 0#1#3#....#;
            string key;
            for(int count: freq){
                key = key + to_string(count) + '#';
            }

            //step 6 - add strings that have
            //same key means they are anagram
            mp[key].push_back(s); 
        }
        //Step 7 - create final vector of anagrams from unordered map
        vector<vector<string>> result;
        //auto& it collect each pair of key and vector of anagrams and
        //it.second represent vector of anagram that we added for output 
        for(auto& it: mp){
            result.push_back(it.second);
        }
        return result;
    }
};