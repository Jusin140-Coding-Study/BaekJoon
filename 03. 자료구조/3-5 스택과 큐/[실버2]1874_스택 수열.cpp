#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> S;
	string Result = "";
	int N(0); int Num(1);
	bool Able(true);
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int Input(0);

		cin >> Input;

		if (Num <= Input)
		{
			while (Num <= Input)
			{
				S.push(Num++);
				Result += "+";
			}
			S.pop();
			Result += "-";
		}
		else
		{
			int Pop = S.top();
			S.pop();

			if (Pop > Input)
			{
				cout << "NO";
				Able = false;
				break;
			}
			else
			{
				Result += "-";
			}
		}
	}

	if (Able)
	{
		for (auto& c : Result)
			cout << c << "\n";
	}
}