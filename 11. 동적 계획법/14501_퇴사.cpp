#include <iostream>

using namespace std;
int DP[17];

//비용 시간
int P[17];
int T[17];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {

        cin >> T[i];
        cin >> P[i];

    }

    int currentMax = 0;

    for (int i = 1; i <= N + 1; ++i) {

        int nextIndex = i + T[i];

        DP[i] = max(currentMax, DP[i]);

        if (nextIndex > N + 1) {
            DP[N + 1] = max(DP[N + 1], DP[i]);
        }
        else {

            DP[nextIndex] = max(DP[nextIndex], P[i] + DP[i]);
        }

        currentMax = max(currentMax, DP[i]);

    }

    cout << DP[N + 1];


    return 0;
}

