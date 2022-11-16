#pragma once
#include <string>
using namespace std;

typedef struct BigInt //���������
{
	int Length;
	int Sign;		  //��������λ,1Ϊ������-1Ϊ����
	string Value;

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
	if (S.Sign == T.Sign) { //���ͬ����Ƚ�ֵ�Ĵ�С

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
		if (S.Sign - T.Sign == 2) { //�����ֱ�ӶԱȷ���
			return 1;
		}
		else {
			return -1;
		}

	}
}