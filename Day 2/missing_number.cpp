#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int xorall = 0, xorarr = 0;


    for (int i = 1; i <= n + 1; i++) {
        xorall ^= i;
    }

    for (int i = 0; i < n; i++) {
        xorarr ^= arr[i];
    }

    
    return xorall ^ xorarr;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6};  
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Missing number is: " << findMissing(arr, n) << endl;
    return 0;
}
