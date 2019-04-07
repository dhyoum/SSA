#include <stdio.h>

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
class heap
{
	T data[1000];
	int length;
public:
	heap() : length(0) {}

	void push(T val) {
		data[++length] = val;

		int c = length;
		int root = c / 2;
		while (c > 1 && data[c] > data[root]) {
			swap(data[c], data[root]);
			c = root;
			root = c / 2;
		}
	}

	T pop() {
		if (length == 0) return T();

		T val = data[1];
		data[1] = data[length--];

		int c = 1;
		while (1) {
			int next = c * 2;
			if (next < length && data[next] < data[next + 1])
				next++;
			if (next > length || data[c] > data[next])
				break;
			swap(data[c], data[next]);
			c = next;
		}

		return val;
	}

	bool empty() {
		return length==0;
	}

	void show() {
		for (int i = 1; i <= length; ++i) {
			// data[i].dis();
			printf("%d ", data[i]);
		}
	}
};

int main()
{
	heap<int> hq;
	hq.push(1); hq.push(14); hq.push(10);
	hq.pop();
	hq.show();

	return 0;
}
