#include "util.h"

/*
int isNumber(char* s) {
    while (*s == ' ') s++;
    if (*s == 0) return 0;
    if (*s == '.') {
        s++;
        int n = 0;
        while (*s >= '0' && *s <= '9') s++, n=1;
        while (*s == ' ') s++;
        return *s == 0 && n == 1;
    }
    if (*s == '+' || *s == '-') s++;
    if (*s < '0' || *s > '9') return 0;
    s++;
    while (*s >= '0' && *s <= '9') s++;

    // 数字结束后
    if (*s == 0) return 1;
    if (*s == '.') {
        s++;
        while (*s >= '0' && *s <= '9') s++;
        while (*s == ' ') s++;
        return *s == 0;
    }
    if (*s == 'e' || *s == 'E') {
        s++;
        if (*s == '+' || *s == '-') s++;
        if (*s < '0' || *s > '9') return 0;
        s++;
        while (*s >= '0' && *s <= '9') s++;
        while (*s == ' ') s++;
        return *s == 0;
    } if (*s == ' ') {
        while (*s == ' ') s++;
        return *s == 0;
    }
    return 0;
}

int isInt(char *s, int l, int r) {
    if (r > l && s[r-1] == '.') r--;
    if (s[l] == '+' || s[l] == '-') l++;
    if (l == r) return 0;
    while (l < r) {
        if (s[l] < '0' || s[l] > '9') return 0;
        l++;
    }
    return 1;
}

int isNumber(char* s) {
    char *p = s;
    int e = 0, ep = 0; // e个数及位置
    int dot = 0, dp = 0; // 点个数及位置
    int len = 0; // 长度
    // 先找到e及其位置
    while (*p != 0) {
        if (*p == '.') {
            dot++;
            dp = len;
        } else if (*p == 'e' || *p == 'E') {
            e++;
            ep = len;
        }
        p++;
        len++;
    }
    // 过滤前后空格
    int start = 0;
    p = s;
    while (*p == ' ') p++, start++;
    if (*p == 0) return 0;
    while (len > 0 && s[len-1] == ' ') len--;
    if (len == 0) return 0;

    if (e > 1) return 0;
    if (e == 1) {
        return isInt(s, start, ep) && isInt(s, ep+1, len);
    }
    if (dot > 1) return 0;
    if (dot == 1) {
        // 只有一个点
        if (dp == start && dp+1 == len) return 0;
        // dot后面
        int n = 0;
        int r = 1;
        for (int i = dp + 1; i < len; i++) {
            if (s[i] < '0' || s[i] > '9') {
                r = 0;
                break;
            } else {
                n++;
            }
        }
        // dot前面
        int l = 1;
        if (s[start] == '+' || s[start] == '-') start++;
        while (start < dp) {
            if (s[start] < '0' || s[start] > '9') {
                l = 0;
                break;
            } else {
                n++;
            }
            start++;
        }
        return l && r && n>0;
    }
    return isInt(s, start, len);
}

int isNumber(char* s) {
    int add = 0, apos = -1;
    int dot = 0, dpos = -1; // 点个数及位置
    int e = 0, epos = -1; // e个数及位置
    int minus = 0, mpos = -1;
    int number = 0, npos = -1;
    int other = 0;

    char *p = s;
    while (*p == ' ') p++;
    int start = p - s;
    int i = 0;
    while (*p != 0) {
        if (*p == '+') {add++; apos=i;}
        else if (*p == '-') {minus++; mpos=i;}
        else if (*p == '.') {dot++; dpos=i;}
        else if (*p == 'e' || *p == 'E') {e++; epos=i;}
        else if (*p >= '0' && *p <= '9') {number++; npos=i;}
        else if (*p != ' ') {other++;}
        p++, i++;
    }
    int end = i;
    while (end > start && s[end - 1] == ' ') end--;
}
*/

int isInt(const char *s, const char *e) {
    if (*s == '+' || *s == '-') s++;
    int n = 0;
    while (s < e) {
        if (*s >= '0' && *s <= '9') {
            n++;
        } else {
            return 0;
        }
        s++;
    }
    return n > 0;
}

int isUint(const char *s, const char *e) {
    int n = 0;
    while (s < e) {
        if (*s >= '0' && *s <= '9') {
            n++;
        } else {
            return 0;
        }
        s++;
    }
    return n > 0;
}

int isFloat(const char *s, const char *e) {
    const char *dot = NULL;
    const char *p = s;
    while (p < e) {
        if (*p == '.') {
            dot = p;
            break;
        }
        p++;
    }
    if (dot == NULL) return 0;
    if (dot == s) { // 小数点在第一位
        return isUint(dot + 1, e);
    } else if (dot + 1 == e) { // 小数点在最后一位
        return isInt(s, dot);
    } else if (dot == s + 1) {
        return (*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')) && isUint(dot + 1, e);
    } else {
        return isInt(s, dot) && isUint(dot + 1, e);
    }
    return 0;
}

int isNumber(char* s) {
    char *p = s;
    while (*p == ' ') p++;
    if (*p == 0) return 0;
    char *start = p;
    int e = 0;
    char *eptr = NULL;
    while (*p != 0) {
        if (*p == 'e' || *p == 'E') {
            e++;
            eptr = p;
        }
        p++;
    }

    while (*(p-1) == ' ') p--;
    char *end = p;

    if (e > 1 || end <= start) return 0;
    if (e == 1) {
        if (!isInt(eptr + 1, end)) {
            return 0;
        }
        end = eptr;
    }
    return isInt(start, end) || isFloat(start, end);
}

int main(int argc, char *argv[]) {
    int ret = isNumber(argv[1]);
    printf("ret:%d %s\n", ret, argv[1]);
    return 0;
}
