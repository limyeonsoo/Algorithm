import java.util.HashMap;

class Solution {
    public String solution(String[] participant, String[] completion) {
        final var matcherMap = new HashMap<String, Integer>();
        
        for(var success : completion) {  
            matcherMap.put(success, matcherMap.getOrDefault(success, 0) + 1);
        }
        
        for(var person : participant) {
            if( matcherMap.get(person) == null ) return person;    
            else if( matcherMap.get(person) == 0 ) return person;
            else matcherMap.put(person, matcherMap.get(person) - 1);
        }
        
        return "";
    }
}
