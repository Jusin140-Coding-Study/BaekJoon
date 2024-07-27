/*
* @title    : 26069�� ���Ӽ� ���� ������(�ǹ�4)
* @content  : ��ȭ 2
* @author   : �յ���
* @date     : 240724
* @time     : 0ms
* @memory   : 2160 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_set<string> usNames;
	usNames.emplace("ChongChong");
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string A, B;
		cin >> A >> B;
		if (usNames.find(A) != usNames.end() || usNames.find(B) != usNames.end())
		{
			usNames.emplace(A);
			usNames.emplace(B);
		}
	}
	
	cout << usNames.size();

	return 0;
}
