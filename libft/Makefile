# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 18:55:27 by arebelo           #+#    #+#              #
#    Updated: 2023/02/21 17:51:20 by arebelo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
# **************************************************************************** #
NAME 				= libft.a

# FILES
# **************************************************************************** #
FILES				= ft_atoi.c\
					ft_bzero.c\
					ft_calloc.c\
					ft_isalnum.c\
					ft_isalpha.c\
					ft_isascii.c\
					ft_isdigit.c\
					ft_isprint.c\
					ft_itoa.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_memcpy.c\
					ft_memmove.c\
					ft_memset.c\
					ft_putchar_fd.c\
					ft_putendl_fd.c\
					ft_putnbr_fd.c\
					ft_putstr_fd.c\
					ft_split.c\
					ft_strchr.c\
					ft_strdup.c\
					ft_striteri.c\
					ft_strjoin.c\
					ft_strlcat.c\
					ft_strlcpy.c\
					ft_strlen.c\
					ft_strmapi.c\
					ft_strncmp.c\
					ft_strnstr.c\
					ft_strtrim.c\
					ft_substr.c\
					ft_tolower.c\
					ft_toupper.c\
					ft_strrchr.c\
					ft_lstadd_back.c\
					ft_lstadd_front.c\
					ft_lstclear.c\
					ft_lstdelone.c\
					ft_lstiter.c\
					ft_lstlast.c\
					ft_lstmap.c\
					ft_lstnew.c\
					ft_lstsize.c

SRCS				=${addprefix ${SRCS_DIR}, ${FILES:.c=.o}}
OBJS				=${addprefix ${OBJS_DIR}, ${FILES:.c=.o}}
DEPS				=${addprefix ${OBJS_DIR}, ${FILES:.c=.d}}

# DIRECTORY
# **************************************************************************** #
OBJS_DIR			= objs/
SRCS_DIR			= srcs/

# LIBRARIES
# **************************************************************************** #
INCLUDE				= -I inc

# COMPILATION
# **************************************************************************** #
LINK				= gcc
CC					= gcc -c
DEPFLAGS			= -MMD -MP
CFLAGS				= -Wall -Wextra -Werror 
RM					= rm -rf
AR					= ar rc
RN 					= ranlib

# RULES
# **************************************************************************** #
all:				${NAME}

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@

${NAME}:		${OBJS}
					${AR} ${NAME} ${OBJS}
					${RN} ${NAME}

clean:
			${RM} ${OBJS_DIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

-include ${DEPS}

.PHONY:		all clean fclean re
