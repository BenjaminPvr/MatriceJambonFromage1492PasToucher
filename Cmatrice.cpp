
/************************************
	Constructeur par défaut
*************************************
Entrée		: Rien
Nécessité	: Néant
Sortie		: Rien
Entraîne	: (L'objet en cours est initialisé)
*************************************/
template <class MType>
Cmatrice<MType>::Cmatrice()
{
	uiMATnombreLignes = 0;
	uiMATnombreColonnes = 0;
	ppMTPMATmatrice = NULL;
}


/************************************
	Constructeur de confort
*************************************
Entrée		: Nombre de lignes de la matrice,
				Nombre de colonnes de la matrice,
				Tableau d'éléments pour initialiser la matrice
Nécessité	: (Les dimensions passées en paramètre correspondent aux dimensions du tableau)
Sortie		: Rien
Entraîne	: (L'objet en cours est initialisé à partir des dimensions et du tableau passé en paramètre)
*************************************/
template <class MType>
Cmatrice <MType>::Cmatrice(unsigned int uiNombreLignes, unsigned int uiNombreColonnes, MType ** ppMTPtableau)
{
	uiMATnombreLignes = uiNombreLignes;
	uiMATnombreColonnes = uiNombreColonnes;

	//Allocation tableau 2 dimensions
	ppMTPMATmatrice = new MType*[uiMATnombreLignes];
	for (unsigned int uiBoucle = 0; uiBoucle < uiMATnombreLignes; uiBoucle++)
		ppMTPMATmatrice[uiBoucle] = new MType[uiMATnombreColonnes];

	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < uiMATnombreLignes; uiBoucleLignes++)
		for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < uiMATnombreColonnes; uiBoucleColonnes++)
			ppMTPMATmatrice[uiBoucleLignes][uiBoucleColonnes] = ppMTPtableau[uiBoucleLignes][uiBoucleColonnes];
}

/************************************
	Constructeur de recopie
*************************************
Entrée		: Objet Cmatrice à recopier
Nécessité	: Néant
Sortie		: Rien
Entraîne	: (L'objet en cours est initialisé)
*************************************/
template <class MType>
Cmatrice<MType>::Cmatrice(Cmatrice<MType> & MATparam)
{
	uiMATnombreLignes = MATparam.uiMATnombreLignes;
	uiMATnombreColonnes = MATparam.uiMATnombreColonnes;

	if (MATparam.ppMTPMATmatrice == NULL)
		ppMTPMATmatrice = NULL;
	else
	{
		ppMTPMATmatrice = new MType*[uiMATnombreLignes];
		for (unsigned int uiBoucle = 0; uiBoucle < uiMATnombreLignes; uiBoucle++)
			ppMTPMATmatrice[uiBoucle] = new MType[uiMATnombreColonnes];

		for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < uiMATnombreLignes; uiBoucleLignes++)
			for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < uiMATnombreColonnes; uiBoucleColonnes++)
				ppMTPMATmatrice[uiBoucleLignes][uiBoucleColonnes] = MATparam.ppMTPMATmatrice[uiBoucleLignes][uiBoucleColonnes];
	}
}


/************************************
	Destructeur
*************************************
Entrée		: Rien
Nécessité	: Néant
Sortie		: Rien
Entraîne	: (L'objet en cours est détruit)
			ET (La mémoire allouée à l'objet en cours est libérée)
*************************************/
template <class MType>
Cmatrice<MType>::~Cmatrice()
{
	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < uiMATnombreLignes; uiBoucleLignes++)
		delete [] ppMTPMATmatrice[uiBoucleLignes];
	delete [] ppMTPMATmatrice;
}


/************************************
	Lecteur d'élément de matrice
*************************************
Entrée		: Indice de ligne de l'élément,
				Indice de colonne de l'élément
Nécessité	: Néant
Sortie		: L'élément de la matrice correspondant aux indices spécifiés
Entraîne	: (L'élément souhaité est retourné)
			OU (Une exception est levée en cas d'indice(s) incorrect(s))
*************************************/
template <class MType>
MType Cmatrice<MType>::MATgetElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne) const
{
	if (uiIndiceLigne >= uiMATnombreLignes || uiIndiceColonne >= uiMATnombreColonnes)
	{
		Cexception EXCobjet(ERREUR_INDICE_INCORRECT , "Erreur lecture element : Indice(s) incorrect(s)");
		throw EXCobjet;
	}
	else
		return ppMTPMATmatrice[uiIndiceLigne][uiIndiceColonne];
}


/************************************
	Modificateur d'élément de matrice
*************************************
Entrée		: Indice de ligne de l'élément à modifier,
				Indice de colonne de l'élément à modifier,
				Nouvelle valeur de l'élément
Nécessité	: Néant
Sortie		: Rien
Entraîne	: (L'élément souhaité est modifié avec la nouvelle valeur)
			OU (Une exception est levée en cas d'indice(s) incorrect(s))
*************************************/
template <class MType>
void Cmatrice<MType>::MATsetElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MType MTPelement)
{
	if (uiIndiceLigne >= uiMATnombreLignes || uiIndiceColonne >= uiMATnombreColonnes)
	{
		Cexception EXCobjet(ERREUR_INDICE_INCORRECT , "Erreur modification element : Indice(s) incorrect(s)");
		throw EXCobjet;
	}
	else
		ppMTPMATmatrice[uiIndiceLigne][uiIndiceColonne] = MTPelement;
}


/************************************
	Transposition de matrice
*************************************
Entrée		: Rien
Nécessité	: Néant
Sortie		: Nouvelle Cmatrice, transposée de la Cmatrice courante
Entraîne	: (L'objet en sortie est créé et initialisé par transposition de l'objet courant)
*************************************/
template <class MType>
Cmatrice<MType> Cmatrice<MType>::MATtransposer()
{
	//Tableau 2D temporaire pour stocker les éléments transposés
	MType ** ppMTPelementsTransposes;

	if (uiMATnombreLignes > 0 && uiMATnombreColonnes > 0)
	{
		//Allocation du tableau 2D utilisé pour initialisé la future matrice
		ppMTPelementsTransposes = new MType*[uiMATnombreColonnes];
		for (unsigned int uiBoucle = 0; uiBoucle < uiMATnombreColonnes; uiBoucle++)
			ppMTPelementsTransposes[uiBoucle] = new MType[uiMATnombreLignes];

		//Transposition des éléments de la matrice courante dans le tableau 2D
		for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < uiMATnombreColonnes; uiBoucleLignes++)
			for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < uiMATnombreLignes; uiBoucleColonnes++)
				ppMTPelementsTransposes[uiBoucleLignes][uiBoucleColonnes] = ppMTPMATmatrice[uiBoucleColonnes][uiBoucleLignes];

		//Initialisation de la nouvelle matrice, avec indices inversés et en utilisant le tableau 2D
		Cmatrice<MType> MATmatriceTransposee(uiMATnombreColonnes, uiMATnombreLignes, ppMTPelementsTransposes);
		return MATmatriceTransposee;

		//Désallocation du tableau 2D temporaire
		for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < uiMATnombreColonnes; uiBoucleLignes++)
			delete [] ppMTPelementsTransposes[uiBoucleLignes];
		delete [] ppMTPelementsTransposes;
	}
	else
	{
		/*Si la matrice courante est vide (Au moins un indice nul), 
		 *on renvoie une matrice vide avec des indices nuls via le constructeur par défaut*/
		Cmatrice<MType> MATmatriceTransposee;
		return MATmatriceTransposee; 
	}
}


/************************************
	Surcharge opérateur de sortie standard 
*************************************
Entrée		: Référence sur le flux de sortie
				Matrice d'éléments MType à afficher sur la sortie standard
Nécessité	: Il doit exister une surcharge de l'opérateur "<<" pour MType
Sortie		: Référence sur le flux de sortie représentant la matrice
Entraîne	: (Une représentation de la matrice est affichée sur la sortie standard)
*************************************/
template <class MType> 
ostream & operator<<(ostream& os, Cmatrice<MType> MATparam)
{
	
	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < MATparam.MATgetNbrLignes(); uiBoucleLignes++)
	{
		for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < MATparam.MATgetNbrColonnes(); uiBoucleColonnes++)
			os << MATparam.MATgetElement(uiBoucleLignes, uiBoucleColonnes) << "\t";
		os << endl;
	}
	return os;
}