//8-6

//#include<iostream>
//
//using namespace std;
//
//const double PI = 3.14;   //定义PI为常数3.14
//
////抽象类Shape声明
//class Shape {
//public:
//	virtual double getArea() = 0;   //纯虚函数，在抽象类Shape中定义统一的接口
//	virtual double getPerim() = 0;   //纯虚函数，在抽象类Shape中定义统一的接口
//};
//
////派生类Rectangle类声明
//class Rectangle :public Shape {   //公 有继承Shape类
//public:
//	Rectangle() :length(4), width(2) {}
//	double getArea();   //给出Shape中纯虚函数的定义
//	double getPerim();   //给出Shape中纯虚函数的定义
//	double get_length() { return length; };   //给外部提供访问私有成员的接口
//	double get_width() { return width; };   //给外部提供访问私有成员的接口
//private:
//	double length;
//	double width;
//};
//
////派生类Circle类声明
//class Circle :public Shape {
//public :
//	Circle() :radius(5.5) {}   //Circle类构造函数
//	double getArea();   //给出Shape中纯虚函数的定义
//	double getPerim();   //给出Shape中纯虚函数的定义
//	double get_radius() { return radius; };   //给外部提供访问私有成员的接口
//private:
//	double radius;
//};
//
////函数实现
//
////Rectangle 类
//double Rectangle::getArea() {   //在派生类中给出抽象类中纯虚函数实现
//	double area = length * width;
//	return area;
//}
//double Rectangle::getPerim() {   //在派生类中给出抽象类中纯虚函数实现
//	double perim = 2 * (length + width);
//	return perim;
//}
//
////Circle 类
//double Circle::getArea() {    //在派生类中给出抽象类中纯虚函数实现
//	double area_of_circle = PI * radius * radius;
//	return area_of_circle;
//}
//
//double Circle::getPerim() {   //在派生类中给出抽象类中纯虚函数实现
//	double perim_of_circle = 2 * PI * radius;
//	return perim_of_circle;
//}
//
////测试
//int main() {
//	Shape* ptr_of_shape = NULL;
//	Rectangle myRec;
//	Circle myCir;
//
//	ptr_of_shape = &myRec;
//	cout<<"The area of Rectangle is " << ptr_of_shape->getArea() << endl;
//	cout << "The perim of Rectangle is " << ptr_of_shape->getPerim() << endl;
//
//	ptr_of_shape = &myCir;
//	cout << "The area of Circle is " << ptr_of_shape->getArea() << endl;
//	cout << "The perim of Circle is " << ptr_of_shape->getPerim() << endl;
//	
//	return 0;
//}

//8-7

#include <iostream>
using namespace std;

//首先定义类Point
class Point {
public:
	int getx() { return x; }
	int gety() { return y; }

	//Point类的构造函数
	Point(int x_of_p,int y_of_p):x(x_of_p),y(y_of_p){}
	
	Point& operator ++() {     //前置++运算符重载
		cout << "前置++重载被调用"<<endl;
		x += 1;
		y += 1;
		return *this;
	}

	Point& operator --() {   //前置--运算符重载
		cout << "前置--重载被调用" << endl;
		x -= 1;
		y -= 1;
		return *this;
	}

	Point operator ++(int) {     //后置++运算符重载
		cout << "后置++重载被调用" << endl;
		x += 1;
		y += 1;
		return Point(x - 1, y - 1);   //创建临时对象并返回
	}

	Point operator --(int) {     //后置++运算符重载
		cout << "后置--被调用"<<endl;
		x -= 1;
		y -= 1;
		return Point(x + 1, y + 1);     //创建临时对象并返回
	}

private:
	int x;
	int y;
};

ostream& operator <<(ostream& out,Point pt) {     	// <<的运算符重载
	out << "(" << pt.getx() << "," << pt.gety() << ")"<<endl;
	return out;
}


//测试
int main() {
	Point myPoint(4, 4);

	cout << "生成对象" << myPoint;

	//调用前置++
	cout << ++myPoint;
	cout << myPoint;

	//调用前置--
	cout << --myPoint;
	cout << myPoint;

	//调用后置++
	cout << myPoint++;
	cout << myPoint;

	//调用后置++
	cout << myPoint--;
	cout << myPoint;

	return 0;
}