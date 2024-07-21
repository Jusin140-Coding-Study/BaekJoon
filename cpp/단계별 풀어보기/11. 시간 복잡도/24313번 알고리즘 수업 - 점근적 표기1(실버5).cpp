/*
* @title    : 24313번 알고리즘 수업 - 점근적 표기1(실버5)
* @content  :
* @author   : 손동찬
* @date     : 240709
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
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