#include <iostream>
#include <queue>
using namespace std;

struct compare
{
	bool operator()(int o1, int o2) 
	{
		int first_abs = abs(o1);
		int second_abs = abs(o2);
		if (first_abs == second_abs)
		{
			return o1 > o2;
		}
		else
		{
			return first_abs > second_abs;
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, compare> MyQue;

	int N(0);
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int Input(0);
		cin >> Input;

		if (0 == Input)
		{
			if (MyQue.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << MyQue.top() << "\n";
				MyQue.pop();
			}
		}
		else
		{
			MyQue.push(Input);
		}
	}

	return 0;
}