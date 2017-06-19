/**
 * 人类说法方法的多态模拟类结构
 * https://gcc.godbolt.org/ 观察对应的汇编是如何的。
*/
#include <stdio.h>

// 多态
class CPerson
{
public:
	CPerson(){
	}
	virtual ~CPerson(){
	}
	virtual void ShowSpeak(){//纯虚函数
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

// 美国人，继承自人类
class CAmerican : public CPerson
{
public:
	CAmerican(){}
	virtual ~CAmerican(){}
	virtual void ShowSpeak()
	{
		printf("Speak American\r\n");
	}
};


// 德国人，继承自人类
class CGerman : public CPerson
{
public:
	CGerman(){}
	virtual ~CGerman(){}
	virtual void ShowSpeak()
	{
		printf("Speak German\r\n");
	}
};

void ShowSpeak(CPerson * pPerson)
{
	pPerson->ShowSpeak();
}

int main(){
	CChinese Chinese;
	CAmerican American;
	CGerman German;

	ShowSpeak(&Chinese);
	ShowSpeak(&American);
	ShowSpeak(&German);
	return 0;
}