# Minimum Spanning Tree

## Kruskal Algorithm

1. 초기화시 vertex로만 그래프를 구성한다.
2. Edge set을 non-decreasing으로 sorting한다.
3. weight가 제일 작은 edge부터 검토한다.
4. Cycle이 생기지 않는 경우에만 edge를 추가한다.

 5.  모든 vertex가 연결되면 종료된다.

 6.  모든 edge에 대한 판단이 이루어졌다면 완성될 수 없다.

[Union-Find](Union-Find%205f9c469108b5464fa90bc7086ae2155f.md)

**Time Complexity**

1. Edge weight sorting = O(E log E)
2. cycle 검사 및 set-id통일 = O(E log E)

 O(E log E)

## Prim Algorithm

1. 초기화시 한 개의 vetex로 구성한다.
2. 그 vertex로 부터 외부에 있는 vertex사이의 edge를 연결하는데 가장 작은 weight의 edge 및 vertex를 추가한다.

    즉, vertex와 관계없이 edge의 weight만 본다.

    **A→D를 연결했다면 D만 보는 것이 아니라, A, D 에 연결된 모든 edge에서 비교한다.**

3. 모든 vertex들이 연결되면 종료된다.

**Time Complexity**

 O(E log V)

Reference

[https://ko.wikipedia.org/wiki/프림_알고리즘](https://ko.wikipedia.org/wiki/%ED%94%84%EB%A6%BC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)

[1197_(prim)최소 스패닝 트리](1197_(prim)%E1%84%8E%E1%85%AC%E1%84%89%E1%85%A9%20%E1%84%89%E1%85%B3%E1%84%91%E1%85%A2%E1%84%82%E1%85%B5%E1%86%BC%20%E1%84%90%E1%85%B3%E1%84%85%E1%85%B5%20dac17fcffbed4cbb816b6260e1b4352d.md)

[2887_(kruskal)행성터널](2887_(kruskal)%E1%84%92%E1%85%A2%E1%86%BC%E1%84%89%E1%85%A5%E1%86%BC%E1%84%90%E1%85%A5%E1%84%82%E1%85%A5%E1%86%AF%2010da08d23d5b4a15af67a2479a22d5d9.md)