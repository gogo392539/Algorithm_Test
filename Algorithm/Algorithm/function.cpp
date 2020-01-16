#include "function.h"
#include "stdafx.h"

/*
[����]
� ���� ���� X�� �ڸ����� ���������� �̷�ٸ�, �� ���� �Ѽ���� �Ѵ�. 
���������� ���ӵ� �� ���� ���� ���̰� ������ ������ ���Ѵ�. 
N�� �־����� ��, 1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

[�Է�]
ù° �ٿ� 1,000���� �۰ų� ���� �ڿ��� N�� �־�����.

[���]
ù° �ٿ� 1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����Ѵ�.
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


