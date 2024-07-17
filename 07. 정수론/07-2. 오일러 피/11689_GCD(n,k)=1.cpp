#include <iostream>
#include <cmath>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;
    long long result = N;

    for (long long p = 2; p * p <= N; ++p) {

        if (N % p == 0) {

            result = result - result / p;

            while (0 == N % p) {
                N /= p;
            }
        }
    }

    if (N > 1) {
        result = result - result / N;
    }

    cout << result;

    return 0;
}
