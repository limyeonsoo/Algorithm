# 최단거리 알고리즘

---

## Dijkstra

[Dijkstra](%E1%84%8E%E1%85%AC%E1%84%83%E1%85%A1%E1%86%AB%E1%84%80%E1%85%A5%E1%84%85%E1%85%B5%20%E1%84%8B%E1%85%A1%E1%86%AF%E1%84%80%E1%85%A9%E1%84%85%E1%85%B5%E1%84%8C%E1%85%B3%E1%86%B7%20646dd2a232d14d66a18ffeeeb27fc96a/Dijkstra%200b27a47ab4df42c9a1e54bdb7e554e9b.md)

## The Bellman_Ford

[Bellman Ford](%E1%84%8E%E1%85%AC%E1%84%83%E1%85%A1%E1%86%AB%E1%84%80%E1%85%A5%E1%84%85%E1%85%B5%20%E1%84%8B%E1%85%A1%E1%86%AF%E1%84%80%E1%85%A9%E1%84%85%E1%85%B5%E1%84%8C%E1%85%B3%E1%86%B7%20646dd2a232d14d66a18ffeeeb27fc96a/Bellman%20Ford%209b605804bc0f44eaa34da52b5524d70f.md)

## Floyd-Warshall

[Floyd-Warshall](%E1%84%8E%E1%85%AC%E1%84%83%E1%85%A1%E1%86%AB%E1%84%80%E1%85%A5%E1%84%85%E1%85%B5%20%E1%84%8B%E1%85%A1%E1%86%AF%E1%84%80%E1%85%A9%E1%84%85%E1%85%B5%E1%84%8C%E1%85%B3%E1%86%B7%20646dd2a232d14d66a18ffeeeb27fc96a/Floyd-Warshall%20b010d646e30b44dda02b1e9716ca5742.md)

---

최단 경로 문제

1. **단일 출발(single-source) 최단 경로**
하나의 정점에서 출발 → 나머지 모든 정점까지 경로 탐색.
2. **단일 도착(single-destination) 최단 경로**
모든 정점에서 출발 → 하나의 정점까지 경로 탐색.

    ⇒ (1)과 (2)는 대우 관계

3. **단일 쌍(single-pair) 최단 경로**
어떤 정점 x에서 y로 가는 최단 경로 탐색.
4. **전체 쌍(all-pair) 최단 경로**
모든 정점 쌍들 사이의 최단 경로 탐색.

![%E1%84%8E%E1%85%AC%E1%84%83%E1%85%A1%E1%86%AB%E1%84%80%E1%85%A5%E1%84%85%E1%85%B5%20%E1%84%8B%E1%85%A1%E1%86%AF%E1%84%80%E1%85%A9%E1%84%85%E1%85%B5%E1%84%8C%E1%85%B3%E1%86%B7%20646dd2a232d14d66a18ffeeeb27fc96a/Untitled.png](%E1%84%8E%E1%85%AC%E1%84%83%E1%85%A1%E1%86%AB%E1%84%80%E1%85%A5%E1%84%85%E1%85%B5%20%E1%84%8B%E1%85%A1%E1%86%AF%E1%84%80%E1%85%A9%E1%84%85%E1%85%B5%E1%84%8C%E1%85%B3%E1%86%B7%20646dd2a232d14d66a18ffeeeb27fc96a/Untitled.png)