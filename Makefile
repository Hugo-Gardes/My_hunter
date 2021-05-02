##
## EPITECH PROJECT, 2020
## B-CPE-210-MPL-2-1-solostumper05-hugo.gardes
## File description:
## Makefile
##

CC	=	gcc

NAME	=	my_hunter

SRC		=	$(wildcard *.c)
SRC		+=	$(wildcard */*.c)
SRC		+=	$(wildcard */*/*.c)
SRC		+=	$(wildcard */*/*/*.c)
SRC		+=	$(wildcard */*/*/*/*.c)
SRC		+=	$(wildcard */*/*/*/*/*.c)

OBJS	=	$(SRC:.c=.o)

RM	=	rm -f

CFLAGS	=	-W -Wall -Wextra

CFLAGS	+=	-I include/ -lm

LDFLAGS	=	-lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJS)
	@ $(CC) -o $@ $(OBJS) $(LDFLAGS) $(CFLAGS)
	@ echo "\033[1;34mCOMPILE ...     [ OK ]\033[0m"

clean:
	@ $(RM) $(OBJS)
	@ $(RM) *~
	@ $(RM) #*#

fclean:	clean
	@ $(RM) $(NAME)

re:	fclean all
