main:
	meson setup build
	meson compile -C build
	./build/src/main/main