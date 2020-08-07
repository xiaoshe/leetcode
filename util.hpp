#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

// 字符串转数组
// ret数组要足够大，返回数组大小
void string_to_vector(char *s, vector<int> *ret) {
    while (*s != 0) {
        int number = 0;
        int pos = 1; // 默认：正数
        while (*s != '-' && !isdigit(*s)) s++;
        if (*s == '-') {
            pos = 0;
            s++;
        }
        while (isdigit(*s)) {
            number = number * 10 + *s - '0';
            s++;
        }
        if (pos == 1) {
            ret->push_back(number);
        } else {
            ret->push_back(0 - number);
        }
    }
}
void print_vector(const std::vector<int>& ret) {
    for (size_t i = 0; i < ret.size(); i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
}

#endif
