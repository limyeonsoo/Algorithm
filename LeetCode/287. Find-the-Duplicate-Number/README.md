---
title: "LeetCode 287. Find the Duplicate Number"
categories:
    - leetcode
tags:
    - [PS, Algorithm, Hash]

toc: true
toc_icon: true
toc_sticky: true

author_profile: true
sidebar_main: true
toc_sticky: true

date: 2022-03-29
last_modified_at: 2022-03-29
---

```java
class Solution {
    public int findDuplicate(int[] nums) {
        var numberSet = new HashSet<Integer>();

        for(var num: nums) {
            if(numberSet.contains(num)) return num;
            numberSet.add(num);
        }
        
        return 0;
    }
}
```
