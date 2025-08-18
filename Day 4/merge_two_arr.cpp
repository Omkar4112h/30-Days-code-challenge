#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2); 
}

void merge(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int gap = nextGap(m + n);

    while (gap > 0) {
        int i = 0, j = gap;

        while (j < (m + n)) {
           
            int a, b;

            if (i < m) a = arr1[i];
            else a = arr2[i - m];

            if (j < m) b = arr1[j];
            else b = arr2[j - m];

        
            if (a > b) {
                if (i < m && j < m) swap(arr1[i], arr1[j]);
                else if (i < m && j >= m) swap(arr1[i], arr2[j - m]);
                else swap(arr2[i - m], arr2[j - m]);
            }
            i++;
            j++;
        }
        gap = nextGap(gap);
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    int m = arr1.size();
    int n = arr2.size();

    merge(arr1, arr2, m, n);

    cout << "arr1: ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2: ";
    for (int x : arr2) cout << x << " ";
    return 0;
}
