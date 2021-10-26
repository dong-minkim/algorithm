#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	int T, test_case;
	int R;


	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		long long  radius = 0;
		cin >> radius;

		long long sum = 0;
		for (long long i = 1; i < radius; i++) {
			long long temp = (radius * radius);
			temp -= (i * i);
			long long temp2 = sqrt(temp);
			if (temp2 * temp2 == temp) {
				sum += temp2 - 1;
			}
			else {
				sum += temp2;
			}
		}
		sum *= 4;
		sum += (radius - 1) * 4 + 1;
		cout << "Case #" << test_case + 1 << endl;
		cout << sum << endl;
	}

	return 0;
}