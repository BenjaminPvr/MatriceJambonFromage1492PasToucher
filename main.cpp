#include "Cmatrice.h"


void main()
{
	unsigned int uiLignes = 4;
	unsigned int uiColonnes = 3;
	int ** ppiTab = new int*[4];
	for (int i = 0; i < 4; i++)
		ppiTab[i] = new int[3];
	ppiTab[0][0] = 0;
	ppiTab[0][1] = 1;
	ppiTab[0][2] = 2;
	ppiTab[1][0] = 3;
	ppiTab[1][1] = 4;
	ppiTab[1][2] = 5;
	ppiTab[2][0] = 6;
	ppiTab[2][1] = 7;
	ppiTab[2][2] = 8;
	ppiTab[3][0] = 9;
	ppiTab[3][1] = 10;
	ppiTab[3][2] = 11;

	Cmatrice<int> MAT1(uiLignes, uiColonnes, ppiTab);
	try
	{
		cout << MAT1.MATgetElement(0,0) << "\t"
			<< MAT1.MATgetElement(0,1) << "\t"
			<< MAT1.MATgetElement(0,2) << endl
			<< MAT1.MATgetElement(1,0) << "\t"
			<< MAT1.MATgetElement(1,1) << "\t"
			<< MAT1.MATgetElement(1,2) << endl
			<< MAT1.MATgetElement(2,0) << "\t"
			<< MAT1.MATgetElement(2,1) << "\t"
			<< MAT1.MATgetElement(2,2) << endl
			<< MAT1.MATgetElement(3,0) << "\t"
			<< MAT1.MATgetElement(3,1) << "\t"
			<< MAT1.MATgetElement(3,2) << endl << endl;
	}
	catch (Cexception EXCobjet)
	{
		cout << "Erreur code " << EXCobjet.EXClireValeur() << " : " << EXCobjet.EXClireMessage() << endl;
	}

	Cmatrice<int> MAT2 = MAT1.MATtransposer();
	cout << MAT2.MATgetElement(0,0) << "\t"
		<< MAT2.MATgetElement(0,1) << "\t"
		<< MAT2.MATgetElement(0,2) << "\t"
		<< MAT2.MATgetElement(0,3) << endl
		<< MAT2.MATgetElement(1,0) << "\t"
		<< MAT2.MATgetElement(1,1) << "\t"
		<< MAT2.MATgetElement(1,2) << "\t"
		<< MAT2.MATgetElement(1,3) << endl
		<< MAT2.MATgetElement(2,0) << "\t"
		<< MAT2.MATgetElement(2,1) << "\t"
		<< MAT2.MATgetElement(2,2) << "\t"
		<< MAT2.MATgetElement(2,3) << endl << endl;

	cout << "Mat1 : " << endl << MAT1 << endl << endl << "Mat2: " << endl << MAT2 << endl;

}

