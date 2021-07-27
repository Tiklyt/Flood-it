# flood-it

## g52816

### documentation

#### documentation complète 

ko

#### pas de documentation fournie ni de fichier de configuration pour doxygen

(void)

#### fichiers pas documentés => énumérations et fonctions absentes de la doc générée

vrai mais la documentation de l'enum Color est quand même là (?)

#### pas de documentation pour les classes / méthodes

+ les classes MainWindow, Observable et Observer ne sont pas documentées

### code

#### C++17

ok

#### problème de casse dans nom de fichier

(void)

#### pas d'affichage dans les classes métier

ok

#### O/SDO ou MVC

pas tout à fait ok

seule la classe CellView est Observer, pas GameView

#### choix de la taille du plateau

ok

#### possibilité d'un plateau rectangulaire

ko : 

dans l'interface, je ne peux choisir que 5 x 5 ou 10 x 10 (et 5 ou 8 couleurs). 

allant voir GameView::initializeButton(), je vois que d'autres choix existent, 
mais ils ne sont pas accessibles !

#### choix du nombre de couleurs

ok

2 choix accessibles, mais 3 codés dans GameView::initializeButton() !

#### extension de la tache

ok

##### détection fin de jeu

ok

#### enregistrement du nouveau record

ko

il y a bien une classe FileManager (avec getScore() et writeScore(unsigned score)) 
et un attribut de ce type dans GameView,
mais il est juste instancié et jamais utilisé... d'ailleurs GameView n'est pas
Observer

#### affichage du record en fin de jeu

ko

il y a bien une classe FileManager (avec getScore() et writeScore(unsigned score)) 
et un attribut de ce type dans GameView,
mais il est juste instancié et jamais utilisé... d'ailleurs GameView n'est pas
Observer

#### fuites mémoire

(void)

