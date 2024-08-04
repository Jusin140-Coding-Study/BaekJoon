#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int N, M, H;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };

int tomatos[100][100][100];
bool visited[100][100][100];
queue<tuple<int, int, int>> q;

int answer = 0;
bool isAlreadyDone = true;

void BFS();

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    //배열 채우기
    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                int current;
                cin >> current;

                if (isAlreadyDone && 0 == current) {
                    isAlreadyDone = false;
                }


                tomatos[h][n][m] = current;

            }
        }
    }


    if (isAlreadyDone) {
        cout << 0;
        return 0;
    }

    BFS();

    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                
                if (!visited[h][n][m] && -1 != tomatos[h][n][m]) {
                    cout << -1;
                    return 0;
                }

            }
        }
    }


    cout << answer - 1;

    return 0;
}


void BFS() {

    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                //익은 토마토
                if (1 == tomatos[h][n][m]) {
                    q.push({ h, n, m });
                    visited[h][n][m] = true;
                }
            }
        }
    }

    //answer
    int count = 0;
    int nowSize = q.size();

    while (!q.empty()) {

        int row, col, height;
        tie(height, col, row) = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {
            int nextRow = row + dx[i];
            int nextCol = col + dy[i];
            int nextHeight = height + dh[i];

            //범위 제한
            if (nextRow >= M || nextCol >= N || nextHeight >= H ||
                nextRow < 0 || nextCol < 0 || nextHeight < 0 ||
                visited[nextHeight][nextCol][nextRow]) {
                continue;
            }

            visited[nextHeight][nextCol][nextRow] = true;
            int currentValue = tomatos[nextHeight][nextCol][nextRow];

            if (0 == currentValue) {
                q.push({ nextHeight, nextCol, nextRow });
            }
        }

        ++count;

        if (nowSize == count) {
            count = 0;
            nowSize = q.size();
            ++answer;
        }

    }

}

