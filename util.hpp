#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
using namespace std;

int StringToInt(char *s) {
    int pos = 1;
    if (*s == '-') {
        pos = 0;
        s++;
    }
    int number = 0;
    while (isdigit(*s)) {
        number = number * 10 + *s - '0';
        s++;
    }
    return pos == 1 ? number : 0 - number;
}

// 字符串转整数数组
// ret数组要足够大，返回数组大小
// "1,-2,0,3,4" => [1,-2,0,3,4]
void StringToVector(char *s, vector<int> *ret) {
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

void PrintVector(const vector<int>& ret) {
    for (size_t i = 0; i < ret.size(); i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
}
void PrintVector(const vector<string>& ret) {
    printf("size:%ld\n", ret.size());
    for (size_t i = 0; i < ret.size(); i++) {
        printf("%ld|%s|\n", ret[i].size(), ret[i].c_str());
    }
    printf("\n");
}

// 切分字符串，返回字符数组
void SplitString(const string& str, char sep, vector<string> *ret) {
  size_t last = 0;
  size_t i;
  size_t c = str.size();
  for (i = 0; i <= c; ++i) {
    if (i == c || str[i] == sep) {
      size_t len = i - last;
      string tmp = str.substr(last, len);
      ret->push_back(tmp);
      last = i + 1;
    }
  }
}
#endif
