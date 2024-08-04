#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int M, N;
int tomatos[1005][1005];

vector<int> answer;
bool isAlreayDone = true;
bool visited[1005][1005];

void BFS();

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int days = 0;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;


    for (int n = 0; n <= N + 1; ++n) {

        fill_n(tomatos[n], M + 2, -1);
    }
    

    for (int n = 1; n <= N; ++n) {

        for (int m = 1; m <= M; ++m) {

            int current;
            cin >> current;

            if (0 == current && isAlreayDone)
                isAlreayDone = false;


            tomatos[n][m] = current;
        }
    }

    //이미 처음부터 다 익어있는 경우
    if (isAlreayDone) {
        cout << 0;
        return 0;
    }

    BFS();

    for (int n = 1; n <= N; ++n) {
        for (int m = 1; m <= M; ++m) {

            if (0 == tomatos[n][m] && !visited[n][m]) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << days - 1;

    return 0;
}

void BFS(){

    queue<pair<int, int>> q;

    for (int n = 1; n <= N; ++n) {
        for (int m = 1; m <= M; ++m) {
            if (1 == tomatos[n][m]) {
                q.push({ n, m });
                visited[n][m] = true;
            }
        }
    }

    int nowSize = q.size();
    int count = 0;

    while (!q.empty()) {

        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int next = tomatos[current.first + dx[i]][current.second + dy[i]];

            if (!visited[current.first + dx[i]][current.second + dy[i]]) {
                visited[current.first + dx[i]][current.second + dy[i]] = true;

                if (0 == next) {
                    q.push({ current.first + dx[i], current.second + dy[i] });
                }
            }
        }

        count++;
        if (count == nowSize) {
            ++days;
            nowSize = q.size();
            count = 0;
        }

    }

}

