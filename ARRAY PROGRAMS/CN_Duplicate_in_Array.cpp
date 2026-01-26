int findDuplicate(vector<int> &arr) 
{
    int answer = 0;

    // Step 1:
    // XOR all the elements of the array.
    // All numbers from 1 to N-1 appear once,
    // except one number which appears twice.
    for(int i = 0; i < arr.size(); i++){
        answer = answer ^ arr[i];
    }

    // Step 2:
    // XOR numbers from 1 to N-1.
    // These numbers will cancel out the non-duplicate elements.
    for(int i = 1; i < arr.size(); i++){
        answer = answer ^ i;
    }

    // Step 3:
    // All numbers except the duplicate cancel out.
    // The remaining value in 'answer' is the duplicate number.
    return answer;
}
