#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 그리디 알고리즘
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 그리디 알고리즘 수행 과정
	// 1. 해 선택 : 현재 상태에서 가장 최선이라고 생각되는 해를 선택한다.
	// 2. 적절성 검사 : 현재 선택한 해가 전체 문제의 제약 조건에 벗어나지 않는지 검사한다.
	// 3. 해 검사 : 현재까지 선택한 해 집합이 전체 문제를 해결할 수 있는지 검사한다.
	//				전체 문제를 해결하지 못한다면 1.로 돌아가 같은 과정을 반복한다.

	int N = 0; int Result = 0;
	cin >> N;

	// 내림 차순의 우선순위 큐
	priority_queue<int, vector<int>, greater<>> PQ;

	for (int i = 0; i < N; ++i)
	{
		int Input = 0;
		cin >> Input;

		PQ.push(Input);
	}

	while (1 < PQ.size())
	{
		int first = PQ.top();
		PQ.pop();
		int second = PQ.top();
		PQ.pop();

		Result += first + second;
		PQ.push(first + second);
	}

	cout << Result;
	return 0;
}