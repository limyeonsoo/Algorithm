import java.text.*;
import java.util.*;

class Solution {
    public int[] solution(int[] fees, String[] records) {
    
        var findRecordByCar = new HashMap<String, ArrayList<String>>();
        for(var record: records) {
            var splitedRecord = record.split(" ");
            if(findRecordByCar.containsKey(splitedRecord[1])) {
                var list = findRecordByCar.get(splitedRecord[1]);
                list.add(splitedRecord[0]);
            }else {
                var list = new ArrayList<String>();
                list.add(splitedRecord[0]);
                findRecordByCar.put(splitedRecord[1], list);
            }
        }
        
        var findTimeByCar = new HashMap<String, Integer>();
        for(var carMap: findRecordByCar.entrySet()) {
            if(carMap.getValue().size() % 2 == 1) {
                var list = carMap.getValue();
                list.add("23:59");
            }
            
            for(var i=0; i<carMap.getValue().size(); i+=2) {
                var result = getDiff(hhmmToMinutes(carMap.getValue().get(i)), hhmmToMinutes(carMap.getValue().get(i+1)));
                if(findTimeByCar.containsKey(carMap.getKey())) {
                    findTimeByCar.put(carMap.getKey(), findTimeByCar.get(carMap.getKey()) + result);
                }else {
                    findTimeByCar.put(carMap.getKey(), result);
                }
            }
        }
        
        List sortedCar = new ArrayList(findTimeByCar.keySet());
        Collections.sort(sortedCar);
    
        int[] answer = new int[sortedCar.size()];
        for(var i=0; i<sortedCar.size(); i++){
            if(findTimeByCar.get(sortedCar.get(i)) < fees[0]) answer[i] = fees[1];
            else answer[i] = fees[1] + (int)Math.ceil((double) (findTimeByCar.get(sortedCar.get(i)) - fees[0]) / fees[2]) * fees[3];
        }
        
        return answer;
    }
    
    private int getDiff(final Date inTime, final Date outTime) {
        return (int)(outTime.toInstant().getEpochSecond() - inTime.toInstant().getEpochSecond()) / 60;
    }
    
    private Date hhmmToMinutes(final String hhmm) {
        SimpleDateFormat transFormat = new SimpleDateFormat("HH:mm");
        try {
            return transFormat.parse(hhmm);    
        } catch(ParseException e) {
            return null;
        }
    }
}

