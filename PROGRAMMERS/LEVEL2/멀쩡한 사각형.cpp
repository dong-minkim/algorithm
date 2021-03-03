using namespace std;

//수학적 사고력을 요하는 문제.
long long solution(int w, int h) {
    long long answer;
    answer = ((long long)w * (long long)h) - (long long)w - (long long)h;
    while (h != 0) {
        int tmp = w % h;
        w = h;
        h = tmp;
    }
    answer += w;

    return answer;

}