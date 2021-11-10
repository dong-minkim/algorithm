#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows�� 2���� �迭 sizes�� �� ����, sizes_cols�� 2���� �迭 sizes�� �� �����Դϴ�.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    int max_x = 0;
    int max_y = 0;
    for (int i = 0; i < sizes_rows; i++) {
        if (sizes[i][0] < sizes[i][1]) {
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
    }
    for (int i = 0; i < sizes_rows; i++) {
        if (max_x < sizes[i][0]) max_x = sizes[i][0];
        if (max_y < sizes[i][1]) max_y = sizes[i][1];
    }
    answer = max_x * max_y;
    return answer;
}