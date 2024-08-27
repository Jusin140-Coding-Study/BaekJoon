#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;

vector<vector<int>> board;
vector<vector<bool>> visited;

int answer = 0;

void DFS(int _depth, int _result, int _prevX, int _prevY);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    board.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    //ㅗ 제외 블록들 DFS 체크
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            visited[i][j] = true;
            DFS(0, board[i][j], j, i);
            visited[i][j] = false;
        }
    }

    //ㅗ 모양 블록 체크
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {

            if(j - 1 >= 0 && j + 1 < M && i + 1 < N)
                answer = max(answer, board[i][j] + board[i][j - 1] + board[i][j + 1] + board[i + 1][j]);
            if (j - 1 >= 0 && j + 1 < M && i - 1 >= 0)
                answer = max(answer, board[i][j] + board[i][j - 1] + board[i][j + 1] + board[i - 1][j]);
            if (i - 1 >= 0 && j + 1 < M && i + 1 < N)
                answer = max(answer, board[i][j] + board[i - 1][j] + board[i][j + 1] + board[i + 1][j]);
            if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < N)
                answer = max(answer, board[i][j] + board[i- 1][j] + board[i][j - 1] + board[i + 1][j]);

        }
    }




    cout << answer;

    return 0;
}

void DFS(int _depth, int _result, int _prevX, int _prevY) {


    if (3 == _depth) {
        answer = max(answer, _result);
        return;
    }


    for (int i = 0; i < 4; ++i) {
        int nextX = _prevX + dx[i];
        int nextY = _prevY + dy[i];

        if (nextX < 0 || nextY < 0 || nextY >= N || nextX >= M || visited[nextY][nextX])
            continue;

        visited[nextY][nextX] = true;
        DFS(_depth + 1, _result + board[nextY][nextX], nextX, nextY);
        visited[nextY][nextX] = false;
    }
}
