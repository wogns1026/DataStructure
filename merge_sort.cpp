/*
stable ���Ŀ� ���ϸ�, �������� �˰����� �ϳ��̴�.
�ð����⵵�� �׻� O(nlogn)���� ����ȴ�.
������ ������ �޸𸮰� O(n)��ŭ �� �ʿ��ϴ�.

<sort ���>
1. ����Ʈ�� ���̰� 1�� �� ������ �����Ѵ�.
2. ���̰� 0 �Ǵ� 1 �̸� �̹� ���ĵ� ������ ����.
3. �� ���ҵǸ� �� �κ� ����Ʈ�� ��������� �����ϸ鼭 �ٽ� merge ��Ų��.

*/

#include <iostream>

using namespace std;

int sorted_arr[1001]; // ������ �޸� �ʿ�

void merge(int arr[], int l, int mid, int r) {
	int i = l;
	int j = mid + 1;
	int k = l;

	while (i <= mid && j <= r) { // �� ����Ʈ ��
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

	if (i > mid) { // ������ ����Ʈ�� ���� �����ִ� ���
		for (int a = j; a <= r; a++) {
			sorted_arr[k] = arr[a];
			k++;
		}
	}
	else { // ���� ����Ʈ�� ���� �����ִ� ���
		for (int a = i; a <= mid; a++) {
			sorted_arr[k] = arr[a];
			k++;
		}
	}
	// ���ĵ� �迭 ���� 
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