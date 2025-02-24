SRC =	src/main/push_swap.c \
		src/std/ft_putstr_fd.c src/std/ft_strlcat.c src/std/ft_strlen.c \
		src/std/ft_strcmp.c src/std/ft_split.c src/std/ft_substr.c \
		src/std/ft_strdup.c src/std/ft_atoi.c \
		src/utils/utils.c src/utils/parser.c src/utils/moves_0.c src/utils/moves_1.c \
		src/utils/sort.c src/utils/sorting.c src/utils/max_min.c

SRC_BONS = 	bonus/checker_bonus.c bonus/utils/ft_atoi_bonus.c bonus/utils/ft_putstr_fd_bonus.c \
			bonus/utils/ft_split_bonus.c bonus/utils/ft_strlcat_bonus.c \
			bonus/utils/parser_bonus.c bonus/utils/utils_bonus.c bonus/utils/ft_substr_bonus.c \
			bonus/utils/ft_strlen_bonus.c bonus/utils/ft_strdup_bonus.c bonus/utils/get_next_line.c \
			bonus/utils/get_next_line_utils.c bonus/utils/ft_strcmp_bonus.c \
			bonus/utils/moves_0_bonus.c bonus/utils/moves_1_bonus.c

OBJ =	$(SRC:%.c=%.o)

OBJ_BONS = $(SRC_BONS:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

NAME = push_swap

NAME_BONUS = checker

HEADS = include/push_swap.h bonus/inlcude/checker_bonus.h

%.o: %.c $(HEADS)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(SRC_BONS) $(OBJ_BONS)
	@ $(CC) $(CFLAGS) $(OBJ_BONS) -o $(NAME_BONUS)

clean :
	rm -f $(OBJ) $(OBJ_BONS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : clean bonus