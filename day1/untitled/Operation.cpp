//
// Created by Administrator on 2024/9/10.
//

#include "Operation.h"
#include <map>

/**
 * @note 暴力算法：双循环
 * @brief 获取两数之和为指定值的数组元素和元素下标
 * @param array 需要计算的数组
 * @param num 求和的值
 * @note 只会存在一个有效答案
 * @return std::vector<std::vector<int>> 返回数组下标和元素元素
 */
std::vector<std::vector<int>> Operation::TwoNumAdd(const std::vector<int> &array, const int &num)
{
    std::vector<int> array1;
    std::vector<int> array2;
    for(int i = 0; i < array.size() - 1; i++)
    {
        for(int j = i + 1; j < array.size(); j++)
        {
            if(array[i] + array[j] == num)
            {
                array1.push_back(i);
                array1.push_back(array[i]);
                array2.push_back(j);
                array2.push_back(array[j]);
                goto end;
            }
        }
    }
    end:
        std::vector<std::vector<int>> nums;
        nums.push_back(array1);
        nums.push_back(array2);
        return nums;
}

/**
 * @note 暴力算法，双循环
 * @brief 获取两数之和为指定值的数组元素和元素下标
 * @param nums 需要计算的数组
 * @param target 求和的值
 * @return 返回数组下标和元素元素
 */
vector<int> Operation::twoSum(vector<int> &nums, int target)
{
    std::vector<int> num;
    for(int i = 0; i < nums.size() - 1; i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            if(nums[i] + nums[j] == target)
            {
                num.push_back(i);
                num.push_back(j);
                goto end;
            }
        }
    }
    end:
        return num;
}

/**
 * @note 哈希表算法：一次循环
 * @brief 获取两数之和为指定值的数组元素和元素下标
 * @param nums 需要计算的数组
 * @param target 求和的值
 * @return 返回数组下标和元素元素
 */
vector<int> Operation::twoSum2(vector<int> &nums, int target)
{
    std::map<int, int> array;
    for(int i = 0; i < nums.size(); i++)
    {
        auto aReturn = array.find(target - nums[i]);
        if(aReturn != array.end())
        {
            return {aReturn->second, i};
        }
        else
        {
            array.insert({nums[i], i});
        }
    }
    return {};
}

