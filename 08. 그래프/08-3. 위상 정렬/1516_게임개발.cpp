#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
int times[501] = { 0 };
int Count[501] = { 0 };

vector<int> answer;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	v.resize(N + 1);
	answer.resize(N + 1);


	for (int i = 1; i < N + 1; ++i) {

		cin >> times[i];

		int num;
		cin >> num;

		while (num != -1) {

			v[num].push_back(i);
			++Count[i];

			cin >> num;
		}
	}

	queue<pair<int, int>> q;

	for (int i = 1; i < N + 1; ++i) {

		if (0 == Count[i]) {
			q.push({i, times[i]});
		}
	}


	while (!q.empty()) {

		pair<int, int> cur = q.front();

		for (int i = 0; i < v[cur.first].size(); ++i) {

			int next = v[cur.first][i];
			
			--Count[next];
			answer[next] = max(answer[next], cur.second + times[next]);

			if (0 == Count[next]) {

				q.push({ next, answer[next] });
				
			}

		}
		
		q.pop();
		answer[cur.first] = cur.second;

	}

	for (int i = 1; i < answer.size(); ++i) {

		cout << answer[i] << "\n";

	}


	return 0;
}