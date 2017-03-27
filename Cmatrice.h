#pragma once
#include "Cexception.h"
#include <iostream>
using namespace std;




#ifndef CMATRICE_H
#define CMATRICE_H

#define ERREUR_INDICE_INCORRECT 100

template <class MType> class Cmatrice
{
private:
	unsigned int uiMATnombreLignes;
	unsigned int uiMATnombreColonnes;
	MType ** ppMTPMATmatrice;


public:
	//Constructeurs et destructeur
	Cmatrice();
	Cmatrice(unsigned int uiNombreLignes, unsigned int uiNombreColonnes, MType ** ppMTPtableau);
	Cmatrice(Cmatrice<MType> & MATparam);
	~Cmatrice(void);

	//Accesseurs
	unsigned int MATgetNbrLignes() const
		{ return uiMATnombreLignes; }
	unsigned int MATgetNbrColonnes() const
		{ return uiMATnombreColonnes; }

	MType MATgetElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne) const;
	void MATsetElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MType MTPelement);

	//Méthode
	Cmatrice<MType> MATtransposer();

	//Surcharges d'opérateurs
	template <class ConstantType> Cmatrice<MType> operator*(ConstantType CTPconstante);
	template <class ConstantType> Cmatrice<MType> operator/(ConstantType CTPconstante);

	Cmatrice<MType> operator+(Cmatrice<MType> MATparam);
	Cmatrice<MType> operator-(Cmatrice<MType> MATparam);
	Cmatrice<MType> operator*(Cmatrice<MType> MATparam);
};

//Surcharges d'opérateurs
template <class MType> ostream & operator<<(ostream& os, Cmatrice<MType> MATparam);

#include "Cmatrice.cpp"

#endif //CMATRICE_H
