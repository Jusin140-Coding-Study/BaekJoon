#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

static int N, M, K, X;
static vector<vector<int>> v;
static vector<int> answer;
static vector<bool> checked;

void BFS(int node);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K >> X;

    v.resize(N + 1);

    checked.resize(N + 1, false);
    checked[0] = true;
         
    for (int i = 0; i < M; ++i) {
        int start, end;
        cin >> start >> end;
        v[start].push_back(end);
    }

    BFS(X);

    int count = 0;

    sort(answer.begin(), answer.end(), less<int>());

    for (int i = 0; i < answer.size(); ++i) {
         ++count;
         cout << answer[i] << "\n";
        
    }

    if (0 == count) {
        cout << -1;
    }

    return 0;
}

void BFS(int node)
{

    queue<pair<int, int>> q;

    q.push({ node, 0 });
    checked[node] = true;

    while (!q.empty()) {

        pair<int,int> current = q.front();

        for (int i = 0; i < v[current.first].size(); ++i) {
            
            int nextIdx = v[current.first][i];

            if (!checked[nextIdx] && current.second < K) {
                q.push({ nextIdx , current.second + 1});
                checked[nextIdx] = true;
            }
        }

        if (current.second == K) {
            answer.push_back(current.first);
        }

        q.pop();

    }


}
