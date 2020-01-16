#include "function.h"
#include "stdafx.h"

/*
[문제]
어떤 양의 정수 X의 자리수가 등차수열을 이룬다면, 그 수를 한수라고 한다. 
등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. 
N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.

[입력]
첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

[출력]
첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.
*/
int fn_getSequenceCount(int nData)
{
	int nCount = 0;

	if (nData > 1000) {
		return -1;
	}

	if (nData < 100) {
		for (int i = 1; i <= nData; i++) {
			nCount++;
		}
	}
	else {
		nCount = 99;
		int* pChipers = NULL;
		
		for (int i = 100; i <= nData; i++) {
			pChipers = new int[sizeof(int) * 4]{ 0 };
			fn_getChipers(i, &pChipers);
			//cout << pChipers[3] << " " << pChipers[2] << " " << pChipers[1] << " " << pChipers[0] << endl;
			if (((pChipers[2] - pChipers[1]) == (pChipers[1] - pChipers[0])) && pChipers[3] == 0) {
				nCount++;
			}

			if (pChipers != NULL) {
				delete[] pChipers;
				pChipers = NULL;
			}
		}
	}
	cout << nCount << endl;

	return 0;
}

int fn_getChipers(int nData, int** ppszOutData)
{
	int nDividend = 0;
	int nRest = 0;
	int nQuitient = 0;
	int nDivisor = 0;
	int* pChipers = NULL;

	pChipers = *ppszOutData;

	nDivisor = 1000;
	nDividend = nData;
	for (int i = 0; i < 4; i++) {
		nQuitient = nDividend / nDivisor;
		nRest = nDividend % nDivisor;

		if (nQuitient != 0) {
			pChipers[3 - i] = nQuitient;
		}
		else {
			pChipers[3 - i] = 0;
		}

		nDividend = nRest;
		nDivisor /= 10;
		nQuitient = 0;
		nRest = 0;
	//	cout << "TEST : " << narChiper[3 - i] << endl;
	}

	return pChipers[2];
}


