all:
	meson compile -C builddir/
run: all
	builddir/main
setup:
	meson setup builddir/
