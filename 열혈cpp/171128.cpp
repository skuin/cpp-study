// 2017.11.28 ȭ

// ������, ����������, ������ ����

#include "stdafx.h"

using namespace std;


/*
// ������, ���� ������

int main()
{
	
	int n = 10;
	int* pn = &n;
	int** dpn = &pn;

	cout << n << endl;		// 10
	cout << &n << endl;		// n�� adress
	cout << &pn << endl;	// pn�� adress
	cout << pn << endl;		// pn�� ����Ű�� adress = n�� adress
	cout << *pn << endl;	// pn�� ����Ű�� value = n = 10
	cout << dpn << endl;	// dpn�� ����Ű�� adress = pn�� adress
	cout << &dpn << endl;	// dpn�� adress
	cout << *dpn << endl;	// dpn�� ����Ű�� adress = pn�� ����Ű�� adress = n�� adress
	cout << **dpn << endl;	// dpn�� ����Ű�� �� = pn�� ����Ű�°� = n = 10
	

}
*/

/*
//���� 1
// �����ڸ� �̿��ؼ� ���� �䱸���׿� �����ϴ� �Լ��� ���� �����Ͽ���
// -> ���ڷ� ���޵� int �� ������ ���� 1�� ������Ű�� �Լ�
// -> ���ڷ� ���޵� int �� ������ ��ȣ�� �ٲٴ� �Լ�


void plusOne(int& num);
void negativeNum(int& num);

int main()
{
	int num = 10;

	plusOne(num);
	cout << num << endl;

	negativeNum(num);
	cout << num << endl;
}

void plusOne(int& num)
{
	num += 1;
}
void negativeNum(int& num)
{
	num *= (-1);
}
*/

// ����3
// ������ ���� �Լ� �����
void SwapPointer(int *(&ptr1), int *(&ptr2));

int main()
{
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;

	cout << num1 << " "<< num2 << endl;
	SwapPointer(ptr1, ptr2);
	cout << num1 <<" "<< num2 << endl;
}

void SwapPointer(int *(&ptr1), int *(&ptr2))
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}