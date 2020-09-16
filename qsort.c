#include "util.h"

void sort(int *nums, int low, int high) {
    if (low < high) {
        int key = nums[low];
        int i = low, j = high;
        while (i < j) {
            while (i < j && nums[j] >= key) j--;
            nums[i] = nums[j];
            while (i < j && nums[i] <= key) i++;
            nums[j] = nums[i];
        }
        nums[i] = key;
        sort(nums, low, i - 1);
        sort(nums, i + 1, high);
    }
}

int cmp(const void *a, const void *b) {
    return *(int*)a < *(int*)b;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    print_array(a, n);

    sort(a, 0, n-1);
    print_array(a, n);

    qsort(a + 2, n - 2, sizeof(int), cmp);
    print_array(a, n);
    return 0;
}
