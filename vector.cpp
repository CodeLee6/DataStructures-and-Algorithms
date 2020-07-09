#include<iostream>
using namespace std;

typedef struct
{
	int data[10];
	int length;
}vector;

//初始化 
void initvect(vector&v)
{
	for (int i = 0;i < 10;i++)
	{
		v.data[i] = 0;
		v.length = 0;
	}
}
//插入
bool insertvect(vector& v,int i,int e) 
{
	if (i < 0 || i>10) 
	{
		cout << "非法范围" << endl;
		return false;
	}
	for (int j = 9; j > i; j--)
	{
		v.data[j] = v.data[j - 1];
	}
	v.data[i] = e;
	v.length++;
	return true;
}
//按位修改
bool modifyvect1(vector& v, int i,int e)
{
	if (i < 0 || i>10)
	{
		cout << "非法范围" << endl;
		return false;
	}
	v.data[i] = e;
	return true;
}
//按值修改
//删除
bool deletevect(vector& v, int i)
{
	if (i < 0 || i>10)
	{
		cout << "非法范围" << endl;
		return false;
	}
	for (int j = i; j <10; j++)
		v.data[j] = v.data[j+1];
	v.length--;
	return true;
}
//容量
int capcityvect(vector& v)
{
	return v.length;
}
//打印
void print(vector v)
{
	for (int i = 0; i < 10; i++)
        cout << v.data[i]<<" ";
	cout << endl;
}

int main() 
{
	vector e;
	initvect(e);
	int i,l=0;
	insertvect(e, 0, 5);
	insertvect(e, 2, 15);
	insertvect(e,9, 6);
	print(e);
	cout<<capcityvect(e)<<endl;
	modifyvect1(e, 5, 20);
	print(e);
	cout << capcityvect(e) << endl;
	deletevect(e, 5);
	print(e);
	cout << capcityvect(e) << endl;

	return 0;
}