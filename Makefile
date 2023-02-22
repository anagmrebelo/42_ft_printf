# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 15:23:30 by arebelo           #+#    #+#              #
#    Updated: 2023/02/22 01:04:49 by anarebelo        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
# **************************************************************************** #
NAME				= libftprintf.a
NAME_BONUS			= libftprintf_bonus.a

# FILES
# **************************************************************************** #

FILES 				= clean_struct.c\
					conversions_first.c\
					conversions_last.c\
					conversions_main.c\
					counter_funcs.c\
					ft_putnbr_base_x.c\
					ft_putnbr_x.c\
					ft_putnbr_xu.c\
					is_id.c\
					libftprintf.c\
					print_mfw.c\
					putstr_limited.c\
					print_percent.c

FILES_BONUS			= clean_struct.c\
					conversions_first.c\
					conversions_last.c\
					conversions_main_bonus.c\
					counter_funcs.c\
					ft_putnbr_base_x.c\
					ft_putnbr_x.c\
					ft_putnbr_xu.c\
					is_id.c\
					libftprintf.c\
					print_mfw.c\
					putstr_limited.c\
					print_percent.c

SRCS				=${addprefix ${SRCS_DIR}, ${FILES:.c=.o}}
OBJS				=${addprefix ${OBJS_DIR}, ${FILES:.c=.o}}
OBJS_BONUS			=${addprefix ${OBJS_DIR}, ${FILES:.c=.o}}
DEPS				=${addprefix ${OBJS_DIR}, ${FILES:.c=.d}}
DEPS_BONUS			=${addprefix ${OBJS_DIR}, ${FILES:.c=.d}}

# DIRECTORY
# **************************************************************************** #
OBJS_DIR			= objs/
SRCS_DIR			= srcs/
LIBFT_DIR			= libft/

# LIBRARIES
# **************************************************************************** #
INCLUDE				= -I inc -I ${LIBFT_DIR}inc
LIBS_EXEC			= $(LIBFT_DIR)libft.a

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
all:	make_libft ${NAME}

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@

make_libft:
					@make -C $(LIBFT_DIR)

${NAME}:	${OBJS}
					cp libft/libft.a .
					mv libft.a ${NAME}
					${AR} ${NAME} ${OBJS}
					${RN} ${NAME}

bonus:	make_libft ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
					@cp libft/libft.a .
					@mv libft.a ${NAME_BONUS}
					${AR} ${NAME} ${OBJS_BONUS}
					${RN} ${NAME_BONUS}

clean:
					@${RM} ${OBJS_DIR}
					@${MAKE} -C ${LIBFT_DIR} clean

fclean:	clean
					@${RM} ${NAME}
					@${RM} ${NAME_BONUS}
					@${MAKE} -C ${LIBFT_DIR} fclean

re:	fclean all

 -include ${DEPS}
 -include ${DEPS_BONUS}

.PHONY:		all clean fclean re
