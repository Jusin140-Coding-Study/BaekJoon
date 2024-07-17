#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    cin >> A >> B;

    long long  b;
    b = sqrtl(B);

    vector<long long > v(b + 1, 0);

    long long  answer = 0;

    for (long long  i = 0; i <= b; ++i) {

        v[i] = i;

    }

    for (long long  i = 2; i * i <= b; ++i) {

        if (0 == v[i])
            continue;

        for (long long j = i * i; j <= b; j += i) {
            v[j] = 0;
        }

    }

    v[1] = 0;

    for (long long i = 2; i <= b; ++i) {

        if (0 == v[i])
            continue;

        int count = 0;

        for (long long k = i * i; k <= B; k *= i) {

            if (A <= k) {
                ++answer;
            }

            ++count;

            if (k > LLONG_MAX / i) {
                break;
            }
        }
    }


    cout << answer;


    return 0;
}
