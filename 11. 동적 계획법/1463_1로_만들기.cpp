#include <iostream>

using namespace std;

int DP[1000001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    DP[2] = 1;
    DP[3] = 1;

    int N;
    cin >> N;

    for (int i = 4; i <= N; ++i) {

        int result = DP[i - 1] + 1;

        if (0 == i % 2) {
            result = min(result, DP[i / 2] + 1);
        }

        if (0 == i % 3) {

            result = min(result, DP[i / 3] + 1);
        }

        DP[i] = result;

    }

    cout << DP[N];


    return 0;
}

