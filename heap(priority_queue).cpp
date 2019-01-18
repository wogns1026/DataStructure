/*
heap은 최댓값 또는 최솟값을 찾아내는 연산을 빠르게 하기 위해 고안된 자료구조
완전 이진 트리를 기반으로 하는 자료구조이다.(이를 이용한 STL이 priority_queue 이다.)
루트가 최댓값이냐 최솟값이냐에 따라 max-heap, min-heap이라 부른다.

만약 min-heap이라고 한다면
부모 노드의 값이 자식 노드의 값보다 항상 작아야 한다는 것이 기본 아이디어이다.
오로지 부모 자식간의 관계에서만 이 조건이 성립되고, 형제 사이에는 아무 관계도 있지 않다.

구현 방법은 일차원 배열로 구현하는데 완전 이진 트리이므로 
부모와 자식간의 관계는 부모가 n번째 인덱스라 하면 자식의 인덱스는 2n, 2n+1 임을 이용하여 구현한다.
완전 이진 트리이므로 push와 pop의 시간복잡도는 log(n) 임이 보장된다.
queue와 비슷하게 뒤에서 넣고 앞에서 뺀다.(FIFO)
*/

#include <iostream>
#define maxsize 1001

using namespace std;

// min-heap을 구현
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
		// 우선 가장 마지막 부분에 값을 넣음(완전 이진 트리의 마지막 자리)
		// 부모와 비교해가면서 부모보다 값이 더 작으면 swap
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
		// 맨 위의 노드를 pop 하므로 가장 마지막 노드를 맨 위로 가져옴
		// 그 후 자식들과 비교하며 우선순위를 따져 재배치 함
		arr[1] = arr[cnt - 1];
		cnt--;
		int cur = 1;
		int left = 2 * cur;
		int right = 2 * cur + 1;
		while (1) {
			// 왼쪽과 오른쪽 자식이 모두 있을 경우***
			if (right <= cnt - 1) {
				if (arr[left] < arr[right]) { // 왼쪽이 우선순위가 높을 경우
					if (arr[left] < arr[cur]) 
						swap(&arr[left], &arr[cur]);	
					else
						break;
					cur = left;
				}
				else { // 오른쪽이 우선순위가 높을 경우
					if (arr[right] < arr[cur]) 
						swap(&arr[right], &arr[cur]);
					else
						break;
					cur = right;
				}
			}
			// 왼쪽만 자식이 있거나 아예 없는 경우***
			else {
				// 왼쪽 자식만 있는 경우
				if (left <= cnt - 1) {
					if (arr[left] < arr[cur])
						swap(&arr[left], &arr[cur]);
					else
						break;
				}
				// 자식이 아예 없는 경우
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