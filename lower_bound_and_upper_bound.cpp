/*
이분탐색을 응용한 lower_bound, upper_bound를 직접 구현해볼 것이다.
(stl이 있지만 직접 구현해보는 것이 좋을 것 같음)
lower_bound는 정렬된 배열에서 찾고자 하는 값이 처음 나타나는 위치를 말한다.
upper_bound는 정렬된 배열에서 찾고자 하는 값보다 큰 값이 처음 나타나는 위치를 말한다.
이 두 함수 모두 이분탐색을 이용하여 구하므로 시간복잡도는 O(logn)이다.

이 두 함수를 구현할 때 lower는 찾고자 하는 값을 포함하기 이전의 구간을 구한다고 생각하고
upper는 찾고자 하는 값을 포함하는 구간을 구한다고 생각하니 더 편리했다.

(boj)7453번 문제 풀이에 적용
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
int n, a[4001], b[4001], c[4001], d[4001];
ll sum[16000001];

// l과 r이 해당 숫자보다 작은 수들을 포함하는 구간을 나타내도록 하고, 따라서 r + 1 값이 lower_bound 값이 됨
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

// l과 r이 해당 숫자까지를 포함하는 구간을 나타내도록 하고, 따라서 l값이 upper_bound 값이 됨
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
	sort(sum, sum + idx); // lower_bound, upper_bound 구현이 중요하니 sort는 stl 사용
	
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += _upper_bound(sum, 0, idx - 1, -(a[i] + b[j])) - _lower_bound(sum, 0, idx - 1, -(a[i] + b[j]));
		}
	}
	cout << ans << '\n';

	return 0;
}