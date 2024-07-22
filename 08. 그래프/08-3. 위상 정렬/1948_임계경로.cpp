#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> v;
vector<vector<pair<int, int>>> vReverse;
vector<int> Count;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int roadCount = 0;

	v.resize(N + 1);
	Count.resize(N + 1);
	vReverse.resize(N + 1);

	for (int i = 0; i < M; ++i) {

		int s, e, t;
		cin >> s >> e >> t;

		v[s].push_back({ e, t });
		vReverse[e].push_back({ s, t });
		++Count[e];

	}

	int start, end;
	cin >> start >> end;

	queue<int> q;
	q.push(start);

	vector<int> answer;
	answer.resize(N + 1);

	while (!q.empty()) {

		int cur = q.front();

		for (int i = 0; i < v[cur].size(); ++i) {

			pair<int, int> next = v[cur][i];
			--Count[next.first];
			answer[next.first] = max(answer[next.first], answer[cur] + next.second);
			
			if (0 == Count[next.first]) {
				q.push(next.first);
			}


		}

		q.pop();

	}

	int resultCount = 0;
	vector<bool> visited;
	visited.resize(N + 1);

	queue<int> rqueue;
	rqueue.push(end);
	visited[end] = true;

	while (!rqueue.empty()) {

		int now = rqueue.front();
		rqueue.pop();

		for (int i = 0; i < vReverse[now].size(); ++i) {

			pair<int, int> next = vReverse[now][i];
			
			if (answer[next.first] + next.second == answer[now]) {
				resultCount++;

				if (visited[next.first] == false) {
					visited[next.first] = true;
					rqueue.push(next.first);
				}
			}


		}


	}


	cout << answer[end] << "\n" << resultCount;


	return 0;

}