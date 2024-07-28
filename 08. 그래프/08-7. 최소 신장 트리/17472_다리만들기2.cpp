#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
int world[12][12];
bool visited[12][12];

int islandCount = 0;


struct edge {
    int first, end, value;
};

struct cmp {
    bool operator()(edge& a, edge& b) {
        return a.value > b.value;
    }
};

priority_queue<edge, vector<edge>, cmp> pq;
vector<edge> v;

int dx[4] = { 1, -1, 0 , 0 };
int dy[4] = { 0, 0 , 1, -1 };

int answer = 0;
int edgeCount = 0;
int parent[7];

void BFS(int row, int col);
int Find(int origin);
void Union(int a, int b);
void GetDistance(int row, int col);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < 7; ++i) {
        parent[i] = i;
    }


    //섬-바다 정보 저장
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> world[i][j];
        }
    }

    //섬 구분해두기
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <=M; ++j) {

            if (!visited[i][j] && 0 != world[i][j]) {
                BFS(i, j);
            }
        }
    }

    //거리재기
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (0 != world[i][j]) {

                GetDistance(i, j);
            }
        }
    }


    bool isDone = false;

    //최단루트찾기(유니온-파인드)
    while (!pq.empty())
    {

        edge current = pq.top();
        pq.pop();

        if (Find(current.first) != Find(current.end)) {

            answer += current.value;
            ++edgeCount;
            Union(current.first, current.end);

        }

        if (edgeCount >= islandCount - 1) {
            isDone = true;
            break;
        }
    }

    if (isDone) {
        cout << answer;
    }
    else {
        cout << -1;
    }



    return 0;
}


void BFS(int row, int col) {

    queue<pair<int, int>> q;

    q.push({ row, col });

    ++islandCount;
    
    world[row][col] = islandCount;

    while (!q.empty()) {

        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {

            if (!visited[current.first + dy[i]][current.second + dx[i]]) {
                visited[current.first + dy[i]][current.second + dx[i]] = true;

                if (0 != world[current.first + dy[i]][current.second + dx[i]]) {
                    world[current.first + dy[i]][current.second + dx[i]] = islandCount;
                    q.push({ current.first + dy[i] , current.second + dx[i] });
                }
            }
        }
    }

}

int Find(int origin) {
    
    if (origin == parent[origin])
        return origin;

    return parent[origin] = Find(parent[origin]);

}

void Union(int a, int b) {

    a = Find(a);
    b = Find(b);

    if (a == b)
        return;
    
    parent[a] = b;
    
}

void GetDistance(int row, int col) {

    int start = world[row][col];

    int visited[7] = {false, false, false, false, false, false, false };
    visited[start] = true;

    if (start != world[row + 1][col]) {
        for (int i = row + 1; i <= N; ++i) {

            if (start == world[i][col])
                break;

            if (visited[world[i][col]])
                continue;

            visited[world[i][col]] = true;

            if ((i - row - 1 <= 1 && start != world[i][col] && world[i][col] != 0)||
                 start == world[i][col]) {
                break;
            }

            if (start != world[i][col] && 0 != world[i][col] && i - row - 1 > 1) {
                pq.push({ start,world[i][col], i - row -1 });
                break;
            }

        }
    }

    int visited2[7] = { false, false, false, false, false, false, false };
    visited2[start] = true;

    if (start != world[row][col + 1]) {
        for (int i = col + 1; i <= M; ++i) {

            if (start == world[row][i])
                break;

            if (visited2[world[row][i]])
                continue;

            visited2[world[row][i]] = true;

            if (i - col - 1 <= 1 && start != world[row][i] && world[row][i] != 0) {
                break;
            }

            if (start != world[row][i] && 0 != world[row][i] && i - col - 1 > 1) {

                pq.push({ start,world[row][i], i - col - 1 });
                break;

            }
        }
    }
}



