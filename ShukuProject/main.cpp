// ShudoProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "Shuku.h"
#include<ctime>
#include<fstream>
#include <string>
#include <sstream>
#include <cstdlib>

//�ж��ַ����Ƿ�ֻ������
bool isnum(string s)
{
	stringstream sin(s);
	double d;
	char c;
	if (!(sin >> d))
		return false;
	if (sin >> c)
		return false;
	else
		return true;
}

int main(int argc,char** argv)
{
	int n;
	ofstream out("sudoku.txt");
	//�ж������Ƿ�Ϸ�
	if (argc == 3) 
	{
		if (strcmp(argv[1],"-c")==0) //-c�����ɵ��������̵�����
		{
			if (!isnum(argv[2])) 
			{
				cout << "Error input parameter" << endl<<"Please re-enter an integer:";
				cin >> n;
			}
			else 
			{
				n = atoi(argv[2]);
			}
		}
		else
		{
			cout << "Error input parameter" << endl << "Please re-enter an integer:";
			cin >> n;
		}
	}
	else
	{
		cout << "Error input parameter" << endl << "Please re-enter an integer:";
		cin >> n;
	}
	//�ж�����������Ƿ�Ϊ0
	while (n == 0) 
	{
		cout << "Error input parameter" << endl << "Please re-enter an integer:";
		cin >> n;
	}
	Shuku *sk=new Shuku[n];//��̬����n������
	srand(unsigned(time(NULL)));//������������ӣ���ֹÿ�β������������ͬ
	for (int i = 0; i < n; i++) 
	{
		sk[i].GenerateShuku();
		sk[i].PrintShuku();
		sk[i].WriteFile(out);
		cout << endl;
		out << endl;
	}
	delete[] sk;
    return 0;
}

