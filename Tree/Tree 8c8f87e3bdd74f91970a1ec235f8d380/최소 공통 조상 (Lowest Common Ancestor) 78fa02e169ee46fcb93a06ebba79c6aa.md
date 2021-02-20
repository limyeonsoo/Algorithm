# 최소 공통 조상 (Lowest Common Ancestor)

[11812 K진 트리](11812%20K%E1%84%8C%E1%85%B5%E1%86%AB%20%E1%84%90%E1%85%B3%E1%84%85%E1%85%B5%2085057b95e7634620a03e3cf4f7a6eef3.md)

## Logic

### 1. 모든 Node에 대한 Depth를 계산한다.

### 2. 두 Node에서 Depth가 동일 할 때 까지 거슬러 올라간다.

### 3. 그 후, 부모가 같아질 때 까지 거슬러 올라간다.

## Method

### 1. 한 부모씩 거슬러 가면서 탐색 ⇒ $O(N)$

### 2. $2^N$부모씩 거슬러 가면서 탐색 ⇒ $O(NlogN)$

![%E1%84%8E%E1%85%AC%E1%84%89%E1%85%A9%20%E1%84%80%E1%85%A9%E1%86%BC%E1%84%90%E1%85%A9%E1%86%BC%20%E1%84%8C%E1%85%A9%E1%84%89%E1%85%A1%E1%86%BC%20(Lowest%20Common%20Ancestor)%2078fa02e169ee46fcb93a06ebba79c6aa/Untitled.png](%E1%84%8E%E1%85%AC%E1%84%89%E1%85%A9%20%E1%84%80%E1%85%A9%E1%86%BC%E1%84%90%E1%85%A9%E1%86%BC%20%E1%84%8C%E1%85%A9%E1%84%89%E1%85%A1%E1%86%BC%20(Lowest%20Common%20Ancestor)%2078fa02e169ee46fcb93a06ebba79c6aa/Untitled.png)

![%E1%84%8E%E1%85%AC%E1%84%89%E1%85%A9%20%E1%84%80%E1%85%A9%E1%86%BC%E1%84%90%E1%85%A9%E1%86%BC%20%E1%84%8C%E1%85%A9%E1%84%89%E1%85%A1%E1%86%BC%20(Lowest%20Common%20Ancestor)%2078fa02e169ee46fcb93a06ebba79c6aa/Untitled%201.png](%E1%84%8E%E1%85%AC%E1%84%89%E1%85%A9%20%E1%84%80%E1%85%A9%E1%86%BC%E1%84%90%E1%85%A9%E1%86%BC%20%E1%84%8C%E1%85%A9%E1%84%89%E1%85%A1%E1%86%BC%20(Lowest%20Common%20Ancestor)%2078fa02e169ee46fcb93a06ebba79c6aa/Untitled%201.png)