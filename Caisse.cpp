#include "Caisse.h"

#include <algorithm>

Caisse::Caisse(int id) :  m_id{ id }{}

void Caisse::ajouterCommande(std::string commande)
{
	for (int i = 0; i < m_abonnes.size(); i++)
	{
		m_abonnes[i]->miseAJour(m_id, { 0, commande });
	}
}

void Caisse::abonner(IAbonne* abonne)
{
	m_abonnes.push_back(abonne);
}

void Caisse::desabonner(IAbonne* abonne)
{
	m_abonnes.erase(std::remove(m_abonnes.begin(), m_abonnes.end(), abonne), m_abonnes.end());
}
