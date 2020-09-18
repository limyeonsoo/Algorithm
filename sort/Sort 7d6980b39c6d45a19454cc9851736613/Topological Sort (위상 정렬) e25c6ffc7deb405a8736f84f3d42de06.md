# Topological Sort (위상 정렬)

## DAG (Directed Acyclic Graph)

1. Cycle이 없어야 한다.

## BFS 구현

indegree(한 정점에서 자신에게 들어오는 방향인 간선의 수)를 이용.

queue를 이용.

(-) queue가 중간에 끝난다면 Cycle이 있는 것

## DFS 구현

DFS를 실행하면서 끝나는 순서대로 기록하면 그 역순이 위상정렬.

![Topological%20Sort%20(%E1%84%8B%E1%85%B1%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8C%E1%85%A5%E1%86%BC%E1%84%85%E1%85%A7%E1%86%AF)%20e25c6ffc7deb405a8736f84f3d42de06/Untitled.png](Topological%20Sort%20(%E1%84%8B%E1%85%B1%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8C%E1%85%A5%E1%86%BC%E1%84%85%E1%85%A7%E1%86%AF)%20e25c6ffc7deb405a8736f84f3d42de06/Untitled.png)

![Topological%20Sort%20(%E1%84%8B%E1%85%B1%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8C%E1%85%A5%E1%86%BC%E1%84%85%E1%85%A7%E1%86%AF)%20e25c6ffc7deb405a8736f84f3d42de06/Untitled%201.png](Topological%20Sort%20(%E1%84%8B%E1%85%B1%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8C%E1%85%A5%E1%86%BC%E1%84%85%E1%85%A7%E1%86%AF)%20e25c6ffc7deb405a8736f84f3d42de06/Untitled%201.png)

return 하는 순서대로 값을 Stack에 저장한다.

Stack : 7 5 2 6 3 4 1 

pop시 :  1 → 4 → 3 → 6 → 2 → 5 →  7

![Topological%20Sort%20(%E1%84%8B%E1%85%B1%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8C%E1%85%A5%E1%86%BC%E1%84%85%E1%85%A7%E1%86%AF)%20e25c6ffc7deb405a8736f84f3d42de06/Untitled%202.png](Topological%20Sort%20(%E1%84%8B%E1%85%B1%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8C%E1%85%A5%E1%86%BC%E1%84%85%E1%85%A7%E1%86%AF)%20e25c6ffc7deb405a8736f84f3d42de06/Untitled%202.png)

이와 같을 경우 단순히 visit로 2를 체크 할 경우 Cycle을 확인할 수 없음

Finish 배열 등 따로 Cycle을 체크 할 수 있는 로직을 만들어주어야함.

## reference

[https://jason9319.tistory.com/93](https://jason9319.tistory.com/93)

[2252_줄 세우기](2252_%E1%84%8C%E1%85%AE%E1%86%AF%20%E1%84%89%E1%85%A6%E1%84%8B%E1%85%AE%E1%84%80%E1%85%B5%202ce9f70d7be94f91bc614f532e9536fc.md)

![Topological%20Sort%20(%E1%84%8B%E1%85%B1%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8C%E1%85%A5%E1%86%BC%E1%84%85%E1%85%A7%E1%86%AF)%20e25c6ffc7deb405a8736f84f3d42de06/Untitled%203.png](Topological%20Sort%20(%E1%84%8B%E1%85%B1%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8C%E1%85%A5%E1%86%BC%E1%84%85%E1%85%A7%E1%86%AF)%20e25c6ffc7deb405a8736f84f3d42de06/Untitled%203.png)