#include <iostream> 
#include "Utils.h"
#include <stack>

void reverse(int* nums, unsigned int size) 
{
    std::stack<int> stack;

    // pushing the numbers to the stack
    for (unsigned int i = 0; i < size; i++) 
    {
        stack.push(nums[i]);
    }

    // return the number in 
    for (unsigned int i = 0; i < size; i++) 
    {
        nums[i] = stack.top();
        stack.pop();
    }
}

int* reverse10() 
{
    int* nums = new int[10];

    std::cout << "enter 10 numbers:\n";
    for (int i = 0; i < 10; i++) {
        std::cin >> nums[i];
    }

    // reverse
    for (int i = 0; i < 5; i++) 
    {
        int temp = nums[i];
        nums[i] = nums[9 - i];
        nums[9 - i] = temp;
    }

    return nums;
}
