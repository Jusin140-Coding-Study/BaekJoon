/*
* @title    : 25192�� �λ缺 ���� ������(�ǹ�4)
* @content  : ��ȭ 2
* @author   : �յ���
* @date     : 240723
* @time     : 36 ms
* @memory   : 8312 KB
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

	unordered_set<string> usData;
	int N;
	cin >> N;
	int iCount = 0;
	for (int i = 0; i < N; ++i)
	{
		string a;
		cin >> a;
		if (a == "ENTER")
			unordered_set<string>().swap(usData);

		else
		{
			if (usData.find(a) == usData.end())
			{
				++iCount;
				usData.emplace(a);
			}
		}	
	}
	cout << iCount;

	return 0;
}
