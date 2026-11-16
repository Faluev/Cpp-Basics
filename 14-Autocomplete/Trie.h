#pragma once

#include <string>
#include <vector>

class Trie
{
public:
    Trie() = default;
    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    void insert(const std::string& word);
    std::vector<std::string> complete(const std::string& prefix) const;

private:
    static const int alphabetSize = 26;

    struct Node
    {
        Node* children[alphabetSize] = {};
        bool isWord = false;

        ~Node();
    };

    static int letterIndex(char letter);
    static void collectWords(const Node* node, std::string& word,
        std::vector<std::string>& matches);

    Node root;
};
