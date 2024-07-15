#include <iostream>
#include <vector>

using namespace std;

static bool isAnswer = false;

void DFS(vector<vector<int>>& a, int count, vector<bool> visit, int prevNum);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> P;
    P.resize(N, {});

    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;

        P[s].push_back(e);
        P[e].push_back(s);
    }

    vector<bool> visited(N, false);

    for (int i = 0; i < P.size(); ++i) {
        
        DFS(P, 0, visited, i);

    }

    if (isAnswer)
        cout << 1;
    else
        cout << 0;


    return 0;
}

void DFS(vector<vector<int>>& a, int count, vector<bool> visit, int prevNum) {

    if (isAnswer)
        return;

    ++count;
    visit[prevNum] = true;


    if (5 <= count) {
        isAnswer = true;
        return;
    }


    for (int j = 0; j < a[prevNum].size(); ++j) {

        if (!visit[a[prevNum][j]]) {
            DFS(a, count, visit, a[prevNum][j]);
        }
    }

}

