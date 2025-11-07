#include"CMatrix.h"
using namespace std;
CMatrix::CMatrix(int row = 0, int col = 0)
{
	cout << "您定义了一个矩阵" << endl;
	cout << "它有" << row << "行" << col << "列" << endl;
	mCols = col;
	mRows = row;

	mData = new double* [mRows];//给mData分配行数个指针
	
	for (int i = 0; i < row; i++)
		mData[i] = new double[col];//再给每个指针分配列数个空间

	//矩阵的初始化
	for (int i = 0; i < mRows; i++)
		for (int j = 0; j < mCols; j++)
			mData[i][j] = 0;
}

CMatrix::CMatrix()
{
	cout << "您定义了一个矩阵" << endl;
	cout << "它有几行" << endl;
	cin >> mRows;
	cout << "它有几列" << endl;
	cin >> mCols;

	mData = new double* [mRows];//给mData分配行数个指针

	for (int i = 0; i < mRows; i++)
		mData[i] = new double[mCols];//再给每个指针分配列数个空间

	//矩阵的初始化
	for (int i = 0; i < mRows; i++)
		for (int j = 0; j < mCols; j++)
			mData[i][j] = 0;
}

CMatrix::~CMatrix()
{
	cout << "销毁矩阵" << endl;
}

CMatrix CMatrix::operator + (const CMatrix other)
{
	if(mRows != other.mRows || mCols != other.mCols) {
		cout << "错误！这两个矩阵大小不同，不能进行加法运算" << endl;
		return;
	}
	CMatrix result(mRows, mCols);
	for (int i = 0; i < mRows; i++) 
		for (int j = 0; j < mCols; j++) 
			result(i, j) = mData[i][j] + other(i, j);
	return result;
}

CMatrix CMatrix::operator - (const CMatrix other)
{
	if (mRows != other.mRows || mCols != other.mCols) 
	{
		cout << "错误！这两个矩阵大小不同，不能进行加法运算" << endl;
		return;
	}
	CMatrix result(mRows, mCols);
	for (int i = 0; i < mRows; i++)
		for (int j = 0; j < mCols; j++)
			result(i, j) = mData[i][j] - other(i, j);
	return result;
}

CMatrix CMatrix::operator * (const CMatrix other)
{
	if (mCols != other.mRows) 
	{
		cout << "错误！这两个矩阵不能相乘" << endl;
		return;
	}

	CMatrix result(mRows, mCols);
	for (int i = 0; i < mRows; i++)
	{
		for (int j = 0; j < other.mCols; j++)
		{
			int sum = 0;
			for (int m = 0; m < mCols;m++)
			{
				sum += mData[i][m] * other.mData[m][j];
			}
			result.mData[i][j] = sum;
		}
	}

	return result;
}

CMatrix& CMatrix::operator = (const CMatrix other)
{
	mRows = other.mRows;
	mCols = other.mCols;
	for (int i = 0; i < mRows; i++) 
		for (int j = 0; j < mCols; j++)
			mData[i][j] = other(i, j);
}

double& CMatrix::operator ()(int row = 0, int col = 0)
{
	if (row > mRows || col > mCols) {
		cout << "错误！超出范围！" << endl;
		return;
	}
	return mData[row][col];
}

const double& CMatrix::operator ()(int row = 0, int col = 0) const
{
	if (row > mRows || col > mCols) {
		cout << "错误！超出范围！" << endl;
		return;
	}
	return mData[row][col];
}

istream& operator >>(istream is, CMatrix& m)
{

}