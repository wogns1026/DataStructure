/*
�̺� Ž���� O(logn) Ÿ�Ӹ��� ã�����ϴ� ���� ã�� �˰����̴�.
��, ���ĵ� ������ �ȿ��� ����ؾ��Ѵٴ� ���������� �ִ�.
�̺� Ž���� �� �� ������ ������("[ )")���� ���� �󱸰�("[ ]")���� ����
�� �� �׿� �°� �����ؾ��Ѵ�.

������ ������ quicksort�� �����Ͽ���, ���̳ʸ� ��ġ�� ���������� ������ ���Ҵ�.
*/

#include <iostream>

using namespace std;

// ���Ŀ��� quicksort�� �̿� 
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

		// ���̳ʸ� ��ġ ����
		while (l < r) {
			mid = (l + r) / 2; // mid ���� ����
			if (arr[mid] == num) { // �ش� ���̸� break
				flag = true;
				break;
			}
			else if (arr[mid] > num) { // �ش� ���� mid�� ������ ������ ������ ���� �������� 
				r = mid;
			}
			else { // �ش� ���� mid�� ������ ũ�� ������ ������ ��������
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