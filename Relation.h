#pragma once

#include "Membre.h"

#include <vector>

class Relation
{
private:
	Membre* m_membre;
	std::vector<Membre*> m_liens;
public:
	Relation(Membre*);
	Membre* getMembre() const;
	bool isRelation(Membre*);
	void ajouterLien(Membre*);
	void supprimerLien(Membre*);
};

