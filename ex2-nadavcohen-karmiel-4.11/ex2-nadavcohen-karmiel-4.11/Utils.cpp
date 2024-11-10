#include "Utils.h"
#include <stack>

void reverse(int* nums, unsigned int size) {
    std::stack<int> stack;
    for (unsigned int i = 0; i < size; i++) {
        stack.push(nums[i]);
    }

    for (unsigned int i = 0; i < size; i++) {
        nums[i] = stack.top();
        stack.pop();
    }
}

int* reverse10() {
    static int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    return arr;
}
