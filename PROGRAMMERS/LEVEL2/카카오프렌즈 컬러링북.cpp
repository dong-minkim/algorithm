#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<vector<int>> picture;
int M, N;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visited[101][101];

int dfs(const vector<vector<int>> picture, int start_y, int start_x, int now) {
    int cnt = 1;
    visited[start_y][start_x] = 1;
    for (int i = 0; i < 4; i++) {
        int Y = start_y + dy[i];
        int X = start_x + dx[i];

        if (Y < 0 || Y >= M || X < 0 || X >= N) continue;
        if (visited[Y][X] == 0 && (now == picture[Y][X])) {
            cnt += dfs(picture, Y, X, now);
        }
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    M = m;
    N = n;
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<int> answer(2);
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0 && picture[i][j] != 0) {
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, dfs(picture, i, j, picture[i][j]));
            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}