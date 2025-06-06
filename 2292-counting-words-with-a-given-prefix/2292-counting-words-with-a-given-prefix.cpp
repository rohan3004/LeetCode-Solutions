class Node {
public:
    Node* children[26];
    int count;

    Node() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        count = 0;
    }
};

class PrefixTree {
private:
    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }

    void addWord(const string& word) {
        Node* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new Node();
            }
            current = current->children[index];
            current->count++;
        }
    }

    int getPrefixCount(const string& prefix) {
        Node* current = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return 0;
            }
            current = current->children[index];
        }
        return current->count;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string prefix) {
        PrefixTree tree;
        for (const string& word : words) {
            tree.addWord(word);
        }
        return tree.getPrefixCount(prefix);
    }
};