#include <iostream>

using namespace std;

int answer = 0;

class Trie {

public:
    Trie* next[26];
    bool isEnd;

    Trie() : isEnd(false) {
        fill(next, next + 26, nullptr);
    }

    ~Trie() {
        for (auto& node : next) {
            delete node;
        }
    }

    void Insert(const char* _nodes) {

        if (0 == *_nodes) {
            isEnd = true;
        }
        else {

            int index = _nodes[0] - 'a';

            if (nullptr == next[index]) {
                next[index] = new Trie();
            }

            next[index]->Insert(_nodes + 1);

        }
    }

    Trie* Find(const char* _nodes) {
        if (0 == *_nodes) {
            return this;
        }
        else {

            int index = _nodes[0] - 'a';

            if (nullptr == next[index]) {
                return nullptr;
            }

            return next[index]->Find(_nodes + 1);

        }


    }



};


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    Trie* root = new Trie();

    for (int i = 0; i < N; ++i) {
        
        string s;
        cin >> s;
        root->Insert(s.c_str());
    }
    
    int count = 0;

    while (count < M)
    {
        string findString;
        cin >> findString;
        
        Trie* temp = root->Find(findString.c_str());

        if (nullptr != temp && temp->isEnd) {
            
            ++answer;
        }

        ++count;
    
    }


    cout << answer;

    delete root;

    return 0;
}
