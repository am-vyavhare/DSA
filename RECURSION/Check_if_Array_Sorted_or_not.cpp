#include<iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    // Base case: an array of size 0 or 1 is sorted
    if(size == 0 || size == 1) {
        return true;     
    }
    // Check if the first element is greater than the second
    if(arr[0] > arr[1]) {
        return false;     
    }
    // Recursive call to check the rest of the array  
    return isSorted(arr + 1, size - 1); // Move to the next element
    
}

int main(){
    int arr[] = {23,45,65,66,78};

    int ans = isSorted(arr, 5);
    if(ans){
        cout << "Array is sorted" << endl;
    }   
    else{
        cout << "Array is not sorted" << endl;
    }

    return 0;
}