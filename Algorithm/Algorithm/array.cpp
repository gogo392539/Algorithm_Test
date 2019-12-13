#include "array.h"
#include "stdafx.h"

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
		//cout << dPercent << endl;

		//printf("%.3f\n", dPercent);
	}

	for (int i = 0; i < nCount; i++) {

		printf("%.3f%% \n", darPercents[i]);
	}


	return 0;
}
