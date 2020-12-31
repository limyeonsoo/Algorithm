import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static boolean[] erathosChae = new boolean[2000001];
    public static ArrayList<Integer> prime = new ArrayList<Integer>();

    public static void makeErathosChae(){
        for(int i=2; i<=2000000; i++)
            if(!erathosChae[i]){
                prime.add(i);
                for(int j=i+i; j<=2000000; j+=i)
                    erathosChae[j] = true;
            }
    }

    public static String erathosCheck(long left, long right){
        long target = left + right - 2;

        for(int i=0; (i<prime.size()) && ((long)prime.get(i)*prime.get(i) <= target); i++){
            if(target % prime.get(i) == 0) return "NO";
        }
        return "YES";
    }

    public static void main(String[] args) throws IOException{

        makeErathosChae();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCase = Integer.parseInt(br.readLine());
        for(int i=0; i<testCase; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            long lefter = Long.valueOf(st.nextToken());
            long righter = Long.valueOf(st.nextToken());
            if(lefter+righter <= 3) System.out.println("NO");
            else if((lefter+righter)%2 == 0) System.out.println("YES");
            else System.out.println(erathosCheck(lefter, righter));
        }
    }
}
