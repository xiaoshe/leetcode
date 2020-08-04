#ifndef UTIL_HPP_
#define UTIL_HPP_

using namespace std;

void print_vector(const std::vector<int>& ret) {
    for (size_t i = 0; i < ret.size(); i++) {
        printf("%d ", ret[i]);
    }
    printf("\n");
}

#endif
