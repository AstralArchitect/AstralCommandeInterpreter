all:
	meson setup bin/ --reconfigure
	meson compile -C bin/
run:
	bin/AstralCommandInterpreter
install:
	pip install meson ninja
removeMeson:
	pip uninstall meson ninja