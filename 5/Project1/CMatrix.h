#ifndef CMATRIX_H
#define CMATRIX_H
#include<iostream>
#include<cmath>
using namespace std;
class CMatrix {
private:
	int mCols;
	int mRows;
	double** mData;
public:
	CMatrix(int row = 0, int col = 0);	//构造函数
	CMatrix();	//重载构造函数，用户自定义
	CMatrix(const CMatrix& other);	//拷贝调用函数
	~CMatrix();	//析构函数

	CMatrix operator + (const CMatrix other);	//矩阵加法
	CMatrix operator - (const CMatrix other);	//矩阵减法
	CMatrix operator * (const CMatrix other);	//矩阵乘法

	CMatrix& operator = (const CMatrix other);	//赋值

	double& operator ()(int row = 0, int col = 0);	//访问元素
	const double& operator ()(int row = 0, int col = 0) const;	//用于访问常量元素	

	friend istream& operator >>(istream is, CMatrix& m);	//输入
	friend ostream& operator <<(ostream os, CMatrix& m);	//输出
};
#endif