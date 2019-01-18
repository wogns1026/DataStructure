/*
�ؽ� �Լ��� ������ ������ �����͸� ������ ������ ������(�ؽ� ��)�� �������ִ� �Լ��̴�.
�ؽ� �Լ��� �̿��Ͽ� �ؽ� ���̺��� ������ �� �ְ�, 
�� �ؽ� ���̺��� ���� �ſ� ���� ������ �˻��� �����ϴ�.
=> ���� �ð� ���� ã�Ⱑ �ʿ��� �� ���

***�ؽ� �Լ��� ���� �ؽ� �浹 Ȯ���� ���� �����ȴ�.***
Ű ���� �浹�ϸ� �ε����� �ϳ��� �ø��鼭 ����ִ� ���� ã�� ���� �ִ´�.
���� Ű ���� �浹���� �ʵ��� �ؽ� �Լ��� �����ϴ� ���� �߿��ϴ�.
�� �ؽ� �Լ� ���� �ؽ� ���̺��� �ּ� ���� ������ ���� �����Ǵ� ���� ����.

open addressing ��İ� close addressing ����� �ִ�.
open addressing�� �迭�� �̿��� ����̰�, 
close addressing�� ����Ʈ�� �̿��� ����̴�.
open addressing�� ���� n�� 4�� ������ ũ�Ⱑ �ʿ� 
close addressing�� ���� n�� 2�� ������ ũ�Ⱑ �ʿ�

�̹� ������ open addressing ����� �̿��Ͽ� �����ϰ� ���� ã���� �����Ͽ���.
*/

#include <iostream>

#define a 4578369
#define b 1657043
#define tblsz 400007
#define maxval 30000000000

using namespace std;

long long hashtable[tblsz]; // �ؽ� ���̺�

void init() { 
	// �ؽ� ���̺� �ʱ�ȭ(������ 0�� ���ü��� �ִ� �������� ���� �� ���� ������ �ʱ�ȭ ��Ŵ)
	for (int i = 0; i < tblsz; i++) {
		hashtable[i] = maxval;
	}
}

int hash_func(int num) {
	int hashval = (a*num + b) % tblsz;
	if (hashval < 0) // �������� �ؽ� ���� ������ ���� ���� �ֱ� ������ ����� �ٲ���
		hashval = -hashval;
	return hashval;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, num = 0, idx = 0;
	cin >> n;
	init();
	for (int i = 0; i < n; i++) {
		cin >> num;

		// �ؽ� ���̺� �� ����
		idx = hash_func(num);
		while (hashtable[idx] != maxval) {
			idx++;
			if (idx == tblsz)
				idx = 0;
		}
		hashtable[idx] = num;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		idx = hash_func(num);
		// �ؽ� ���̺��� ���� ã��
		while (1) {
			if (hashtable[idx] == num) {
				cout << 1 << '\n';
				break;
			}
			else if (hashtable[idx] == maxval) {
				cout << 0 << '\n';
				break;
			}
			else {
				idx++;
			}
		}
	}

	return 0;
}