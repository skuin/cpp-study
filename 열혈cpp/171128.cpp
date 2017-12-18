// 2017.11.28 화

// 포인터, 더블포인터, 참조자 정리

#include "stdafx.h"

using namespace std;


/*
// 포인터, 더블 포인터

int main()
{
	
	int n = 10;
	int* pn = &n;
	int** dpn = &pn;

	cout << n << endl;		// 10
	cout << &n << endl;		// n의 adress
	cout << &pn << endl;	// pn의 adress
	cout << pn << endl;		// pn이 가리키는 adress = n의 adress
	cout << *pn << endl;	// pn이 가리키는 value = n = 10
	cout << dpn << endl;	// dpn이 가리키는 adress = pn의 adress
	cout << &dpn << endl;	// dpn의 adress
	cout << *dpn << endl;	// dpn이 가리키는 adress = pn이 가리키는 adress = n의 adress
	cout << **dpn << endl;	// dpn이 가리키는 값 = pn이 가리키는값 = n = 10
	

}
*/

/*
//문제 1
// 참조자를 이용해서 다음 요구사항에 부합하는 함수를 각각 정의하여라
// -> 인자로 전달된 int 형 변수의 값을 1씩 증가시키는 함수
// -> 인자로 전달된 int 형 변수의 부호를 바꾸는 함수


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

// 문제3
// 포인터 스왑 함수 만들기
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