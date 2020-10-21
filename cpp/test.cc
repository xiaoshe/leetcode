#include "util.hpp"

int main(int argc, char *argv[]) {
    /*
    vector<string> words;
    SplitString(argv[1], ' ', &words);
    print(words);

    int n = StringToInt(argv[1]);
    printf("n:%d\n", n);
    */

    vector<int> ret = StringToVector(argv[1]);
    print(ret);
}
