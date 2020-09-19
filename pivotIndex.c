#include "util.h"

/*
给定一个整数类型的数组 nums，请编写一个能够返回数组 “中心索引” 的方法。

我们是这样定义数组 中心索引 的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。

如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。


示例 1：

输入：
nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
索引 3 (nums[3] = 6) 的左侧数之和 (1 + 7 + 3 = 11)，与右侧数之和 (5 + 6 = 11) 相等。
同时, 3 也是第一个符合要求的中心索引。

示例 2：

输入：
nums = [1, 2, 3]
输出：-1
解释：
数组中不存在满足此条件的中心索引。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/yf47s/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */


int pivotIndex(int* nums, int numsSize){
    int left[10001];
    int s = 0;
    for (int i = 0; i < numsSize; i++) {
        s += nums[i];
        left[i] = s;
    } 

    int right[10001];
    s = 0;
    for (int i = numsSize-1; i >= 0; i--) {
        s += nums[i];
        right[i] = s;
    } 

    for (int i = 0; i < numsSize; i++) {
        int l = 0;
        if (i > 0) l = left[i-1];
        int r = 0;
        if (i < numsSize - 1) r = right[i+1];
        if (l == r) return i;
    }

    return -1;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    int ret = pivotIndex(a, n);
    printf("ret:%d\n", ret);
    return 0;
}
