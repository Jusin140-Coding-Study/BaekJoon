#include <iostream>

using namespace std;

int DP[1001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= N; ++i) {

        DP[i] = DP[i - 1] + DP[i - 2];
        DP[i] %= 10007;
    }


    cout << DP[N];

    return 0;
}

