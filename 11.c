#include <stdio.h>
#include <limits.h>

/*
 * [题目]
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 *
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 *
 * [思路]
 * 高：数字大小，宽：横向距离，面积：容器大小（高×宽）
 * 结论：定义2个指针left和right，分别从左右两侧向中间移动，移动时移动高小的一端。
 * 暴力+减枝：移动right指针并依次计算比较，当num[right]==num[left]时，不再移动。因为再移动面积一定会减少。
 * 此时移动left，是否需要将right从最右侧开始？不需要，因为right右边的高都比left高小。
 *
 */

int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int area = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            int t = height[left] * (right - left);
            if (area < t) {
                area = t;
            }
            left++;
        } else {
            int t = height[right] * (right - left);
            if (area < t) {
                area = t;
            }
            right--;
        }
    }
    return area;
}

int main(int argc, char *argv[]) {
    int a[] = {1,8,6,2,5,4,8,3,7};
    int ret = maxArea(a, 9);
    printf("ret:%d\n", ret);
}
