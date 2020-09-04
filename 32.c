#include "util.h"

void print(char *s, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d", s[i]);
    }
    printf("\n");
}

// 方法1：
/*
 * 找出所有最小的()配对，设置为1，其他为0，例如((()())转化为0011110
 * 然后找出连续的1，判断左边为(右边为)，同样设置为1，得0111111，继续找出所有连续的1直到没变化为止
 */


/*
int expand(char *s, char *flag, int len) {
    int ret = 0;
    int i = 0;
    while (i < len) {
        // left指向连续1的第一个，right指向最后一个
        int left = -1;
        for (int j = i; j < len; j++) {
            if (flag[j] == 1) {
                left = j;
                break;
            }
        }
        if (left == -1) break;
        int right = left + 1;
        while (right < len) {
            if (flag[right] == 1) right++;
            else break;
        }
        if (right == len || flag[right] == 0) right--;

        while (left > 0 && right + 1 < len) {
            if (s[left - 1] == '(' && s[right+1] == ')') {
                ret = 1;
                flag[left - 1] = 1;
                flag[right + 1] = 1;
                left--, right++;
            } else {
                break;
            }
        }

        i = right + 1;
    }
    return ret;
}

int longestValidParentheses(char * s){
    int len = strlen(s);
    // 标记0或1
    char *flag = (char *)malloc(len);
    // 最小的()配对标记为1,其他标记为0
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' && i+1<len && s[i+1] == ')') {
            flag[i] = 1;
            flag[i+1] = 1;
            i += 1;
        } else {
            flag[i] = 0;
        }
    }

    while (1) {
        // 针对连续的1,判断两端是否为()
        int ret = expand(s, flag, len);
        if (ret == 0) break;
    }
    // 找出最大的连续1的个数
    int max = 0;
    int t = 0;
    for (int i = 0; i < len; i++) {
        if (flag[i] == 0) {
            if (max < t) max = t;
            t = 0;
        } else {
            t++;
        }
    }
    free(flag);
    return max > t ? max : t;
}
*/


// 方法2：栈，能匹配的记1,不能的记0,找连续最大1
int longestValidParentheses(char * s){
    int len = strlen(s);
    int *stack = (int *)malloc(len*sizeof(int)); // 只有(入栈，记录(位置
    int top = -1; // 栈顶
    char *flag = (char *)malloc(len);

    for (int i = 0; i < len; i++) {
        flag[i] = 0;
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            if (top > -1) {
                int p = stack[top--];
                flag[i] = 1;
                flag[p] = 1;
            }
        }
    }
    // 找出最大的连续1的个数
    int max = 0;
    int t = 0;
    for (int i = 0; i < len; i++) {
        if (flag[i] == 0) {
            if (max < t) max = t;
            t = 0;
        } else {
            t++;
        }
    }
    free(flag);
    free(stack);
    return max > t ? max : t;
}

int main(int argc, char *argv[]) {
    int ret = longestValidParentheses(argv[1]);
    printf("ret:%d\n", ret);
    return 0;
}
