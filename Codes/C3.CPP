#include <bits/stdc++.h>
using namespace std;

int main() {

    int a = 10, b = 20, c = 30;

    // TOdo: method 1

    if (a > b && a > c) {
        cout << "Largest: " << a;
    } else if (b > c) {
        cout << "Largest: " << b;
    } else {
        cout << "Largest: " << c;
    }

    // TOdo: method 2
    int largest = max({a,b,c});

    // TOdo: method 3
        int arr[] = {10, 20, 30};
    int largest = arr[0];

    for (int i = 1; i < 3; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // TODO: method 4
    int largest = max(max(a, b), c);

    return 0;
}
