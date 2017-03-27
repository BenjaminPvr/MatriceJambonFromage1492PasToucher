#pragma once
#include <stdio.h>
#include <string.h>

#ifndef CEXCEPTION_H
#define CEXCEPTION_H

class Cexception
{
private:
	unsigned int uiEXCValeur;	//Valeur de l'exception
	char * pcEXCMessage;		//Message de l'exception

public:
	//Constructeurs et destructeur
	Cexception();
	Cexception(unsigned int Valeur, const char * Message);
	Cexception(Cexception & EXCParam);
	~Cexception();

	//Accesseurs uiEXCValeur
	unsigned int EXClireValeur() const 
		{ return uiEXCValeur; }
	void EXCecrireValeur(unsigned int uiValeur) 
		{ uiEXCValeur = uiValeur; }

	//Accesseurs pcEXCMessage
	char * EXClireMessage() const 
		{ return pcEXCMessage; }
	void EXCecrireMessage(const char * pcMessage);

	//Surcharge de l'opérateur '='
	Cexception & operator=(Cexception EXCParam);
};

inline void Cexception::EXCecrireMessage(const char * pcMessage)
{
	if (pcEXCMessage != NULL)
		delete pcEXCMessage;
	pcEXCMessage = _strdup(pcMessage);
}


#endif // !CEXCEPTION_H
