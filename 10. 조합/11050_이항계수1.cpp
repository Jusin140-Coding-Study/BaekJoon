#include <iostream>

using namespace std;
int N, K;

int D[11][11];

int Combination(int _total, int _pickNum);


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;


    for (int i = 0; i <= N; ++i) {

        D[i][1] = i;
        D[i][i] = 1;
        D[i][0] = 1;

    }


    for (int i = 2; i <= N; ++i) {

        for (int j = 1; j <= i; ++j) {

            D[i][j] = D[i - 1][j] + D[i - 1][j - 1];

        }

    }

    cout << D[N][K];

    return 0;
}

int Combination(int _total, int _pickNum) {

    if (_total == _pickNum || _total < 1 || _pickNum < 1)
        return 1;

    return Combination(_total - 1, _pickNum) + Combination(_total - 1, _pickNum - 1);

}

