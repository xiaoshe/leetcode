#include "util.hpp"

void print(const vector< vector<int> >& m) {
    int n = m.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int half = n / 2;
        for (int i = 0; i < half; i++) matrix[i].swap(matrix[n-i-1]);
        print(matrix);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }
};

int main() {
    FILE *rp = fopen("data/48.txt", "r");
    int n = 0;
    fscanf(rp, "%d", &n);
    vector< vector<int> > matrix;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            int t;
            fscanf(rp, "%d", &t);
            tmp.push_back(t);
        }
        matrix.push_back(tmp);
    }

    fclose(rp);

    print(matrix);
    Solution s;
    s.rotate(matrix);
    print(matrix);

}
