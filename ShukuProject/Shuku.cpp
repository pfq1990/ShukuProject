#include "stdafx.h"
#include "Shuku.h"
#include "Element.h"
#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

Shuku::Shuku()
{
	shuku = new Element[9][9];
	Shuku::InitShuku();
}

//��������
void Shuku::GenerateShuku()
{
	Node currentNode;
	currentNode.x = 0;
	currentNode.y = 0;
	Element* currentElement = NULL;
	while (true) {
		currentElement = &shuku[currentNode.x][currentNode.y];
		if (!currentElement->IsProcessed()) {
			GetNextValue(currentElement);
		}
		if (!currentElement->IsValueListEmpty()) {
			currentElement->PickNextValue();
			if (currentNode.x == MaxSize - 1 && currentNode.y == MaxSize - 1) {
				break;
			}
			else {
				NextNode(currentNode);
			}
		}
		else {
			if (currentNode.x == 0 && currentNode.y == 0) {
				break;
			}
			else {
				currentElement->Clear();
				PrevNode(currentNode);
			}
		}
	}
}

//��ȡ��һ����Ч��ֵ
void Shuku::GetNextValue(Element* currentElement) 
{
	for (int i = 1; i <= MaxSize; i++) {
		if (valueInRow(i, currentElement->X(), currentElement->Y()) && valueInCol(i, currentElement->X(), currentElement->Y()) && valueInSmallShuku(i, currentElement->X(), currentElement->Y())) {
			currentElement->AddNextValue(i);
		}
	}
}

//������Ƿ����������Ķ���
bool Shuku::valueInRow(int value, int x, int y) 
{
	for (int i = 0; i < y; i++) {
		if (!shuku[x][i].IsProcessed()) {
			continue;
		}
		if (shuku[x][i].value == value) {
			return false;
		}
	}
	return true;
}

//������Ƿ�������������
bool Shuku::valueInCol(int value, int x, int y) 
{
	for (int i = 0; i < x; i++) {
		if (!shuku[i][y].IsProcessed()) {
			continue;
		}
		if (shuku[i][y].value == value) {
			return false;
		}
	}
	return true;
}

//���С�Ź����Ƿ�������������
bool Shuku::valueInSmallShuku(int value, int x, int y) {
	int startRow = (x / 3) * 3;
	int endRow = (x / 3) * 3 + 3;
	int startCol = (y / 3) * 3;
	int endCol = (y / 3) * 3 + 3;

	for (int i = startRow; i < endRow; i++) {
		for (int j = startCol; j < endCol; j++) {
			if (!shuku[i][j].IsProcessed()) {
				continue;
			}
			if (shuku[i][j].value == value) {
				return false;
			}
		}
	}
	return true;
}

//��ʼ������
void Shuku::InitShuku() 
{

	for (int i = 0; i < MaxSize; i++) {
		for (int j = 0; j < MaxSize; j++) {
			shuku[i][j].SetX(i);
			shuku[i][j].SetY(j);
		}
	}
	//����������һ�����ݣ���������1-9����ֲ�
	int v[9];
	for (int i = 1; i <= MaxSize; i++)v[i - 1] = i;
	random_shuffle(&v[0], &v[8]);
	for (int i = 0; i < MaxSize; i++) {
		shuku[0][i].AddNextValue(v[i]);
		shuku[0][i].setIsProcessed(true);
	}
}

//��������ӡ������̨
void Shuku::PrintShuku()const 
{
	for (int i = 0; i < MaxSize; i++) {
		for (int j = 0; j < MaxSize; j++) {
			cout << shuku[i][j].value << " ";
		}
		cout << endl;
	}
}

//������д�����ļ�������
void Shuku::WriteFile(ofstream &out)const
{
	for (int i = 0; i < MaxSize; i++) {
		for (int j = 0; j < MaxSize; j++) {
			out << shuku[i][j].value << " ";
		}
		out << endl;
	}
	out << endl;
}

//������һ����
void Shuku::NextNode(Node& currentNode) 
{
	if (currentNode.y == MaxSize - 1) {
		currentNode.y = 0;
		currentNode.x = currentNode.x + 1;
	}
	else {
		currentNode.y = currentNode.y + 1;
		currentNode.x = currentNode.x;
	}
}

//����ǰһ����
void Shuku::PrevNode(Node& currentNode) 
{
	if (currentNode.y == 0) {
		currentNode.y = MaxSize - 1;
		currentNode.x = currentNode.x - 1;
	}
	else {
		currentNode.x = currentNode.x;
		currentNode.y = currentNode.y - 1;
	}
}

Shuku::~Shuku()
{
	delete[] shuku;
}
