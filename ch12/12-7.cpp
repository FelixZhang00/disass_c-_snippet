/**
 * 构造函数和析构函数中调用虚函数的流程
 * https://gcc.godbolt.org/ 观察对应的汇编是如何的。
*/
#include <stdio.h>

// 多态
class CPerson
{
public:
	CPerson(){
		ShowSpeak();
	}
	virtual ~CPerson(){
		ShowSpeak();
	}
	virtual void ShowSpeak(){
		printf("Speak No\r\n");
	}
};

// 中国人，继承自人类
class CChinese : public CPerson
{
public:
	CChinese(){}
	virtual ~CChinese(){}
	virtual void ShowSpeak()
	{
		printf("Speak Chinese\r\n");
	}
};

int main(){
	CChinese Chinese;
	return 0;
}