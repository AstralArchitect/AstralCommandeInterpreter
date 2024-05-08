# Qu'est-ce que c'est

Ceci est un interpréteur de commande inventé par AstralArchitect en collaboration avec [Nautilus-1021](https://github.com/Nautilus-1021)

# Compiler

## installer un compilateur
Pour compiler le code, vous devrez d'abors installer un compilateur C/C++. Personnelement, je vous recommande [gcc](https://gcc.gnu.org/) que vous pouvez installer sur:
### Linux Debian/Ubuntu ou Kali Linux
 Pour installer gcc sur Debian ou Ubuntu, tapez la commande suivante dans un terminal :
  ```
  sudo apt-get install gcc
  ```
### Arch Linux
  Pour installer gcc sur Arch Linux, tapez la commande suivante dans un terminal :
  ```
  sudo pacman -S gcc
  ```
### Alpine Linux
  Pour installer gcc sur Alpine Linux, tapez la commande suivante dans un terminal :
  ```
  sudo apk add gcc
  ```
### Windows
  Pour installer gcc sur Windows, rendez vous sur [Source Forge](https://sourceforge.net/projects/mingw/) et téléchargez MinGw (l'équivalent de gcc sur windows).
  Ensuite lançez l'installeur.
  
  <img width="452" alt="image" src="https://github.com/AstralArchitect/AstralCommandeInterpreter/assets/154975712/5398c00f-dee2-4020-a4fe-b53a1f67ba29">
  
  Puis, cliquez sur "Install".
  
  <img width="450" alt="image" src="https://github.com/AstralArchitect/AstralCommandeInterpreter/assets/154975712/fc5f18a2-ed98-438f-8bf7-65749646558d">
  
  Après, cliquez sur "Continue" et attendez la fin de l'installation de MinGW.

 <img width="453" alt="image" src="https://github.com/AstralArchitect/AstralCommandeInterpreter/assets/154975712/44f3a130-82ea-497b-af1c-73eb0a75f2fc">

 Ensuite, cliquez sur "Continue" et MinGW installer devrai se lancer.

 <img width="1430" alt="image" src="https://github.com/AstralArchitect/AstralCommandeInterpreter/assets/154975712/58503a8f-1352-41d7-8ff1-7175fc7b9d07">

 Les paquets nécéssaires sont déja installés. Vous pouvez fermer MinGW Installation Manager.
 Pour pouvoir utiliser directement gcc dans un terminal, vous devrez l'ajouter au Path de Windows.
 Pour ce fait, ouvrez une fenêtre de Windows Explorer et faite un clique droit sur "ce PC"(dans la barre des racourcis à gauche), puis Cliquez sur propriétés.
 ![Sans titre](https://github.com/AstralArchitect/AstralCommandeInterpreter/assets/154975712/6dd14ef1-09ea-4aeb-87f4-7f469a7f7f95)
 Ensuite, cliquez sur "paramètres avancés du système".
 
 <img width="308" alt="image" src="https://github.com/AstralArchitect/AstralCommandeInterpreter/assets/154975712/ddb52f36-c738-4162-9281-d0626ce43691">
 
 Puis sur "Variables d'envirronement...".

 ![Sans titre](https://github.com/AstralArchitect/AstralCommandeInterpreter/assets/154975712/312049d4-3074-452a-9317-1d9b1e078a5f)

 Puis cliquez sur "Path" puis "Modifier".

 ![Sans titre2](https://github.com/AstralArchitect/AstralCommandeInterpreter/assets/154975712/8f83117a-9925-4599-b36f-66a296a6f01b)

 Enfin, cliquez sur Ok, la fenêtre va se fermer puis sur l'anciennne fenêtre, cliquez une 2ème fois sur ok, elle se fermera aussi et cliquez sur appliquer.
 
 Gcc est maintenant installé sur votre ordinateur!
## Installer Make
 Maintenant, vous aurez besoin de [Make](https://www.gnu.org/software/make/) pour compiler le code. pour l'installer sur :
 ### Linux Debian/Ubuntu ou Kali Linux
 Pour installer make sur Debian ou Ubuntu, tapez la commande suivante dans un terminal :
  ```
  sudo apt-get install make
  ```
### Arch Linux
  Pour installer make sur Arch Linux, tapez la commande suivante dans un terminal :
  ```
  sudo pacman -S make
  ```
### Alpine Linux
  Pour installer make sur Alpine Linux, tapez la commande suivante dans un terminal :
  ```
  sudo apk add make
  ```
### Windows 
 Pour installer make sur Windows, tapez la commande suivante dans un terminal ouvert en tant qu'Administrateur:
  ```
  choco install make
  ```
## Installer Meson et Ninja
 Une fois avoir installer make, rendez vous dans le répertoire AstralCommandeInterpreter et tapez 
 ```
 make install
 ```
 Pour que cela marche, vous aurez besoin d'installer [Python](https://www.python.org/).
## Compiler le code
 Maintenant que vous avez installé : 
 - GCC
 - Make
 - Meson
 - Ninja
 
 Vous pouvez maintenant compiler le code.
 Pour ce fait, rendez vous dans le dossier AstralCommandeInterpreter et tapez la commande
 ```
 make
 ```
# Executer
 Vous avez maintenant compilé le code. Pour l'éxécuter il vous suffira juste de taper la commande ``make run``. sinon, l'éxécutable est dans le dossier bin/.
