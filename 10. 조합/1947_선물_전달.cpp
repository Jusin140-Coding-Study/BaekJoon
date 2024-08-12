#include <iostream>

using namespace std;

int N;
int MOD = 1000000000;
long long D[1000001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    D[1] = 0;
    D[2] = 1;

    for (int i = 3; i <= N; ++i) {

        D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % MOD;
    }

    cout << D[N];

    return 0;
}
