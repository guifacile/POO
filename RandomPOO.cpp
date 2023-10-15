#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Création de la classe Aleatoire
class Aleatoire
{
private:
    int m_valeurGeneree, m_Score, m_Choix, m_Arreter;
    const string m_playerName;
    const int m_Niveau;

public:
    Aleatoire(const string &, const int &);
    ~Aleatoire();

    int Generation(int min, int max)
    {
        srand(time(0)); // Référence horaire
        return rand() % (max - min + 1) + min;
    }

    int Niveau()
    {
        switch (m_Niveau)
        {
        case 1:
            return 10;
        case 2:
            return 7;
        case 3:
            return 6;
        case 4:
            return 3;
        case 5:
            return 2;
        default:
            return 5;
        }
    }

    void Choix()
    {
        do
        {
            int m_nombreMin, m_nombreMax;
            cout << "Bonjour, " << m_playerName << " !" << endl;
            do
            {
                cout << "Donner un nombre minimale: ";
                cin >> m_nombreMin;
                cout << "Donner un nombre maximale: ";
                cin >> m_nombreMax;

                if (m_nombreMin == m_nombreMax)
                {
                    cout << "Choix invalide ! Les nombres minimaux et maximaux doivent être différents." << endl;
                }
                else if (m_nombreMin > m_nombreMax)
                {
                    cout << "Les nombres minimaux et maximaux sont inversés. Veuillez réessayer." << endl;
                }
            } while (m_nombreMin >= m_nombreMax);

            m_valeurGeneree = Generation(m_nombreMin, m_nombreMax);
            int valeurTentative = 0;
            m_Score = Niveau();

            cout << "Votre nombre de tentative est : " << m_Score << endl;

            do
            {
                valeurTentative++;
                cout << "Il vous reste : " << m_Score << " tentative(s)" << endl;
                m_Score--;

                cout << "Choisissez un nombre, entre : " << m_nombreMin << " et " << m_nombreMax << ": ";
                cin >> m_Choix;

                if (m_Choix > m_valeurGeneree)
                {
                    cout << "Le nombre choisi est plus 'GRAND'" << endl;
                }
                else if (m_Choix < m_valeurGeneree)
                {
                    cout << "Le nombre choisi est plus 'PETIT'" << endl;
                }
                else
                {
                    cout << "BINGO !" << endl;
                }
            } while (m_Choix != m_valeurGeneree && m_Score > 0);

            if (m_Choix == m_valeurGeneree)
            {
                cout << "Félicitations ! Vous avez trouvé le nombre en : " << valeurTentative << " tentative(s)." << endl;
            }
            else
            {
                cout << "Désolé ! Le nombre cherché était : " << m_valeurGeneree << endl;
            }

            cout << "Appuyez sur 0 pour arrêter le jeu, sinon 1 pour rejouer : ";
            cin >> m_Arreter;
        } while (m_Arreter != 0);
    }
};

Aleatoire::Aleatoire(const string &playerName, const int &niveau) : m_playerName(playerName), m_Niveau(niveau),
                                                                 m_valeurGeneree(0), m_Score(0), m_Choix(0), m_Arreter(0)
{
    cout << "--- " << playerName << " Bienvenue au jeu des nombres aléatoires ---" << endl;
}

Aleatoire::~Aleatoire() {}

// Corps du programme
int main()
{
    Aleatoire alea("Jean", 4);

    alea.Choix();

    return 0;
}
