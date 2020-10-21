#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void print(const vector<int>& ret) {
    for (size_t i = 0; i < ret.size(); i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
}
void print(const vector< vector<int> >& ret) {
    for (size_t i = 0; i < ret.size(); i++) {
        print(ret[i]);
    }
}
void print(const vector<string>& ret) {
    printf("size:%ld\n", ret.size());
    for (size_t i = 0; i < ret.size(); i++) {
        printf("%ld:\"%s\"\n", ret[i].size(), ret[i].c_str());
    }
    printf("\n");
}

int StringToInt(const char *s) {
    while (isspace(*s)) s++;
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
int StringToInt(const string& s) {
    return StringToInt(s.c_str());
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


// 字符串转整数数组
// "1,-2,0,3,4" => [1,-2,0,3,4]
vector<int> StringToVector(char *s) {
    vector<int> ret;
    vector<string> tmp;
    SplitString(s, ',', &tmp);
    for (size_t i = 0; i < tmp.size(); i++) {
        int n = StringToInt(tmp[i]);
        ret.push_back(StringToInt(tmp[i]));
    }
    return ret;
}


#endif
