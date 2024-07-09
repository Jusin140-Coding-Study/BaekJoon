/*
* @title    : 12891번 DNA 비밀번호(실버2)
* @content  :
* @author   : 손동찬
* @date     : 240709
* @time     : 292 ms
* @memory   : 3688 KB
* @state    : 완료
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S, P;
	cin >> S >> P;
	string strDNA;
	cin >> strDNA;
	string strCheck = "ACGT";
	unordered_map<char, int> umCheck;
	unordered_map<char, int> umMy;
	int iResult = 0;

	bool CheckDNA(string _strCheck, unordered_map<char, int> _umCheck, unordered_map<char, int> _umMy);

	for (int i = 0; i < strCheck.size(); ++i)
		cin >> umCheck[strCheck[i]];

	for (int i = 0; i < P; ++i)
		umMy[strDNA[i]]++;

	if (CheckDNA(strCheck, umCheck, umMy)) iResult++;

	for (int i = P; i < S; ++i)
	{
		umMy[strDNA[i-P]]--;
		umMy[strDNA[i]]++;
		if (CheckDNA(strCheck, umCheck, umMy)) iResult++;
	}

	cout << iResult << "\n";

	return 0;
}

bool CheckDNA(string _strCheck, unordered_map<char, int> _umCheck, unordered_map<char, int> _umMy)
{
	bool bCheck = true;

	for (int i = 0; i < _strCheck.size(); ++i)
	{
		if (_umCheck[_strCheck[i]] > _umMy[_strCheck[i]])
		{
			bCheck = false;
			break;
		}
	}
	return bCheck;
}