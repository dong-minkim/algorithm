import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class Solution {
	
	public static int[] solution(String[] id_list, String[] report, int k) {
		int[] answer = {};
		
		answer = new int[id_list.length];
		
		Map<String, Integer> result = new HashMap<>();
		Map<String, HashSet<String>> reportMap = new HashMap<>();
		
		for(int i=0;i<id_list.length;i++) {
			HashSet<String> from = new HashSet<>();
			reportMap.put(id_list[i], from);
			result.put(id_list[i], 0);
		}
		
		for(String str : report) {
			String[] token = str.split(" ");
			reportMap.get(token[1]).add(token[0]);
		}
		
		for(String to : reportMap.keySet() ) {
			int reportCnt = reportMap.get(to).size();
			if (reportCnt >= k) {
				for (String id : reportMap.get(to)) {
					result.put(id, result.get(id) + 1);
				}
			}
		}
		
		for(int i=0;i<id_list.length;i++) {
			answer[i] = result.get(id_list[i]);
		}
		
		return answer;
	}
}