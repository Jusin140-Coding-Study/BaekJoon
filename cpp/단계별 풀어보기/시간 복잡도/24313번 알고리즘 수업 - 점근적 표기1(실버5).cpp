/*
* @title    : 24313�� �˰��� ���� - ������ ǥ��1(�ǹ�5)
* @content  :
* @author   : �յ���
* @date     : 240709
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

	int a, b, c, n;
	cin >> a >> b;
	cin >> c;
	cin >> n;

	int iResult;
	if(a*n + b <= c*n && a<=c) iResult = 1;
	else iResult = 0;

	cout << iResult << "\n";
}