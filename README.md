# Qu'est-ce que c'est

Ceci est un interpréteur de commande inventé par AstralArchitect en collaboration avec [Nautilus-1021](https://github.com/Nautilus-1021)

# Commandes de base

- **exit**: sortir de AstralCommandeInterpreter
- **reload**: recharger le fichier de personnalisation
- **ls**: afficher le contenu d'un fichier
- **mv**: deplacer un fichier
- **rm**: supprimer un fichier
  
  *note* : ls, mv et rm s'utilisent de la même façon que sur linux
# Compiler le code
Pour compiler le code, installez d'abord meson et ninja avec `pip install meson` et `pip install ninja`.
Ensuite, tapez les commandes suivantes
```
meson setup bin
meson compile -C bin
```
et tous les executables seront dans le dossier bin
