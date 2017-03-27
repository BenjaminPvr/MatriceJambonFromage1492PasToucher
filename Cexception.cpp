#include "Cexception.h"


/************************************
	Constructeur par défaut
*************************************
Entrée		: Rien
Nécessité	: Néant
Sortie		: Rien
Entraîne	: (L'objet en cours est initialisé)
*************************************/
Cexception::Cexception()
{
	pcEXCMessage = NULL;
}


/************************************
	Constructeur à deux arguments
*************************************
Entrée		: La valeur de l'erreur et un message d'erreur
Nécessité	: Néant
Sortie		: Rien
Entraîne	: (L'objet en cours est initialisé par copie des paramètres)
*************************************/
Cexception::Cexception(unsigned int Valeur, const char * Message)
{
	uiEXCValeur = Valeur;
	pcEXCMessage = _strdup(Message);
}


/************************************
	Constructeur de recopie
*************************************
Entrée		: L'objet Cexception à recopier
Nécessité	: Néant
Sortie		: Rien
Entraîne	: (L'objet en cours est initialisé par copie du paramètre)
*************************************/
Cexception::Cexception(Cexception & EXCParam)
{
	uiEXCValeur = EXCParam.uiEXCValeur;
	if (EXCParam.pcEXCMessage != NULL)
		pcEXCMessage = _strdup(EXCParam.pcEXCMessage);
	else
		pcEXCMessage = NULL;
}


/************************************
	Destructeur
*************************************/
Cexception::~Cexception()
{
	if (pcEXCMessage != NULL)
		delete pcEXCMessage;
}


/************************************
	Surcharge de l'opérateur d'affectation
*************************************
Entrée		: L'objet Cexception à copier
Nécessité	: Néant
Sortie		: L'objet à modifier, modifié par copie de l'objet d'entrée
Entraîne	: (L'objet en cours est modifié par copie du contenu du paramètre)
*************************************/
Cexception & Cexception::operator=(Cexception EXCParam)
{
	uiEXCValeur = EXCParam.uiEXCValeur;

	if (pcEXCMessage != NULL)
		delete pcEXCMessage;
	if (EXCParam.pcEXCMessage != NULL)
		pcEXCMessage = _strdup(EXCParam.pcEXCMessage);
	else
		pcEXCMessage = NULL;

	return *this; 
}

