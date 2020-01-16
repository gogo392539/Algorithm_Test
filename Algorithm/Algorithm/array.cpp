#include "array.h"
#include "stdafx.h"
#include <sstream>


/*
4344�� - ����� �Ѱ���
���л� ��������� 90%�� �ڽ��� �ݿ��� ����� �Ѵ´ٰ� �����Ѵ�. ����� �׵鿡�� ���� ������ �˷���� �Ѵ�.
[�Է�]
ù° �ٿ��� �׽�Ʈ ���̽��� ���� C�� �־�����.
��° �ٺ��� �� �׽�Ʈ ���̽����� �л��� �� N(1 �� N �� 1000, N�� ����)�� ù ���� �־�����, 
�̾ N���� ������ �־�����. ������ 0���� ũ�ų� ����, 100���� �۰ų� ���� �����̴�.
[���]
�� ���̽����� �� �پ� ����� �Ѵ� �л����� ������ �ݿø��Ͽ� �Ҽ��� ��° �ڸ����� ����Ѵ�.
*/
/*
[4344�� ����]
���л� ��������� 90%�� �ڽ��� �ݿ��� ����� �Ѵ´ٰ� �����Ѵ�. ����� �׵鿡�� ���� ������ �˷���� �Ѵ�.

[�Է�]
ù° �ٿ��� �׽�Ʈ ���̽��� ���� C�� �־�����.
��° �ٺ��� �� �׽�Ʈ ���̽����� �л��� �� N(1 �� N �� 1000, N�� ����)�� ù ���� �־�����, �̾ N���� ������ �־�����.
������ 0���� ũ�ų� ����, 100���� �۰ų� ���� �����̴�.

[���]
�� ���̽����� �� �پ� ����� �Ѵ� �л����� ������ �ݿø��Ͽ� �Ҽ��� ��° �ڸ����� ����Ѵ�.

[input]
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91

[output]
40.000%
57.143%
33.333%
66.667%
55.556%
*/
int fn_Averege(int nCount)
{
	int nStudentNum = 0;
	int narStudents[1000] = { 0, };
	double darPercents[1000] = { 0.0, };

	for (int i = 0; i < nCount; i++) {
		int nAverage = 0;
		int nAboveAverage = 0;
		double dPercent = 0.0;

		cin >> nStudentNum;

		if (nStudentNum < 1 || nStudentNum > 1000) {
			return -1;
		}

		for (int j = 0; j < nStudentNum; j++) {
			cin >> narStudents[j];

			if (narStudents[i] < 0 || narStudents[i] > 100) {
				return -1;
			}

			nAverage += narStudents[j];
		}
		nAverage /= nStudentNum;

		for (int j = 0; j < nStudentNum; j++) {
			if (narStudents[j] > nAverage) {
				nAboveAverage++;
			}
		}

		dPercent = ((double)nAboveAverage / (double)nStudentNum) * 100.0;
		darPercents[i] = dPercent;
	}

	for (int i = 0; i < nCount; i++) {
		printf("%.3f%% \n", darPercents[i]);
	}


	return 0;
}



/*
����
���� ��ҹ��ڿ� ���⸸���� �̷���� ���ڿ��� �־�����.
�� ���ڿ����� �� ���� �ܾ ������? �̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
��, �� �ܾ ���� �� �����ϸ� ������ Ƚ����ŭ ��� ����� �Ѵ�.

�Է�
ù �ٿ� ���� ��ҹ��ڿ� ����� �̷���� ���ڿ��� �־�����.
�� ���ڿ��� ���̴� 1,000,000�� ���� �ʴ´�. �ܾ�� ���� �� ���� ���еǸ�,
������ �����ؼ� ������ ���� ����. ���� ���ڿ��� �հ� �ڿ��� ������ ���� ���� �ִ�.

���
ù° �ٿ� �ܾ��� ������ ����Ѵ�.
*/
int fn_CountOfWord(string& strData)
{
	int nCount = 0;
	string strToken;
	stringstream ssData(strData);

	if (strlen(strData.c_str()) > 1000000) {
		return -1;
	}

	while (getline(ssData, strToken, ' ')) {
		//cout << strToken << endl;
		if (strcmp(strToken.c_str(), "") != 0) {
			nCount++;
		}
	}

	cout << nCount << endl;

	return 0;
}


/*
����
������� ���� ����� ������ ���� ���Ѵ�. ����� ���ڸ� �дµ� ������ �ִ�. �̷��� ������ ���ϴ� ����� ���ؼ� ����̴� ���� ũ�⸦ ���ϴ� ������ ���־���. 
����̴� �� �ڸ� �� �� ���� ĥ�ǿ� ���־���. �� ������ ũ�Ⱑ ū ���� ���غ���� �ߴ�.

����� ���� �ٸ� ����� �ٸ��� �Ųٷ� �д´�. ���� ���, 734�� 893�� ĥ�ǿ� �����ٸ�, 
����� �� ���� 437�� 398�� �д´�. ����, ����� �� ���� ū ���� 437�� ū ����� ���� ���̴�.

�� ���� �־����� ��, ����� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����̰� ĥ�ǿ� ���� �� �� A�� B�� �־�����. 
�� ���� ���� ���� �� �ڸ� ���̸�, 0�� ���ԵǾ� ���� �ʴ�.
*/
int fn_DiffusionCoefficient()
{
	int nNum1 = 0;
	int nNum2 = 0;
	string strNum1;
	string strNum2;
	string strReNum1;
	string strReNum2;

	cin >> strNum1 >> strNum2;

	for (int i = 0; i < 3; i++) {
		strReNum1 += strNum1.at(3 - i - 1);
		strReNum2 += strNum2.at(3 - i - 1);
	}

	nNum1 = atoi(strReNum1.c_str());
	nNum2 = atoi(strReNum2.c_str());

	cout << nNum1 << " " << nNum2 << endl;

	if (nNum1 > nNum2) {
		cout << nNum1 << endl;
	}
	else {
		cout << nNum2 << endl;
	}

	return 0;
}


/*
2941��
*/
int fn_CroatiaAlphabet()
{
	int nIdx = 0;
	int nLen = 0;
	int nCount = 0;
	string strWords;
	cin >> strWords;

	nLen = strWords.length();
	while (nIdx < nLen) {
		int nReturn = 0;
		nReturn = fn_Search_CroatiaAlphabet(strWords.substr(nIdx).c_str());
		nIdx += nReturn;
		nCount++;
	}

	cout << nCount << endl;

	return 0;
}

int fn_Search_CroatiaAlphabet(const char szData[])
{
	char arCroatiaAlpha[10][8] = {
	"c=",
	"c-",
	"dz=",
	"d-",
	"lj",
	"nj",
	"s=",
	"z="
	};
	int arLen[8] = { 2,2,3,2,2,2,2,2 };

	for (int i = 0; i < 8; i++) {
		if (strncmp(szData, arCroatiaAlpha[i], arLen[i]) == 0) {
			return arLen[i];
		}
	}

	return 1;
}


/*
1316��
*/
int fn_GroupWords()
{
	int nIdx = 0;
	int nCount = 0;
	string strWords;

	cin >> nCount;


	for (int i = 0; i < nCount; i++) {
		cin >> strWords;

		if (fn_Check_GroupWords(strWords) == 0) {
			nIdx++;
		}
	}
	
	cout << nIdx << endl;





	return 0;
}

int fn_Check_GroupWords(string& strWords)
{
	char arAlphabets[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	return 0;
}
