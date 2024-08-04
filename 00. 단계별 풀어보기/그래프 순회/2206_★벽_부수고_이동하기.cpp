#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <tuple>

using namespace std;

int N, M;
void BFS();

int maps[1002][1002];

vector<vector<vector<int>>> mapCheck;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0 , 1, -1 };

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N : 세로 , M : 가로
    cin >> N >> M;

    //못 가는 구역 -1 세팅 
    for (int i = 0; i <= N + 1; ++i) {
        fill_n(maps[i], M + 2, -1);
    }

    for (int i = 1; i <= N; ++i) {
        string row;
        cin >> row;

        for (int j = 1; j <= M; ++j) {
            maps[i][j] = row[j - 1] - '0';
        }
    }

    if (N == 1 && M == 1) {
        cout << 1;
        return 0;
    }

    mapCheck.resize(2, vector<vector<int>>(N + 1, vector<int>(M + 1, -1)));

    BFS();

    return 0;
}



void BFS() {

    queue<tuple<int, int, bool>> q;

    q.push({ 1, 1, false });
    mapCheck[0][1][1] = 1;


    while (!q.empty()) {

        tuple<int, int, bool> current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {

            int col = get<0>(current) + dy[i];
            int row = get<1>(current) + dx[i];
            bool isCrash = get<2>(current);

            if (col == N && row == M) {
                cout << mapCheck[(int)isCrash][get<0>(current)][get<1>(current)] + 1;
                return;
            }

            if (0 == maps[col][row] && -1 == mapCheck[(int)isCrash][col][row]) {
                mapCheck[(int)isCrash][col][row] = mapCheck[(int)isCrash][get<0>(current)][get<1>(current)] + 1;
                q.push({ col, row, isCrash });
            }
            else if (1 == maps[col][row] && !isCrash && -1 == mapCheck[1][col][row]) {
                mapCheck[1][col][row] = mapCheck[(int)isCrash][get<0>(current)][get<1>(current)] + 1;
                q.push({ col, row, true });
            }
        }

    }

    cout << -1;

}