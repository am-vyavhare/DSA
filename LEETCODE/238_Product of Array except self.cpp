//optimal solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //Step 1 - get the size of the array
        int size = nums.size();

        //Step 2 - create an answer vector to store the result
        //answer[i] will store product of all elements except nums[i]
        vector<int> answer(size);

        //Step 3 - initialize first element as 1
        //because there is no element on the left of index 0
        answer[0] = 1;

        //Step 4 - calculate the prefix product for each index
        //answer[i] = product of all elements to the left of i
        for(int i = 1; i < size; i++){
            answer[i] = answer[i-1] * nums[i-1];
        }

        //Step 5 - create a variable to store suffix product
        //this will store product of elements to the right
        int suffixprod = 1;

        //Step 6 - traverse from the end and multiply suffix product
        //with the prefix product already stored in answer[]
        for(int i = size-1; i >= 0; i--){
            answer[i] = answer[i] * suffixprod;
            suffixprod = suffixprod * nums[i];
        }

        //Step 7 - return the final answer vector
        return answer;
    }
};


// step by step approach not optimal respect to space complexity
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        //create two array to store the prefix and suffix product and variable to 
        //maintain product
        int size = nums.size();
        int prefix[size];
        int prefixprod = 1;
        int suffix[size];
        int suffixprod = 1;

        //two pointers one from start and one from end
        int i = 1;
        int j = size - 2;

        //logically first and last element have prefix and suffix prod as 1 
        prefix[0] = 1;
        suffix[size-1] = 1;

        while(i < size && j >= 0){
            //calculate the prefix product for the given index
            prefixprod *= nums[i-1];
            prefix[i] = prefixprod;
            //calculate suffix product similarly
            suffixprod *= nums[j+1];
            suffix[j] = suffixprod;
            i++;
            j--;
        }
        //answer vector
        vector<int> answer;
        for(int i = 0; i < size ; i++){
            answer.push_back(prefix[i]*suffix[i]);
        }
        return answer;
    }
};