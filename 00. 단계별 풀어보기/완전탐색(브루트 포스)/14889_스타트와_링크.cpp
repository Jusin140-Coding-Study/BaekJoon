#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> arr;
vector<int> teams;
vector<bool> InTeams;

int answer = INT_MAX;

void DFS(int _depth, int _nextIdx);
void GetDiff();


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    arr.resize(N, vector<int>(N));
    InTeams.resize(N);
    teams.resize(N / 2);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    DFS(0, 0);

    cout << answer;

    return 0;
}


void DFS(int _depth, int _nextIdx) {

    if (_depth == N / 2) {

        GetDiff();
        return;

    }

    for (int i = _nextIdx; i < N; ++i) {

        InTeams[i] = true;
        DFS(_depth + 1, i + 1);
        InTeams[i] = false;
    }

}


void GetDiff() {

    int resultTeam1 = 0;
    int resultTeam2 = 0;

    bool isInTeams = false;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j)
                continue;

            if (InTeams[i] && InTeams[j]) {
                resultTeam1 += arr[i][j];
            }
            else if (!InTeams[i] && !InTeams[j]) {
                resultTeam2 += arr[i][j];
            }
        }
    }

    answer = min(answer, abs(resultTeam1 - resultTeam2));
}

