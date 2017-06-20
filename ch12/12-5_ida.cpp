/**
 * 使用ida观察类的继承
 * p283
 * g++ -m32 12-5_ida.cpp
*/
#include <stdio.h>

// 多态
class CPerson
{
public:
	CPerson(){
		ShowSpeak(); //构造函数调用了虚函数
	}
	virtual ~CPerson(){
		ShowSpeak();
	}
	virtual void ShowSpeak(){
		//调用了其它的虚函数
		printf("%s::\n", GetClassName());
	}
	virtual char* GetClassName(){
		return "CPerson";
	}
};

// 中国人，继承自人类
class CChinese : public CPerson
{
public:
	CChinese(){
		ShowSpeak();
	}
	virtual ~CChinese(){
		ShowSpeak();
	}
	virtual char* GetClassName(){
		return "CChinese";
	}
};

int main(){
	CPerson *pPerson = new CChinese;
	pPerson->ShowSpeak();
	delete pPerson;
	return 0;
}