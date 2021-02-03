# 비판적 Sorting

[Sorting Table](%E1%84%87%E1%85%B5%E1%84%91%E1%85%A1%E1%86%AB%E1%84%8C%E1%85%A5%E1%86%A8%20Sorting%20f1f046cde5034beeb4ac84d1c36ece66/Sorting%20Table%207836ca42c07a429390fde9e894276023.csv)

---

---

1. Quick sort가 빠른데, Merge, Heap sort가 있는 이유.

- Merge sort

    Merge sort algorithm은 Devide and Conquer 기반.
    즉, 작은 문제로 나누어 sorting후, combine 할 수 있음.

    빅 데이터의 경우 ( 메모리에 데이터 전부를 올릴 수 없을 때) Merge sort가 유용할 수 있음.

- Heap sort

    Heap sort algorithm은 heap의 성질에 의해 최솟값, 최댓값을 때에 따라 O(1)만에 추출 가능.
    또한, Heap이 구성된 상태에서는 heapify를 통해 O(log n)만에 sorting 가능.

2. Quick sort는 항상 빠른가?

- n이 작을 때, n log n 과 n^2의 차이는 미비하다. 즉, Quick sort내부의 function call만 많아질 뿐 효과를 볼 수 없다.
⇒ C++, Java에서는 n이 작을 때, 자동으로 Insertion sort로 sorting한다.
- quick sort는 임의 접근을 하기 때문에 locality가 있을 때 효과적이다.

---

Reference

[https://asfirstalways.tistory.com/338](https://asfirstalways.tistory.com/338)