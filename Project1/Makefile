ALLEGRO_DIR=/usr/include
export PKG_CONFIG_PATH=$(ALLEGRO_DIR)/lib/pkgconfig
CFLAGS=$(shell export PKG_CONFIG_PATH=$(PKG _CONFIG_PATH) && pkg-config --cflags allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5 allegro_font-5 allegro_ttf-5 allegro_dialog-5 allegro_primitives-5)
LDFLAGS=$(shell export PKG_CONFIG_PATH=$(PKG _CONFIG_PATH) && pkg-config --libs allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5 allegro_font-5 allegro_ttf-5 allegro_dialog-5 allegro_primitives-5)

main: main.o sprite.o world.o Tank.o hellfire.o missed.o hit.o birds.o
	g++ -ggdb -o main main.o sprite.o world.o Tank.o hellfire.o missed.o hit.o birds.o ${LDFLAGS}

main.o: main.C sprite.h world.h
	g++ -ggdb -c main.C ${CFLAGS}

sprite.o: sprite.h sprite.C
	g++ -ggdb -c sprite.C ${CFLAGS}

world.o: world.h sprite.h birds.h world.C
	g++ -ggdb -c world.C ${CFLAGS}

Tank.o: Tank.h Tank.C sprite.h
	g++ -ggdb -c Tank.C ${CFLAGS}

hellfire.o: hellfire.h hellfire.C sprite.h
	g++ -ggdb -c hellfire.C ${CFLAGS}

missed.o: missed.h missed.C sprite.h
	g++ -ggdb -c missed.C ${CFLAGS}

hit.o: hit.h hit.C sprite.h
	g++ -ggdb -c hit.C ${CFLAGS}

birds.o: birds.h birds.C
	g++ -ggdb -c birds.C ${CFLAGS}

clean:
	rm -f *.o main
