class Solution {
public:
    bool containsDuplicate(vector<int>& nums){
        //unordered set to store element and check frequency
        unordered_set<int> seen;
        for(int element:nums){
            //if count is 1 then it is occured twice it is duplicate so return
            if(seen.count(element)){
                return true;
            }
            //insert element if unique
            seen.insert(element);
        }
        return false;
    }
};