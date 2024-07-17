#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct comp {
    bool operator()(string a, string b) {
        if (a.size() < b.size()) {
            return true;
        }
        else if (a.size() > b.size()) {
            return false;
        }

        //size same
        int word = 'a';
        int count = 0;

        for (int i = 0; i < a.size(); ++i) {

            if (a[i] - 'a' < b[i] - 'a') {
                return true;
            }
            else if(a[i] - 'a' > b[i] - 'a'){
                return false;
            }
        }
        return false;
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<string> v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];

    }

    sort(v.begin(), v.end(), comp());
    v.erase(unique(v.begin(), v.end()), v.end());


    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << "\n";
    }

    return 0;
}
