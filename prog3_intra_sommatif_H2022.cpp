
#include <iostream>

#include "Caisse.h"
#include "Planificateur.h"

int main()
{
	// Initialisation du système avec 3 caisses
	Caisse caisse1{ 1 };
	Caisse caisse2{ 2 };
	Caisse caisseAuto{ 3 };

	Planificateur planif;
	Planificateur* ptr_planif{ &planif };

	planif.ajouterCaisse(1);
	planif.ajouterCaisse(2);
	planif.ajouterCaisse(3);

	// Connexion des caisses pour la mise à jour
	caisse1.abonner(ptr_planif);
	caisse2.abonner(ptr_planif);
	caisseAuto.abonner(ptr_planif);

	// Test des opérations du système
	caisse1.ajouterCommande("Le Big Mac");
	caisse1.ajouterCommande("Royal with cheese");
	caisse2.ajouterCommande("Big Kahuna burger");
	caisseAuto.ajouterCommande("Cornerstone of any nutritious breakfast");
	caisseAuto.ajouterCommande("Pork tastes good");

	for (int i = 0; i < 5; i++)
	{
		planif.produireCommande();
	}

	planif.miseAJour(1, { 10, "FIN" });
}
