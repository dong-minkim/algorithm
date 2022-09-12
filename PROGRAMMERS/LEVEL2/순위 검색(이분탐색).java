import java.util.*;
import java.util.Map.Entry;

class Solution {
	   
    public int[] solution(String[] info, String[] query) {
    	int[] answer = new int[query.length];
        
        Map<String, ArrayList<Integer>> map = new HashMap<>();
        
        for(int i=0; i<info.length; i++){// 풀이 순서 1
           
            String[] infoSplit = info[i].split(" ");
            String[] str1 = { infoSplit[0], "-" };
            String[] str2 = { infoSplit[1], "-" };
            String[] str3 = { infoSplit[2], "-" };
            String[] str4 = { infoSplit[3], "-" };
            
            for(String s1 : str1){
                for(String s2 : str2){
                    for(String s3 : str3){
                        for(String s4 : str4){
                            String str = s1+s2+s3+s4;
                            if(map.containsKey(str)){
                                map.get(str).add(Integer.parseInt(infoSplit[4]));
                            }else{
                                ArrayList<Integer> list = new ArrayList<>();
                                list.add(Integer.parseInt(infoSplit[4]));
                                map.put(str, list);
                            }
                        }
                    }
                }
            }
        }
        
        for(String key : map.keySet()){
            Collections.sort(map.get(key));
        }
        
        for(int i=0; i<query.length; i++){// 풀이 순서 3
            String[] q = query[i].replaceAll(" and ", " ").split(" ");
            String str = q[0]+q[1]+q[2]+q[3];
            int target = Integer.parseInt(q[4]);
            
            if(map.containsKey(str)){
               
                if(map.get(str).size()==1){  //1개일 경우 
                    if(target<=map.get(str).get(0)){
                    	answer[i] = 1; 
                    	}
                }else{                       //2개 이상일 경우              
                    int min = 0;
                    int max = map.get(str).size()-1;
                    int mid;
                    
                    while (min<=max){
                        mid = (min+max)/2;
                        if (map.get(str).get(mid)<target){ min = mid + 1; }
                        else { max = mid - 1; }
                    }
                    answer[i] = map.get(str).size()-min;
                }
            }
        }
        return answer;
    }
}
