// 17.12.18 ����� ������ ������ ����

#include<iostream>
#include<cstring>

using namespace std;

//class Person {
//private:
//	int age;
//	char name[50];
//public:
//	Person(int myage, char* myname) : age(myage) {
//		strcpy_s(name, strlen(myname) + 1, myname);
//	}
//	~Person()
//	{
//		delete []name;
//	}
//	void WhatYourName() const
//	{
//		cout << "My name is " << name << endl;
//	}
//	void HowOldAreYou() const
//	{
//		cout << "I'm " << age << " years old" << endl;
//	}
//
//};
//
//class UnivStudent : public Person {
//private:
//	char major[50]; //��������
//public:
//	UnivStudent(char * myname, int myage, char * mymajor) : Person(myage, myname) {
//		strcpy_s(major, strlen(mymajor) + 1, mymajor);
//	}
//	~UnivStudent()
//	{
//		delete[]major;
//	}
//	void WhoAreYou() const
//	{
//		WhatYourName();
//		HowOldAreYou();
//		cout << "My major is " << major << endl;
//	}
//};
//
//
//int main()
//{
//	UnivStudent ustd1("Lee", 23, "Computer eng.");
//	ustd1.WhoAreYou();
//
//	UnivStudent ustd2("Kim", 22, "Electronic eng. ");
//	ustd2.WhoAreYou();
//}

//class Car {
//private:
//	int gasolineGauge;
//public:
//	Car(int mygas) : gasolineGauge(mygas) {}
//	int GetGasGauge()
//	{
//		return gasolineGauge;
//	}
//};
//
//class HybridCar : public Car { // ���̺긮�� �ڵ���
//private:
//	int electricGauge;
//public:
//	HybridCar(int myeletric, int mygas) : electricGauge(myeletric), Car(mygas) {}
//	int GetElecGauge()
//	{
//		return electricGauge;
//	}
//};
//
//class HybirdWaterCar : public HybridCar {
//private:
//	int waterGauge;
//public:
//	HybirdWaterCar(int mygas, int myelect, int mywater) : HybridCar(myelect, mygas), waterGauge(mywater) {}
//	void ShowCurrentGauge()
//	{
//		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
//		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
//		cout << "�ܿ� ���Ͷ�: " << waterGauge << endl;
//	}
//};
//
//
//int main()
//{
//	HybirdWaterCar hbwc(30, 45, 60);
//	hbwc.ShowCurrentGauge();
//}

class MyFriendinfo {
private:
	char * name;
	int age;
public:
	MyFriendinfo(int myage, char * myname) : age(myage) {
		name = new char[strlen(myname) + 1];
		strcpy_s(name, strlen(myname) + 1, myname);
	}
	~MyFriendinfo()
	{
		delete[]name;
	}
	void ShowMyFriendInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
};

class MyFriendDetailInfo : public MyFriendinfo {
private:
	char * addr;
	char * phone;
public:
	MyFriendDetailInfo(char * myname, int myage, char* myaddr, char* myphone) : MyFriendinfo(myage, myname)
	{
		addr = new char[strlen(myaddr) + 1];
		strcpy_s(addr, strlen(myaddr) + 1, myaddr);
		phone = new char[strlen(myphone) + 1];
		strcpy_s(phone, strlen(myphone) + 1, myphone);

	}
	~MyFriendDetailInfo()
	{
		delete[]addr, phone;
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl;
	}
};

int main()
{
	MyFriendDetailInfo frd("������", 23, "���� ������", "010-5763-0427");
	frd.ShowMyFriendDetailInfo();
}