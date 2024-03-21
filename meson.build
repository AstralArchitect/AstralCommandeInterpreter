project('AstralCommandInterpreter', 'c')

executable('AstralCommandInterpreter', 'Code/Main/main.c', 'Code/commandes_System/universallib.c')

# Celui là ne marche pas sous Windows, ce serait bien que tu cherches une solution
# executable('ls', 'Code/commandes_System/ls.c')
executable('mv', 'Code/commandes_System/mv.c')
executable('rm', 'Code/commandes_System/rm.c')
executable('aff', 'Code/commandes_System/aff.c')

# Pour utiliser meson, tu dois l'installer (ça parait logique)
# je conseille cette commande: pip install meson

# Tu vas sûrement aussi devoir installer Ninja
# Pour cela soit:
# - pip install Ninja
# - winget install Ninja-build.Ninja

# Après ça pour compiler tu fais:
# 1. meson setup builddir
# 2. meson compile -C builddir
