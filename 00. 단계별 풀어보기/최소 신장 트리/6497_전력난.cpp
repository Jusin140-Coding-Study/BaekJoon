#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {

    int first, second, value;

};

struct cmp {
    bool operator()(edge a, edge b) {
        return a.value < b.value;
    }
};

vector<edge> roads;
vector<int> parent;

int FindRoot(int origin);
void Union(int a, int b);

int M, N;
int answer = 0;
int edgeCount = 0;
int total = 0;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {

        cin >> M >> N;

        if (0 == M && 0 == N)
            break;


        parent.resize(M);
        roads.resize(N);

        //유니온 배열 초기화
        for (int i = 0; i < M; ++i) {
            parent[i] = i;
        }

        for (int i = 0; i < N; ++i) {
            roads[i] = {};
        }


        total = 0;
        answer = 0;
        edgeCount = 0;

        //그래프 정보 저장
        for (int i = 0; i < N; ++i) {
            cin >> roads[i].first;
            cin >> roads[i].second;
            cin >> roads[i].value;

            total += roads[i].value;
        }

        sort(roads.begin(), roads.end(), cmp());

        for (int i = 0; i < N; ++i) {

            int root1 = FindRoot(roads[i].second);
            int root2 = FindRoot(roads[i].first);

            if (root1 == root2)
                continue;

            parent[root1] = root2;

           answer += roads[i].value;
           ++edgeCount;

            if (edgeCount == M - 1)
                break;
        }


        cout << total - answer << "\n";

    }

    return 0;
}


int FindRoot(int origin) {

    if (origin == parent[origin])
        return origin;

    return parent[origin] = FindRoot(parent[origin]);
}


void Union(int a, int b) {

    a = FindRoot(a);
    b = FindRoot(b);

    if (a == b)
        return;

    parent[a] = b;


}