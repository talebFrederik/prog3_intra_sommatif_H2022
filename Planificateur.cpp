#include "Planificateur.h"

#include <map>
#include <deque>
#include <iterator>
#include <iostream>

Planificateur::Planificateur() {}

void Planificateur::ajouterCaisse(int id)
{
	m_commandes.insert(std::pair<int, std::deque<Commande>>{id, {}});
}

void Planificateur::miseAJour(int id, Commande commande)
{
	m_commandes[id].push_back(commande);
	m_commandes[id].front().priorite = m_commandes[id].size();
}

void Planificateur::produireCommande()
{
	std::map<int, std::deque<Commande>>::iterator it = m_commandes.begin();

	int id{ -1 };
	int prio{ -1 };

	for (std::pair<int, std::deque<Commande>> element : m_commandes)
	{
		if (!element.second.empty())
		{
			if (element.second.front().priorite > prio)
			{
				id = element.first;
				prio = element.second.front().priorite;
			}
		}
	}

	if (id > 0)
	{
		std::cout << m_commandes[id].front().desc << "\n";
		m_commandes[id].pop_front();
	}

	if (!m_commandes[id].empty())
	{
		m_commandes[id].front().priorite = m_commandes[id].size();
	}
}
