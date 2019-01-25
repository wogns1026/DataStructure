/*
�̺�Ž���� ������ lower_bound, upper_bound�� ���� �����غ� ���̴�.
(stl�� ������ ���� �����غ��� ���� ���� �� ����)
lower_bound�� ���ĵ� �迭���� ã���� �ϴ� ���� ó�� ��Ÿ���� ��ġ�� ���Ѵ�.
upper_bound�� ���ĵ� �迭���� ã���� �ϴ� ������ ū ���� ó�� ��Ÿ���� ��ġ�� ���Ѵ�.
�� �� �Լ� ��� �̺�Ž���� �̿��Ͽ� ���ϹǷ� �ð����⵵�� O(logn)�̴�.

�� �� �Լ��� ������ �� lower�� ã���� �ϴ� ���� �����ϱ� ������ ������ ���Ѵٰ� �����ϰ�
upper�� ã���� �ϴ� ���� �����ϴ� ������ ���Ѵٰ� �����ϴ� �� ���ߴ�.

(boj)7453�� ���� Ǯ�̿� ����
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
int n, a[4001], b[4001], c[4001], d[4001];
ll sum[16000001];

// l�� r�� �ش� ���ں��� ���� ������ �����ϴ� ������ ��Ÿ������ �ϰ�, ���� r + 1 ���� lower_bound ���� ��
int _lower_bound(ll arr[], int l, int r, int val) {
	int mid = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (arr[mid] == val)
			r = mid - 1;
		else if (arr[mid] < val)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return r + 1;
}

// l�� r�� �ش� ���ڱ����� �����ϴ� ������ ��Ÿ������ �ϰ�, ���� l���� upper_bound ���� ��
int _upper_bound(ll arr[], int l, int r, int val) {
	int mid = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (arr[mid] == val) {
			l = mid + 1;
		}
		else if (arr[mid] < val)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum[idx] = c[i] + d[j];
			idx++;
		}
	}
	sort(sum, sum + idx); // lower_bound, upper_bound ������ �߿��ϴ� sort�� stl ���
	
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += _upper_bound(sum, 0, idx - 1, -(a[i] + b[j])) - _lower_bound(sum, 0, idx - 1, -(a[i] + b[j]));
		}
	}
	cout << ans << '\n';

	return 0;
}