#include <iostream>

using namespace std;

long long DP[101];
int T;
int N;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 1;

    cin >> T;

    for (int i = 3; i <= 100; ++i) {
        DP[i] = DP[i - 2] + DP[i - 3];
    }

    for (int i = 0; i < T; ++i) {
        cin >> N;
        cout << DP[N]<< "\n";
    }


    return 0;
}

