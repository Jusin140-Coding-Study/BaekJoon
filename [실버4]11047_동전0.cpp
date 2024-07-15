#include <iostream>
#include <algorithm>
#include <vector>
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
	// 3. 해 검사 : 현재까지 선태갛ㄴ 해 집합이 전체 문제를 해결할 수 있는지 검사한다.
	//				전체 문제를 해결하지 못한다면 1.로 돌아가 같은 과정을 반복한다.

	// N : 동전 종류의 개수
	// K : 맞춰야 하는 금액
	int N = 0; int K = 0; int Result = 0;
	cin >> N >> K;

	vector<int> V(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> V[i];

	reverse(V.begin(), V.end());

	for (int i = 0; i < N; ++i)
	{
		// 배열에 들어있는 동전의 금액이 K보다 작다면?
		if (V[i] < K)
		{
			Result += K / V[i];
			K = K % V[i];
		}

		// if (K == 0) break;
	}

	cout << Result;
}