all:
	meson setup bin/ --reconfigure
	meson compile -C bin/
run:
	bin/AstralCommandInterpreter