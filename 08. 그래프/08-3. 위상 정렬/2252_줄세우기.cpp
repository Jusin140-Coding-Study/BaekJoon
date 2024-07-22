#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> students;
int D[32001] = {0};

vector<int> answer;

queue<int> q;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	students.resize(N + 1);

	for (int i = 0; i < M; ++i) {

		int num1, num2;
		cin >> num1 >> num2;

		students[num1].push_back(num2);
		++D[num2];

	}

	for (int i = 1 ; i < students.size(); ++i) {

		if (0 == D[i]) {
			q.push(i);
		}

	}

	while (!q.empty()) {

		int current = q.front();
		

		for (int i = 0; students[current].size() > i; ++i) {

			int next = students[current][i];

			--D[next];

			if (0 == D[next]) {
				q.push(next);
			}

		}

		q.pop();
		answer.push_back(current);
	}

	for (int i = 0; i < answer.size(); ++i) {

		cout << answer[i] << " ";
	}


	return 0;
}