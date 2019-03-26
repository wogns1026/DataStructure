/*

���ڿ��� ���ϴ� strcmp �Լ��� ���� �����غ��Ҵ�.

<���� strcmp stl �����>
char *a, *b;
strcmp(a, b); 
=> a�� b�� ���ڿ��� ������ 0 return
=> a�� b�� ���ڿ��� �ٸ��� a - b return
(��, a�� �� ũ�� ���, ������ ���� return)

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