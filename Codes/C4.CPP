#include <bits/stdc++.h>
using namespace std;

int countDigits(int num) {
    if (num == 0) return 0;
    return 1 + countDigits(num / 10);  // Recursive division by 10
}


int main() {

    // TODO: METHOD 1 - looping method
    int num = 12345;
    int count = 0;

    while (num != 0) {
        num /= 10;  // Divide the number by 10 in each iteration
        count++;    // Increment the count
    }

    cout << "Number of digits: " << count;

    // TODO: METHOD 2 - String conversion
    int num = 12345;
    string numStr = to_string(num);
    cout<< "Number of digits: " << numStr;

    // TODO: METHOD 3 - Logarithm
    int num = 12345;

    int digits = log10(num) + 1;  // Logarithmic method to calculate digits
    cout << "Number of digits: " << digits;

    // TODO: METHOD 4 - RECURSION
    int num = 12345;
    cout << "Number of digits: " << countDigits(num);



    return 0;
}
