**Note**
- 일단 알고리즘의 분야가 매우 다양하고, 알아야할 지식들이 너무 많다.
- 기본적으로 [분류](https://www.acmicpc.net/problem/tags)도 많아서, 기본이 되는 것들만 정리

### Basic Code
1. Heapify : up, down 방식 모두 암기 / 삭제 / 삭제
2. Quick Sort 
3. Queue / LinkedList / vector 구현
4. 순열, 조합 경우의 수를 만들어 내기
5. 부분 집합을 만들어 내기
6. Binaray Search 
7. DFS / BFS 구현
8. DisjoinSet / Kruskal / Dijkstra / Floyd Wrashall
 
### Next Step
9. 문자열 : SA, LCA ..
10. Topolgy Sort : BFS 로 구현 진입차수가 0 인 노드들을 Queue 에 넣음
11. Network Flow : BFS 로 구현
12. 이분 매칭 : DFS 로 구현
13. Line Sweeping
14. [Segment Tree](https://www.acmicpc.net/blog/view/9) : 구간 합 - 배열크기 1<<(N+1),또는 4* 속도 : O(logN)
15. BIT(Binary Index Tree, [Fenwick Tree](https://www.acmicpc.net/blog/view/21)) : 구간 합 - 배열크기 N, 속도 : O(logN)
16. LCA

### Basic Approach

0. 글과 그림으로 표현한다. 특히 조건문 / 순회 방식 / 답을 바로 구하는 것이 좋은지, 반대를 구하고 전체에서 빼는 게 좋은지?
1. DFS / BFS 로 풀어 낼 수 있는지 확인힌다.
     - 이때, 순회를 어떻게 할 것인가를 결정 ( 순열이나, 조합이냐, 부분 집합 이냐 ), 조건은 어떻게 어디서 판단할 것인가.
        - 재귀함수에 대한 이해가 필수 ([문제](https://www.acmicpc.net/problem/14888))
     - DFS : 한쪽으로 뻣어나가면서 검색하면서, 전체를 순회하고 답의 크기를 비교.
     - 2차원 그래프를 순회할때는 좌표단위로 움직일것인가? 단순히 Node 와 Node 를 연결해서 움직일 것인가 ?
     - 전자는 2차원적 움직임 / 후자는 1차원으로 next 로 
     - 노드의 개수가 10,000 개를 넘어가면, 2중 배열을 메모리 부족으로 잡을 수 없다.
       ( 따라서, 이런경우에는 반드시 linked list 로 처리해야한다.)
     - BFS : 둥굴게 둥굴게 퍼지면서 검색 - 최단거리를 찾을 때 사용, 처음나온 것이 답이다.
       ( Queue 에 넣기전에 visit 처리해야한다. )
   
2. 메모이제이션
3. 절대 답이될수 없는 부분은 가지치기로 더이상 순회하지 않는다.
4. 2차원 상의 그래프에서 객체의 움직임 표현하고 기술 하는 방식을 구현
     - 특히 여러 객체가 움직이는 경우, 충돌에 대한처리 ( 별도의 MAP 또는 충돌만 관리하는 MAP )
5. DP 로 풀수있는가? 
     - 사실상 아는 문제가 아니면 공식을 생각하기가 어렵다.

* 문제의 출력조건을 확인하라. 단순히 거리의 합인가? 목록을 출력하기 인가? 어떠한 제약조건이 있는가?
* 입력되는 노드가 크기가 백만이 넘어간다면 DP 또는 이분탐색을 고려해봐라.
* 순서가 중요하지 않다면 list 나 vector 를 사용하지 않고, 단순 배열 로 처리하기 위한 방법을 고려하라.
    - insert : szie++ 마지막 에 원소 삽입
    - delete : MAX 크기의 배열을 잡고, 마지막 원소를 삭제하려는 원소에 복사하고, size-- 를 수행.

### 유명한 알고리즘

0. 크루스컬 알고리즘 : 전체 노드를 최단 거리로 순회하기
   - Union Find 암기
   - 정렬

1. 플로이드 와샬 : 전체 노드의 최단 거리 찾기.
   - O(n^3) 즉, n 이 1000 이하에서만 가능하다. 그 이상이면 사용 불가.

2. 다익스트라 : 시작점에서 마지막점이 주어진 경우 최단거리 찾기 
   - prioirty queue 구현
   - 정점과 간선의 개수가 늘아나면,
   - [문제](https://www.acmicpc.net/problem/1753)

3. Fenwick Tree
   - 일정 범위씩 서로 다른 구간의 정보를 저장함.
   - 일정 범위 : i & -i 로 저장하고 있는 값들의 개수를 계산 (어떤 수 i를 이진수로 나타냈을 떄, 마지막 1의 위치)
   
```c
int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
void update(int i, int num) { // num 는 diff 
    while (i <= n) {
        tree[i] += num;
        i += (i & -i);
    }
}
```

4. 라인 스위핑
   - 기본 개념에 비해서 실제 응용은 구현이 다양함.
   - 1차원 연결 -> 2차원으로 넘어가면 까다로움 
  
 
### 문자열 관련 

... 으윽.
