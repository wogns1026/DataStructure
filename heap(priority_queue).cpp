/*
heap�� �ִ� �Ǵ� �ּڰ��� ã�Ƴ��� ������ ������ �ϱ� ���� ��ȵ� �ڷᱸ��
���� ���� Ʈ���� ������� �ϴ� �ڷᱸ���̴�.(�̸� �̿��� STL�� priority_queue �̴�.)
��Ʈ�� �ִ��̳� �ּڰ��̳Ŀ� ���� max-heap, min-heap�̶� �θ���.

���� min-heap�̶�� �Ѵٸ�
�θ� ����� ���� �ڽ� ����� ������ �׻� �۾ƾ� �Ѵٴ� ���� �⺻ ���̵���̴�.
������ �θ� �ڽİ��� ���迡���� �� ������ �����ǰ�, ���� ���̿��� �ƹ� ���赵 ���� �ʴ�.

���� ����� ������ �迭�� �����ϴµ� ���� ���� Ʈ���̹Ƿ� 
�θ�� �ڽİ��� ����� �θ� n��° �ε����� �ϸ� �ڽ��� �ε����� 2n, 2n+1 ���� �̿��Ͽ� �����Ѵ�.
���� ���� Ʈ���̹Ƿ� push�� pop�� �ð����⵵�� log(n) ���� ����ȴ�.
queue�� ����ϰ� �ڿ��� �ְ� �տ��� ����.(FIFO)
*/

#include <iostream>
#define maxsize 1001

using namespace std;

// min-heap�� ����
struct Heap {
	int arr[maxsize];
	int cnt;

	Heap() {
		cnt = 1;
	}
	int heap_size() { // => O(1)
		return cnt - 1;
	}
	bool empty() { // => O(1)
		if (cnt == 1)
			return true;
		return false;
	}
	int top() { // => O(1)
		return arr[1];
	}
	void swap(int *a, int *b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
	void push_val(int v) { // => O(logn)
		// �켱 ���� ������ �κп� ���� ����(���� ���� Ʈ���� ������ �ڸ�)
		// �θ�� ���ذ��鼭 �θ𺸴� ���� �� ������ swap
		arr[cnt] = v;
		int cur = cnt;
		int parent = cur / 2;
		while (cur > 1 && arr[parent] > arr[cur]) {
			swap(&arr[parent], &arr[cur]);
			cur = parent;
			parent = cur / 2;
		}
		cnt++;
	}
	void pop_val() { // => O(logn)
		// �� ���� ��带 pop �ϹǷ� ���� ������ ��带 �� ���� ������
		// �� �� �ڽĵ�� ���ϸ� �켱������ ���� ���ġ ��
		arr[1] = arr[cnt - 1];
		cnt--;
		int cur = 1;
		int left = 2 * cur;
		int right = 2 * cur + 1;
		while (1) {
			// ���ʰ� ������ �ڽ��� ��� ���� ���***
			if (right <= cnt - 1) {
				if (arr[left] < arr[right]) { // ������ �켱������ ���� ���
					if (arr[left] < arr[cur]) 
						swap(&arr[left], &arr[cur]);	
					else
						break;
					cur = left;
				}
				else { // �������� �켱������ ���� ���
					if (arr[right] < arr[cur]) 
						swap(&arr[right], &arr[cur]);
					else
						break;
					cur = right;
				}
			}
			// ���ʸ� �ڽ��� �ְų� �ƿ� ���� ���***
			else {
				// ���� �ڽĸ� �ִ� ���
				if (left <= cnt - 1) {
					if (arr[left] < arr[cur])
						swap(&arr[left], &arr[cur]);
					else
						break;
				}
				// �ڽ��� �ƿ� ���� ���
				else 
					break;
				cur = left;
			}
			
			left = 2 * cur;
			right = 2 * cur + 1;
		}
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, num = 0;
	Heap pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		pq.push_val(num);
	}
	while (!pq.empty()) {
		cout << pq.top() << '\n';
		pq.pop_val();
	}

	return 0;
}