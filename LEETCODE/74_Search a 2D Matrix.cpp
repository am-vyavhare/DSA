
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //create two variable to maintain the row and col index
        int row = matrix.size();
        int col = matrix[0].size();
        
        //two pointer to use while traversing the matrix
        int start = 0;
        int end = row * col -1;
        //mid index if we consider all row elements as a single array
        int mid = start + (end - start)/2;
        //check until start and end pointer cross each other
        while(start <= end){
            //to get the row index from mid divide it by col and for col index mod it with col
            int element = matrix[mid/col][mid%col];
            //if element found at mid position return true
            if(element == target){
                return 1;
            }
            //if mid is greater then shift to first half part of the matrix
            if(target < element){
                end = mid - 1;
            }
            else{       //otherwise shift to last half part of the array
                start = mid + 1;
            }
            //calcualte the new mid with the same formula
            mid = start + (end - start)/2;
        }      
        return 0;
    }
};