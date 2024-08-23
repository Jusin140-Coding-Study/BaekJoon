#include <iostream>
#include <vector>

using namespace std;

vector<int> origin;
vector<int> DP;
int N;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    origin.resize(N);
    DP.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> origin[i];
    }

    int answer = 0;

    for (int i = 0; i < N; ++i) {
        DP[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (origin[i] > origin[j]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }

        answer = max(answer, DP[i]);
    }


    cout << answer;

    return 0;
}

