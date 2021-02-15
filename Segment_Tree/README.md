# Segment Tree

[1280 나무 심기](https://www.notion.so/1280-b97fcfc6c9b2496694519d5de74fb5d2) 

# 목적 : 구간을 저장하기 위한 트리

## 1. 구간의 정보

구간의 합, 곱 등 구간 마다 정보를 저장하기 위한 Tree형태이다.

ex)

- [구간 합 구하기](http://noj.am/2042)
- [구간 곱 구하기](http://noj.am/11505)
- [하떨별](http://noj.am/17353)

## 2. 구간 중 특정 값 변경

ex) [수열과 쿼리](https://www.acmicpc.net/problemset?search=%EC%88%98%EC%97%B4%EA%B3%BC+%EC%BF%BC%EB%A6%AC)

## 3. 구간 중 최소, 최대 값

ex) [최솟값과 최댓값](https://www.acmicpc.net/problem/2357)

# 생성 과정

## init()

![Segment%20Tree%20f2ee767222f14bfabfe1c7844473d47a/Untitled.png](Segment%20Tree%20f2ee767222f14bfabfe1c7844473d47a/Untitled.png)

- **Leaf Node**에는 **각각의 data**에 해당하는 요소들이 있다.
그들의 **parent** Node에는 자식에 해당하는 **구간에 대한 정보**가 담겨져 있다.
- **Tree Node의 수** : `tree.resize( (1 << ((int)ceil(log2(N)) + 1)));`

    Tree의 크기는 2의 승수 만큼 커질 것. → N개의 node를 표현하려면 log2(N)보다 제곱 만큼 많은 수(+1 한 후, 비트 shift)의 공간이 필요하다.

- **Tree의 값** :
    - Leaf Node라면 ? 구간 start - end 가 같을 것 : tree 값에 arr[start] (**data**)를 넣어준다.
    - Leaf Node가 아니면 ? **구간에 대한 정보**를 넣어준다. (아래는 자식(left & right)의 합.)

    ```cpp
    void init(int node, int start, int end) {
    	if (start == end) tree[node].value = arr[start];
    	else {
    		int mid = (end-start)/2 + start;
    		tree[node].value = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
    	}
    }
    ```

## update()

![Segment%20Tree%20f2ee767222f14bfabfe1c7844473d47a/Untitled%201.png](Segment%20Tree%20f2ee767222f14bfabfe1c7844473d47a/Untitled%201.png)

- 변경할 값이 구간에 해당하는지 확인한다.
- 구간에 해당할 때만 **변경할 값/ 변경할 구간** 을 이용하여 정보를 갱신해준다.

    ```cpp
    void update(int node, int start, int end, int index, int diff){ } or
    void update(int node, int start, int end, int left, int right) {}
    	
    	if (구간이 아니면) return;

    	//구간이면
    	tree[node].value += diff  //정보를 변경..

    	//다음 자식도 update 필수.
    	update(node * 2, start, (start + end) / 2, left, right);
    	update(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    }
    ```

- 구간을 그때 그때 update하지 않는 **Lazy Propagation**도 있다.