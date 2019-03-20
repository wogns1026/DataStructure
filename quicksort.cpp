/*
quicksort는 O(nlogn) 타임의 시간복잡도를 갖는 정렬 알고리즘이다.
최악의 경우 O(n^2)의 시간복잡도를 가지기도 한다.
=> n^2이 나오는 경우는 이미 정렬된 배열을 가지고 퀵소트를 할 때이다.
다른 O(nlogn) 알고리즘들에 비해 더 빠르다.
=> 불필요한 데이터 이동을 줄이고, 먼 거리의 데이터를 교환하고, 
한번 결정된 기준은 추후 연산에서 제외되는 성질을 가지기 때문이다.
*/

/*
분할정복 알고리즘의 하나
merge sort와는 달리 리스트를 비균등하게 분할함
<sort 방식>
1. 리스트 안에 있는 한 요소를 랜덤으로 선택한다. 이를 pivot이라 한다.
2. pivot을 기준으로 작은 요소들은 모두 pivot의 왼쪽으로 옮겨지고
pivot보다 큰 요소들은 pivot의 오른쪽으로 옮겨진다.
3. 분할된 부분 리스트에 대하여 재귀적으로 정렬을 반복한다.
(부분 리스트에서도 pivot을 기준으로 2개의 부분 리스트로 나누는 과정을 반복)
4. 부분 리스트들의 크기가 더이상 분할이 불가능할 때까지 반복한다.
(리스트의 크기가 0이나 1이 될 때까지 반복)

*/

#include <iostream>

using namespace std;

int arr[501], n;

void quicksort(int a[], int l, int r) {
	if (l >= r)
		return;
	int i = l;
	int j = r;
	int mid = (i + j) / 2;
	int pivot = a[mid];
	while (i <= j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	if (i < r)
		quicksort(a, i, r);
	if (j > l)
		quicksort(a, l, j);

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quicksort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	return 0;
}