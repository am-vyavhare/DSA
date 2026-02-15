#include<algorithm>
string addBinaryString(string &a, string &b, int n, int m)
{
    //create two pointer to traverse the string from end 
    //and add up the bits by maintaining the carry also 
    int i = n - 1;
    int j = m - 1;
    string result = "";
    int carry = 0;
    while(i >= 0 || j >= 0 || carry !=0){
        //to update the bit sum with the last carry value
        int sum = carry;
        if(i >= 0){
            sum = sum + a[i] -'0'; //char to int with ascii conversion
            i--;
        }
        if(j >= 0){
            sum = sum + b[j] -'0'; //char to int with ascii conversion
            j--;
        }
        //same conversion for int to string
        result = result +char((sum % 2) + '0');
        carry = sum/2;
    }
    //since we appended the digits from the right to left
    reverse(result.begin(), result.end());
    return result;
}