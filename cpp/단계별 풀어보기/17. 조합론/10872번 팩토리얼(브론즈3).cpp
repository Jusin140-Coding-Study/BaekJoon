/*
* @title    : 10872�� ���丮��(�����3)
* @content  : ���շ�
* @author   : �յ���
* @date     : 240722
* @time     : 0ms
* @memory   : 2020 KB
* @state    : �Ϸ�
*/
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int Result = 1;
	for (int i = 1; i <= N; ++i)
		Result *= i;
	
	cout << Result;

	return 0;
}
