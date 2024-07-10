#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0);
	cin >> N;

	queue<int> MyQue;

	for (int i = 1; i <= N; ++i)
	{
		MyQue.push(i);
	}

	while (MyQue.size() != 1)
	{
		MyQue.pop();

		int Top = MyQue.front();
		MyQue.pop();
		MyQue.push(Top);
	}

	cout << MyQue.front();

	return 0;
}