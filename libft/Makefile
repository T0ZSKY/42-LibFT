# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 14:50:20 by tomlimon          #+#    #+#              #
#    Updated: 2024/11/05 23:16:39 by tomlimon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Source files
SRCS            =    ft_isalnum.c ft_isprint.c ft_memcmp.c \
                    ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
                    ft_memcpy.c   ft_strchr.c  ft_strlcpy.c \
                    ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c \
                    ft_memmove.c   ft_strdup.c  ft_strlen.c  ft_strrchr.c \
                    ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c \
                    ft_strtrim.c ft_split.c ft_itoa.c ft_strjoin.c
                    
                    
# Object files
OBJS            = $(SRCS:.c=.o)

# Compiler settings
CC              = cc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror -I.

# Library name
NAME            = libft.a

# Default target
all:            $(NAME)

# Create the library
$(NAME):        $(OBJS)
	          ar rcs $(NAME) $(OBJS)

# Clean up object files
clean:
	          $(RM) $(OBJS)

# Clean and remove the library
fclean:         clean
	          $(RM) $(NAME)

# Rebuild everything
re:             fclean $(NAME)

# Phony targets
.PHONY:        all clean fclean re