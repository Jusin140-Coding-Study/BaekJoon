#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// �׸��� �˰���
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �׸��� �˰��� ���� ����
	// 1. �� ���� : ���� ���¿��� ���� �ּ��̶�� �����Ǵ� �ظ� �����Ѵ�.
	// 2. ������ �˻� : ���� ������ �ذ� ��ü ������ ���� ���ǿ� ����� �ʴ��� �˻��Ѵ�.
	// 3. �� �˻� : ������� ������ �� ������ ��ü ������ �ذ��� �� �ִ��� �˻��Ѵ�.
	//				��ü ������ �ذ����� ���Ѵٸ� 1.�� ���ư� ���� ������ �ݺ��Ѵ�.

	int N = 0; int Result = 0;
	cin >> N;

	// ���� ������ �켱���� ť
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