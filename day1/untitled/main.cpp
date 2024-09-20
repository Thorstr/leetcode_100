#include <iostream>
#include "Operation.h"

int main()
{
    auto *m_p = new Operation;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 26;

    // auto aReturn = m_p->TwoNumAdd(nums, target);
    auto aReturn = m_p->twoSum2(nums, target);

    if(!aReturn.empty())
    {
        //    std::cout << "two number : " << "nums[" << aReturn[0][0] << "] = " << aReturn[0][1]
//    << ", nums[" << aReturn[1][0] << "] = " << aReturn[1][1] << std::endl;
        std::cout << "two number : " << "nums[" << aReturn[0] << "]"
                  << ", nums[" << aReturn[1] << "] " << std::endl;
    }
    else
    {
        std::cout << "error: no two number add up to target" << std::endl;
    }


    return 0;
}
