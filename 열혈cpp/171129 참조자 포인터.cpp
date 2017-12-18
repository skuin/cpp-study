// 17.11.29
// ��ȯ���� �������ΰ�, �����Ϳ� ������

#include <iostream>
#include <cstring>

using namespace std;

/* ������. �Լ�. ������

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

	cout << "������ �Է��ϼ���:";
	cin >> p1->xPos >> p1->yPos;
	cin >> p2->xPos >> p2->yPos;
	
	cout << "�� ���� �� -> (" << sum.xPos << "," << sum.yPos << ")" << endl;

	delete p1,p2;
	delete &sum;
}

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point * pptr = new Point;	// �����Ҵ�
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
//		cout << "���� ��ǥ�� (" << xpos << "," << ypos << ") �Դϴ�" << endl;
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
//	cout << "����: " << addCount << " ����: " << minCount << "����: " << supCount << "������: " << divCount << endl;
//}


// ���ڿ� ���� , ���ڿ� ����ϴ� Printer ��� Ŭ���� ������

//
//class Printer {
//private :
//	char *str;
//public:
//	void SetString(const char* s)
//	{
//		str = new char[strlen(s) + 1];		// ��� �̰Ŷ����� �󸶳� ������Ѱž�. strcpy_s ���ַ��� �ϴ� �����Ҵ���� ������
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
//		cout << "�����Ҵ�� �޸� �����Ϸ�!" << endl;
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