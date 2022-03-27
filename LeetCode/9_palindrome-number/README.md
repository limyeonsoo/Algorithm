class Solution {
    public boolean isPalindrome(int x) {
        final var xStr = String.valueOf(x);
        
        for(var i=0; i<xStr.length()/2; i++) {
            final var leftIndex = i;
            final var rightIndex = xStr.length() - 1 - i;
            if(xStr.charAt(leftIndex) != xStr.charAt(rightIndex))
                return false;
        }
        
        return true;
    }
}

