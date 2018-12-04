[Question](https://www.acmicpc.net/problem/2748)
```c
int fibonacci(int n)
{
    if (n==0) return 0;
    if (n==1) return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}
```

[메모이제이션](https://ko.wikipedia.org/wiki/메모이제이션)을 이용한 약간의 개선
```c
int fibonacci(int n)
{
      if (n==0) return 0;
      if (n==1) return 1;
  
      if (array[n]) return array[n];
      array[n] = fibonacci(n-1) + fibonacci(n-2);
  
      return array[n];
}
```
참고 : [Pisano Period](https://en.wikipedia.org/wiki/Pisano_period) 
피보나치의 결과값을 임의의 수 n 으로 나는 나머지는 일정한 주기(Pisano Period)라 부름
관련 문제
https://www.acmicpc.net/problem/2749
https://www.acmicpc.net/problem/9471
