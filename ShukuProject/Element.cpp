#include "stdafx.h"
#include "Element.h"


Element::Element(int x,int y):isProcessed(false),value(0)
{
	node.x = x;
	node.y = y;
}


Element::~Element(){}

//����λ����ֵ�Ƿ��Ѵ����
bool Element::IsProcessed()const 
{
	return isProcessed;
}

//��ȡ����ֵ�к�
int Element::X() const
{
	return node.x;
}

//��ȡ����ֵ�к�
int Element::Y()const
{
	return node.y;
}

//���ø���ֵ���к�
void Element::SetX(int x)
{
	node.x = x;
}

//���ø���ֵ���к�
void Element::SetY(int y)
{
	node.y = y;
}

//�����Ч��ֵ�б��Ƿ�Ϊ��
bool Element::IsValueListEmpty()const 
{
	return valueList.empty();
}

//������number��ӵ���Ч��ֵ�б���
void Element::AddNextValue(int number)
{
	valueList.push_back(number);
}

//ѡ����һ����Ч��ֵ
void Element::PickNextValue()
{
	int nextValue = valueList.front();
	valueList.pop_front();
	value = nextValue;
	isProcessed = true;
}

//���ô����־
void Element::setIsProcessed(bool ip) 
{
	isProcessed = ip;
}

//��ո���ֵ
void Element::Clear()
{
	valueList.clear();
	value = 0;
	isProcessed = false;
}
