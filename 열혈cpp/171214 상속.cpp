// 17.12.14 상속 시작
// 천천히 깊이 공부할것!, 상속을 음미해볼것

#include <iostream>
#include <cstring>

using namespace std;

// 정규직
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
	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
	EmployeeHandler handler;

	// 직원등록
	handler.AddEmployee(new PermanentWorker("Kim", 1000));
	handler.AddEmployee(new PermanentWorker("Cho", 2000));
	handler.AddEmployee(new PermanentWorker("Choi", 3000));
	
	// 이번 달에 지불해야 할 급여의 정보
	handler.showAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.showTotalSalary();
}