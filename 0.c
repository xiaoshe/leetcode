#include "util.h"


int main(int argc, char *argv[]) {
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
	int a[][32] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
	};
    int m = 3, n = 3;
    int sizes[32] = {};
    sizes[0] = n;
    int **b = array(a, m, n);
    */

    return 0;
}
