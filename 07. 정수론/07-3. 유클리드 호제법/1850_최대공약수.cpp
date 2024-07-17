#include <iostream>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    cin >> A >> B;

    long long minNum = min(A, B);
    long long maxNum = max(A, B);

    long long count = max(minNum , maxNum % minNum);

    while (0 != maxNum % minNum) {

        count = maxNum % minNum;

        maxNum = minNum;
        minNum = count;

    }

    for (int i = 0; i < count; ++i) {
        cout << 1;
    }

    return 0;
}
