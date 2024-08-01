#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0; int Result = 0;
	cin >> N >> M;

	vector<string> vecStrings;

	for (int i = 0; i < N; ++i)
	{
		string strInput = "";
		cin >> strInput;

		vecStrings.push_back(strInput);
	}

	sort(vecStrings.begin(), vecStrings.end());

	for (int i = 0; i < M; ++i)
	{
		string strInput = "";
		cin >> strInput;

		bool bInclude = binary_search(vecStrings.begin(), vecStrings.end(), strInput);
		if (bInclude)
			++Result;
	}

	cout << Result;

	return 0;
}