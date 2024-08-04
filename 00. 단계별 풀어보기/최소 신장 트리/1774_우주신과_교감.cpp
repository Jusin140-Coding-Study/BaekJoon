#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


struct dist {
    int point1, point2;
    double distance;
};

struct cmp {

    bool operator()(dist& a, dist& b) {
        return a.distance < b.distance;
    }
};

vector<pair<double, double>> points;
vector<int> parent;
vector<dist> distances;

int N, M;
long long edgeCount = 0;
double answer = 0.f;

int FindRoot(int origin);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    points.resize(N + 1);
    parent.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }


    for (int i = 1; i <= N; ++i) {

        cin >> points[i].first;
        cin >> points[i].second;

    }

    for (int i = 1; i <= N - 1; ++i) {
        for (int k = i + 1; k <= N; ++k) {

            double currentDistX = points[i].first - points[k].first;
            double currentDistY = points[i].second - points[k].second;

            double result = sqrt(pow(currentDistX, 2) + pow(currentDistY, 2));
            distances.push_back({ i, k , result });
        }
    }

    sort(distances.begin(), distances.end(), cmp());

    for (int i = 0; i < M; ++i) {

        int unionNum1, unionNum2;
        cin >> unionNum1 >> unionNum2;

        unionNum1 = FindRoot(unionNum1);
        unionNum2 = FindRoot(unionNum2);

        if (unionNum1 != unionNum2) {
            parent[unionNum1] = unionNum2;
            ++edgeCount;
        }

    }

    for (long long i = 0; i < (int)distances.size(); ++i) {

        int root1 = FindRoot(distances[i].point1);
        int root2 = FindRoot(distances[i].point2);

        if (root1 != root2) {

            parent[root1] = root2;
            answer += distances[i].distance;

        }

    }

    cout.precision(2);

    cout << fixed << answer;

    return 0;
}



int FindRoot(int origin) {

    if (parent[origin] == origin)
        return origin;

    return parent[origin] = FindRoot(parent[origin]);
}

