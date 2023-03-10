#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
    // your code
};

struct DynaTableau{
    int* donnees;
    // your code
    int capacite;
    int taille = 0;
};


void initialise(Liste* liste)
{
    liste->premier = nullptr;
}

bool est_vide(const Liste* liste)
{
    if(liste->premier == nullptr){
        return true;
    }
    return false;
}

void ajoute(Liste* liste, int valeur)
{
    Noeud* newNoeud = new Noeud;
    newNoeud->donnee = valeur;
    newNoeud->suivant = nullptr;

    Noeud* tempo = liste->premier;

    if(tempo != nullptr){
        while (tempo->suivant != nullptr)
        {
            tempo = tempo->suivant;
        }
        tempo->suivant = newNoeud;
    }else{
        liste->premier = newNoeud;
    }

}

void affiche(const Liste* liste)
{
    Noeud* affichage = liste->premier;
    while (affichage != nullptr)
    {
        cout << affichage->donnee << ", ";
        affichage = affichage->suivant;
    }
    cout << endl;

}

int recupere(const Liste* liste, int n)
{
    Noeud* tempo = liste->premier;
    for(int i = 0; i < n; i++){
        tempo = tempo->suivant;
    }
    return tempo->donnee;
}

int cherche(const Liste* liste, int valeur)
{
    Noeud* tempo = liste->premier;
    int count = 1;
    while(tempo->donnee != valeur && tempo != nullptr){
        tempo = tempo->suivant;
        count++;
    }
    if(tempo == nullptr){
        return -1;
    }else{
        return count;
    }
}

void stocke(Liste* liste, int n, int valeur)
{
    Noeud* tempo = liste->premier;
    int i = 1;
    while(i!=n && tempo != nullptr){
        tempo = tempo->suivant;
        i++;
    }
    if(tempo != nullptr){
        tempo->donnee = valeur;
    }
}

void ajoute(DynaTableau* tableau, int valeur)
{
    if(tableau->taille >= tableau->capacite){
        tableau->capacite = tableau->capacite*2;

        int* newTab = new int[tableau->capacite];
        for(int i = 0; i < tableau->taille; i++) {
            newTab[i] = tableau->donnees[i];
        }
        delete[] tableau->donnees;
        tableau->donnees = newTab;
    }

    tableau->donnees[tableau->taille] = valeur;
    tableau->taille = tableau->taille + 1;
}


void initialise(DynaTableau* tableau, int capacite)
{
    tableau->donnees = new int[capacite];
    tableau->capacite = capacite;
}

bool est_vide(const DynaTableau* tableau)
{
    if(tableau->taille == 0){
        return true;
    }
    return false;
}

void affiche(const DynaTableau* tableau)
{
    for(int i = 0; i < tableau->taille; i++){
        cout << tableau->donnees[i] << ", ";
    }
    cout << endl;
}

int recupere(const DynaTableau* tableau, int n)
{
    if(n>=tableau->taille){
        return 0;
    }else{
        return tableau->donnees[n];
    }
}

int cherche(const DynaTableau* tableau, int valeur)
{
    int count = 0;
    while(tableau->donnees[count] != valeur && count<tableau->taille){
        count++;
    }
    if(count >= tableau->taille){
        return -1;
    }else{
        return count+1;
    }
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    tableau->donnees[n-1] = valeur;
}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{
    ajoute(liste, valeur);
}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    Noeud *tempo = liste->premier;
    if(tempo!=nullptr){
        int valeur = tempo->donnee;
        liste->premier = tempo->suivant;
        delete tempo;
        return valeur;
    }else{
        return -1;
    }
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{
    ajoute(liste, valeur);
}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    Noeud *tempo = liste->premier;
    int valeur;

    if(tempo != nullptr && tempo->suivant == nullptr){
        valeur = tempo->donnee;
        delete tempo;
        liste->premier = nullptr;
        return valeur;
    }

    if(tempo != nullptr && tempo->suivant != nullptr){
        while (tempo->suivant->suivant != nullptr)
        {
            tempo = tempo->suivant;
        }
        valeur = tempo->suivant->donnee;

        delete tempo->suivant;
        tempo->suivant = nullptr;
        return valeur;
    }else{
        return -1;
    }
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
