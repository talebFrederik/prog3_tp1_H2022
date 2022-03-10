#include "Reseau.h"

#include <iostream>

Membre* Reseau::getMembreParId(std::string id)
{
	Membre* tempMembre{ nullptr };
	for (int i = 0; i < m_membres.size(); i++)
	{
		if (m_membres[i]->getId() == id)
		{
			tempMembre = m_membres[i];
		}
	}
	return nullptr;
}

Relation* Reseau::getRelationMembreActuel()
{
	Relation* tempRelation{ nullptr };
	if (m_membreActuel)
	{
		int index{ 0 };
		while (!tempRelation && index < m_relations.size())
		{
			if (m_relations[index]->getMembre()->getId() == m_membreActuel->getId())
			{
				tempRelation = m_relations[index];
			}
			index++;
		}
	}
	return tempRelation;
}

FileMessage* Reseau::getFileMessageParIds(std::string id1, std::string id2)
{
	FileMessage* tempFile{ nullptr };
	for (int i = 0; i < m_filesMessages.size(); i++)
	{
		if (m_filesMessages[i]->isFileMessage(id1, id2))
		{
			tempFile = m_filesMessages[i];
		}
	}
	return tempFile;
}

Reseau::Reseau() : m_membreActuel{ nullptr } {}

Reseau::~Reseau()
{
	for (int i = 0; i < m_membres.size(); i++)
	{
		delete m_membres[i];
		m_membres[i] = nullptr;
	}
	for (int i = 0; i < m_relations.size(); i++)
	{
		delete m_relations[i];
		m_relations[i] = nullptr;
	}
	for (int i = 0; i < m_filesMessages.size(); i++)
	{
		delete m_filesMessages[i];
		m_filesMessages[i] = nullptr;
	}
}

bool Reseau::isMembre(std::string id)
{
	bool existe{ false };
	for (int i = 0; i < m_membres.size(); i++)
	{
		if (m_membres[i]->getId() == id)
		{
			existe = true;
		}
	}

	return existe;
}

void Reseau::ajouterMembre(std::string prenom, std::string nom, std::string dateNaissance)
{
	Membre* tempMembre{ new Membre{ prenom, nom, dateNaissance } };
	m_membres.push_back(tempMembre);
	m_relations.push_back(new Relation(tempMembre));
	tempMembre = nullptr;
}

void Reseau::supprimerMembre(std::string id)
{
	if (m_membres.size() > 0)
	{
		int index{ 0 };
		for (int i = 0; i < m_membres.size(); i++)
		{
			if (m_membres[i]->getId() == id)
			{
				index = i;
			}
		}
		m_membres[index] = nullptr;
		m_membres.erase(m_membres.begin() + index);
	}
}

void Reseau::seConnecter(std::string id)
{
	if (!m_membreActuel)
	{
		for (int i = 0; i < m_membres.size(); i++)
		{
			if (m_membres[i]->getId() == id)
			{
				m_membreActuel = m_membres[i];
			}
		}
	}
}

void Reseau::seDeconnecter()
{
	m_membreActuel = nullptr;
}

bool Reseau::isLien(std::string id)
{
	bool existe{ false };

	Relation* tempRelation{ getRelationMembreActuel() };
	Membre* tempMembre{ getMembreParId(id) };

	if (tempRelation && tempMembre)
	{
		existe = tempRelation->isRelation(tempMembre);
	}

	return existe;
}

void Reseau::ajouterLien(std::string id)
{
	Membre* tempMembre{ getMembreParId(id) };

	if (tempMembre && !isLien(id))
	{
		getRelationMembreActuel()->ajouterLien(tempMembre);
		m_filesMessages.push_back(new FileMessage(m_membreActuel, tempMembre));
	}

	tempMembre = nullptr;
}

void Reseau::supprimerLien(std::string id)
{
	Membre* tempMembre{ getMembreParId(id) };
	if (tempMembre && isLien(id))
	{
		getRelationMembreActuel()->supprimerLien(tempMembre);
	}
}

void Reseau::envoyerMessage(std::string idDestinataire, std::string message)
{
	if (m_membreActuel && isLien(idDestinataire))
	{
		getFileMessageParIds(m_membreActuel->getId(), idDestinataire)->recevoirMessage(m_membreActuel, message);
	}
}

void Reseau::lireMessages(std::string idLien)
{
	if (m_membreActuel && isLien(idLien))
	{
		getFileMessageParIds(m_membreActuel->getId(), idLien)->AfficherMessages();
	}
}

void Reseau::afficherMembres()
{
	for (int i = 0; i < m_membres.size(); i++)
	{
		std::cout << m_membres[i]->getNomComplet() << " : " << m_membres[i]->getId() << "\n";
	}
}


