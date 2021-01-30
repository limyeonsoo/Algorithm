# D.P.

[LeetCode 45 Jump Game II](D%20P%205a1eb342c2bb42738f147f124869ff9c/LeetCode%2045%20Jump%20Game%20II%20f22cc6706cca4a0abd428deee09704d2.md)

[Programmers 1843 사칙연산](D%20P%205a1eb342c2bb42738f147f124869ff9c/Programmers%201843%20%E1%84%89%E1%85%A1%E1%84%8E%E1%85%B5%E1%86%A8%E1%84%8B%E1%85%A7%E1%86%AB%E1%84%89%E1%85%A1%E1%86%AB%20ee43dbe76f9a4b7fb84e00cf1adc4c2b.md)

- 점화식
- Memorization
- 작은 문제로 큰 문제를 해결.

## Ex) 귀납법

![D%20P%205a1eb342c2bb42738f147f124869ff9c/Untitled.png](D%20P%205a1eb342c2bb42738f147f124869ff9c/Untitled.png)

## Ex) Memorization (피보나치)

```cpp
int fibonacci(int n){

		if(n==0) return 1;
		if(n==1) return 1;

		return fibonacci(n-1) + fibonacci(n-2);
}
```

```cpp
int fibonacci(int n){
		if(n==0) return 1;
		if(n==1) return 1;
		if(memo[n]) return memo[n];
		memo[n] = fibonacci(n-1) + fibonacci(n-2);
		return memo[n];
}
```

![D%20P%205a1eb342c2bb42738f147f124869ff9c/Untitled%201.png](D%20P%205a1eb342c2bb42738f147f124869ff9c/Untitled%201.png)

## DP가 필요한 예)

![D%20P%205a1eb342c2bb42738f147f124869ff9c/Untitled%202.png](D%20P%205a1eb342c2bb42738f147f124869ff9c/Untitled%202.png)