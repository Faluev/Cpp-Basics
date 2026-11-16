#include "Trie.h"

Trie::Node::~Node()
{
    for (Node* child : children)
    {
        delete child;
    }
}

int Trie::letterIndex(char letter)
{
    if (letter >= 'a' && letter <= 'z')
    {
        return letter - 'a';
    }
    if (letter >= 'A' && letter <= 'Z')
    {
        return letter - 'A';
    }
    return -1;
}

void Trie::insert(const std::string& word)
{
    if (word.empty())
    {
        return;
    }

    for (char letter : word)
    {
        if (letterIndex(letter) == -1)
        {
            return;
        }
    }

    Node* node = &root;
    for (char letter : word)
    {
        const int index = letterIndex(letter);
        if (node->children[index] == nullptr)
        {
            node->children[index] = new Node;
        }
        node = node->children[index];
    }
    node->isWord = true;
}

std::vector<std::string> Trie::complete(const std::string& prefix) const
{
    std::vector<std::string> matches;
    if (prefix.empty())
    {
        return matches;
    }

    const Node* node = &root;
    std::string word;
    for (char letter : prefix)
    {
        const int index = letterIndex(letter);
        if (index == -1 || node->children[index] == nullptr)
        {
            return matches;
        }
        node = node->children[index];
        word += static_cast<char>('a' + index);
    }

    // Only visit the branch reached by the prefix.
    collectWords(node, word, matches);
    return matches;
}

void Trie::collectWords(const Node* node, std::string& word,
    std::vector<std::string>& matches)
{
    if (node->isWord)
    {
        matches.push_back(word);
    }

    for (int index = 0; index < alphabetSize; ++index)
    {
        if (node->children[index] != nullptr)
        {
            word += static_cast<char>('a' + index);
            collectWords(node->children[index], word, matches);
            word.pop_back();
        }
    }
}
