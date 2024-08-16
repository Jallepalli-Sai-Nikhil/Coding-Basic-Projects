#include <bits/stdc++.h>
using namespace std;

int main(){
    // Todo: Method 1
    int a = 5, b = 10;
    int temp

    temp = a;
    a = b;
    b = temp;

    // Todo: Method 2
    a = a + b;
    b = a - b;
    a = a - b;

    // Todo: Method 3
    a = a * b;
    b = a / b;
    a = a / b;

    // Todo: Method 4
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    
    return 0;
}