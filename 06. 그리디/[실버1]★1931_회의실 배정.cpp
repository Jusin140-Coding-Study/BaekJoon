#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int Result = 0;
	cin >> N;
	
	vector<pair<int, int>> V(N);

	// 회의 종료 시간이 빠를 수록 다음 회의와 겹치지 않는데 유리하다는 아이디어가 핵심.
	for (int i = 0; i < N; ++i)
	{
		// 종료 시간 우선 정렬을 위해 종료를 first에 저장
		cin >> V[i].second;
		cin >> V[i].first;
	}

	sort(V.begin(), V.end());

	int iMinEndTime = -1;
	for (int i = 0; i < N; ++i)
	{
		// 종료 시간 순으로 정렬 했으니까, 처음부터 순회하면서 cnt를 증가시킨다.
		// 겹치지 않는 회의가 나오면 종료 시간을 업데이트 한다.
		if (V[i].second >= iMinEndTime)
		{
			iMinEndTime = V[i].first;
			Result++;
		}
	}

	cout << Result;
}