#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> child;
    TrieNode* fail = nullptr;
    bool isEnd = false;
};

TrieNode pool[100000];
int pool_idx = 0;

TrieNode* new_node() {
    return &pool[pool_idx++];
}

void insert(TrieNode* root, const string& word) {
    TrieNode* cur = root;
    for (char c : word) {
        if (cur->child.find(c) == cur->child.end()) {
            cur->child[c] = new_node();
        }
        cur = cur->child[c];
    }
    cur->isEnd = true;
}

void build_failure(TrieNode* root) {
    queue<TrieNode*> q;
    root->fail = root;

    for (auto& [c, node] : root->child) {
        node->fail = root;
        q.push(node);
    }

    while (!q.empty()) {
        TrieNode* cur = q.front();
        q.pop();

        for (auto& [c, next] : cur->child) {
            TrieNode* fail = cur->fail;
            while (fail != root && fail->child.find(c) == fail->child.end()) {
                fail = fail->fail;
            }
            if (fail->child.find(c) != fail->child.end()) {
                next->fail = fail->child[c];
            } else {
                next->fail = root;
            }
            if (next->fail->isEnd) {
                next->isEnd = true;
            }
            q.push(next);
        }
    }
}

bool aho_corasick_search(TrieNode* root, const string& text) {
    TrieNode* cur = root;

    for (char c : text) {
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
    TrieNode* root = new_node();
    int n, m;
    cin >> n;

    string word;
    for (int i = 0; i < n; i++) {
        cin >> word;
        insert(root, word);
    }

    build_failure(root);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> word;
        if (aho_corasick_search(root, word)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
