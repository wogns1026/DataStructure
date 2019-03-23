/*
stable 정렬에 속하며, 분할정복 알고리즘의 하나이다.
시간복잡도는 항상 O(nlogn)임이 보장된다.
하지만 별도의 메모리가 O(n)만큼 더 필요하다.

<sort 방식>
1. 리스트의 길이가 1이 될 때까지 분할한다.
2. 길이가 0 또는 1 이면 이미 정렬된 것으로 본다.
3. 다 분할되면 두 부분 리스트를 재귀적으로 정렬하면서 다시 merge 시킨다.

*/

#include <iostream>

using namespace std;

int sorted_arr[1001]; // 별도의 메모리 필요

void merge(int arr[], int l, int mid, int r) {
	int i = l;
	int j = mid + 1;
	int k = l;

	while (i <= mid && j <= r) { // 두 리스트 비교
		if (arr[i] <= arr[j]) { 
			sorted_arr[k] = arr[i];
			i++;
		}
		else {
			sorted_arr[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i > mid) { // 오른쪽 리스트에 값이 남아있는 경우
		for (int a = j; a <= r; a++) {
			sorted_arr[k] = arr[a];
			k++;
		}
	}
	else { // 왼쪽 리스트에 값이 남아있는 경우
		for (int a = i; a <= mid; a++) {
			sorted_arr[k] = arr[a];
			k++;
		}
	}
	// 정렬된 배열 삽입 
	for (int a = l; a <= r; a++) {
		arr[a] = sorted_arr[a];
	}
}

void merge_sort(int arr[], int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		merge_sort(arr, l, mid);
		merge_sort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}


int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	
	int n, arr[1001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	merge_sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}