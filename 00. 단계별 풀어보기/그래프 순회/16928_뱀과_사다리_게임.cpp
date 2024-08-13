#include <iostream>
#include <queue>

using namespace std;

int moves[100];
int N, M;
int dice[6] = {1, 2, 3, 4, 5, 6};

int answer = 0;

void BFS();

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N + M; ++i) {
        int x, y;
        cin >> x >> y;

        moves[x] = y - x;
    }

    BFS();

    cout << answer;

    return 0;
}

void BFS() {

    queue<pair<int,int>> q;
    q.push({1, 1});

    bool visited[100];

    fill_n(&visited[0], 100, false);
    visited[1] = true;
    visited[0] = true;

    while (!q.empty()) {

        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {

            int next = current.first + dice[i];
            int currentCount = current.second;

            if (100 == next) {
                answer = currentCount;
                return;
            }

            int finNext = next + moves[next];


            if (100 > finNext && !visited[finNext]) {
                visited[finNext] = true;
                q.push({ finNext , currentCount + 1});
            }
            
        }
    }


}

