NAME = ft_ls
CC = cc
FLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
PATH_SRCS = ./srcs/
SRCS =	main.c options.c
OBJ = $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
BUILD_DIR = .build
LIBFT = ./includes/libft/libft.a
DEBUG = -D DEBUG=1

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $@
	@echo "\nft_ls is ready for use!\n"

$(BUILD_DIR)/%.o: $(PATH_SRCS)%.c Makefile $(LIBFT)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -MMD -MP -c $< -o $@ -I ./includes

-include $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

$(LIBFT): FORCE
	make -C includes/libft bonus

debug: FLAGS += $(DEBUG)
debug: sclean all

sclean: 
	@rm -rf $(BUILD_DIR)

clean:
	@make --no-print-directory -C ./includes/libft clean
	@rm -rf $(BUILD_DIR)

fclean: clean
	@make --no-print-directory -C ./includes/libft fclean
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean
	@make --no-print-directory

FORCE:

.PHONY: all clean fclean re bonus FORCE debug