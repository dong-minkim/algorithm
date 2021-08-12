#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<pair<int, int>> box(6, { 0,0 });

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int Answer = 1e9;

		for (int i = 0; i < 3; i++) {
			int w, h;
			cin >> w >> h;
			box[i].first = w; box[i].second = h;
			box[i + 3].first = h; box[i + 3].second = w;
		}

		

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k < 6; k++) {
					if (i % 3 == j % 3 || j % 3 == k % 3 || k % 3 == i % 3) continue; //같은 상자

					int width = box[i].first + box[j].first + box[k].first;
					int height = max(box[i].second, max(box[j].second, box[k].second));
					Answer = min(Answer, width * height);

					width = max(box[i].first, box[j].first + box[k].first);
					//height = min(box[j].second, box[k].second) + box[i].second;
					height = box[i].second + max(box[j].second, box[k].second);
					Answer = min(Answer, width * height);

				}
			}
		}

		cout << Answer << '\n';
	}
	return 0;
}