#include<iostream>
using namespace std;

class TrieNode {

public:

    TrieNode* children[129];

    TrieNode() {
        for (int i = 0; i <= 128; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {

public:

    TrieNode root;
    int node_count;

    Trie() {
        // Отслеживаем количество узлов в дереве.
        node_count = 0;
    }

    // Вставить строку в дерево.
    void Insert(string str) {

        TrieNode* parent = &root;

        for (size_t i = 0; i < str.size(); i++) {
            int N = str.at(i);
            if (parent->children[N] == NULL) {
                parent->children[N] = new TrieNode;
                node_count++;
            }
            parent = parent->children[N];
        }
    }
};

int main() {
    Trie t;
    string str;
    cin >> str;

    for (size_t i = 0; i < str.size(); i++) {
        t.Insert(str.substr(i, str.size() - i));
    }
    cout << t.node_count;
    return 0;
}