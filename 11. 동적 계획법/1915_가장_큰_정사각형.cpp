#include <iostream>

using namespace std;

int N, M;
int Origin[1001][1001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int answer = 0;

    for (int i = 0; i < N; ++i) {

        string s;
        cin >> s;

        for (int j = 0; j < M; ++j) {

            Origin[i][j] = s[j] - '0';

            if (1 == Origin[i][j] && i > 0 && j > 0) {

                Origin[i][j] = min(min(Origin[i - 1][j - 1], Origin[i][j - 1]), Origin[i - 1][j]) + Origin[i][j];
                
            }

            answer = max(answer, Origin[i][j]);
        }
    }


    cout << answer * answer;

    return 0;
}

