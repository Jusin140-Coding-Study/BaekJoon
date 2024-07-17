#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long min, max;
    cin >> min >> max;

    vector<bool> v(max - min + 1, false);
    long long answer = 0;

    for (long long i = 2; i * i <= max; ++i) {

        long long pow = i * i;

        long long start = min / pow;

        if (0 != min % pow) {
            start += 1;
        }

        for (long long k = start; k * pow <= max; ++k) {
            v[k * pow - min] = true;
        }
    }

    for (long long i = 0; i < v.size(); ++i) {
        if (false == v[i]) {
            ++answer;
        }
    }

    cout << answer;


    return 0;
}
