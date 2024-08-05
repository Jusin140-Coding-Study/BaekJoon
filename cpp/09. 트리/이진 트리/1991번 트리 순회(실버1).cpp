/*
* @title    : 1991번 트리 순회(실버1)
* @content  : 이진 트리
* @author   : 손동찬
* @date     : 240729
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

void PreOrderTraversal(int _iIndex, vector<pair<char, char>>& _vecBinaryTree)
{
	cout << (char)(_iIndex + 'A');

	if (_vecBinaryTree[_iIndex].first != '.')
		PreOrderTraversal(_vecBinaryTree[_iIndex].first - 'A', _vecBinaryTree);

	if (_vecBinaryTree[_iIndex].second != '.')
		PreOrderTraversal(_vecBinaryTree[_iIndex].second- 'A', _vecBinaryTree);
	
}
void InOrderTraversal(int _iIndex, vector<pair<char, char>>& _vecBinaryTree)
{
	if (_vecBinaryTree[_iIndex].first != '.')
		InOrderTraversal(_vecBinaryTree[_iIndex].first - 'A', _vecBinaryTree);

	cout << (char)(_iIndex + 'A');

	if (_vecBinaryTree[_iIndex].second != '.')
		InOrderTraversal(_vecBinaryTree[_iIndex].second - 'A', _vecBinaryTree);
}
void PostOrderTraversal(int _iIndex, vector<pair<char, char>>& _vecBinaryTree)
{
	if (_vecBinaryTree[_iIndex].first != '.')
		PostOrderTraversal(_vecBinaryTree[_iIndex].first - 'A', _vecBinaryTree);

	if (_vecBinaryTree[_iIndex].second != '.')
		PostOrderTraversal(_vecBinaryTree[_iIndex].second - 'A', _vecBinaryTree);

	cout << (char)(_iIndex + 'A');
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<char, char>> vecBinaryTree(N);
	for (int i = 0; i < N; ++i)
	{
		char A, B, C;
		cin >> A >> B >> C;
		vecBinaryTree[A-'A'] = make_pair(B, C);
	}

	PreOrderTraversal(0, vecBinaryTree);
	cout << "\n";
	InOrderTraversal(0, vecBinaryTree);
	cout << "\n";
	PostOrderTraversal(0, vecBinaryTree);

	return 0;
}
