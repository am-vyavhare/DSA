class Solution {
public:

    void solve(vector<int> nums, int index, vector<int> output, vector<vector<int>>& ans){
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        //call of excluding the element
        solve(nums, index+1, output, ans);

        //call of including the element 
        output.push_back(nums[index]);
        solve(nums, index+1, output, ans);
    }



    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> ans;
        vector <int> output;
        // int index = 0;
        
        solve(nums, 0 , output, ans);
        return ans;
    }
};