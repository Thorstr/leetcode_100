//
// Created by Administrator on 2024/9/12.
//

#ifndef UNTITLED_SOLUTION_H
#define UNTITLED_SOLUTION_H

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:

    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string> &strs);

    bool findLetter(const std::string &str, const char &letter);

    bool findWord(const std::string &str1, const std::string &str2);

    std::vector<std::vector<std::string>> groupAnagrams1(const std::vector<std::string> &strs);

    std::vector<std::vector<std::string>> groupAnagrams2(const std::vector<std::string> &strs);
};


#endif //UNTITLED_SOLUTION_H
