    class Solution {
public:
    int trap(vector<int>& height){
    //step 1 - create two pointer that will point to current start element 
    //and current end element
    int start = 0;
    int end = height.size() - 1;
    //Step 2 - create 2 variable to store the value of leftmax height and rightmax
    //height seen so far with respect to current element which is left max and rightmax
    int leftmax = 0;
    int rightmax = 0;   
    //variable to store total water     
    int totalwater = 0; 
    //Step 3 -Traverse the heights vector till start and end cross by calculating 
    //the total amount of water trap possible
    while(start < end){
        //compare heights at both ends
        //water trapped depends on smaller side 
        if(height[start] < height[end]){
            //if current height(start pointer)is greater than left max then update leftmax
            if(height[start] >= leftmax){
                leftmax = height[start];
            }
            else{
            //if not means leftmax is at smaller height side so calculate water and add
            totalwater = totalwater + leftmax - height[start];
            }
            //update the start pointer
            start++;
        }
        else{
            //if right side is less then check heights[end] is greater than 
            //right max then update right max
            if(height[end] >= rightmax){
                rightmax = height[end];
            }
            else{
                //if not means rightmax is at smaller height side so calculate water and add
                totalwater = totalwater + rightmax - height[end];
            }
            //update the start pointer
            end--;
        }
    }
    return totalwater;
    }
};