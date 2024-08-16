#include <bits/stdc++.h>
using namespace std;

int main() {

    // TODO: method 1 - Looping 
    int num = 12345;
    int reversed = 0;

    while (num != 0) {
        int digit = num % 10;  // Extract the last digit
        reversed = reversed * 10 + digit;  // Append the digit to reversed number
        num /= 10;  // Remove the last digit from num
    }

    cout << "Reversed Number: " << reversed;

    // TODO: method 2 - String conversion
    int num = 12345;
    string numStr = to_string(num);  // Convert number to string

    reverse(numStr.begin(), numStr.end());  // Reverse the string
    int reversed = stoi(numStr);  // Convert the reversed string back to integer

    cout << "Reversed Number: " << reversed;

    // TODO: method 3 - Bitwise
    int num = 12345;
    int reversed = 0;

    while (num != 0) {
        reversed <<= 3; // Multiplying reversed by 8 (similar to multiplying by 10)
        reversed += (reversed << 1);  // Adding reversed multiplied by 2 (completing * 10)
        reversed += num % 10;  // Add the last digit of num to reversed
        num /= 10;  // Remove last digit from num
    }

    cout << "Reversed Number: " << reversed;

    return 0;
}
