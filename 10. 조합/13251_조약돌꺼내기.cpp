#include <iostream>

using namespace std;

int N, M, K;
int num[50];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> M;

    for (int i = 0; i < M; ++i) {
        int input;
        cin >> input;
        N += input;
        num[i] = input;
    }

    cin >> K;

    double rate = 0.0;

    for (int i = 0; i < M; ++i) {

        double currentRate = 1.0;

        if (num[i] < K)
            continue;

        for (int j = 0; j < K; ++j) {

            currentRate *= (double)(((double)num[i] - (double)j) / (double)((double)N - (double)j));

        }

        rate += currentRate;
    }

    cout.precision(16);

    cout << fixed << rate;


    return 0;
}

