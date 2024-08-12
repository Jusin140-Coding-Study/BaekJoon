#include <iostream>
#include <limits.h>

using namespace std;

long long DP[100001][5][5];

int distances[5][5] = { 0, 2, 2, 2,  2, //0
                        2, 1, 3, 4, 3, //1
                        2, 3, 1, 3, 4, //2
                        2, 4, 3, 1, 3, //3
                        2, 3, 4, 3, 1 //4
};


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count = 1;
    fill_n(&DP[0][0][0], 100001 * 5 * 5, LLONG_MAX);

    DP[0][0][0] = 0;


    while (true) {

        int command;
        cin >> command;

        if (0 == command) break;

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {

                if (LLONG_MAX == DP[count - 1][i][j])
                    continue;

                if (command != j) {
                    DP[count][command][j] = min(DP[count][command][j] , distances[i][command] + DP[count - 1][i][j]);
                }

                if (command != i) {
                    DP[count][i][command] = min(DP[count][i][command], distances[j][command] + DP[count - 1][i][j]);
                }
            }
        }

        ++count;
    }

    long long answer = LLONG_MAX;

    for (int i = 0; i < 5; ++i) {

        for (int j = 0; j < 5; ++j) {

            if (LLONG_MAX != DP[count -1][i][j]) {
                answer = min(answer, DP[count - 1][i][j]);
            }

        }

    }

    cout << answer;

    return 0;
}

