#include "KPeriodic.h"

#include <iostream>

int main()
{
    struct Example
    {
        const char* text;
        int k;
        bool expected;
    };

    const Example examples[] = {
        { "abcabcabcabc", 3, true },
        { "abcabcabcabc", 6, true },
        { "abcabcabd", 3, false },
        { "abcab", 3, false },
        { "aaaa", 1, true },
        { "ab", 1, false },
        { "a a a ", 2, true },
        { "abc", 3, true },
        { "abc", 4, false },
        { "abc", 0, false },
        { "abc", -1, false },
        { "", 1, false },
    };

    bool passed = true;
    const int exampleCount = static_cast<int>(sizeof(examples) / sizeof(examples[0]));
    for (int i = 0; i < exampleCount; ++i)
    {
        const Example& example = examples[i];
        const bool result = IsKPeriodic(example.text, example.k);
        std::cout << '"' << example.text << "\", K=" << example.k
            << ": " << std::boolalpha << result;
        if (result != example.expected)
        {
            std::cout << " (expected " << example.expected << ')';
            passed = false;
        }
        std::cout << '\n';
    }

    return passed ? 0 : 1;
}
