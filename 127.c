#include "util.h"

int diff(char *a, char *b) {
    int c = 0;
    while (*a != 0) {
        if (*a != *b) c++;
        a++, b++;
    }
    return c;
}

void print_pos(int h, int t, char **pos, int sz) {
    printf("head:%d tail:%d ", h, t);
    for (int i = 0; i < sz; i++) {
        printf("%d:%s ", i, pos[i]);
    }
    printf("\n");
}

// 每个字符串只能使用一次，记录在used[]中
int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    // 记录选用过的单词
    char **pos = (char**)malloc(wordListSize*sizeof(char*));
    int head = 0, tail = 0;

    int *used = (int*)malloc(wordListSize*sizeof(int));
    for (int i = 0; i < wordListSize; i++) {
        used[i] = 0;
    }
    for (int i = 0; i < wordListSize; i++) {
        if (diff(beginWord, wordList[i]) == 1) {
            pos[tail++] = wordList[i];
            used[i] = 1;
        }
    }

    int ret = 1;
    int find = 0;
    while (head < tail) {
        // pos不为空
        for (int i = head; i < tail; i++) {
            // 找到
            if (diff(endWord, pos[i]) == 0) {
                find = 1;
                break;
            }
        }
        if (find == 1) break;

        // 没找到，则继续找下一批符合条件的字符串
        int h = tail;
        int t = h;
        for (int j = head; j < tail; j++) {
            for (int i = 0; i < wordListSize; i++) {
                if (used[i] == 0 && diff(wordList[i], pos[j]) == 1) {
                    used[i] = 1;
                    pos[t++] = wordList[i];
                }
            }
        }
        head = h;
        tail = t;
        ret += 1;
    }

    free(pos);
    free(used);
    return find == 0 ? 0 : ret + 1;
}

int main(int argc, char *argv[]) {
    char *begin = "hit";
    char *end = "cog";
    char *list[6] = {"hot","dot","dog","lot","log","cog"};
    int ret = ladderLength(begin, end, list, 5);
    printf("ret:%d\n", ret);
    return 0;
}
