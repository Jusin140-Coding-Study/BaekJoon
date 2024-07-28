#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct edge {

    int first, second;
    float value;

};

struct cmp {

    bool operator()(edge a, edge b) {
        return a.value < b.value;
    }

};

vector<pair<float, float>> StartPos;
vector<edge> Distance;
vector<int> Parent;

float answer = 0.f;
int edgeCount = 0;

int Find(int origin);
void Union(int a, int b);

int N;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    StartPos.resize(N);
    Parent.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> StartPos[i].first;
        cin >> StartPos[i].second;
    }

    //Union 배열 초기화
    for (int i = 0; i < N; ++i) {
        Parent[i] = i;
    }


    //그래프 저장
    for (int i = 0; i < N; ++i) {

        for (int j = i + 1; j < N; ++j) {
            float firstDiff = StartPos[j].first - StartPos[i].first;
            float secondDiff = StartPos[j].second - StartPos[i].second;

            float calcResult = sqrtf(firstDiff * firstDiff + secondDiff * secondDiff);
            Distance.push_back({ i, j , calcResult });

        }
    }

    //정렬
    sort(Distance.begin(), Distance.end(), cmp());


    for (int i = 0; i < (int)Distance.size(); ++i) {

        if (Find(Distance[i].first) != Find(Distance[i].second)) {

            Union(Distance[i].first, Distance[i].second);
            answer += Distance[i].value;
            ++edgeCount;

        }

        if (edgeCount == N - 1) {
            break;
        }
    }

    answer = (float)((int)(answer * 100.f)) / 100.f;
    cout << answer;

    return 0;
}


int Find(int origin) {

    if (origin == Parent[origin])
        return origin;

    return Parent[origin] = Find(Parent[origin]);

}


void Union(int a, int b) {

    a = Find(a);
    b = Find(b);

    if (a == b)
        return;

    Parent[a] = b;
}
