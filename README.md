# LAN Party

Aplicatia automatizeaza procesul competitiei LAN Party, oferind utilizatorului date despre structura meciurilor dintre echipe, topul echipelor, respectiv castigatorii campionatului.

# Structura si implementare

Pentru realizarea tuturor cerintelor am implementat 11 clase, acestea sunt (in ordinea aparitiei in interiorul programului):
- `Player`
	- Clasa `Player` contine informatii despre jucator: atributele de tipul `string` `firstName`, respectiv `lastName` si atributul de tipul `int` `points`, ce reprezinta punctele de experienta ale jucatorului.
	- Obiectele de tip `Player` se pot crea folsind constructorul cu parametri: `Player(string first, string second, int pts)`.
	- Au fost implementate, de asemenea, gettere si settere pentru atribute, metoda `promote()` ce incrementeaza punctajul jucatorului si supraincarcari ale operatorilor de citire si scriere.
- `Team`
	- Clasa `Team` contine 3 atribute: `size`, dimensiunea echipei, de tipul `int`, `name`, numele echipei, de tipul `string` si un tablou de elemente de tipul `Player` de dimensiune `size`, `players`, ce contine lista jucatorilor membri.
	- Pentru aceasta clasa exista 2 variante de constructor: constructorul cu parametri `Team(int s, string n, Player* p)` si cel de copiere `Team(const Team& t)`.
	- Pe langa gettere pentru atribute, mai sunt prezente supraincarcari ale operatorilor logici si a celor de citrie/scriere si inca 2 metode : `void printWithScore()` ce afiseaza numele echipei alaturi de scor si metoda `promote()` ce apeleaza functia cu acelasi nume din clasa `Player` pentru fiecare jucator.
- `Node`
	- Clasa `Node` contine un atribut de tip `Team` `value` si unul de tip `Node*` `next`, adresa urmatorului nod.
	- Un `Node` se poate crea prin constructorul cu parametri Node(const Team& v, Node* n), fie cu ambii parametri, fie cu primul (cel mai des) sau chiar cu niciunul, valorile implicite fiind `Team()` si `NULL`.
	- Pentru `Node` au fost implementate doar gettere si settere.
- `List`
	- `List` are 2 atribute: un pointer la capul de lista `Node* head` si dimensiunea `int size`.
	- O lista se poate crea prin 3 metode diferite: constructor fara parametri `List()`, creeaza o lista goala, constructor cu parametri `List(const Team& v, Node* n)`, creeaza o lista cu un singur nod care va fi capul de lista si constructor de copiere `List(const List& l`).
	- Sunt disponibile gettere si settere pentru atribute, metode pentru adaugarea unei echipe la o anumita pozitie `add(const Team& t, int pos)` si stergerea unei anumite echipe `remove(const Team& t)`, afisarea numelor echipelor din lista `printNames(ostream& o)` si metoda `removeLowest(int `num`)` ce apeleaza `remove` pentru cele mai slabe `num` echipe din lista. Implicit functia de adaugare adauga la inceputul listei `pos = 0`, iar functia de afisare, la apelul fara parametru, va afisa informatiile pe consola.
- `Match`
	- Clasa `Match` are ca atribute 2 echipe `Team t1, t2`, participantele la respectivul meci.
	- O partida se va crea apeland constructorul `Match(Team team1, Team team2)`.
	- Pentru obtinerea castigatorului, respectiv perdantului partidei se vor apela functiile `Team getWinner()` si `Team getLoser()`. Functia `void setWinner()` apeleaza functia `promote()` pentru echipa castigatoare. De asemenea, a fost supraincarcat `operator<<`.
- `QNode`
	- Clasa similara clasei `Node`, atributul `value` este in acest caz de tipul `Match`, iar structura de coada ce foloseste `QNode` necesita folosirea a 2 pointeri `QNode *prev, *next`.
	- Apelul constructorului este similar cu cel pentru `Node`: `QNode(const Match& v, QNode* p, QNode* n)`. Valorile implicite ale parametrilor sunt `Match()`, `NULL`, `NULL`.
	- Gettere si settere pentru fiecare atribut.
- `Queue`
	- Structura de coada necesita si un pointer la finalul unei liste inlantuite de aceea clasa `Queue` are 3 atribute: `QNode* head`, `QNode* tail` si `int size`.
	- Similar cu `List` se pot creea obiecte prin toate cele 3 metode : `Queue()`, `Queue(const Match& m, QNode* p, QNode* n)` si copy-constructor `Queue(const Queue& q)`.
	- Metode pentru adaugare si eliminare: `void push(const Match& m)` si `void pop()`, gettere pentru atribute, functie de afisare `print(ostream& devo)` similara cu cea a listei. Pentru buna functionare a aplicatiei, clasa `Queue` mai contine metodele: `scheduleMatches(const List& l)` , ce initializeaza partidele intre echipele din lista l si le adauga in coada, si metoda `simulateRound(List** teams, int round, ostream& devo)` ce 'joaca' meciurile din coada, populeaza stivele de invingatori si invinsi, retine echipele ramase in `teams` si afiseaza, in consola sau in fisier, castigatorii rundei curente `round`.
- `Stack`
	- Clasa `Stack` are o structura aproape identica clasei `List`.
	- Constructorii au aceeasi forma ca si cei pentru `List`.
	- Metoda `void push(const Team&)` este echivalentul lui `add` din list cu `pos = 0`, `void pop()` elimina primul element din stiva, gettere, exact ca la lista, functie de afisare similara. Functia `void toList(List* l)` copiaza atributele stivei in lista l si 'goleste' stiva.
- `TreeNode`
	- Clasa `TreeNode` are ca atribute: o echipa `Team key`, inaltimea nodului (pt arbori AVL) `int height` si pointeri catre cele 2 noduri copil `TreeNode *left, *right`.
	- Un obiect de tip `TreeNode` se poate crea prin apelul constructorului cu parametri `TreeNode(const Team& k, int h, TreeNode* l, TreeNode* r)`. Implicit,`k = Team()`, `h = 1`, iar `l = r = NULL`.
	- Pentru aceasta clasa sunt implementate gettere si settere.
- `BST`
	- `BST` contine un singur atribut, un pointer la radacina arborelui: `TreeNode* root`.
	- Constructorii clasei sunt cel fara parametri `BST()` care seteaza atributul `root = NULL` si cel cu parametri `BST(const Team& val, int h, TreeNode* l, TreeNode* r)` ce seteaza atributul root cu adresa unui nou `TreeNode` creat cu atributele date. Implicit, `h = 1`, iar `l = r = NULL`.
	- Pe langa getter si setter pentru atribut, exista metode publice pentru adaugare : `insert(const Team& t)` si pentru afisare `print(ostream& devo, int order)`. 
	- Pe langa metodele publice, exista mai multe metode helper, ce functioneaza recursiv pentru a putea efectua inserarea si afisarea, dar si pentru a putea elibera memoria folosind destructorul. 
		- Prima metoda protected este `void destroyRec(TreeNode* root)` ce se apeleaza recursiv, post-order pentru a sterge nodurile arborelui. 
		- In aceeasi maniera, metoda recursiva `insertRec(const Team& k, TreeNode* r)` se apeleaza recursiv, dar in-order, pentru a adauga o noua echipa in arbore. 
		- Similar lucreaza si metodele de afisare recurisva, care poate fi in ordine crescatoare si descrescatoare : `printInOrderAsc(TreeNode* n, ostream& devo)` si `printInOrderDesc(TreeNode* n, ostream& devo)`.
- `AVL`
	- `AVL` este o clasa derivata din `BST`.
	- Metoda `insert()` suprascrie metoda cu acelasi din clasa parinte, metoda `printLevel(int level, ostream& devo)` afiseaza echipele de pe nivelul `level` din arbore, iar metoda `fromBST(BST* b)` insereaza nodurile unui arbore BST `b` in arborele AVL.
	- Inserarea intr-un arbore AVL se face prin procedee mai complicate, ce implica rotatii si verificari ale inaltimilor, de aceea, pentru implementarea corecta clasa contine mai multe metode ajutatoare: 
		- `int height(TreeNode* root)` - returneaza inaltimea unui nod;
		- `int max(int a, int b)` - returneaza maximul dintre 2 numere;	
		- `TreeNode* rotateRight(TreeNode* root)` - returneaza noua radacina dupa o rotatie la dreapta;
		- `TreeNode* rotateLeft(TreeNode* root)` - returneaza noua radacina dupa o rotatie la stanga;
		- `int getBalance(TreeNode* root)` - calculeaza factorul de balansarea al unui nod;
	- Pentru celelalte metode publice exista, de asemenea, metode ajutatoare ce lucreaza recursiv: `printLvlPreOrder(TreeNode* r, int currLvl, int setLvl, ostream& devo)` si `insertFromBST(TreeNode* r)`.
	
In `main` se va face deschiderea fisierelor de intrare `c.in` si `d.in` si a fisierului de iesire `r.out`, popularea listei de echipe si in functie de numarul cerintei se vor executa instructiunile necesare cerintei.
