#include<iostream>
#include<math.h> 
using namespace std;

int main() {
    int binary;
    cout<<"Enter the number: ";
    cin>>binary;

    int bit;
    int decimal = 0;
    
    int i = 0;
    while(binary != 0) {
        bit = binary % 10; // since in the memory treated as integer so each and every binary is operated for the and operation so we used moduluo

        if(bit==1){
            decimal = decimal + (bit*pow(2,i));
        }
        binary = binary / 10; // using remainder so no right shift used at this time 
       
        i = i + 1;
    }
    cout<<"Decimal is : "<<decimal;
    return 0;
}