// 17.11.29
// 반환형이 참조형인것, 포인터와 참조자

#include <iostream>
#include <cstring>

using namespace std;

/* 참조자. 함수. 포인터

typedef struct __Point
{
	int xPos;
	int yPos;
}Point;

Point& PntAdder(const Point& p1, const Point& p2);

int main()
{
	Point *p1 = new Point;
	Point *p2 = new Point;
	Point &sum = PntAdder(*p1, *p2);

	cout << "두점을 입력하세요:";
	cin >> p1->xPos >> p1->yPos;
	cin >> p2->xPos >> p2->yPos;
	
	cout << "두 점의 합 -> (" << sum.xPos << "," << sum.yPos << ")" << endl;

	delete p1,p2;
	delete &sum;
}

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point * pptr = new Point;	// 동적할당
	pptr->xPos = p1.xPos + p2.xPos;
	pptr->yPos = p1.yPos + p2.yPos;
	
	return *pptr;
}

*/

//
//struct Point
//{
//	int xpos;
//	int ypos;
//
//	void MovePos(int x, int y)
//	{
//		xpos += x;
//		ypos += y;
//	}
//
//	void AddPoint(const Point& pos)
//	{
//		xpos += pos.xpos;
//		ypos += pos.ypos;
//	}
//
//	void ShowPosition()
//	{
//		cout << "현재 좌표는 (" << xpos << "," << ypos << ") 입니다" << endl;
//	}
//};
//
//int main()
//{
//	Point pos1 = { 12,4 };
//	Point pos2 = { 20, 30 };
//	
//	pos1.MovePos(-7, 10);
//	pos1.ShowPosition();
//
//	pos1.AddPoint(pos2);
//	pos1.ShowPosition();
//}


//class Carculator {
//private:
//	int num1, num2;
//	int addCount,divCount,minCount,supCount;
//public:
//	void Init(void);
//	float Add(float n1, float n2);
//	float Div(float n1, float n2);
//	float Min(float n1, float n2);
//	float Sup(float n1, float n2);
//	void ShowOpCount(void);
//};
//
//int main()
//{
//	Carculator cal;
//	cal.Init();
//	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
//	cout << "3.5 + 1.7 = " << cal.Div(3.5, 1.7) << endl;
//	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
//	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
//	cal.ShowOpCount();
//}
//
//void Carculator::Init(void)
//{
//	num1 = 0;
//	num2 = 0;
//	addCount = 0;
//	divCount = 0;
//	minCount = 0;
//	supCount = 0;
//}
//
//float Carculator::Add(float n1, float n2)
//{
//	addCount++;
//	return n1 + n2;
//}
//
//float Carculator::Div(float n1, float n2)
//{
//	divCount++;
//	return n1 / n2;
//}
//
//float Carculator::Min(float n1, float n2)
//{
//	minCount++;
//	return n1 - n2;
//}
//
//float Carculator::Sup(float n1, float n2)
//{
//	supCount++;
//	return n1 * n2;
//}
//
//void Carculator::ShowOpCount(void)
//{
//	cout << "덧셈: " << addCount << " 뺄셈: " << minCount << "곱셈: " << supCount << "나눗셈: " << divCount << endl;
//}


// 문자열 저장 , 문자열 출력하는 Printer 라는 클래스 디자인

//
//class Printer {
//private :
//	char *str;
//public:
//	void SetString(const char* s)
//	{
//		str = new char[strlen(s) + 1];		// 어우 이거때문에 얼마나 고생을한거야. strcpy_s 해주려면 일단 동적할당부터 해주자
//		strcpy_s(str, strlen(s)+1, s);
//	}
//
//	void ShowString()
//	{
//		cout << str << endl;
//	}
//
//	void deleteStr()
//	{
//		delete str;
//		cout << "동적할당된 메모리 삭제완료!" << endl;
//	}
//};
//
//int main()
//{
//	Printer pnt;
//	pnt.SetString("hello world!");
//	pnt.ShowString();
//
//	pnt.SetString("I love C++");
//	pnt.ShowString();
//
//	pnt.deleteStr();
//	
//}

class Point {
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void showPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point center;
	int rad;
public:
	void Init(int x, int y, int r)
	{
		center.Init(x, y);
		rad = r; 
	}
	void showCircleInfo()
	{
		cout << "radius: " << rad << endl;
		center.showPointInfo();
	}
};

class Ring {
private:
	Circle c1,c2;
public:
	void Init(int x1, int y1, int r1, int x2, int y2, int r2)
	{
		c1.Init(x1, y1, r1);
		c2.Init(x2, y2, r2);
	}
	void showRingInfo()
	{
		cout << "Inner Circle Info..." << endl;
		c1.showCircleInfo();
		cout << "Inner Circle Info..." << endl;
		c2.showCircleInfo();
	}
};

int main()
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.showRingInfo();
}