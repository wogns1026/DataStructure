/*
quicksort�� O(nlogn) Ÿ���� �ð����⵵�� ���� ���� �˰����̴�.
�־��� ��� O(n^2)�� �ð����⵵�� �����⵵ �Ѵ�.
=> n^2�� ������ ���� �̹� ���ĵ� �迭�� ������ ����Ʈ�� �� ���̴�.
�ٸ� O(nlogn) �˰���鿡 ���� �� ������.
=> ���ʿ��� ������ �̵��� ���̰�, �� �Ÿ��� �����͸� ��ȯ�ϰ�, 
�ѹ� ������ ������ ���� ���꿡�� ���ܵǴ� ������ ������ �����̴�.
*/

/*
�������� �˰����� �ϳ�
merge sort�ʹ� �޸� ����Ʈ�� ��յ��ϰ� ������
<sort ���>
1. ����Ʈ �ȿ� �ִ� �� ��Ҹ� �������� �����Ѵ�. �̸� pivot�̶� �Ѵ�.
2. pivot�� �������� ���� ��ҵ��� ��� pivot�� �������� �Ű�����
pivot���� ū ��ҵ��� pivot�� ���������� �Ű�����.
3. ���ҵ� �κ� ����Ʈ�� ���Ͽ� ��������� ������ �ݺ��Ѵ�.
(�κ� ����Ʈ������ pivot�� �������� 2���� �κ� ����Ʈ�� ������ ������ �ݺ�)
4. �κ� ����Ʈ���� ũ�Ⱑ ���̻� ������ �Ұ����� ������ �ݺ��Ѵ�.
(����Ʈ�� ũ�Ⱑ 0�̳� 1�� �� ������ �ݺ�)

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