#include <iostream>
#include <list>
#include <filesystem>
#include <regex>
#include <limits>
using namespace std;

namespace fs = std::filesystem;


static void Finder() {
    std::string path;
    std::cout << std::endl;
    std::cout << "Enter the path you want to search in : " << std::endl;
    std::getline(std::cin, path);

    std::string keyword;
    std::cout << std::endl;
    std::cout << "Enter what you want to search : " << std::endl;
    std::cin >> keyword;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    fs::path filePath = path;
    list<string> kW = {};

    if (!fs::exists(path)) {
        std::cerr << "File not found" << std::endl;
    } else {
     try {
        for (const auto& word : fs::recursive_directory_iterator(path)) {
            fs::path fileOnly = word.path().filename();
            std::string FileNameOnly = fileOnly.string();

            std::regex self_regex(keyword, std::regex_constants::ECMAScript | std::regex_constants::icase);
            if (regex_search(FileNameOnly, self_regex)){
                cout << "Résultat(s) : \n";
                kW.push_front(word.path().string());
               }
          }
            
        }
        catch(const std::regex_error& e)  {
          std::cerr << "ERREUR : recherche impossible" << keyword << " n'est pas un regex valide.\n";
          std::cerr << "Détail technique : " << e.what() << std::endl;
        }

    }
    for (const auto& entry : kW) {
        cout << entry << "\n";
    }
}



int main() {

    Finder();




    return 0;


}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
     /*cout << "Hello World!\n"
        << "Je suis Alexandre et je vais réussir."
        << endl
        << "Saut de ligne"
        << std::endl
        << "Autre méthode de saut de ligne." << "\n"
        << "Je peux aussi faire comme ça" << "\n"
        << "Salut\n"
        << "--------------------"
        << std::endl
        << "Je peux aussi faire ça : ne mettre qu'un seul cout et finir avec une ; au cout final."
        << std::endl
        << "D'ailleurs, COUT signifie Character Output !"
        << endl
        << 42 << "Est un nombre, je n'ai pas besoin de le mettre en guillement quand je cout"
        << endl
        << "un autre nombre est  : " << 3.314;*/



        /*bool isAlive { false }; //Le monstre est-il en vie ? Possibilité d'initialiser "isAlive" en une ligne
        // Définir "isAlive" en 2 lignes : isAlive = false; 
        int Health { 100 };
        float Armure { 0.4 };*/

        /*cout << "Le monstre est : " << Name
             << endl
             << "Il est actuellement level " << Level
             << std::endl;*/

        //un "float" est un nombre décimal, du genre Float Armor { 0.4 };

        //int GrandNombre { 100'000'000 }; //Utilisation de l'apostrophe pour facilité la lisibilité des grands nombres.
        //int Level = 1;
        //int LevelUp = Level++;
        // Si je veux initialiser mon niveau je peux très bien faire : int Level { 1 } ou encore int Level { 5 + 1 }; Je peux redéfinir après : Level = 5*2...;
        //L'ordre des opérations est le même qu'en maths : parenthèses puis multiplication / division puis le reste.
        // Exemple si je veux initialiser le niveau 7 : int Level { 1 + 3 * 2 };
        //Ou encore int Level { (1 + 2) * 3 } pour le level 9 par exemple.

       /*bool isAlive { false };
       if (!isAlive)
       {
        cout << "Vous êtes en vie ! "
             << std::endl;
       } else {
        cout << "Vous êtes mort ! ";
       }*/

       /*
       int8_t Level{ 50 }; ici je décide d'attribuer 8 bits à cette variable, donc de -128 à 127. De ce que je comprends
       je ne pourrais pas dépasser le niveau 127 avec 8 bits. Dans ce cas la je devrais utiliser int16_t, int32_t ou int64_t pour attribuer
       plus de mémoire afin de pouvoir stocker de plus grandes valeurs.

       int8_t SmallNumber{100};
       int16_t MediumNumber{10'000};
       int32_t LargeNumber{1'000'000'000};
       int64_t HugeNumber{1'000'000'000'000'000'000};
       */
       
       /*on peut utiliser "short" pour les petits nombres du genre 100 ou int pour les moyen (10'000) ou encore long pour les grands (1'000'000'000)
       short SmallNumber{100};
       int MediumNumber{10'000};
       long LargeNumber{1'000'000'000};
       */

       /*
        Possible de faire des overflow de mémoire en dépassant la limite de bits disponible :
        int Number{2'000'000'000};
        Number += 1'000'000'000;
        cout << Number;

        -1294967296

        Possible de manipuler la mémoire pour programmer des actions indésirables ? (Cf: BufferOverflow??)
        */

        //Existance des "unsigned integrer" qui permettent d'éliminer les possibilités négatives (pas de -126565) juste du +; Cependant mieux d'uitliser des bits plus grand du genre int64_t;


        /*note : 
        "We saw how 8 bits of memory can store 256 different possible values. But what range of integers should we map to those options?

        Most integer types are signed, meaning they can store negative values. 
        If we map our 256 possibilities to a range that includes the same quantity of negative and non-negative numbers,
        an 8-bit signed integer can store values in the range of -128 to 127:" 
        */

        //Pour la version "unsigned" qui permet de faire sauter les nb négatifs il suffit d'ajouter un "u" devant : uint8_t. Avec ça 8 bits valent 0 à 255 au lieu de -128 à 127;

        /* erreur avec les unsigned, les overflow sont plus fréquents, c'est risqué car on travail avec des nombres proche de 0 ex: 
        
        unsigned int Health { 0 };
        Health -= 1; 
        cout << Health;

        4294967295
        */

        /*pour les chiffres à virgule : As with basic integers, the C++ specification doesn't specify how many bits should be allocated but, in practice, 
        it's usually 32 bits for a float and 64 bits for a double. This means a double is more precise than a float at the expense of consuming more memory.
        float A{3.14};
        double B{9.8};


        par défaut cout nous donnes les 6 premiers chiffres après la virgule mais on peut demander à être plus précis avec "cout.precision(16) par exemple.
        
        
        " // Cause cout to show more decimal places
          // when outputting floating point numbers
            cout.precision(16);

          float A { 1.1111111111111111 };
          cout << "Float Precision:  "
               << A + A << '\n';

            double B { 1.1111111111111111 };
            cout << "Double Precision: "
                 << B + B;""

        */

        /* "Ternary operator" ou  "Opérateur ternaire" "?"
        manière plus concise de crée ce if : if (isDead) {
  DropLoot();
    } else {
    Attack();
    } on peut le faire avec "?"
    isDead ? DropLoot() : Attack();
    Après le isDead ? 
    DropLoot() intervient si c'est true et après les ":" n'interviendra seulement si c'est false.*/ 



