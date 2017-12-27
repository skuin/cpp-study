// 17.12.26 가상함수

#include<iostream>
#include<cstring>

using namespace std;

//class Employee {
//private:
//	char name[100];
//public:
//	Employee(char * name) { strcpy_s(this->name, strlen(name) + 1, name); }
//	virtual void ShowYourName() const
//	{
//		cout << "name: " << name << endl;
//	}
//	virtual int GetPay() const = 0;
//	virtual void ShowSalaryInfo() const = 0;
//};
//
//// 정규직
//class PermanentWorker : public Employee {
//private:
//	int salary;
//public:
//	PermanentWorker(char * name, int money) : Employee(name), salary(money) { }
//
//	int GetPay() const { return salary; }
//
//	void ShowSalaryInfo() const
//	{
//		ShowYourName();
//		cout << "salary: " << GetPay() << endl << endl;
//	}
//};
//
//class SalesWorker :public PermanentWorker {
//private:
//	int salesResult;	// 월 판매실적
//	double bonusRatio;	// 상여금 비율
//public:
//	SalesWorker(char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
//	void AddSalesResult(int value)
//	{
//		salesResult += value;
//	}
//	int GetPay(void) const
//	{
//		return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
//	}
//	void ShowSalaryInfo() const
//	{
//		ShowYourName();
//		cout << "salary: " << GetPay() << endl << endl;
//	}
//};
//
//class TemporaryWorker : public Employee {
//private:
//	int workTime;
//	int payPerHour;
//public:
//	TemporaryWorker(char* name, int pay) : Employee(name), workTime(0),payPerHour(pay) {}
//
//	void AddWorkTime(int time)
//	{
//		workTime += time;
//	}
//
//	int GetPay() const { return workTime*payPerHour; }
//
//	void ShowSalaryInfo() const
//	{
//		ShowYourName();
//		cout << "salary: " << GetPay() << endl << endl;
//	}
//};
//
//namespace RISK_LEVEL {
//	enum { RISK_A=30, RISK_B=20, RISK_C=10 };
//}
//
//class ForeignSalesWorker : public SalesWorker{
//private:
//	const int riskLevel;
//public:
//	ForeignSalesWorker(char* name, int money, double ratio, int riskLv) : SalesWorker(name, money, ratio), riskLevel(riskLv) {}
//
//	int GetRiskPay() const
//	{
//		return (int)(SalesWorker::GetPay()) * (riskLevel / 100.0);
//	}
//	int GetPay() const
//	{
//		return SalesWorker::GetPay() + GetRiskPay();
//	}
//	void ShowSalaryInfo() const
//	{
//		ShowYourName();
//		cout << "salary: " << SalesWorker::GetPay() << endl;
//		cout << "risk pay: " << GetRiskPay() << endl;
//		cout << "sum: " << GetPay() << endl << endl;
//	}
//};
//
//class EmployeeHandler {
//private:
//	Employee* empList[50];
//	int empNum;
//public:
//	EmployeeHandler() : empNum(0) {}
//	void AddEmployee(Employee* emp)
//	{
//		empList[empNum++] = emp;
//	}
//	void ShowAllSalaryInfo() const
//	{
//		for (int i = 0; i < empNum; ++i)
//			empList[i]->ShowSalaryInfo();
//	}
//	void ShowTotalSalary() const
//	{
//		int sum = 0;
//		for (int i = 0; i < empNum; ++i)
//			sum += empList[i]->GetPay();
//		cout << "salary sum: " << sum << endl;
//	}
//	~EmployeeHandler()
//	{
//		for (int i = 0; i < empNum; i++)
//			delete empList[i];
//	}
//
//
//};
//
//int main()
//{
//	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
//	EmployeeHandler handler;
//
//	// 정규직등록
//	handler.AddEmployee(new PermanentWorker("KIM", 1000));
//	handler.AddEmployee(new PermanentWorker("LEE", 1500));
//
//	// 임시직 등록
//	TemporaryWorker* alba = new TemporaryWorker("JUNG", 700);
//	alba->AddWorkTime(5);
//	handler.AddEmployee(alba);
//
//	// 영업직 등록
//	SalesWorker* seller = new SalesWorker("HONG", 1000, 0.1);
//	seller->AddSalesResult(7000);
//	handler.AddEmployee(seller);
//
//	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
//	fseller1->AddSalesResult(7000);
//	handler.AddEmployee(fseller1);
//
//	//이번달에 지불해야할 급여의 정보
//	handler.ShowAllSalaryInfo();
//
//	//이번달에 지불해야할 급여의 총합
//	handler.ShowTotalSalary();
//	return 0;
//}


// 가상 소멸자

class First {
private:
	char* strOne;
public:
	First(char* str)
	{
		strOne = new char[strlen(str) + 1];
	}
	virtual ~First()
	{
		cout << "~First()" << endl;
		delete[]strOne;
	}
};

class Second : public First {
private:
	char* strTwo;
public:
	Second(char* str1, char* str2) : First(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}
	~Second()
	{
		cout << "~Second()" << endl;
		delete[]strTwo;
	}
};


int main()
{
	First* ptr = new Second("sinple", "complex");
	delete ptr;
	return 0;
}