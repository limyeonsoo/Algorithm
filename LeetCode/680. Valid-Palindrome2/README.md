---
title: "LeetCode 680. Valid Palindrome 2"
categories:
- leetcode
tags:
- [PS, Algorithm, String]

toc: true
toc_icon: true
toc_sticky: true

author_profile: true
sidebar_main: true
toc_sticky: true

date: 2022-04-02
last_modified_at: 2022-04-02
---

```Java
class Solution {
    public boolean validPalindrome(String s) {
        int l = 0;
        int r = s.length() - 1;
        
        while(l < r) {
            if(s.charAt(l) == s.charAt(r)) {
                l++; r--;
            }else {
                return isPalindrome(s, l+1, r) | isPalindrome(s, l, r-1);
            }
        }
        return true;
    }
    
    private static boolean isPalindrome(String s, int l, int r) {
        while(l < r) {
            if(s.charAt(l) != s.charAt(r)) {
                return false;
            }
            l++; r--;
        }
        return true;
    }
}
```

can be delete **at most one** character from it.

기회가 1번 주어진다.

왼쪽에서 1개 봐주던지, 오른쪽에서 1개 봐주던지 딱 한 번 기회를 더 줬다.
