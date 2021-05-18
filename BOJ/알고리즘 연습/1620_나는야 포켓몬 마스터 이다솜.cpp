#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;

map<string, int> monster_str;
map<int, string> monster_int;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		
		monster_str[str]= i+1;
		monster_int[i+1] = str;
	}

	for (int i = 0; i < M; i++)
	{
		string st;
		cin >> st;
		char ch = st[0];
		if (ch >= 'A')
		{
			cout << monster_str[st]<<'\n';
		}
		else
		{
			int num = atoi(st.c_str());
			cout << monster_int[num] << '\n';
		}
	}
	return 0;
}