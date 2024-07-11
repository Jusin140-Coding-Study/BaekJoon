#include <iostream>
#include <deque>
#include <vector>
using namespace std;

typedef pair<int, int> Node;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<Node> D;
	int N(0); int L(0);
	cin >> N >> L;

	for (int i = 1; i <= N; ++i)
	{
		int Input(0);
		cin >> Input;

		while (!D.empty() && D.back().second > Input)
		{
			D.pop_back();
		}
		D.push_back({ i, Input });

		if (D.front().first <= i - L)
			D.pop_front();

		cout << D.front().second << " ";
	}
}