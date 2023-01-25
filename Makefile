# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 13:13:45 by mgomes-d          #+#    #+#              #
#    Updated: 2023/01/25 07:52:12 by mgomes-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
#CFLAGS += -g -fsanitize=address
AR		= ar
ARFLAGS	= -rcs
RM		= rm
RMFLAGS	= -rf

# LIBRARY ARCHIVE
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)


LIBRARIES = -lft -lm -L$(LIBFT_DIRECTORY)

# HEADERS
HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

# SOURCES
SOURCES_DIRECTORY = ./src/
SOURCES_LIST = push_swap.c \
			actions01.c \
			actions02.c \
			actions03.c \
			actions04.c \
			struct.c \
			algo01.c \
			ft_raditz.c \
			inittab.c \
			struct_utils.c \
			struct_utils2.c \
			struct_utils3.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

# OBJECTS
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLOR FLAGS
CLR_BLACK   = \033[0;30m
CLR_RED		= \033[0;31m
CLR_GREEN	= \033[0;32m
CLR_LBLUE   = \033[0;94m
CLR_YELLOW  = \033[0;33m
CLR_MAGENTA = \033[0;35m
CLR_RESET	= \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(NAME): $(CLR_GREEN)objects were created$(CLR_RESET)"
	@echo "$(NAME): $(CLR_GREEN)$(NAME) was created$(CLR_RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(CLR_GREEN)$(OBJECTS_DIRECTORY) was created$(CLR_RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(CLR_GREEN).$(CLR_RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(CLR_YELLOW)Creating $(LIBFT)...$(CLR_RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(RM) $(RMFLAGS) $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(CLR_RED)$(OBJECTS_DIRECTORY) was deleted$(CLR_RESET)"
	@echo "$(NAME): $(CLR_RED)objects were deleted$(CLR_RESET)"

fclean: clean
	@$(RM) $(RMFLAGS) $(LIBFT)
	@echo "$(NAME): $(CLR_RED)$(LIBFT) was deleted$(CLR_RESET)"
	@$(RM) $(RMFLAGS) $(NAME)
	@echo "$(NAME): $(CLR_RED)$(NAME) was deleted$(CLR_RESET)"

re: fclean all

.PHONY: all clean fclean re
