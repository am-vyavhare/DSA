class Solution {
public:
    int maxArea(vector<int>& height){
        //declare two pointer to make container and calculate area;
        int start = 0;
        int end = height.size() - 1;
        int maxarea = 0;
        //traverse and check area each time
        while(start < end){
            //here end - start define width and minimum height is height for container
            int area = (end - start)*(min(height[start],height[end]));
            //set max area
            maxarea = max(area, maxarea);
            //check whether which line is smaller and move it forward if any big line
            //comes then chances of most water container
            if(height[start] < height[end]){
                start++;
            } 
            else{
                end--;
            }
            
        }
        return maxarea;
    }
};