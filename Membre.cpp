#include "Membre.h"
#include <string>
#include <random>

Membre::Membre(std::string prenom, std::string nom, std::string dateNaissance) :
    m_prenom{ prenom }, m_nom{ nom }, m_dateNaissance{ dateNaissance }
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(10, 99);

    m_id = m_nom[0] + m_prenom.substr(0, 3) + m_dateNaissance + std::to_string(dist(rng));
}

std::string Membre::getId()
{
    return m_id;
}

std::string Membre::getNomComplet()
{
    return m_prenom + " " + m_nom;
}