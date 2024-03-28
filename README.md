# Projet C++ - Rendu Intermédiaire

Ce projet intermédiaire propose deux simulations d'univers en C++. Voici comment les exécuter :

1. **Simulations avec scripts :**
   Vous pouvez lancer les simulations à l'aide des scripts suivants :
   - `./scripts/orbits.sh` : Lance une simulation en 2D à l'aide de Gnuplot représentant le Soleil, la Terre, Jupiter et Haley.
   - `./scripts/univers2D.sh` : Simule orbits à l'aide de la classe Univers (en 2D) en ajoutant des météorites se dirigeant vers le soleil et d'autres planètes.
   - `./scripts/univers3D.sh` : Simule un univers random dans un petit espace en 3D. 
   
   Ces scripts génèrent un fichier GIF animé représentant la simulation.
	
	
	
2. **Exécution manuelle :**
   Pour exécuter les simulations manuellement :
   - Exécutez `make` dans le répertoire principal pour compiler le projet.
   - Naviguez vers `build` puis `demo/build`.
   - Exécutez le programme généré, dans un fichier `output.txt` que vous pouvez mettre dans le répertoire `simulation_files`.
   - Lancez Gnuplot sur le fichier `stromer.plot` pour obtenir un GIF nommé `stromer.gif`.

3. **Remarques**
    Pour être honnêtes, nous pensons que la simulation d'univers (avec les météorites est un         peu éronné, nous nous posons la question pour savoir s'il s'agissait de la cause de division par 0. De même, pour univers3D, la divergence semble assez compromettante. 
