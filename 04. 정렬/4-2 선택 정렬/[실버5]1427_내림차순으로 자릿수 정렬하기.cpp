#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0);
	string strNum = "";
	vector<int> V(0, 0);
	cin >> N;

	strNum = to_string(N);
	for (auto& c : strNum)
		V.push_back(c - '0');
	
	for (int i = 0; i < V.size(); ++i)
	{
		int MaxNum(1);
		int MaxIndex(i);

		for (int j = i; j < V.size(); ++j)
		{
			if (MaxNum < V[j])
			{
				MaxNum = V[j];
				MaxIndex = j;
			}
		}

		swap(V[i], V[MaxIndex]);
	}

	for (auto& n : V)
		cout << n;
}