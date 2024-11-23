#include <iostream>

// fonction pour calculer la longueur d'une chaine caractere
int longueur(const char* chaine) {
    int longueur = 0;
    while (chaine[longueur] != '\0')
    {//tant que le caractere n'est pas le caratere nul
        longueur++;
    }
    return longueur;

}
// une fonction pour copier les chaines de caractere
void copie(char* dest, const char* source) { // pour copier chaque caractere de source vers dest(pour destination)
    int i = 0;
    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0'; // ajouter le caractere nul a la fin de la chaine destination
}
//fonction pour concatener la chaine
void concatene(char* dest, const char* source) {
    int i = longueur(dest); // pour trouver la fin de dest
    int j = 0;
    while (source[j] != '\0')
    {
        dest[i] = source[j];
        i++;
        j++;
    }
    dest[i] = '\0'; //pour ajouter le caratere nul a la fin de la chaine concatenee

}
//Fonction de comparaison lexicographique de deux chaines
int compare(const char* chaine1, const char* chaine2) {
    while (*chaine1 != '\0' && *chaine2 != '\0') {
        if (*chaine1 != *chaine2) {
            return (unsigned char)(*chaine1) - (unsigned char)(*chaine2);
        }
        chaine1++;
        chaine2++;
    }
    return (unsigned char)(*chaine1) - (unsigned char)(*chaine2);

}

// fonction pour chercher un caractere dans une chaine
char* cherche_char(const char* chaine, char caractere) {
    while (*chaine != '\0')
    {
        if (*chaine == caractere) {
            return const_cast<char*>(chaine); // Retourne un pointeur vers la premiere occurence
        }
        chaine++;
    }
    return nullptr; // caractere non trouve

}
//fonction pour inverser une chaine
void inverse(char* chaine) {
    size_t debut = 0;
    size_t fin = longueur(chaine) - 1;
    while (debut < fin) {
        //Echange des caracteres
        char temp = chaine[debut];
        chaine[debut] = chaine[fin];
        chaine[fin] = temp;

        debut++;
        fin--;
    }
}

// fonction pour convertir une chaine en majuscule
void to_upper(char* chaine) {
    while (*chaine != '\0')
    {
        *chaine = toupper(*chaine); // Convertit le caractere courant en majuscule
        chaine++;
    }

}
// fonction pour convertir en miniscule
void to_lower(char* chaine) {
    while (*chaine != '\0')
    {
        *chaine = tolower(*chaine); // Convertit le caractere courant en miniscule
        chaine++;
    }
}

//fonction pour rechercher mot dans une phrase
char* cherche_mot(const char* phrase, const char* mot) {
    const char* p_phrase = phrase; // Pointeur sur la phrase
    const char* p_mot = mot; // Pointeur sur mot

    while (*p_phrase != '\0') {
        const char* debut = p_phrase; // Retient le point de depart
        p_mot = mot; // Reinitialise le pointeur du mot

        // comparer les caracteres de la phrase et du mot
        while (*p_phrase != '\0' && *p_mot != '\0' && *p_phrase == *p_mot)
        {
            p_phrase++;
            p_mot--;
        }
        // Si on parcours tout le mot on trouve la correspondance
        if (*p_mot == '\0') {
            return const_cast<char*>(debut);
        }
        // sinon on reprend a la prochaine position dans la phrase
        p_phrase = debut + 1;

    }
    // si aucune correspondance n'a ete trouvee
    return nullptr;

}


// fonction main pour tester les fonctions
int main() {
    // test avec differents chaines de caracteres meme celle vide
    const char* test1 = "Bonjour";
    const char* test2 = "Le C++ est tres amusant";
    const char* test3 = ""; // la chaine vide
    const char* test4 = "1234567891011121314151617";
    const char* test5 = "Le professeur de game programming est un genie";


    //test pour la fonction copie
    const char* source1 = "Bonjour ";
    const char* source2 = "Le C++ est tres amusant";
    const char* source3 = ""; // la chaine vide
    const char* source4 = "1234567891011121314151617 :";
    const char* source5 = " Le professeur de game programming est un genie";

    // creation des buffers pour les chaines copiees
    char dest1[100];
    char dest2[100];
    char dest3[100];
    char dest4[100];
    char dest5[100];

    //copie des chaines de caratere
    copie(dest1, source1);
    copie(dest2, source2);
    copie(dest3, source3);
    copie(dest4, source4);
    copie(dest5, source5);



    //affiche les resultats pour la longueur
    std::cout << "-AFFICHAGE DES LONGUEURS DE CHAINE :" << std::endl;

    std::cout << "Longueur de \"" << test1 << "\": " << longueur(test1) << std::endl;

    std::cout << "Longueur de \"" << test2 << "\": " << longueur(test2) << std::endl;

    std::cout << "Longueur de \"" << test3 << "\": " << longueur(test3) << std::endl;

    std::cout << "Longueur de \"" << test4 << "\": " << longueur(test4) << std::endl;

    std::cout << "Longueur de \"" << test5 << "\": " << longueur(test5) << std::endl;

    // resultats pour les copies
    std::cout << "-AFFICHAGE DES COPIES DE CHAINE : " << std::endl;

    std::cout << "Source: \"" << source1 << "\", Copie: \"" << dest1 << "\"" << std::endl;

    std::cout << "Source: \"" << source2 << "\", Copie: \"" << dest2 << "\"" << std::endl;

    std::cout << "Source: \"" << source3 << "\", Copie: \"" << dest3 << "\"" << std::endl;

    std::cout << "Source: \"" << source4 << "\", Copie: \"" << dest4 << "\"" << std::endl;

    std::cout << "Source: \"" << source5 << "\", Copie: \"" << dest5 << "\"" << std::endl;

    //concatenation
    concatene(dest1, source2);
    std::cout << "Apres concatenation de source2: \"" << dest1 << "\"" << std::endl;

    concatene(dest2, source3);
    std::cout << "Apres concatenation de source3: \"" << dest2 << "\"" << std::endl;

    concatene(dest4, source5);
    std::cout << "Apres concatenation de source5: \"" << dest4 << "\"" << std::endl;

    std::cout << " Affichage de dest1 : " << dest1 << std::endl;
    std::cout << " Affichage de dest4 : " << dest4 << std::endl;

    // comparaison
    int  result = compare(test1, test2);
    std::cout << "  Comparaison de test1 et test2: ";
    if (result == 0) {
        std::cout << "  Les chaines sont egales. " << std::endl;
    }
    else if (result > 0) {
        std::cout << "test1 est plus  grand que test2." << std::endl;
    }
    else {
        std::cout << "test1 est plus petit que test2." << std::endl;
    }

    result = compare(test2, test3);
    std::cout << "Comparaison de test2 et test3: ";
    if (result == 0) {
        std::cout << "Les chaines sont egales. " << std::endl;
    }
    else if (result > 0) {
        std::cout << "test2 est plus  grand que test3." << std::endl;
    }
    else {
        std::cout << "test2 est plus petit que test3." << std::endl;
    }

    // chercher le caractere
    char caractere = 'e';
    char* position = cherche_char(test2, caractere);
    if (position) {
        std::cout << "Caractere'" << caractere << "' trouve a la position : " << (position - test2) << " dans \"" << test2 << "\"" << std::endl;
    }
    else {
        std::cout << "Caractere '" << caractere << "' non trouve dans \"" << test2 << "\"" << std::endl;
    }

    // test inverse , on utilise le dest1 = test1 + test2
    std::cout << "Chaine avant inversion : " << dest1 << std::endl;
    inverse(dest1);
    std::cout << "Chaine apres inversion : " << dest1 << std::endl;

    // test de conversion en majuscule
    to_upper(dest4);
    std::cout << "Dest4 en majuscule est : " << dest4 << std::endl;

    // tesr de conversion en miniscule
    to_lower(dest1);
    std::cout << "Dest1 en miniscule est : " << dest1 << std::endl;

    // recherche de mot
    const char* mot = "genie";
    char* emplacement = cherche_mot(dest5, mot);

    if (emplacement != nullptr) {
        std::cout << "Le mot \"" << mot << "\" a ete trouve a l'emplacement : " << emplacement - dest5 << std::endl;
    }
    else {
        std::cout << "Le mot \"" << mot << "\" n'a pas ete trouve.Merci! " << std::endl;
    }


    return 0;
}
