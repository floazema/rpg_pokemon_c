##
## EPITECH PROJECT, 2021
## Task 01
## File description:
## Compiles library, cleans folder and puts my.h in ../../include/
##

SRC 	=	./my_atoi.c					\
			./my_compute_power_rec.c	\
			./my_compute_square_root.c	\
			./my_find_prime.c			\
			./my_getnbr.c				\
			./my_is_prime.c				\
			./my_isneg.c				\
			./my_print_alpha.c			\
			./my_print_revalpha.c		\
			./my_put_nbr.c				\
			./my_put_unnbr.c			\
			./my_putchar.c				\
			./my_putstr.c				\
			./my_revstr.c				\
			./my_showmem.c				\
			./my_showstr.c				\
			./my_str_isalpha.c			\
			./my_str_islower.c			\
			./my_str_isnum.c			\
			./my_str_isupper.c			\
			./my_str_to_word_array.c	\
			./my_strcapitalize.c		\
			./my_strcat.c				\
			./my_strcpy.c				\
			./my_strdup.c				\
			./my_strlen.c				\
			./my_strlowcase.c			\
			./my_strncat.c				\
			./my_strncpy.c				\
			./my_strstr.c				\
			./my_strupcase.c			\
			./my_swap.c					\
			./printf/flags.c			\
			./printf/flagssec.c			\
			./printf/flagsthree.c		\
			./printf/my_printf.c		\
			./my_strcmp.c				\
			./my_itoa.c					\
			./my_strcmpd.c				\

HDR	=	my.h

CFLAGS = ##-Wall -Wextra

OBJ	=	$(SRC:.c=.o)

NAME	=	compile_lib

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^\
	&& printf "[\033[1;35mcompiled\033[0m]% 50s\n" $< |  tr ' ' '.'\
	|| printf "[\033[1;31merror\033[0m]% 50s\n" $< |  tr ' ' '.'

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME): $(OBJ)
	@ar rc libmy.a $(OBJ)
	@cp libmy.a ../..
	@printf "\e[1;36mFinished compiling library\e[0m\n"

clean:
	@rm -f ../../libmy.a
	@echo "Removed root's libmy.a"

fclean:	clean
	@rm -f $(OBJ)
	@rm -f ./libmy.a
	@rm -f ../libmy.a
	@cd ../../include/ && rm -f $(HDR_FILES)
	@printf "\e[1;32mDeleted all .o in lib and all libmy.a\e[0m\n"

re: fclean all
