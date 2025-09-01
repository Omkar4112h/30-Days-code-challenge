#include<iostream>
using namespace std;

int countDivisors(int N) {
    int cnt = 0;
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            cnt++;
            if (i != N / i) cnt++; 
        }
    }
    return cnt;
}

int main() {
    int N = 12;
    cout << "Number of divisors of " << N << " = " << countDivisors(N) << endl;
    return 0;
}
