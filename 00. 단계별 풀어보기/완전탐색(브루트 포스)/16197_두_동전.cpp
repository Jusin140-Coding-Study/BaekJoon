#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int N, M;
vector<vector<int>> board;

// - 1 : ¶³¾îÁü , 0 : ºóÄ­ 1: º®
vector<pair<int, int>> coinPos;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0 , 0 };

void DFS(pair<int, int> _pos1, pair<int, int> _pos2, int _count);

int answer = INT_MAX;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    board.resize(N + 2, vector<int>(M + 2, -1));

    for (int i = 1; i < N + 1; ++i) {
        for (int j = 1; j < M + 1; ++j) {

            char sign;
            cin >> sign;

            if (sign == '.') {
                board[i][j] = 0;
            }
            else if (sign == '#') {
                board[i][j] = 1;
            }
            else if (sign == 'o') {
                board[i][j] = 0;
                coinPos.push_back({ i, j });
            }
        }
    }

    DFS(coinPos[0], coinPos[1], 0);


    if (INT_MAX == answer) {
        cout << -1;
    }
    else {
        cout << answer;
    }


    return 0;
}


void DFS(pair<int, int> _pos1, pair<int, int> _pos2, int _count) {

    if (_count >= 10) {
        return;
    }

    for (int i = 0; i < 4; ++i) {

        pair<int, int> nextPos1 = { _pos1.first + dy[i], _pos1.second + dx[i] };
        pair<int, int> nextPos2 = { _pos2.first + dy[i], _pos2.second + dx[i] };

        if (board[nextPos2.first][nextPos2.second] == -1 &&
            board[nextPos1.first][nextPos1.second] == -1) {
            continue;
        }

        //º® ÀÏ¶§
        if (board[nextPos1.first][nextPos1.second] == 1) {
            nextPos1 = _pos1;
        }

        if (board[nextPos2.first][nextPos2.second] == 1) {
            nextPos2 = _pos2;
        }

        //ÇÏ³ª°¡ ¶³¾îÁü
        if ((board[nextPos2.first][nextPos2.second] != -1 &&
            board[nextPos1.first][nextPos1.second] == -1) ||
            (board[nextPos2.first][nextPos2.second] == -1 &&
                board[nextPos1.first][nextPos1.second] != -1)) {
            answer = min(answer, _count + 1);
            continue;
        }

        DFS(nextPos1, nextPos2, _count + 1);

    }


}

