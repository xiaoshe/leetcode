#include "util.h"


int main(int argc, char *argv[]) {
    // 数组
    char *s = "";
    int a[32];
    int n = string_to_array(s, a);
    print_array(a, n);

    // 树
    char *s = "5,2,13";
    s = "5,2,13,1,3,6,15";
    struct TreeNode *root = init_tree(s);
    print_tree(root);

    /*
    // 单链表
     */
    /*
    // 二维数组
    char *s = "[1,   3,  5,  7], [10, 11, 16, 20], [23, 30, 34, 50]";
    array2d arr = init_array2d(s);
    */

    return 0;
}
