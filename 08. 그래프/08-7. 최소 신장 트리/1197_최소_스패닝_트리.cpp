#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int V, E;
int edgeNum = 0;
int answer = 0;

struct edge {
    int first, second, value;
};

struct cmp {
    bool operator()(edge& a, edge& b) {
        return a.value > b.value;
    }
};

priority_queue<edge, vector<edge>, cmp> q;
vector<int> unionG;
int Find(int a);
void Union(int a, int b);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    unionG.resize(V + 1);

    //에지 그래프 저장
    for (int i = 0; i < E; ++i) {
        int f, s, v;
        cin >> f >> s >> v;
        q.push({ f, s, v });
    }

    //유니온 파인드 배열 초기화
    for (int i = 1; i <= V; ++i) {
        unionG[i] = i;
    }

    while (edgeNum < V - 1) {
        edge current = q.top();
        q.pop();
        
        if (Find(current.first) != Find(current.second)) {            
            Union(current.first, current.second);
            answer += current.value;
            ++edgeNum;
        }        
    }

    cout << answer;

    return 0;
}


int Find(int a) {

    if (a == unionG[a])
        return a;

    return unionG[a] = Find(unionG[a]);

}

void Union(int a, int b) {

    a = Find(a);
    b = Find(b);

    if (a == b) return;
    unionG[a] = b;
}
