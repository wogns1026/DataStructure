/*
�迭�� Queue�� ����(ȯ�� ť) => ��ũ�� ����Ʈ�� ���� ����(������ ��ũ�� ����Ʈ�� �����غ�����!)
�ִ� ũ�⸦ 100000 �̶� ���� ��
Queue�� ���� ���� �����Ͱ� ���� ������ FIFO ����
���� ť�� ȯ�� ť 2���� ������ ����
*/

#include <iostream>

using namespace std;

template <typename T> // � type���ε� ���� �����ϰ� ����
class Queue {
private : 
	T *arr; // ������ type �迭
	int cnt; // queue�� ũ��
	int front_idx; // queue�� �� �� index
	int back_idx; // queue�� �� �� index
public : 
	Queue(); // ������
	bool empty(); // queue�� ����ִ��� Ȯ�� => O(1)
	int size(); // queue�� ũ�⸦ ���� => O(1)
	T& front(); // queue�� �� ���� ���� ���� => O(1)
	T& back(); // queue�� �� ���� ���� ���� => O(1)
	void push(T); // queue�� ������ ���� ����(�� �ڿ� ����) => O(1)
	void pop(); // queue�� ������ ���� ����(�� ���� ������ ����) => O(1)
	~Queue(); // �Ҹ���
};

template <typename T>
Queue<T>::Queue() : arr(new T(100000)), cnt(0), front_idx(0), back_idx(-1) { // �迭�� �ִ� ����� 100000���� ����
	// back_idx�� -1�� �ʱ�ȭ �ؾߵ� => �����͸� �߰��ϰ� �װ��� ����Ű�� �־���ϹǷ� +1 �� �� ������ �߰�
}
template <typename T>
bool Queue<T>::empty() {
	if (cnt == 0)
		return true;
	return false;
}
template <typename T>
int Queue<T>::size() {
	return cnt;
}
template <typename T>
T& Queue<T>::front() {
	if (cnt == 0) {
		cout << "Queue is empty\n";
	}
	else
		return arr[front_idx];
}
template <typename T>
T& Queue<T>::back() {
	if (cnt == 0) {
		cout << "Queue is empty\n";	
	}
	else
		return arr[back_idx];
}
template <typename T>
void Queue<T>::push(T val) {
	if (cnt == 100000)
		cout << "Size is over! Maximum size is 100000!\n";
	else{
		back_idx++;
		// ȯ�� ť�̹Ƿ� ������� �ִ� ����� �ƴѵ� index�� �ִ� ��������� Ŀ���� �� �ٽ� 0���� �ʱ�ȭ ����
		if (back_idx == 100000)
			back_idx = 0;
		arr[back_idx] = val;
		cnt++;
	}
}
template <typename T>
void Queue<T>::pop() {
	if (cnt == 0)
		cout << "Queue is empty!\n";
	else {
		arr[front_idx] = NULL;
		front_idx++;
		if (front_idx == 100000)
			front_idx = 0;
		cnt--;
	}
}
template <typename T>
Queue<T>::~Queue() {

}

int main() {
	Queue<int> q;
	cout << q.empty() << '\n';
	q.push(3);
	q.push(4);
	q.push(5);
	cout << q.front() << '\n';
	cout << q.back() << '\n';
	q.pop();
	cout << q.front() << '\n';
	cout << q.size() << '\n';
	cout << q.empty() << '\n';
	q.push(7);
	cout << q.front() << '\n';
	cout << q.back() << '\n';

	return 0;
}