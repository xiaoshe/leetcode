#include "util.h"


int main(int argc, char *argv[]) {
    char *file = "data/0.txt";
    FILE *rp = fopen(file, "r");
    char s[128];
    while (fgets(s, 128, rp)) {
        if (s[0] == '#') continue;
        int a[32];
        int n = string_to_array(s, a);
        print_array(a, n);

        // TODO
        
        
    }
    fclose(rp);
    return 0;
}
