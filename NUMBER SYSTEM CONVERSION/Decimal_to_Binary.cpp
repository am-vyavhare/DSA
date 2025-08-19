#include<iostream>
// #include<math.h> // Not needed if you're not using pow()
using namespace std;

int main() {
    int num;
    cout<<"Enter the number: ";
    cin>>num;

    int bit;
    int answer = 0;
    int power_of_10 = 1; // Start with 10^0

    while(num != 0) {
        bit = num & 1;
        answer = (bit * power_of_10) + answer; // Multiply by current power of 10
        num = num >> 1;

        power_of_10 *= 10; // Update power for the next digit
    }
    cout<<"Binary is : "<<answer;
    return 0;
}