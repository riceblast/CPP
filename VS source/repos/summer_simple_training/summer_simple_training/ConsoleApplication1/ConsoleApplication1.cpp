////1输入一个年份，判断该年份是否是闰年或者平年。(简单 if 语句使用)

//#include<iostream>
//using namespace std;
//
//int main() {
//	int temp,year;
//	while (1) {     //让程序可以一直运行
//		cout << "enter a year, please: ";
//		cin >> year;     //获取用户输入的年份
//
//		//首先判断是否是正百年
//		//由于double类型的数据存在精度损失，故无法直接比较是否相等
//		temp = year / 100;
//		//先除100，取整，再乘100，观察和原数据是否相同，以此来判断是否是整百年
//		if (temp * 100 == year) {     //整百年
//			if (year % 400 == 0)
//				cout << year << " is" << "leap year"<<endl;
//			else
//				cout << year << " is" << " ordinary year"<<endl;
//		}
//		else {     //非整百年
//			if (year % 4 == 0)
//				cout << year << " is " << " leap year"<<endl;
//			else
//				cout << year << " is" << " ordinary year"<<endl;
//		}
//	}//while(1)
//
//	return 0;
//}

//2实现对学生成绩的分级(switch 语句使用)

//#include<iostream>
//using namespace std;
//
//int main() {
//	int score;
//	while (1) {
//		cout << "请输入考试成绩：";
//		cin >> score;
//		switch (score / 10) {     //通过取模的方式将区间变为一个常量
//		case 10:   //即100分
//			cout << "满分" << endl;
//			break;
//		case 9:   //即90到99分
//			cout << "成绩优秀" << endl;
//			break;
//		case 8:   //即80到89分
//			cout << "成绩良好" << endl;
//			break;
//		case 7:   //即70到79分
//			cout << "成绩中等" << endl;
//			break;
//		case 6:   //即60到69分
//			cout << "成绩及格（不行啊小老弟）" << endl;
//			break;
//		default:   //不及格
//			cout << "不及格" << endl;
//			break;
//		}
//	}
//	return 0;
//}

//3编写代码，输入一组二维数组，实现二维数组转置输出（行变列，列变行） 
//中途夭折

//#include<iostream>
//using namespace std;
//
//
//
//int main() {
//	int i, j;
//	int Array[4][2], length = 4;
//	for (int row = 0; row < 2; row += 1) {
//		for (int colume = 0; colume < length; colume += 1) {
//			Array[row][colume] = 6;
//		}
//	}
//
//
//	return 0;
//}

//4写一个函数，程序调用该函数，在输入一组数后，可以找出其中第二大的数，以及最小的
//数并进行输出（函数） 。

//#include<iostream>
//using namespace std;
//
//int main() {
//	int Array[10], temp;
//	cout << "每一次输入结束后请按回车"<<endl;
//	for (int times = 0; times < 10; times += 1) {   //为数组赋值
//		cout << "请输入第" << times + 1 << "个数字: ";
//		cin >> temp;
//		Array[times] = temp;
//	}
//
//	//开始查找最大的元素
//	int max = Array[0], tag = 0;
//	for (int times = 1; times < 10; times += 1) {
//		if (max < Array[times]) {
//			max = Array[times];
//			tag = times;
//		}
//	}
//
//
//	int smax = Array[0];
//	for (int times = 1; times < 10; times += 1) {
//		if (times != tag) {
//			if (smax < Array[times]) {
//				smax = Array[times];
//			}     //第二大元素就是smax
//		}
//	}
//
//	int min = Array[0];
//	for (int times = 1; times < 10; times += 1) {
//		if (min > Array[times]) {
//			min = Array[times];
//		}     //最小素就是min
//	}
//
//	cout << "第二大元素为 " << smax<<endl;
//	cout << "最小元素为 " << min<<endl;
//	return 0;
//}

////5采用结构体来管理学生列表

#include<string>
#include<iostream>
using namespace std;

//F--famele
//M--male

struct student {
//构造函数
	student() {
		ID = -1;
		gender = "###";
		name = "###";
		project_score = 0;
		attitude_socre = 0;
		team_score = 0;
	}

	//student(int id, string sex, string nm) {
	//	ID = id;
	//	gender = sex;
	//	name = nm;
	//}

	//改变Student属性
	void changeId(int id) {
		ID = id;
	}
	void changeGender(string sex) {
		gender = sex;
	}
	void changeName(string nm) {
		name = nm;
	}

	//Student属性
	int ID;
	string gender;
	string name;

	//分数
	int project_score;
	int attitude_socre;
	int team_score;
	//改变分数
	void changeScore(int ps, int as, int ts) {
		project_score = ps;
		attitude_socre = as;
		team_score = ts;
	}
	//计算分数
	double sum() {
		int ss = project_score * 0.6 + attitude_socre * 0.3 + team_score * 0.1;
		return ss;
	}
};

struct manager {
	manager() {}
	student school[100];   //id从1开始
	void addStudent(int id, string sex, string nm,int pscore,int ascore,int tscore) {
		school[id - 1].changeId(id);
		school[id - 1].changeGender(sex);
		school[id - 1].changeName(nm);
		school[id - 1].changeScore(pscore,ascore,tscore);
		cout << "add successfully!"<<endl;
		cout << "ID: " << id << endl;
		cout << "gender: " << sex << endl;
		cout << "name: " << nm << endl;
	}
	
	void deleteStudent(int id) {
		school[id - 1].changeGender("###");
		school[id - 1].changeName("###");
		cout << "delete successfully" << endl;
		cout << "student deleted succesfully"<<endl;
	}

	void findStudent(int id) {
		cout << endl;
		cout << "ID: " << school[id - 1].ID<<endl;
		cout << "gender: " << school[id - 1].gender<<endl;
		cout << "name: " << school[id - 1].name << endl;
	}

	void sum(int id) {
		cout <<id<< "号学生的成绩是"<<school[id - 1].sum();
		return;
	}
};

//测试
int main() {
	manager mymag;
	mymag.addStudent(66,"male", "riceblast",20,30,40);
	mymag.findStudent(66);
	mymag.sum(66);
	return 0;
}

//7. 编写程序：定义抽象基类 Shape

//#include <cmath>
//#include<iostream>
//using namespace std;
//
//const double PI = 3.14;   //定义PI常量
//
//class Shape {
//public:
//	virtual double getArea() = 0;
//};
//
////Circle
//class Circle :public Shape {
//public:
//	Circle(int r_of_circle):radius(r_of_circle) {};
//	double getArea() {
//		double area = radius * radius * PI;
//		cout << "Circle: " << area << endl;
//		return area;
//	}
//private:
//	int radius;
//};
//
////Rectangle
//class Rectangle :public Shape {
//public:
//	Rectangle(int wd, int lh) :width(wd), length(lh) {};
//	double getArea() {
//		double area = width * length;
//		cout << "Rectangle: " << area << endl;
//		return area;
//	}
//private:
//	int width;
//	int length;
//};
//
////Triangle 
//class Triangle :public Shape {
//public:
//	Triangle(int la, int lb, int lc) :line_a(la), line_b(lb), line_c(lc) {};
//	double getArea() {     //海伦公式
//		double p = (line_a + line_b + line_c) / 2;
//		double temp = (p - line_a) * (p - line_b) * (p - line_c) * p;
//		double area = pow(temp,0.5);
//		cout << "Triangle: " << area << endl;
//		return area;
//	}
//private:
//	int line_a;
//	int line_b;
//	int line_c;
//};
//
////Square
//class Square :public Shape {
//public:
//	Square(int wd) :wdh(wd) {};
//	double getArea() {
//		double area = pow(wdh, 2);
//		cout << "square: " << area << endl;
//		return area;
//	}
//private:
//	int wdh;
//};
//
////开始测试
//int main() {
//	Shape* array[4];     //基类指针数组
//
//
//	int l_of_tri, r_of_cir, w_of_rec, l_of_rec, w_of_squ;
//
//	cout << "l_of_tri: ";
//	cin >> l_of_tri;
//	Triangle myTri(l_of_tri, l_of_tri, l_of_tri);
//	array[0] = &myTri;
//	array[0]->getArea();
//
//
//	cout << "r_of_circle: ";
//	cin >> r_of_cir;
//	Circle myCir(r_of_cir);
//	array[1] = &myCir;
//	array[1]->getArea();
//
//
//	cout << "w_of_rec: ";
//	cin >> w_of_rec;
//	cout << "l_of_rec: ";
//	cin >> l_of_rec;
//	Rectangle myRec(w_of_rec, l_of_tri);
//	array[2] = &myRec;
//	array[2]->getArea();
//
//
//
//	cout << "w_of_squ: ";
//	cin >> w_of_squ;
//	Square mySqu(w_of_squ);
//	array[3] = &mySqu;
//	array[3]->getArea();
//
//	//构造对象
//
//
//
//	return 0;
//}

//8

//#include<iostream>
//using namespace std;
//
////Rectangle
//class Rectangle {
//public:
//	//构造函数
//	Rectangle() :width(10), length(10) {};
//	Rectangle(int wd, int lt) :width(wd), length(lt) {};
//
//	int getWid() {
//		return width;
//	}
//
//	int getLen() {
//		return length;
//	}
//
//	void changeW(int wid) {
//		width = wid;
//	}
//	void changeL(int len) {
//		length = len;
//	}
//
//	int getArea() {
//		int area = width * length;
//		return area;
//	}
//
//	int getPerimeter() {
//		int perimeter = 2 * (width * length);
//		return perimeter;
//	}
//private:
//	int width;
//	int length;
//};
//
//class PlainRect:public  Rectangle{
//public:
//	PlainRect() :startX(0), startY(0){
//		changeW(10);
//		changeL(10);
//	}
//
//	PlainRect(int sX, int sY, int wid, int len) {
//		startX = sX;
//		startY = sY;
//		changeW(wid);
//		changeL(len);
//	}
//
//	bool isInside(double x, double y) {
//		bool temp = (x >= startX && (startX + getWid()) && y >= startY && (y <= startY + getLen()));
//		return temp;
//	}
//private:
//	int startX;
//	int startY;
//};
//
////测试程序
//int main() {
//	PlainRect myPlRec(10, 10, 10, 20);
//	cout << "area is " << myPlRec.getArea() << endl;
//	cout << "perimeter is " << myPlRec.getPerimeter() << endl;
//
//	bool tmep=myPlRec.isInside(25.5, 13);
//	cout << "(25.5,13)is in the myPlRec :" << temp << endl;
//
//	return 0;
//}