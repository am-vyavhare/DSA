class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //step 1 - create set to store the unique elements 
        unordered_set<int> unique;
        for(int n : nums){
            unique.insert(n);
        }
        //step 2 - traverse through the set and count sequence length if sequence exist
        int longest = 0;
        for(int n : unique){
            //check if element less than this exist if yes then it is not start of 
            //sequence and if no then start 
            if(unique.count(n-1) == 0){
                int curr = n;
                int len = 1;                  
            //calculate the next consecutive sequence
                while(unique.count(curr+1)){
                    curr++;
                    len++;
                }
                longest = max(len, longest);
                }
            }
            return longest;
        }
};