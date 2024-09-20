#include <iostream>
#include "Solution.h"

int main()
{
    auto *m_s = new Solution;
    //auto word_vector = m_s->groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"});
    auto word_vector = m_s->groupAnagrams({"a"});
    for(auto &word : word_vector)
    {
        std::cout << "[ ";
        for(auto &w : word)
        {
            std::cout << "\"" << w << "\" ";
        }
        std::cout << "]" << std::endl;
    }
    auto word_vector1 = m_s->groupAnagrams2({"eat", "tea", "tan", "ate", "nat", "bat"});
    for(auto &word : word_vector1)
    {
        std::cout << "[ ";
        for(auto &w : word)
        {
            std::cout << "\"" << w << "\" ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}
