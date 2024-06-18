project('AstralCommandInterpreter', 'c')

libNd = library('lib', 'Code/lib/commandes_System/ls.c', 'Code/lib/commandes_System/rm.c', 'Code/lib/commandes_System/configure.c', 'Code/lib/commandes_System/aff.c', 'Code/lib/commandes_System/touch.c')

lib = library('universallib', 'Code/lib/universallib.c', link_with : libNd)

executable('main', 'Code/Main/main.c', link_with : lib)
