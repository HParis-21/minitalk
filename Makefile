NAMEC   =   client
SRCC    =   client.c dop_function.c
NAMES   =   server
SRCS    =   server.c dop_function.c
OBJS	=	$(SRCS:c=o)
OBJC	=	$(SRCC:c=o)
NAME_CB	=   client_bonus
SRC_CB	=   client_bonus.c dop_function.c
NAME_SB	=   server_bonus
SRC_SB	=   server_bonus.c dop_function.c
OBJ_SB	=	$(SRC_SB:c=o)
OBJ_CB	=	$(SRC_CB:c=o)
FLAGS   =   -Wall -Wextra -Werror
HEADER	=	minitalk.h
BONUS	=	bonus
NAME = client_server

all:	$(NAME)
$(NAME): $(NAMES) $(NAMEC)
$(BONUS): $(NAME_SB) $(NAME_CB)
.c.o:       %.c $(HEADER)
			gcc $(FLAGS) -c -o $@ $<
$(NAMEC):	$(OBJC) $(HEADER)
			gcc $(OBJC) -o $(NAMEC)
$(NAMES):	$(OBJS) $(HEADER)
			gcc $(OBJS) -o $(NAMES)
$(NAME_CB):	$(OBJ_CB) $(HEADER)
			gcc $(OBJ_CB) -o $(NAME_CB)
$(NAME_SB):	$(OBJ_SB) $(HEADER)
			gcc $(OBJ_SB) -o $(NAME_SB)
clean:
			rm -f $(OBJS) $(OBJ_SB)
			rm -f $(OBJC) $(OBJ_CB)
fclean:     clean
			rm -f $(NAMEC) $(NAME_CB)
			rm -f $(NAMES) $(NAME_SB)
re:         fclean all

.PHONY:     all clean fclean re