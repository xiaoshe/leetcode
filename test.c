#include <stdio.h>

#include "util.h"


int main(int argc, char *argv[]) {
    char *s = "  \n -123\n ";
    int ret = atoi(s);
    printf("ret:%d\n", ret);

    char *t = trim(s);
    printf("[%s]\n", t);


    s = "1,2,3, 4,5,6,,,,x";
    s = "12345";
    int sz;
    char **r2 = split(s, ',', &sz);
    print_string(r2, sz);

    s = "1, 3, 0, -2,4,-5";
    int a[32];
    int n = string_to_array(s, a);
    print_array(a, n);

    s = "[1, 2, 3, 4], [5, 6, 3,4,7, 8], [9,10,11,12]";
    int *sizes = NULL;
    int **r3 = array2(s, &sz, &sizes);
    for (int i = 0; i < sz; i++) {
        print_array(r3[i], sizes[i]);
    }

    s = "1,2,3,4,5,6,7";
    struct ListNode* r4 = init_list(s);
    print_list(r4);
    /*
    int a[16];
    int n = string_to_array(argv[1], a);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    */
    struct TreeNode *root = init_tree("1,null,2,3,null,2,3");
    print_tree(root);
    return 0;
}
