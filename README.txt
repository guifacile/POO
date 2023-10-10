	1. INTRODUCTION
		Date: 13/09/2023
		Etudiant: Oumar Sadjo Barry
		System: Linux / Ubuntu
		Langage : C++
		TP: TP1 - Premier programme

	2. OBJECTIF:
		C'est un jeux de nombre.
		L'objectif de ce TP1, c'est de faire le premier pas
		en programmation C++ et d'etre sure d'avoir un environnement de developpement stable.
		Programmation sous Linux / Ubuntu, avec l'editeur "gedit" et execution par CMakeLists.txt

	3. EXECUTION (sous Linux / Ubuntu:
		il faut mettre au dossier TP1_random_number et taper les commandes suivantes:

		mkdir build && cd build
		cmake ..
		make

		Un executable "main" va se creer et il siffut de taper: ./main pour voir le resultat.

	5. EXECUTION (sous Windowns):
		Il faut se mettre au dossier TP1_random_number. Cliquer et maintener la touche Shift + clique droit.
		Selectionner "Open PowerShell windowns here" et taper les commandes suivantes:
		
		g++ RandomNumber.cpp -o main
		Un executable main va se creer et taper: ./main pour lancer le programme

	6. FONCTIONNEMENT:
		Le programme demande de definier un intervalle de valeur et le nombre de tantative souhaite.
		En suite, a chaque choix du nombre par l'utilisateur, le nombre de vie restant est affiche.

		A la fin du jeux, l'utilisateur d'ecide de continuer de jouer en cliquant sur 1 ou
		un autre nombre pour arreter le jeux.