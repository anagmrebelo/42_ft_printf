# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 15:23:30 by arebelo           #+#    #+#              #
#    Updated: 2023/02/21 19:51:36 by arebelo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
# **************************************************************************** #
NAME		= libftprintf.a

# FILES
# **************************************************************************** #

SRCS 		= clean_struct.c\
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

SRCS_BONUS 	= clean_struct.c\
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

OBJS				=${addprefix ${OBJS_DIR}, ${SRCS:.c=.o}}
OBJS_BONUS			=${addprefix ${OBJS_DIR}, ${SRCS:.c=.o}}
DEPS				=${addprefix ${OBJS_DIR}, ${SRCS:.c=.d}}
DEPS_BONUS			=${addprefix ${OBJS_DIR}, ${SRCS:.c=.d}}

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
all:	${NAME}

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@

make_libft:
					make -C $(LIBFT_DIR)

${NAME}:	make_libft ${OBJS} ${LIBS_EXEC}
					${AR} ${NAME} ${OBJS} ${LIBS_EXEC}
					${RN} ${NAME}

bonus:	make_libft ${OBJS_BONUS}
					${AR} ${NAME} ${OBJS_BONUS}
					${RN} ${NAME}

clean:
					${RM} ${OBJS_DIR}
					@${MAKE} -C ${LIBFT_DIR} clean

fclean:	clean
					${RM} ${NAME}
					@${MAKE} -C ${LIBFT_DIR} fclean

re:	fclean all

-include ${DEPS}
-include ${DEPS_BONUS}

.PHONY:		all clean fclean re
