#include<iostream>
using namespace std;

int add_array_elements(int arr[], int size) {
    // Base case:
    if(size == 0) {
        return 0;     
    }

    if(size == 1) {
        return arr[0];     
    }

    //Addition of current first eleement with the sum of the rest of the array
    int sum = arr[0] + add_array_elements(arr + 1, size - 1);
    
    return sum;
}

int main(){
    int arr[] = {12, 30 ,34 ,23 , 53};

    int ans = add_array_elements(arr, 5);
    cout << "Sum of all Array elements is "<<ans<<endl;

    return 0;
}