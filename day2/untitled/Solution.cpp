//
// Created by Administrator on 2024/9/12.
//

#include <algorithm>
#include "Solution.h"
#include <unordered_map>

/**
 * @brief 分组 包含相同字母并且字母个数也相同为一组
 * @param strs 需要检索的字符串
 * @return 返回上述类型的所有分组
 */
std::vector<std::vector<std::string>> Solution::groupAnagrams(const std::vector<std::string> &strs)
{
    std::vector<std::vector<std::string>> word_vector;
    std::vector<std::string> temp_vector;
    if(strs.empty())
    {
        return {};
    }
    else if(strs.size() == 1)
    {
        return {strs};
    }
    else
    {
        for(int i = 0; i < strs.size() - 1; i++)
        {
            std::vector<std::string> str_vector;
            if(std::find(temp_vector.begin(), temp_vector.end(), strs[i]) != temp_vector.end())
            {
                goto end;
            }
            for(int j = i + 1; j < strs.size(); j++)
            {
                if(findWord(strs[i], strs[j]))
                {
                    if(std::find(str_vector.begin(), str_vector.end(),strs[i]) == str_vector.end())
                    {
                        str_vector.push_back(strs[i]);
                        temp_vector.push_back(strs[i]);
                    }
                    if(std::find(str_vector.begin(), str_vector.end(),strs[j]) == str_vector.end())
                    {
                        str_vector.push_back(strs[j]);
                        temp_vector.push_back(strs[j]);
                    }
                }
            }
            end:
                if(!str_vector.empty())
                {
                    word_vector.push_back(str_vector);
                }
        }
    }
    return word_vector;
}

/**
 * @brief 判断单词str中是否存在字母letter
 * @param str 字符串
 * @param letter 字母
 * @return true 存在 false 不存在
 */
bool Solution::findLetter(const std::string &str, const char &letter)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == letter)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief 判断两个字符串是否包含相同字母并且字母个数也相同
 * @param str1 字符串1
 * @param str2 字符串2
 * @return true 包含相同字母 false 不包含相同字母
 */
bool Solution::findWord(const std::string &str1, const std::string &str2)
{
    for(int i = 0; i < str1.length(); i++)
    {
        if(!findLetter(str2, str1[i]))
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief 分组 包含相同字母并且字母个数也相同为一组
 * @param strs 需要检索的字符串
 * @return 返回上述类型的所有分组
 */
std::vector<std::vector<std::string>> Solution::groupAnagrams1(const std::vector<std::string> &strs)
{
    // unordered_map实现方式决定了它的性能比map更优，特别是处理大量数据时，使用方法和map类似
    std::unordered_map<std::string, std::vector<std::string>> mp;
    // 遍历字符串容器
    for (const std::string &str: strs) {
        std::string key = str;
        // 排序
        std::sort(key.begin(), key.end());
        // 加入容器中
        mp[key].emplace_back(str);
    }
    // 取出异位词数组
    std::vector<std::vector<std::string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        ans.emplace_back(it->second);
    }
    return ans;
}

/**
 * @brief 分组 包含相同字母并且字母个数也相同为一组
 * @param strs 需要检索的字符串
 * @return 返回上述类型的所有分组
 */
std::vector<std::vector<std::string>> Solution::groupAnagrams2(const std::vector<std::string> &strs)
{
    std::unordered_map<std::string, std::vector<std::string>> mp;
    for(const auto &str : strs)
    {
        std::string m_key = str;
        std::sort(m_key.begin(), m_key.end());
        mp[m_key].emplace_back(str);
    }

    std::vector<std::vector<std::string>> ans;
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.emplace_back(it->second);
    }
    return ans;
}
