#include <stdio.h>

/*
#define get_next(ret) \
    if (i == nums1Size) { \
        ret = nums2[j++]; \
    } else if (j == nums2Size) { \
        ret = nums1[i++]; \
    } else { \
        if (nums1[i] < nums2[j]) { \
            ret = nums1[i++]; \
        } else { \
            ret = nums2[j++]; \
        } \
    }

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int odd = 0; // 奇数
    int half = (nums1Size + nums2Size) / 2;
    if ((nums1Size + nums2Size) % 2 == 1) {
        odd = 1;
        half++; // 奇数则+1
    }

    int i = 0;
    int j = 0;
    int n = 0;
    int last = 0;
    // 找到中间数
    while (n++ < half) {
        get_next(last);
    }
    
    if (odd == 0) {
        // 如果是偶数，需要再找下一个数，然后求平均
        int next = 0;
        get_next(next);
        return (next + last) / 2.0;
    } else {
        return last;
    }
}
*/

int findkth(int* nums1, int i, int n1, int* nums2, int j, int n2, int k) {
    if (i >= n1) return nums2[j + k - 1];
    if (j >= n2) return nums1[i + k - 1];
    if (k == 1) {
        return nums1[i] < nums2[j] ? nums1[i] : nums2[j];
    }
    int half = k / 2; // 2个数组中找第half个数
    if (i + half - 1 >= n1) {
        // 数组越界，移动第二个数组half个位置，第k个转换成第k-half个
        return findkth(nums1, i, n1, nums2, j + half, n2, k - half);
    }
    if (j + half - 1 >= n2) {
        return findkth(nums1, i + half, n1, nums2, j, n2, k - half);
    }
    // 都没越界时，判断2个数组中第half个元素的大小
    if (nums1[i + half - 1] < nums2[j + half - 1]) {
        return findkth(nums1, i + half, n1, nums2, j, n2, k - half);
    } else {
        return findkth(nums1, i, n1, nums2, j + half, n2, k - half);
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int left = (nums1Size + nums2Size + 1) / 2;
    int right = (nums1Size + nums2Size + 2) / 2;
    if (left == right) {
        return findkth(nums1, 0, nums1Size, nums2, 0, nums2Size, left);
    } else {
        int a = findkth(nums1, 0, nums1Size, nums2, 0, nums2Size, left);
        int b = findkth(nums1, 0, nums1Size, nums2, 0, nums2Size, right);
        return (a + b) / 2.0;
    }
}


int main() {
    int a[] = {1};
    int b[] = {2,3, 4,5,6,7,8};
    double ret = findMedianSortedArrays(a, 1, b, 7);
    printf("ret:%.1f\n", ret);
    return 0;
}
