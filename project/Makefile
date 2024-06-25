# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 09:55:09 by isilva-t          #+#    #+#              #
#    Updated: 2024/06/25 10:47:18 by isilva-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = proj/push_swap.c \
	   proj/stack_utils.c \
	   proj/stack_init.c \
	   proj/free_error.c \
	   proj/com_push.c \
	   proj/com_swap.c \
	   proj/com_rotate.c \
	   proj/com_rev_rotate.c \
		  utils/ft_split.c \
		  utils/ft_strlen.c \
		  utils/ft_substr.c \
		  utils/ft_strdup.c \
		  	utils/ft_printf/ft_printf.c \
			utils/ft_printf/pf_print_ptr.c \
			utils/ft_printf/pf_put_nbr_base.c

OBJS = ${SRCS:.c=.o}

NAME = out

MSG1 = @echo "________ Compiled Mandatory files!"
MSG2 = @echo "________ Compiled Bonus files!"
MSG3 = @echo "___________ Cleared!"
MSG4 = @echo "_______________ Full Cleared!"

$(NAME):
	$(CC) ${CFLAGS} $(SRCS) -o $(NAME)
	${MSG1}
	
all: ${NAME}

clean:
	@rm -rf ${OBJS}
	${MSG3}

fclean: clean
	@rm -rf ${NAME}
	${MSG4}

re: fclean all

.PHONY: all clean fclean re
