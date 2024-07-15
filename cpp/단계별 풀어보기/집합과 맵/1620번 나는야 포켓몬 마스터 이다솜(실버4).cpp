/*
* @title    : 1620�� ���¾� ���ϸ� ������ �̴ټ�(�ǹ�4)
* @content  : ���հ� ��
* @author   : �յ���
* @date     : 240714
* @time     : 120 ms
* @memory   : 25140 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unordered_map<string, int> umStrInt;
	unordered_map<int, string> umIntStr;

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		string a;
		cin >> a;
		umStrInt[a] = i;
		umIntStr[i] = a;
	}

	for (int i = 0; i < M; ++i)
	{
		string a;
		cin >> a;
		if (isdigit(a[0]))
			cout << umIntStr[stoi(a)] << "\n";
		else
			cout << umStrInt[a] << "\n";
	}

	return 0;
}
