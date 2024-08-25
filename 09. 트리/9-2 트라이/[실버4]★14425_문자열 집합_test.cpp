#include <iostream>
#include <map>
#include <string>
using namespace std;

static map<string, bool> myMap;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0; int Result = 0;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string strInput;
		cin >> strInput;

		myMap.emplace(strInput, true);
	}

	for (int i = 0; i < M; ++i)
	{
		string strInput;
		cin >> strInput;

		if (myMap[strInput])
			Result++;
	}

	cout << Result;

	return 0;
}