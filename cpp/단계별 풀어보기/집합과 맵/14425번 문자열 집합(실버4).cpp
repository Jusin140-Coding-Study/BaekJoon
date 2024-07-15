/*
* @title    : 14425�� ���ڿ� ����(�ǹ�4)
* @content  : ���հ� ��
* @author   : �յ���
* @date     : 240714
* @time     : 52 ms
* @memory   : 7768 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	unordered_set<string> usWords(N);
	for (int i = 0; i < N; ++i)
	{
		string a;
		cin >> a;
		usWords.insert(a);
	}

	int iCount = 0;
	for (int i = 0; i < M; ++i)
	{
		string a;
		cin >> a;
		if (usWords.find(a) != usWords.end())
			iCount++;
	}

	cout << iCount;

	return 0;
}
