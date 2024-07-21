/*
* @title    : 1181번 단어 정렬(실버5)
* @content  : 정렬
* @author   : 손동찬
* @date     : 240713
* @time     : 36 ms
* @memory   : 3980 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string s1, string s2) 
{
	if (s1.length() == s2.length()) 
		return s1 < s2;
	
	else 
		return s1.length() < s2.length();	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<string> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end(), compare);
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << "\n";

	return 0;
}