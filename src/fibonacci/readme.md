[Question](https://www.acmicpc.net/problem/2748)
```c
int fibonacci(int n)
{
    if (n==0)
        return 0;
    else if (n==1)
        return 1;

    return fibonacci(n-1) + fibonacci(n-2); // fail 
}
```

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
