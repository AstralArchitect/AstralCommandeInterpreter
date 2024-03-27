all:
	meson setup bin/
	meson compile -C bin/
run:
	bin/AstralCommandInterpreter