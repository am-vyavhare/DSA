class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int start = 0;
        int end = arr.size() - 1;
        //swap the data between start and end element until they meet each other
        while(start<=end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
};