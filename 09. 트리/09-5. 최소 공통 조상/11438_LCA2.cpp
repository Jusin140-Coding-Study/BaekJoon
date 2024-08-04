#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

void BFS(int _start);
int FindRoot(int& _origin, int& _height);

int N, M;
int nodes[21][100001];
vector<int> depth;
vector<vector<int>> graph;

int maxPowDepth = 0;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	graph.resize(N + 1);
	depth.resize(N + 1);

	for (int i = 0; i < N - 1; ++i) {

		int first, second;
		cin >> first >> second;

		graph[first].push_back(second);
		graph[second].push_back(first);
	}

	int currentCount = 1;


	while (currentCount <= N) {
		currentCount <<= 1;
		++maxPowDepth;
	}

	BFS(1);

	for (int i = 1; i <= maxPowDepth; ++i) {
		for (int k = 1; k <= N; ++k) {

			nodes[i][k] = nodes[i - 1][nodes[i - 1][k]];
		}
	}


	cin >> M;

	for (int i = 0; i < M; ++i) {

		int num1, num2;
		cin >> num1 >> num2;


		cout << FindRoot(num1, num2) << "\n";

	}


	return 0;
}


void BFS(int _start) {

	queue<int> q;
	
	vector<bool> visited;
	visited.resize(N + 1);

	visited[_start] = true;
	q.push(_start);

	int level = 1;
	int nowSize = 1;
	int count = 0;

	while (!q.empty()) {

		int current = q.front();
		q.pop();
		
		for (int i = 0; i < (int)graph[current].size(); ++i) {

			int next = graph[current][i];

			if (!visited[next]) {

				visited[next] = true;
				nodes[0][next] = current;
				depth[next] = level;
				q.push(next);

			}
		}
		
		++count;
		if (nowSize == count) {
			count = 0;
			nowSize = q.size();
			++level;
		}
	}
}

int FindRoot(int& _origin1, int& _origin2) {


	if (depth[_origin1] > depth[_origin2]) {

		int temp = _origin1;
		_origin1 = _origin2;
		_origin2 = temp;

	}


	for (int j = maxPowDepth; j >= 0; --j) {


		if (pow(2, j) <= depth[_origin2] - depth[_origin1]) {
			if (depth[_origin1] <= depth[nodes[j][_origin2]]) {
				_origin2 = nodes[j][_origin2];
			}
		}
	}

	for (int j = maxPowDepth; j >= 0 && _origin1 != _origin2; --j) {

		if (nodes[j][_origin1] != nodes[j][_origin2]) {
			_origin1 = nodes[j][_origin1];
			_origin2 = nodes[j][_origin2];
		}

	}

	if (_origin1 != _origin2) {
		return nodes[0][_origin1];
	}
	
	return _origin1;

}
