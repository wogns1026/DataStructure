/*
quicksort는 O(nlogn) 타임의 시간복잡도를 갖는 정렬 알고리즘이다.
최악의 경우 O(n^2)의 시간복잡도를 가지기도 한다.
=> n^2이 나오는 경우는 이미 정렬된 배열을 가지고 퀵소트를 할 때이다.
다른 O(nlogn) 알고리즘들에 비해 더 빠르다.
=> 불필요한 데이터 이동을 줄이고, 먼 거리의 데이터를 교환하고, 
한번 결정된 기준은 추후 연산에서 제외되는 성질을 가지기 때문이다.
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