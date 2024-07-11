#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0); int Result(0);
	string strNum = "";

	cin >> N;
	cin >> strNum;

	for (auto& c : strNum)
		Result += c - '0';

	cout << Result;
}