---
title: "LeetCode 344. Reverse String"
categories:
- leetcode
tags:
- [PS, Algorithm, Array]

toc: true
toc_icon: true
toc_sticky: true

author_profile: true
sidebar_main: true
toc_sticky: true

date: 2022-04-01
last_modified_at: 2022-04-01
---

```java
class Solution {
    public void reverseString(char[] s) {
        for(var i=0; i<s.length / 2; i++) {
            var temp = s[i];
            s[i] = s[s.length - i - 1];
            s[s.length - i - 1] = temp;
        }
        return;
    }
}
```
