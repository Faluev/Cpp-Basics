#include "Trie.h"

#include <iostream>
#include <sstream>

int main()
{
    const std::string words[] = {
        "game", "gamer", "gamepad", "gameplay", "garden", "gate",
        "hello", "help", "hero", "house", "level", "light", "lives",
        "score", "screen", "script", "search", "settings", "start",
        "status", "stone", "tree"
    };

    Trie dictionary;
    for (const std::string& word : words)
    {
        dictionary.insert(word);
    }

    std::cout << "Word autocomplete (A-Z). Type :quit to exit.\n";
    std::string line;
    while (true)
    {
        std::cout << "\nEnter a prefix: ";
        if (!std::getline(std::cin, line) || line == ":quit")
        {
            break;
        }
        if (line.empty())
        {
            std::cout << "Enter at least one letter.\n";
            continue;
        }

        const std::vector<std::string> matches = dictionary.complete(line);
        if (matches.empty())
        {
            std::cout << "No suggestions.\n";
            continue;
        }

        const int count = static_cast<int>(matches.size());
        for (int index = 0; index < count; ++index)
        {
            std::cout << index + 1 << ". " << matches[index] << '\n';
        }

        while (true)
        {
            std::cout << "Choose a word by number (0 = new prefix): ";
            if (!std::getline(std::cin, line) || line == ":quit")
            {
                return 0;
            }

            std::istringstream input(line);
            int choice = 0;
            char extra = '\0';
            if (!(input >> choice) || (input >> extra) || choice < 0 || choice > count)
            {
                std::cout << "Enter a number from 0 to " << count << ".\n";
                continue;
            }

            if (choice > 0)
            {
                std::cout << "Selected word: " << matches[choice - 1] << '\n';
            }
            break;
        }
    }

    return 0;
}
