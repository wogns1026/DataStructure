/*
이분 탐색은 O(logn) 타임만에 찾고자하는 값을 찾는 알고리즘이다.
단, 정렬된 데이터 안에서 사용해야한다는 전제조건이 있다.
이분 탐색을 할 때 기준을 개구간("[ )")으로 할지 폐구간("[ ]")으로 할지
고른 후 그에 맞게 구현해야한다.

데이터 정렬은 quicksort로 정렬하였고, 바이너리 서치는 개구간으로 구현해 보았다.
*/

#include <iostream>

using namespace std;

// 정렬에는 quicksort를 이용 
void quicksort(int arr[], int l, int r) {
	if (l >= r)
		return;
	int i = l;
	int j = r;
	int mid = (i + j) / 2;
	int pivot = arr[mid];
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	if (i < r)
		quicksort(arr, i, r);
	if (j > l)
		quicksort(arr, l, j);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, m = 0, arr[100001] = { 0, }, num = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quicksort(arr, 0, n - 1);

	cin >> m;
	bool flag = false;
	int l = 0, r = n, mid = (l + r) / 2;
	for (int i = 0; i < m; i++) {
		cin >> num;
		flag = false;
		l = 0, r = n;

		// 바이너리 서치 구간
		while (l < r) {
			mid = (l + r) / 2; // mid 값을 구함
			if (arr[mid] == num) { // 해당 값이면 break
				flag = true;
				break;
			}
			else if (arr[mid] > num) { // 해당 값이 mid의 값보다 작으면 구간을 왼쪽 구간으로 
				r = mid;
			}
			else { // 해당 값이 mid의 값보다 크면 구간을 오른쪽 구간으로
				l = mid + 1;
			}
		}
		if (flag)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}


	return 0;
}