#include<iostream>
using namespace std;

bool is_found(int arr[],int size, int position, int element){
    // Base case:
    if(position == size) {
            return false;     
    }

    if(arr[0]==element){
            return true;
    }
    
    return is_found(arr+1,size , position+1, element);
}

    //Addition of current first eleement with the sum of the rest of the array
int main(){
    int arr[] = {12, 30 ,34 ,23 , 53};

    int ans = is_found(arr, 5 , 0, 53);
    if(ans == 0){
        cout << "The given element is not found in the array"<<endl;
    }
    else    
    cout << "The given element is found in the array"<<endl;

    return 0;
}