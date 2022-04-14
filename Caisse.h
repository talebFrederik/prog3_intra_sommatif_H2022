#pragma once

#include "Planificateur.h"

#include <string>
#include <vector>

class Caisse
{
private:
	int m_id;
	std::vector<IAbonne*> m_abonnes;
protected:
public:
	Caisse(int);
	void ajouterCommande(std::string);
	void abonner(IAbonne*);
	void desabonner(IAbonne*);
};

