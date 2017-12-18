//17.12.04

// 생성자와 소멸자

#include <iostream>
#include <cstring>

using namespace std;
//
//class Point {
//private:
//	int xpos, ypos;
//public:
//	Point(int x, int y) : xpos(x), ypos(y) {}
//	void showPointInfo() const
//	{
//		cout << "[" << xpos << ", " << ypos << "]" << endl;
//	}
//	~Point() {}
//};
//
//class Circle {
//private:
//	Point center;
//	int rad;
//public:
//	Circle(int x, int y, int r) : center(x,y), rad(r) {}
//	
//	void showCircleInfo()
//	{
//		cout << "radius: " << rad << endl;
//		center.showPointInfo();
//	}
//};
//
//class Ring {
//private:
//	Circle c1, c2;
//public:
//	Ring(int x1, int y1, int r1, int x2,int y2, int r2) : c1(x1,y1,r1), c2(x2,y2,r2){}
//	
//	void showRingInfo()
//	{
//		cout << "Inner Circle Info..." << endl;
//		c1.showCircleInfo();
//		cout << "Inner Circle Info..." << endl;
//		c2.showCircleInfo();
//	}
//};
//
//int main()
//{
//	Ring ring(1, 1, 4, 2, 2, 9);
//	ring.showRingInfo();
//}



// 문제 04-3.2

// Name Card 클래스 정의하기. 성명,회사이름,전화번호,직급 의 정보 저장

namespace COMP_POS{
	enum {CLERK, SENIOR, ASSIST, MANAGER}; }

class NameCard {
private:
	char * cName;
	char * cComName;
	char * cCallNum;
	int iPos;
public:
	NameCard(char* ncName, char* ncComName, char* ncCallNum, int ncPos) :iPos(ncPos)
	{
		cName = new char[strlen(ncName)+1];
		strcpy_s(cName, strlen(ncName) + 1, ncName);

		cComName = new char[strlen(ncComName) + 1];
		strcpy_s(cComName, strlen(ncComName) + 1, ncComName);

		cCallNum = new char[strlen(ncCallNum) + 1];
		strcpy_s(cCallNum, strlen(ncCallNum) + 1, ncCallNum);
	}

	void showNameCardInfo(void);

	~NameCard() {
		delete[] cName, cComName, cCallNum;
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
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodCom", "010-5555-6666", COMP_POS::ASSIST);

	manClerk.showNameCardInfo();
	manSenior.showNameCardInfo();
	manAssist.showNameCardInfo();
}