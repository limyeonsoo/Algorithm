import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        
        var aggregatedReport = new HashMap<String, ArrayList<String>>();
        reportListAggregate(report, aggregatedReport);
        
        var successReporter = getSuccessReporter(aggregatedReport, id_list, k);
        
        int[] answer = new int[id_list.length];
        for(var i=0; i<id_list.length; i++) {
            var target = id_list[i];
            if(successReporter.containsKey(target))
                answer[i] = successReporter.get(target);
            else answer[i] = 0;
        }
        return answer;
    }
    
    private void reportListAggregate(
        final String[] report,
        final HashMap<String, ArrayList<String>> aggregatedReport) {
         for(var content: report) {
             var reporter = content.split(" ")[0];
             var reported = content.split(" ")[1];
            
             ArrayList<String> list = new ArrayList<String>();
             if(aggregatedReport.containsKey(reported)) {
                 list = aggregatedReport.get(reported);
                 list.add(reporter);
             }else {
                 list.add(reporter);
                 aggregatedReport.put(reported, list);
            }
        }
    }
    
    private HashMap<String, Integer> getSuccessReporter(
        HashMap<String, ArrayList<String>> aggregatedReport,
        String[] id_list,
        int k
    ) {
        var successReporter = new HashMap<String, Integer>();
        for(var i=0; i<id_list.length; i++) {
            var target = id_list[i];
            if(aggregatedReport.containsKey(target) == false) continue;
            
            ArrayList<String> list = new ArrayList<String>();
            list = aggregatedReport.get(target);
            Set<String> set = new HashSet<String>(list);
            if(set.size() < k) continue;
            else {
                for(var success: set) {
                    if(successReporter.containsKey(success)) {
                        successReporter.put(success, successReporter.get(success) + 1);
                    }else {
                        successReporter.put(success, 1);
                    }
                }
            }
        } 
        return successReporter;
    }
}
