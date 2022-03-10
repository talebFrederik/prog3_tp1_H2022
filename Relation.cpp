#include "Relation.h"

Relation::Relation(Membre* membre) : m_membre{ membre } {}

Membre* Relation::getMembre() const
{
	return m_membre;
}

bool Relation::isRelation(Membre* membre)
{
	bool existe{ false };
	for (int i = 0; i < m_liens.size(); i++)
	{
		if (m_liens[i]->getId() == membre->getId())
		{
			existe = true;
		}
	}

	return existe;
}

void Relation::ajouterLien(Membre* membre)
{
	if (!isRelation(membre))
	{
		m_liens.push_back(membre);
	}
}

void Relation::supprimerLien(Membre* membre)
{
	if (m_liens.size() > 0)
	{
		int index{ 0 };
		for (int i = 0; i < m_liens.size(); i++)
		{
			if (m_liens[i]->getId() == membre->getId())
			{
				index = i;
			}
		}
		m_liens[index] = nullptr;
		m_liens.erase(m_liens.begin() + index);
	}
}
