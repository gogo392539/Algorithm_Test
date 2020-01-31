#include "array.h"
#include "stdafx.h"
#include <sstream>
#include <map>


/*
4344번 - 평균은 넘겠지
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.
[입력]
첫째 줄에는 테스트 케이스의 개수 C가 주어진다.
둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 
이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.
[출력]
각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.
*/
/*
[4344번 문제]
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.

[입력]
첫째 줄에는 테스트 케이스의 개수 C가 주어진다.
둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다.
점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

[출력]
각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.

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
문제
영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다.
이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오.
단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.

입력
첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문자열이 주어진다.
이 문자열의 길이는 1,000,000을 넘지 않는다. 단어는 띄어쓰기 한 개로 구분되며,
공백이 연속해서 나오는 경우는 없다. 또한 문자열의 앞과 뒤에는 공백이 있을 수도 있다.

출력
첫째 줄에 단어의 개수를 출력한다.
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
문제
상근이의 동생 상수는 수학을 정말 못한다. 상수는 숫자를 읽는데 문제가 있다. 이렇게 수학을 못하는 상수를 위해서 상근이는 수의 크기를 비교하는 문제를 내주었다. 
상근이는 세 자리 수 두 개를 칠판에 써주었다. 그 다음에 크기가 큰 수를 말해보라고 했다.

상수는 수를 다른 사람과 다르게 거꾸로 읽는다. 예를 들어, 734과 893을 칠판에 적었다면, 
상수는 이 수를 437과 398로 읽는다. 따라서, 상수는 두 수중 큰 수인 437을 큰 수라고 말할 것이다.

두 수가 주어졌을 때, 상수의 대답을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이가 칠판에 적은 두 수 A와 B가 주어진다. 
두 수는 같지 않은 세 자리 수이며, 0이 포함되어 있지 않다.
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
2941번
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
1316번
*/
int fn_GroupWords()
{
	int nIdx = 0;
	int nCount = 0;
	string strWords;

	cin >> nCount;

	if (nCount > 100) {
		return -1;
	}

	for (int i = 0; i < nCount; i++) {
		cin >> strWords;

		if (strWords.length() > 100) {
			continue;
		}

		if (fn_Check_GroupWords(strWords) == 0) {
			nIdx++;
		}
	}
	
	cout << nIdx << endl;

	return 0;
}

int fn_Check_GroupWords(string& strWords)
{
	int nLen = 0;

	std::map<char, char> mAlphabets;

	for (int i = 1; i < strWords.length(); i++) {
		if (i == 1) {
			mAlphabets.insert(std::map<char, char>::value_type(strWords.at(i - 1), strWords.at(i - 1)));
		}

		
		if (strWords.at(i - 1) == strWords.at(i)) {

		}
		else {
			std::map<char, char>::iterator iter = mAlphabets.find(strWords.at(i));
			if (iter == mAlphabets.end()) {
				mAlphabets.insert(map<char, char>::value_type(strWords.at(i), strWords.at(i)));
			}
			else {
				return -1;
			}
			
		}
	}

	return 0;
}
