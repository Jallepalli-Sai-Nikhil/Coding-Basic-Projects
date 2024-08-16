#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 10, b = 20;

    // Todo: Method 1
    if(a > b){
        cout << "a is greater than b" << endl;
    }else{
        cout << "b is greater than a" << endl;
    }

    // Todo: Method 2
    int largest = if(a < b) ? a : b;

    // Todo: Method 3
    int large = max(a, b);


    return 0;
}