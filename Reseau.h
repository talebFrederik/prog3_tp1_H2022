#pragma once

#include "Membre.h"
#include "Relation.h"
#include "FileMessage.h"

#include <vector>

class Reseau
{
private:
	std::vector<Membre*> m_membres;
	std::vector<Relation*> m_relations;
	std::vector<FileMessage*> m_filesMessages;
	Membre* m_membreActuel;
	Membre* getMembreParId(std::string);
	Relation* getRelationMembreActuel();
	FileMessage* getFileMessageParIds(std::string, std::string);
public:
	Reseau();
	~Reseau();
	bool isMembre(std::string);
	void ajouterMembre(std::string, std::string, std::string);
	void supprimerMembre(std::string);
	void seConnecter(std::string);
	void seDeconnecter();
	bool isLien(std::string);
	void ajouterLien(std::string);
	void supprimerLien(std::string);
	void envoyerMessage(std::string, std::string);
	void lireMessages(std::string);
	void afficherMembres();
};

