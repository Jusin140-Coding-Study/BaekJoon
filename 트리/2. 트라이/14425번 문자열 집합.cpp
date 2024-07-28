#include <iostream>
using namespace std;

class Node
{
public:
	Node* nextNode[26];
	bool isEnd;
	Node() : isEnd(false)
	{
		fill(nextNode, nextNode + 26, nullptr);
	}

	~Node()
	{
		for (Node* child : nextNode)
			delete child;
	}

	void insert(const char* key)
	{
		if (0 == *key)
			isEnd = true;
		else
		{
			// 현재 알파벳이 다음 노드의 인덱스로
			int iNextIdx = *key - 'a';

			// 아직 생성되지 않은 자식 노드는 새로 생성
			if (nullptr == nextNode[iNextIdx])
				nextNode[iNextIdx] = new Node();

			nextNode[iNextIdx]->insert(key + 1);
		}
	}

	Node* find(const char* key)
	{
		// 문자열의 끝이면 마지막 노드 반환
		if (0 == *key)
			return this;

		int iNextIdx = *key - 'a';

		// 자식 노드로 존재하지 않은 알파벳이면 null 리턴
		if (nullptr == nextNode[iNextIdx])
			return nullptr;

		// 자식 노드 중에서 다음 알파벳 탐색
		return nextNode[iNextIdx]->find(key + 1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	Node* rootNode = new Node();

	while (0 < iN)
	{
		char strInput[501];
		cin >> strInput;

		rootNode->insert(strInput);
		iN--;
	}

	int iResult = 0;

	while (0 < iM)
	{
		char strFind[501];
		cin >> strFind;

		Node* result = rootNode->find(strFind);
		
		// 반환된 노드가 null이 아니고, 마지막 문자 노드면 카운트
		if (result && result->isEnd)
		{
			iResult++;
		}
		iM--;
	}

	cout << iResult;

	return 0;
}