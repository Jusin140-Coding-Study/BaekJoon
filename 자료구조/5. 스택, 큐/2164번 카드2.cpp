#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	queue<int> qResult;

	for (int i = 1; i <= iN; ++i)
	{
		qResult.push(i);
	}
	
	bool isThrow = true;

	while(qResult.size() > 1)
	{
		// 맨 위의 카드 버리기
		if (isThrow)
		{
			qResult.pop();
		}

		// 맨 위의 카드 아래에 깔기
		else
		{
			qResult.push(qResult.front());
			qResult.pop();
		}

		isThrow = !isThrow;
	}

	cout << qResult.front() << '\n';
}