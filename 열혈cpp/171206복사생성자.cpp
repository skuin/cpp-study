// 17.12.06
// 복사생성자.


#include <iostream>
#include <cstring>

using namespace std;
//
//class SoSimple {
//private:
//	int num1;
//	int num2;
//public:
//	SoSimple(int n1, int n2) :num1(n1), num2(n2) {
//		//empty
//	}
//	SoSimple(const SoSimple &copy) : num1(copy.num1), num2(copy.num2) {
//		cout << "called sosimple(SoSimple &copy)" << endl;
//	}
//
//	void ShowSoSimpleData()
//	{
//		cout << num1 << endl;
//		cout << num2 << endl;
//	}
//};
//
//int main()
//{
//	SoSimple sim1(15, 30);
//	cout << "생성및 초기화 직전" << endl;
//	SoSimple sim2(sim1);
//	cout << "생성 및 초기화 직후" << endl;
//	sim2.ShowSoSimpleData();
//	
//}
//
//

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };
}

class NameCard {
private:
	char * cName;
	char * cComName;
	char * cCallNum;
	int iPos;
public:
	NameCard(char* ncName, char* ncComName, char* ncCallNum, int ncPos) :iPos(ncPos)
	{
		cName = new char[strlen(ncName) + 1];
		strcpy_s(cName, strlen(ncName) + 1, ncName);

		cComName = new char[strlen(ncComName) + 1];
		strcpy_s(cComName, strlen(ncComName) + 1, ncComName);

		cCallNum = new char[strlen(ncCallNum) + 1];
		strcpy_s(cCallNum, strlen(ncCallNum) + 1, ncCallNum);
	}

	NameCard(const NameCard& copy) : iPos(copy.iPos)
	{
		cName = new char[strlen(copy.cName) + 1];
		strcpy_s(cName, strlen(copy.cName) + 1, copy.cName);

		cComName = new char[strlen(copy.cComName) + 1];
		strcpy_s(cComName, strlen(copy.cComName) + 1, copy.cComName);

		cCallNum = new char[strlen(copy.cCallNum) + 1];
		strcpy_s(cCallNum, strlen(copy.cCallNum) + 1, copy.cCallNum);
	
	}

	void showNameCardInfo(void);

	~NameCard() {
		delete[] cName, cComName, cCallNum;
		cout << "called delete" << endl;
	}
};

void NameCard::showNameCardInfo(void)
{
	cout << "이름: " << cName << endl;
	cout << "회사: " << cComName << endl;
	cout << "전화번호: " << cCallNum << endl;
	switch (iPos)
	{
	case 0:
		cout << "직급: 사원" << endl << endl;;
		break;
	case 1:
		cout << "직급: 주임" << endl << endl;;
		break;
	case 2:
		cout << "직급: 대리" << endl << endl;;
		break;
	default:
		break;
	}
}

int main()
{
	NameCard manClerk("LEE", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSenior;

	copy1.showNameCardInfo();
	copy2.showNameCardInfo();
}