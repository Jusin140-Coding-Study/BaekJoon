#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

void BFS(int node);

static vector<vector<int>> v;
static vector<int> answer;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    v.resize(N + 1);
    answer.resize(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int start, end;
        cin >> start >> end;
        v[start].push_back(end);
    }

    for (int i = 1; i < v.size(); ++i) {
        BFS(i);
    }

    int maxAnswer = *max_element(answer.begin() + 1, answer.end());

    for (int i = 1; i < answer.size(); ++i) {
        if (maxAnswer == answer[i]) {
            cout << i << " ";
        }
    }

    return 0;
}


void BFS(int node) {

    vector<bool> checked(v.size(), false);
    queue<pair<int, int>> q;

    q.push({ node, 0 });
    checked[node] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();

        for (int i = 0; i < v[current.first].size(); ++i) {
            int next = v[current.first][i];

            if (!checked[next]) {
                checked[next] = true;
                ++answer[next];
                q.push({ next, current.second + 1 });
            }
        }

        q.pop();
    }

}
