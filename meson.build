project('AstralCommandInterpreter', 'c')
libNd = library('lib', 'Code/lib/commandes_System/ls.c', 'Code/lib/commandes_System/rm.c', 'Code/lib/commandes_System/configure.c', 'Code/lib/commandes_System/aff.c', 'Code/lib/commandes_System/touch.c')
lib = library('universallib', 'Code/lib/universallib.c', link_with : libNd)
executable('AstralCommandInterpreter', 'Code/Main/main.c', link_with : lib)

# Pour utiliser meson, tu dois l'installer (ça parait logique)
# je conseille cette commande: pip install meson

# Tu vas sûrement aussi devoir installer Ninja
# Pour cela soit:
# - pip install ninja
# - winget install ninja-build.ninja

# Après ça pour compiler tu fais:
# 1. meson setup bin
# 2. meson compile -C bin
