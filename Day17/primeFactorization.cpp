#include <iostream>
#include <vector>
using namespace std;

vector<long long> primeFactorization(long long n) {
    vector<long long> factors;

    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    for (long long p = 3; p * p <= n; p += 2) {
        while (n % p == 0) {
            factors.push_back(p);
            n /= p;
        }
    }

    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

int main() {
    long long N;
    cin >> N;

    vector<long long> result = primeFactorization(N);

    for (long long f : result) {
        cout << f << " ";
    }
    cout << "\n";

    return 0;
}
