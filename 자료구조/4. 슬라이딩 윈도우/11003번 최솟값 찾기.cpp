#include <iostream>
#include <deque>
using namespace std;
typedef pair<int, int> Node;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iTotalSize = 0;
	int iWindowSize = 0;

	cin >> iTotalSize >> iWindowSize;

	deque<Node> deqWindow;

	for (int i = 0; i < iTotalSize; ++i)
	{
		int iNum;
		cin >> iNum;

		while (deqWindow.size() > 0 && deqWindow.back().second > iNum)
		{
			deqWindow.pop_back();
		}

		deqWindow.push_back(Node(i, iNum));

		if (deqWindow.front().first <= i - iWindowSize)
		{
			deqWindow.pop_front();
		}

		cout << deqWindow.front().second << " ";
	}
}