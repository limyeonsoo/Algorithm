import java.util.Arrays;

class Solution {
    public boolean solution(String[] phone_book) {
        
        Arrays.sort(phone_book);
        
        for(var i = 0; i < phone_book.length -1; i++) {
            final var pre = phone_book[i];
            final var post = phone_book[i+1];
            
            if(pre.length() > post.length()) continue;
            if(pre.equals(post.substring(0, pre.length()))) return false;
        }
        return true;
    }
}
