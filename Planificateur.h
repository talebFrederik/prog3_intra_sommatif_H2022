#pragma once

#include "Commmande.h"

#include <string>
#include <map>
#include <deque>


class IAbonne
{
public:
	virtual void miseAJour(int, Commande) = 0;
};

class Planificateur :
	public IAbonne
{
private:
	std::map<int, std::deque<Commande>> m_commandes;
public:
	Planificateur();
	void ajouterCaisse(int);
	void miseAJour(int, Commande);
	void produireCommande();
};

