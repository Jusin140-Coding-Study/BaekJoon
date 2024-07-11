#include <iostream>
#include <queue>
using namespace std;

struct abs_sort {
	bool operator()(int _iNum1, int _iNum2)
	{
		int iAbs1 = abs(_iNum1);
		int iAbs2 = abs(_iNum2);
		if (iAbs1 == iAbs2)
			return _iNum1 > _iNum2;
		else
			return iAbs1 > iAbs2;
	}
};

int main()
{
	int iN;
	cin >> iN;

	vector<int> vecInput(iN, 0);
	priority_queue<int, vector<int>, abs_sort> qInput;
	vector<int> vecResult;

	for (int i = 0; i < iN; ++i)
	{
		int iInput;

		cin >> iInput;

		if (iInput == 0)
		{
			if (qInput.empty())
				vecResult.push_back(0);

			else
			{
				vecResult.push_back(qInput.top());
				qInput.pop();
			}

		}

		else
			qInput.push(iInput);
	}

	for (int i = 0; i < vecResult.size(); ++i)
	{
		cout << vecResult[i] << '\n';
	}
}