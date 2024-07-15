#include <iostream>
#include <queue>

using namespace std;

static int A[101][101] = { 0 };

void BFS(int dst1, int dst2);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {

		string nums;
		cin >> nums;

		for (int j = 0; j < M; ++j) {
			A[i][j] = nums[j] - '0';
		}
	}

	BFS(N, M);

	cout << A[N-1][M-1];

	return 0;
}

void BFS(int dst1, int dst2) {

	bool visit[101][101] = { false };

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visit[0][0] = true;

	int dx[4] = { 0, 1 ,0 , -1 };
	int dy[4] = { 1, 0 ,-1 , 0 };

	int count = 0;

	while (!q.empty()) {

		pair<int, int> temp = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {

			if (temp.first + dx[i] < 0 || temp.first + dx[i] >= dst1 ||
				temp.second + dy[i] < 0 || temp.second + dy[i] >= dst2)
				continue;

			if (false == visit[temp.first + dx[i]][temp.second + dy[i]] &&
				1 == A[temp.first + dx[i]][temp.second + dy[i]]) {
			
				visit[temp.first + dx[i]][temp.second + dy[i]] = true;

				q.push({ temp.first + dx[i]  ,temp.second + dy[i] });
				A[temp.first + dx[i]][temp.second + dy[i]] = A[temp.first][temp.second] + 1;
		
			}
		}	
	}
	
}