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

	// ȸ�� ���� �ð��� ���� ���� ���� ȸ�ǿ� ��ġ�� �ʴµ� �����ϴٴ� ���̵� �ٽ�.
	for (int i = 0; i < N; ++i)
	{
		// ���� �ð� �켱 ������ ���� ���Ḧ first�� ����
		cin >> V[i].second;
		cin >> V[i].first;
	}

	sort(V.begin(), V.end());

	int iMinEndTime = -1;
	for (int i = 0; i < N; ++i)
	{
		// ���� �ð� ������ ���� �����ϱ�, ó������ ��ȸ�ϸ鼭 cnt�� ������Ų��.
		// ��ġ�� �ʴ� ȸ�ǰ� ������ ���� �ð��� ������Ʈ �Ѵ�.
		if (V[i].second >= iMinEndTime)
		{
			iMinEndTime = V[i].first;
			Result++;
		}
	}

	cout << Result;
}