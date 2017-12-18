// 17.12.14 ��� ����
// õõ�� ���� �����Ұ�!, ����� �����غ���

#include <iostream>
#include <cstring>

using namespace std;

// ������
class PermanentWorker {
private:
	char name[100];
	int salary;
public:
	PermanentWorker(char * name, int money) : salary(money)
	{
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	int GetPay() const	{ return salary;}
	void showSalaryInfo() const
	{
		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler {
private:
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {}
	void AddEmployee(PermanentWorker* emp) {
		empList[empNum++] = emp;
	}
	void showAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->showSalaryInfo();
	}
	void showTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; ++i) 
			sum += empList[i]->GetPay();
		cout << "salary sum : " << sum << endl << endl;
	}

	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; ++i)
			delete empList[i];
	}
	
};

int main()
{
	// ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü ����
	EmployeeHandler handler;

	// �������
	handler.AddEmployee(new PermanentWorker("Kim", 1000));
	handler.AddEmployee(new PermanentWorker("Cho", 2000));
	handler.AddEmployee(new PermanentWorker("Choi", 3000));
	
	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.showAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.showTotalSalary();
}