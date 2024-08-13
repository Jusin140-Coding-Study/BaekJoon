#include <iostream>
#include <queue>

using namespace std;

pair<int, int> moves[8] = { {2, 1}, {1, 2} , {-2, 1} , {-1, 2},
                          {-2, -1} , {-1, -2}, {2, -1} , {1, -2} };

pair<int, int> dstPos;
pair<int, int> startPos;
bool visited[301][301];

int answer = 1;
int maxSize;

void BFS();

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        answer = 1;

        cin >> maxSize;
        cin >> startPos.first >> startPos.second;
        cin >> dstPos.first >> dstPos.second;


        if (startPos.first == dstPos.first &&
            startPos.second == dstPos.second) {
            cout << 0 << "\n";
            continue;
        }

        BFS();

        cout << answer << "\n";
    }

    return 0;
}

void BFS() {

    fill_n(&visited[0][0], 301 * 301, false);

    queue<pair<int, int>> q;
    q.push({ startPos.first , startPos.second });
    visited[startPos.first][startPos.second] = true;

    int nowSize = q.size();
    int count = 0;

    while (!q.empty()) {

        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            pair<int, int> currentMove = moves[i];
            int curX = currentMove.first + current.first;
            int curY = currentMove.second + current.second;

            if (maxSize <= curX || curX < 0 || maxSize <= curY || curY < 0)
                continue;

            if (dstPos.first == curX && dstPos.second == curY) {
                return;
            }

            if (!visited[curX][curY]) {
                visited[curX][curY] = true;
                q.push({ curX, curY });

            }

        }

        ++count;
        if (count == nowSize) {
            nowSize = q.size();
            count = 0;
            ++answer;
        }
    }


}
