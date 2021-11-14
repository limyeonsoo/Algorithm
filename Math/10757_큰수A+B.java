import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Integer> stack = new Stack();
        String tempInput = br.readLine();
        String[] input = tempInput.split(" ");

        char[] arr1 = input[0].toCharArray();
        char[] arr2 = input[1].toCharArray();
        List<Character> list1 = new ArrayList();
        List<Character> list2 = new ArrayList();
        List<Integer> result = new ArrayList();
        for(char each : arr1){
            list1.add(each);
        }
        for(char each : arr2){
            list2.add(each);
        }
        Collections.reverse(list1);
        Collections.reverse(list2);
        int maxLength = Math.max(input[0].length(), input[1].length());
        if(list1.size() != maxLength){
            int temp = list1.size();
            for(int i=0; i<maxLength-temp; i++){
                list1.add('0');
            }
        }
        if(list2.size() != maxLength){
            int temp = list2.size();
            for(int i=0; i<maxLength-temp; i++){
                list2.add('0');
            }
        }

        int carry = 0;
        for(int i=0; i<maxLength; i++){
            int currentSum = 0;

            currentSum = carry + Character.getNumericValue(list1.get(i)) + Character.getNumericValue(list2.get(i));

            if(currentSum >= 10){
                carry = 1;
                currentSum -= 10;
            }else{
                carry = 0;
            }
            result.add(currentSum);
        }
        if(carry != 0) result.add(1);
        Collections.reverse(result);
        for(int i=0; i<result.size(); i++){
            System.out.print(result.get(i));
        }
    }
}
