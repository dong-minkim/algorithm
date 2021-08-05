#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> tmp;
    tmp.push_back(0);
    int answer = 0;
    int size = board.size();
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < size; j++) {
            if (board[j][moves[i] - 1] != 0) {
                if (tmp.back() == board[j][moves[i] - 1]) {
                    tmp.pop_back();
                    answer += 2;
                }
                else {
                    tmp.push_back(board[j][moves[i] - 1]);
                }
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }
    return answer;
}