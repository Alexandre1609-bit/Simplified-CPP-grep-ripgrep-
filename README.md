C++ File Finder

  Ce projet est un outil en ligne de commande (CLI) développé en C++ moderne (C++17). Il permet de rechercher récursivement des fichiers dans un répertoire donné en utilisant des mots-clés   ou des expressions régulières (Regex).
  
  L'objectif de ce projet était de maîtriser les bibliothèques standard du C++, notamment la gestion du système de fichiers (<filesystem>) et le traitement avancé des chaînes de caractères.


Fonctionnalités

  Recherche Récursive : Scanne le dossier cible et tous ses sous-dossiers.
  Support Regex : Accepte des mots-clés simples ou des expressions régulières complexes pour filtrer les noms de fichiers.
  Robustesse : Gestion des erreurs (chemins invalides, regex malformés) via des blocs try-catch.
  Affichage Clair : Liste tous les chemins absolus des fichiers correspondants trouvés.


Technologies Utilisées

  Langage : C++ (Standard C++17 requis pour <filesystem>).
  Bibliothèques Standard :
  <filesystem> : Pour l'itération récursive sur les dossiers et la manipulation des chemins.
  <regex> : Pour le filtrage puissant des noms de fichiers.
  <iostream> : Pour les entrées/sorties console.
  <list> : Pour le stockage dynamique des résultats.


Comment ça marche 

  Le cœur du programme réside dans la fonction Finder() :
  
  Saisie Utilisateur :
  
  Demande le chemin du répertoire racine à scanner.
  
  Demande le terme de recherche (mot-clé ou Regex).
  
  Validation :
  
  Vérifie si le chemin existe avec fs::exists().
  
  Nettoie le buffer d'entrée (cin.ignore) pour éviter les erreurs de saisie.
  
  Exploration (Le Moteur) :
  
  Utilise fs::recursive_directory_iterator pour parcourir l'arborescence des fichiers.
  
  Pour chaque fichier trouvé, extrait son nom (filename()).
  
  Filtrage (Le Cerveau) :
  
  Crée un objet std::regex avec le terme de recherche (options : insensible à la casse icase).
  
  Utilise regex_search pour vérifier si le nom du fichier correspond au critère.
  
  Si correspondance, ajoute le chemin complet à une liste std::list.
  
  Affichage :
  
  Itère sur la liste des résultats pour les afficher à l'utilisateur.


Exemple d'Utilisation

  
  Enter the path you want to search in : 
  C:\Users\Alexa\Documents\Projets
  
  Enter what you want to search : 
  .*\.cpp
  
  Résultat(s) : 
  C:\Users\Alexa\Documents\Projets\Main.cpp
  C:\Users\Alexa\Documents\Projets\Utils.cpp
  C:\Users\Alexa\Documents\Projets\Finder.cpp
  (Dans cet exemple, l'utilisateur cherche tous les fichiers finissant par .cpp grâce au regex .*\.cpp)


Compilation et Exécution

  Prérequis
  Un compilateur C++ compatible avec la norme C++17 (GCC 8+, Clang 5+, MSVC 2017+).
  
  Instructions
  Compiler le fichier source :
  
  Bash
  
  g++ -std=c++17 main.cpp -o finder
  (Sous Windows avec MSVC : cl /std:c++17 main.cpp)
  
  Lancer l'exécutable :
  
  Linux/Mac : ./finder
  
  Windows : finder.exe


Ce que j'ai appris

  Ce projet m'a permis de consolider mes connaissances sur :
  
  L'utilisation des Namespaces (namespace fs = std::filesystem).
  
  La gestion des Itérateurs (recursive_directory_iterator).
  
  La manipulation des Flux (cin, getline, ignore).
  
  La gestion des Exceptions (try, catch, std::regex_error).
  
  Les concepts de base du C++ moderne (types auto, boucles for-range).

  

Projet réalisé en autodidacte pour explorer les capacités du C++ moderne.
