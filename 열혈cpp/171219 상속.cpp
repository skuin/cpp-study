// 상속의 이해

#include<iostream>
#include<cstring>

using namespace std;

//class Rectangle {
//private:
//	int height;
//	int width;
//public:
//	Rectangle(int height, int width) : height(height), width(width) {}
//	
//	void ShowAreaInfo() const
//	{
//		cout << "면적: " << height*width << endl;
//	}
//};
//
//class Square : public Rectangle {
//private:
//	int lenth;
//public:
//	Square(int lenth) : Rectangle(lenth,lenth) {}
//
//};
//
//int main()
//{
//	Rectangle rec(4, 3);
//	rec.ShowAreaInfo();
//
//	Square sqr(7);
//	sqr.ShowAreaInfo();
//}


class Book {
private:
	char * title; //책의제목
	char * isbn; // 국제표준도서번호
	int price;
public:
	Book(char * bTitle, char* bIsbn, int bPrice) : price(bPrice)
	{
		title = new char[strlen(bTitle) + 1];
		strcpy_s(title, strlen(bTitle) + 1, bTitle);
		isbn = new char[strlen(bIsbn) + 1];
		strcpy_s(isbn, strlen(bIsbn) + 1, bIsbn);
	}

	~Book()
	{
		delete[] title, isbn;
	}

	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
};

class Ebook : public Book {
private:
	char * DRMKey;
public:
	Ebook(char* ebTitle, char* ebIsbn, int ebPrice, char* ebDRMKey) : Book(ebTitle, ebIsbn, ebPrice)
	{
		DRMKey = new char[strlen(ebDRMKey) + 1];
		strcpy_s(DRMKey, strlen(ebDRMKey) + 1, ebDRMKey);
	}
	~Ebook()
	{
		delete[] DRMKey;
	}
	void ShowEbookInfo()
	{
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
};

int main()
{
	Book book("좋은 c++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	Ebook ebook("좋은 c++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEbookInfo();
}