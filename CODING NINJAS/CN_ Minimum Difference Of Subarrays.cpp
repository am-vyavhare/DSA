int minimumDifference(int n, vector<int> arr)
{
    //calculate the total of all elements
    // so that we can calculate the difference each by using total - current sum
    int total = 0;
    for(int a : arr){
        total += a;
    }
    //for storing the current on going sum of elements
    int running_sum = 0;
    int minimumdiff = INT_MAX;
    //traverse through the array and calculate the running sum each time 
    for(int i = 0 ; i < n ; i++){
            running_sum += arr[i];
            //calculate difference at current position
            int currdiff = abs(total - 2 * running_sum);
            minimumdiff = min(currdiff,minimumdiff); // keep minimum 
    }
    return minimumdiff;
}


