#pragma once
#include <string>
using namespace std;

typedef struct BigInt //定义大整数
{
	int Length;       //大数的位数
	int Sign;		  //整数符号位,1为正数，-1为负数
	string Value;     //存储大数各位的数字字符

	BigInt() {
		this->Length = 0;
		this->Sign = 1;
		this->Value = "";
	}

	BigInt(char* s) {
		this->Length = strlen(s);
		this->Sign = +1;
		if (s[0] == '-') {
			this->Sign = -1;
			this->Value = s[1];
			this->Length -= 1;
		}
		else {
			this->Value = s;
		}

	}

	BigInt(string s) {
		this->Length = s.size();
		this->Sign = +1;
		if (s[0] == '-') {
			this->Sign = -1;
			this->Value = s.substr(1, s.size());
			this->Length -= 1;
		}
		else {
			this->Value = s;
		}

	}


}BigInt;


static int CmpBigInt(BigInt S, BigInt T) {
	if (S.Sign == T.Sign) { //如果同号则比较值的大小

		if (S.Value == T.Value) return 0;
		if (S.Sign == 1) {
			if (S.Length == T.Length)
			{
				return S.Value.compare(T.Value);
			}
			else
			{
				return S.Length > T.Length ? 1 : -1;
			}
		}
		else
		{
			if (S.Length == T.Length)
			{
				return -S.Value.compare(T.Value);
			}
			else
			{
				return S.Length > T.Length ? -1 : 1;
			}
		}
	}
	else {
		if (S.Sign - T.Sign == 2) { //异号则直接对比符号
			return 1;
		}
		else {
			return -1;
		}

	}
}

//获取数字串从右往左第ind位的数字，没有则返回0
static int GetIndexNum(BigInt BI, int ind) {
	if (ind > BI.Length)
	{
		return 0;
	}
	else {
		char c = BI.Value[BI.Length - ind];
		return c-48;
	}
}