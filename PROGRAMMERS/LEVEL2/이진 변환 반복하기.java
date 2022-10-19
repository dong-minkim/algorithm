import java.util.*;

class Solution {
	public int[] solution(String s) {
		int cnt1 = 0;
		int cnt2 = 0;

		while (!s.equals("1")) {
			String tmp = "";
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) != '0')
					tmp += String.valueOf(s.charAt(i));
				else
					cnt2++;
			}

			int num = tmp.length();
			tmp = "";

			while (num != 1) {
				tmp += num % 2;
				num /= 2;
			}

			s = 1 + tmp;
			cnt1++;
		}
		int[] answer = {cnt1, cnt2};
		return answer;
	}
}