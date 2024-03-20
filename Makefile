all:
	x86_64-w64-mingw32-gcc -c Code/commandes_System/universallib.c
	x86_64-w64-mingw32-gcc -shared -o bin/Windows/universallib.dll universallib.o
	x86_64-w64-mingw32-gcc -o ./bin/Windows/AstralCommandeInterpreter.exe Code/Main/main.c -L bin/Windows/ -luniversallib  
	x86_64-w64-mingw32-gcc Code/commandes_System/ls.c -o Programmes/Win/ls.exe
	x86_64-w64-mingw32-gcc Code/commandes_System/mv.c -o Programmes/Win/mv.exe
	x86_64-w64-mingw32-gcc Code/commandes_System/rm.c -o Programmes/Win/rm.exe 
	x86_64-w64-mingw32-gcc Code/commandes_System/aff.c -o Programmes/Win/aff.exe
	x86_64-w64-mingw32-gcc Code/age/Win/main.c -o Programmes/Win/age.exe
	x86_64-w64-mingw32-gcc Code/date/date.c -o Programmes/Win/date.exe  
	x86_64-w64-mingw32-gcc Code/configure/main.c -o conf/configure.exe  
	x86_64-w64-mingw32-gcc Code/poid_planetes/main.c -o Programmes/Win/poid_planetes.exe
	@echo "compilation pour Windows terminee !"

install:
	sudo apt update -y
	sudo apt upgrade -y
	sudo apt install binutils-mingw-w64-x86-64 gcc-mingw-w64-x86-64 gcc -y
	@echo "minGW a ete installe avec succes!"

lin:
	gcc Code/Main/main.c Code/commandes_System/universallib.c -o ./bin/Linux/AstralCommandeInterpreter  
	gcc Code/commandes_System/ls.c -o Programmes/Lin/ls  
	gcc Code/commandes_System/mv.c -o Programmes/Lin/mv  
	gcc Code/commandes_System/rm.c -o Programmes/Lin/rm  
	gcc Code/commandes_System/aff.c -o Programmes/Lin/aff  
	gcc Code/age/Lin/main.c -o Programmes/Lin/age  
	gcc Code/date/date.c -o Programmes/Lin/date  
	gcc Code/configure/main.c -o conf/configure  
	gcc Code/poid_planetes/main.c -o Programmes/Lin/poid_planetes  
	@echo "compilation pour Linux terminee !"

win:
	gcc -c Code/commandes_System/universallib.c
	gcc -shared -o bin/Windows/universallib.dll universallib.o
	gcc -o ./bin/Windows/AstralCommandeInterpreter.exe Code/Main/main.c -L bin/Windows/ -luniversallib
	gcc Code/commandes_System/ls.c -o Programmes/Win/ls.exe
	gcc Code/commandes_System/mv.c -o Programmes/Win/mv.exe
	gcc Code/commandes_System/rm.c -o Programmes/Win/rm.exe 
	gcc Code/commandes_System/aff.c -o Programmes/Win/aff.exe
	gcc Code/age/Win/main.c -o Programmes/Win/age.exe
	gcc Code/date/date.c -o Programmes/Win/date.exe  
	gcc Code/configure/main.c -o conf/configure.exe  
	gcc Code/poid_planetes/main.c -o Programmes/Win/poid_planetes.exe
	@echo "compilation pour Windows terminee !"
clean:
	rm universallib.o