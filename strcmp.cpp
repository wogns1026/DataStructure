/*

문자열을 비교하는 strcmp 함수를 직접 구현해보았다.

<기존 strcmp stl 사용방법>
char *a, *b;
strcmp(a, b); 
=> a와 b의 문자열이 같으면 0 return
=> a와 b의 문자열이 다르면 a - b return
(즉, a가 더 크면 양수, 작으면 음수 return)

*/

#include <iostream>

using namespace std;

int _strcmp(char *a, char *b) {
	int i = 0;
	while (a[i] != '\0' || b[i] != '\0') {
		if (a[i] > b[i])
			return a[i] - b[i];
		else if (a[i] < b[i])
			return a[i] - b[i];
		i++;
	}

	return 0;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);

	char a[256] = "hello";
	char b[256] = "hello";
	char c[256] = "helol";
	char d[256] = "hell";
	
	cout << _strcmp(a, b) << '\n';
	cout << _strcmp(a, c) << '\n';
	cout << _strcmp(a, d) << '\n';


	return 0;
}