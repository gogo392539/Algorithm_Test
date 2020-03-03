#include "stdafx.h"
#include "math.h"
#include <algorithm>


int fn_BreakEvenPoint()
{
	int nFixedCost = 0;
	int nVariableCost = 0;
	int nSellingPrice = 0;
	int nIdx = 0;
	int nResult = 0;

	cin >> nFixedCost >> nVariableCost >> nSellingPrice;

	if ((nSellingPrice - nVariableCost) <= 0) {
		cout << -1 << endl;
		return -1;
	}

	nResult = (int)(nFixedCost / (nSellingPrice - nVariableCost)) + 1;
	cout << nResult << endl;

	return 0;
}

int fn_Sugar()
{
	int nN = 0;
	int nIdx = 0;
	int nData = 0;
	int nData1 = 0;

	cin >> nN;

	if (!(nN % 5)) {
		nData = nN / 5;
	}
	else if (!(nN % 3)) {
		nData = nN / 3;
	}

	nIdx = 1;
	while (nN >= (nIdx * 5)) {
		if (!((nN - (nIdx * 5)) % 3)) {
			nData1 = ((nN - (nIdx * 5)) / 3) + nIdx;
		}
		nIdx++;
	}

	if (!nData && !nData1) {
		cout << -1 << endl;
	}
	else if (!nData) {
		cout << nData1 << endl;
	}
	else if (!nData1) {
		cout << nData << endl;
	}
	else {
		cout << min(nData, nData1) << endl;
	}
	
	return 0;
}

int fn_Hive()
{
	int nIndex = 0;
	int nResultData = 0;
	int nInputData = 0;

	cin >> nInputData;

	nIndex = 1;
	while (1) {
		nResultData = 1 + (3 * (nIndex * (nIndex - 1)));

		if (nResultData >= nInputData) {
			cout << nIndex << endl;
			break;
		}

		nIndex++;
	}

	return 0;
}

int fn_Find_A_Fraction()
{
	int nIndex = 0;
	int nResultData = 0;
	int nDenominator = 0;
	int nNumerator = 0;
	int nInputData = 0;
	char szResult[20] = { 0, };

	cin >> nInputData;

	while(1) {

	}



	return 0;
}
