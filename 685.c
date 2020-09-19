#include "util.h"

typedef struct queue {
    int data[1001];
    int size;
}Queue;

int bfs(int data[][1001], int from, int to) {
    int visited[1001] = {0};
    Queue a, b;
    a.size = 0;
    for (int i = 1; i <= data[from][0]; i++) {
        int v = data[from][i];
        if (v == to) return 1;
        if (visited[v] == 0) {
            a.data[a.size++] = v;
            visited[v] = 1;
        }
    }
    Queue *pa = &a, *pb = &b;
    while (pa->size > 0) {
        pb->size = 0;
        for (int i = 0; i < pa->size; i++) {
            int u = pa->data[i];
            for (int j = 1; j <= data[u][0]; j++) {
                int v = data[u][j];
                if (v == to) return 1;
                if (visited[v] == 0) {
                    pb->data[pb->size++] = v;
                    visited[v] = 1;
                }
            }
        }
        Queue *t = pa;
        pa = pb;
        pb = t;
    }
    return 0;
}

int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int point[1001] = {0}; // point[i]=j: 代表j->i
    int data[1001][1001] = {0}; // data[i]:代表i节点指向的节点列表, data[i][0]代表列表长度

    *returnSize = 2;
    int *ret = (int*)malloc(sizeof(int)*2);
    ret[0] = 0;
    int parents = 0;
    int circle[2] = {0};

    for (int i = 0; i < edgesSize; i++) {
        // u->v
        int u = edges[i][0];
        int v = edges[i][1];
        if (point[v] > 0) {
            ret[0] = u;
            ret[1] = v;
            parents = 1;
        } else {
            point[v] = u;
        }
        data[u][++data[u][0]] = v;

        // 从v开始能否回到u?
        if (data[v][0] > 0 && bfs(data, v, u) > 0) {
            circle[0] = u;
            circle[1] = v;
        }
    }
    
    if (parents > 0) {
        int u1 = ret[0], v1 = ret[1];
        int u2 = point[v1], v2 = v1;
        // 删除[u1, v1] 或 [u2, v2]
        // 如果u2,v2在环中，则删除，否则删除u1,v1
        if (data[v2][0] > 0 && bfs(data, v2, u2) > 0) {
            ret[0] = u2;
            ret[1] = v2;
        }
        return ret;
    } else {
        ret[0] = circle[0];
        ret[1] = circle[1];
        return ret;
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    char *file = "data/685.txt";
    FILE *rp = fopen(file, "r");
    char s[128];
    while (fgets(s, 128, rp)) {
        if (s[0] == '#') continue;
        int a[32];
        int n = string_to_array(s, a);
        print_array(a, n);

        // TODO
        
        int sz = n / 2;
        int *edges[32] = {NULL};
        for (int i = 0; i < n; i+=2) {
            int *t = (int*)malloc(sizeof(int)*2);
            t[0] = a[i];
            t[1] = a[i+1];
            edges[i/2] = t;
        }
        int sizes[32];
        int retsize;
        int *ret = findRedundantDirectedConnection(edges, sz, sizes, &retsize);
        printf("size:%d\n", retsize);
        print_array(ret, retsize);

        printf("\n");
        
    }
    fclose(rp);
    return 0;

}
