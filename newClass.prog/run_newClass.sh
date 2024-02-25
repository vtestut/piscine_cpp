#!/bin/bash

# Trouver le répertoire où se trouve le script
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
echo "PWD = "$SCRIPT_DIR

# Aller dans le répertoire où se trouve le programme
cd "$SCRIPT_DIR"

# Lancer la commande make
MAKEFILE_PATH="$SCRIPT_DIR/Makefile"
# Supprimer l'espace entre le signe égal et le chemin du fichier Makefile
make -f "$MAKEFILE_PATH"
echo "PWD MAKE = "$MAKEFILE_PATH

# Exécuter le programme avec les arguments fournis
./a.out "$1" "$2"

# Trouver les fichiers générés par le programme
GEN_FILES="$SCRIPT_DIR/output/*"

# Déplacer les fichiers générés dans le répertoire de travail actuel
mv "$SCRIPT_DIR/output"/* "$OLDPWD/"

# Exécuter make fclean
make fclean -f "$MAKEFILE_PATH"

echo "Fichiers générés déplacés dans le répertoire de travail actuel"
