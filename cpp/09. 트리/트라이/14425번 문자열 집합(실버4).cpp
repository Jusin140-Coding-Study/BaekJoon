/*
* @title    : 14425번 문자열 집합(실버4)
* @content  : 트라이
* @author   : 손동찬
* @date     : 240727
* @time     : 1308 ms
* @memory   : 1091020 KB
* @state    : 완료
*/
#include <iostream>

using namespace std;

class Node
{
public:
	Node* next[26];
	bool isEnd;

	Node() : isEnd(false) 
	{
		fill(next, next+26, nullptr);
	}

	~Node()
	{
		for (auto& child : next)
			delete child;
	}


	void insert(char* key)
	{
		if (*key == 0) isEnd = true;
		else
		{
			int next_index = *key - 'a';
			if (next[next_index] == nullptr)
				next[next_index] = new Node();

			next[next_index]->insert(key + 1);
		}
	}

	Node* find(char* key)
	{
		if (*key == 0) return this;
		 
		int next_index = *key - 'a';
		if (next[next_index] == nullptr)
			return nullptr;

		return next[next_index]->find(key + 1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	Node* root = new Node();

	for (int i = 0; i < N; ++i)
	{
		char text[501];
		cin >> text;
		root->insert(text);
	}

	int iCount = 0;
	for (int i = 0; i < M; ++i)
	{
		char text[501];
		cin >> text;
		Node* result = root->find(text);

		if (result && result->isEnd) ++iCount;
	}

	cout << iCount;

	return 0;
}
