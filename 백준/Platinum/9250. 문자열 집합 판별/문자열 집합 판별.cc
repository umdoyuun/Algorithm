#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct Trie {
    unordered_map<char, Trie*> child;
    Trie* fail = nullptr;
    bool isEnd = false;
};

Trie pool[100000];
int pool_idx = 0;
Trie* root;

Trie* new_node() {
    return &pool[pool_idx++];
}

void insert(string str) {
    Trie* cur = root;
    for (char c : str) {
        if (cur->child.find(c) == cur->child.end()) {
            cur->child[c] = new_node();
        }
        cur = cur->child[c];
    }
    cur->isEnd = true;
}

void build_failure() {
    queue<Trie*> q;
    root->fail = root;

    for (auto& [c, node] : root->child) {
        node->fail = root;
        q.push(node);
    }

    while (!q.empty()) {
        Trie* cur = q.front();
        q.pop();

        for (auto& [c, next] : cur->child) {
            Trie* fail = cur->fail;
            while (fail != root && fail->child.find(c) == fail->child.end()) {
                fail = fail->fail;
            }
            if (fail->child.find(c) != fail->child.end()) {
                next->fail = fail->child[c];
            }
            else {
                next->fail = root;
            }
            if (next->fail->isEnd) {
                next->isEnd = true;
            }
            q.push(next);
        }
    }
}

bool aho_corasick_search(const string str) {
    Trie* cur = root;

    for (char c : str) {
        while (cur != root && cur->child.find(c) == cur->child.end()) {
            cur = cur->fail;
        }
        if (cur->child.find(c) != cur->child.end()) {
            cur = cur->child[c];
        }
        if (cur->isEnd) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    root = new_node();
    int n, m;
    cin >> n;

    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        insert(str);
    }

    build_failure();

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (aho_corasick_search(str)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
