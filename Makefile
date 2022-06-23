##
## EPITECH PROJECT, 2021
## <DON'T FORGET TO PUT PROJECT NAME HERE!!!!>
## File description:
## Makefile
##

## Variable to be modified
rm = rm -rf

TARGET = my_rpg

CFLAGS = -Wextra -Wall -Iinclude

LDFLAGS	=	-L./ -lmy -lcsfml-graphics -lcsfml-window	\
			-lcsfml-audio -lcsfml-system -lm

SRC	=	src/game_main/event.c	\
		src/game_main/rpgmain.c	\
		src/start_game/anim_perso.c	\
		src/start_game/choose_name.c	\
		src/start_game/launch_game.c	\
		src/start_game/draw_map.c	\
		src/start_menu/anim_start.c	\
		src/start_menu/button_display_start.c	\
		src/start_menu/keyboard_str.c	\
		src/start_menu/new_game_name.c	\
		src/start_menu/save_load.c	\
		src/start_menu/sound.c	\
		src/start_menu/start_menu_main.c	\
		src/str_manip.c \

OBJ	=	$(SRC:.c=.o)

LIB_MAKE_PATH	=	lib/my/

LIB	= libmy.a

all:	$(LIB)	$(TARGET)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^\
	&& printf "[\033[1;35mcompiled\033[0m] % 29s\n" $< |  tr ' ' '.'\
	|| printf "[\033[1;31merror\033[0m] % 29s\n" $< |  tr ' ' '.'

$(LIB):
	@$(MAKE) -C $(LIB_MAKE_PATH)

$(TARGET): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo -e "\e[1;36mFinished compiling $@\e[0m"

.PHONY:	all	fclean	clean	re

debug: CFLAGS += -g3
debug: clean all

clean:
	@$(rm) $(OBJ)
	@echo "Removed .o files"
	@$(MAKE) -C $(LIB_MAKE_PATH) clean

fclean: clean
	@$(rm) $(TARGET)
	@echo "Removed binary file"
	@$(MAKE) -C $(LIB_MAKE_PATH) fclean

re: fclean all
