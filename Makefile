NAME		=	pipex

SRCS_FILES	=	pipex.c utils.c parsing.c

SRC_DIR		=	srcs

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES))

OBJS		=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES:.c=.o))

LIB_DIR		=	libft

HEADER		=	-I include/pipex.h

CC			=	gcc

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIB_DIR) -lft
			@echo "Compilation done !"

%.o:		%.c $(HEADER)

clean:
			@make clean -C $(LIB_DIR)
			@$(RM) $(OBJS)
			@echo "Objects deleted !"

fclean:		clean
			@make fclean -C $(LIB_DIR)
			@$(RM) $(NAME)
			@echo "Executable deleted !"

re:			fclean all

.PHONY:		all clean fclean re