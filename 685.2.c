#include "util.h"

/*
int bfs(int point[], int sz, int key, int next) {
    for (int i = 0; i < sz; i++) {
        if (point[i] != key) continue;
        if (i == next) return 1;
        if (bfs(point, sz, key, i) > 1) return 1;
    }
    return 0;
}
*/
int bfs(int data[][1001], int visit[], int p, int key) {
    visit[p] = 1;
    for (int i = 1; i <= data[p][0]; i++) {
        int v = data[p][i];
        if (v == key) return 1;
        if (visit[v] == 0 && bfs(data, visit, v, key) > 0) return 1;
    }
    return 0;
}

int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int point[1001] = {0}; // point[i]=j: 代表j->i
    int data[1001][1001] = {0}; // data[i]:代表i节点指向的节点列表, data[i][0]代表列表长度
    int visit[1001] = {0}; // point[i]=j: 代表j->i

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
        for (int i = 1; i <= edgesSize; i++) visit[i] = 0;
        if (data[v][0] > 0 && bfs(data, visit, v, u) > 0) {
            circle[0] = u;
            circle[1] = v;
        }
    }
    
    if (parents > 0) {
        int u1 = ret[0], v1 = ret[1];
        int u2 = point[v1], v2 = v1;
        // 删除[u1, v1] 或 [u2, v2]
        // 如果u2,v2在环中，则删除，否则删除u1,v1

        for (int i = 1; i <= edgesSize; i++) visit[i] = 0;
        if (data[v2][0] > 0 && bfs(data, visit, v2, u2) > 0) {
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
