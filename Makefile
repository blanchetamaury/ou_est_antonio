
CC=cc

SDL_PATH := $(shell pwd)/SDL_LIB

NAME=ou_est_antonio

ANIMATION = animation/mod_animation.c

GNL = gnl/get_next_line.c \
		gnl/get_next_line_utils.c 

EVENT = event.c loop.c

TEXTURE = 	texture/find_texture_or_rect.c \
			texture/list_texture_or_rect.c \
			texture/rect_init.c \
			texture/texture_init.c

ALL_FILE = main.c free_texture_and_rect.c $(ANIMATION) $(TEXTURE) $(EVENT) $(GNL)

SRC = $(addprefix src/, $(ALL_FILE))

RM=rm -f

OBJ = $(SRC:%.c=.obj/%.o)

CFLAGS = -Wall -Wextra -Werror -I$(SDL_PATH)/include/SDL2 -Isrc/include -g
LDLIBS = src/libft/libft.a -lm -L$(SDL_PATH)/lib -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

all: $(NAME)

$(NAME): $(OBJ)
	make -C src/libft
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS)

.obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	make clean -C src/libft
	$(RM) $(OBJ)
	-rm -rf .obj

fclean: clean
	make fclean -C src/libft
	$(RM) $(NAME)
	$(RM) ou_est_antonio.desktop

re: fclean all

.PHONY: all clean fclean re

# Variables
DESKTOP_INSTALL_PATH = ~/.local/share/applications
ICON_INSTALL_PATH = ~/.local/share/icons/hicolor/256x256/apps

# Assurez-vous que les répertoires existent
$(DESKTOP_INSTALL_PATH):
	mkdir -p $(DESKTOP_INSTALL_PATH)

$(ICON_INSTALL_PATH):
	mkdir -p $(ICON_INSTALL_PATH)

# Règle principale pour installer l'application et son icône
APP_NAME = ou_est_antonio
EXEC_PATH = $(shell pwd)/$(APP_NAME)
ICON_PATH = icon.png
DESKTOP_FILE = $(APP_NAME).desktop

install: $(DESKTOP_INSTALL_PATH) $(ICON_INSTALL_PATH)
	# Copier l'icône
	cp $(ICON_PATH) $(ICON_INSTALL_PATH)/$(APP_NAME).png

	# Créer le fichier .desktop
	echo "[Desktop Entry]" > $(DESKTOP_FILE)
	echo "Version=1.0" >> $(DESKTOP_FILE)
	echo "Name=$(APP_NAME)" >> $(DESKTOP_FILE)
	echo "Comment=Un jeu de clicker basé sur les mèmes d'Internet" >> $(DESKTOP_FILE)
	echo "Exec=$(shell pwd)/launch.sh" >> $(DESKTOP_FILE)
	echo "Path=$(shell pwd)" >> $(DESKTOP_FILE)
	echo "Icon=$(APP_NAME)" >> $(DESKTOP_FILE)
	echo "Terminal=false" >> $(DESKTOP_FILE)
	echo "Type=Application" >> $(DESKTOP_FILE)
	echo "Categories=Utility;" >> $(DESKTOP_FILE)

	# Installer le fichier .desktop
	cp $(DESKTOP_FILE) $(DESKTOP_INSTALL_PATH)/
	chmod +x $(DESKTOP_INSTALL_PATH)/$(DESKTOP_FILE)

	# Mettre à jour la base de données des icônes
	xdg-icon-resource forceupdate --size 256

full_install:
	./rebuild_sdl2.sh
	make all
	make install
