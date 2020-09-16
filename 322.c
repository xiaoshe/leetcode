#include "util.h"

typedef struct queue {
    int data[1000];
    int size;
}Queue;

void print(Queue *p) {
    printf("sz:%d ", p->size);
    for (int i = 0; i < p->size; i++) {
        printf("%d ", p->data[i]);
    }
    printf("\n");
}

// 广度bfs
int coinChange(int* coins, int coinsSize, int amount){
    if (amount == 0) return 0;
    char *cache = (char*)malloc(amount+1);
    memset(cache, 0, amount+1);

    Queue a, b;
    a.size = 1;
    a.data[0] = amount;
    cache[amount] = 0;
    

    Queue *pa = &a, *pb = &b;

    int level = 0;
    int ok = 0;
    while (pa->size > 0) {
        print(pa);
        pb->size = 0;
        for (int i = 0; i < pa->size; i++) {
            // 当前值与每个硬币相减
            int left = pa->data[i];
            for (int j = 0; j < coinsSize; j++) {
                if (left == coins[j]) {
                    free(cache);
                    return level + 1;
                } else if (left > coins[j]) {
                    int t = left - coins[j];
                    if (cache[t] == 0) {
                        pb->data[pb->size++] = t;
                        cache[t] = 1;
                    }
                }
            }
        }
        level++;

        Queue *t = pa;
        pa = pb;
        pb = t;
    }
    free(cache);
    return -1;
}

int main(int argc, char *argv[]) {
    int a[32];
    int n = string_to_array(argv[1], a);
    int ret = coinChange(a, n, atoi(argv[2]));
    printf("ret:%d\n", ret);
    return 0;
}
