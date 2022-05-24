# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 00:27:49 by lduboulo          #+#    #+#              #
#    Updated: 2022/05/24 16:10:44 by lduboulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
GREY	= \033[1;90m
BUILD	= \e[38;5;225m
SEP		= \e[38;5;120m
DUCK	= \e[38;5;227m
RESET	= \033[0m

# COLORS


SRCS_DIR	= ./src/
SRCS_FILES	= ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c \
              ft_dyn_substr.c ft_isalnum.c ft_isascii.c ft_isdigit.c \
              ft_isprint.c ft_itoa.c ft_itoa_base.c ft_lstadd_back.c \
              ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
              ft_lstmap.c ft_lstnew.c ft_mem_alloc_check.c \
              ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
              ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
			  ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcpy.c \
			  ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			  ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c \
			  get_next_line_utils.c ft_isalpha.c ft_lstadd_front.c \
              ft_lstsize.c ft_putstr_fd.c ft_strlcat.c ft_strtrim.c \
			  ft_dyn_strjoin.c ft_tab_free.c

SRCS		:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}


O_DIR		= ./objs/

OBJS_FILES	:= ${SRCS_FILES:.c=.o}
OBJS		:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}

HEADS_DIR	= ./../includes/

NAME		= libutils.a

MAKELIB		= ${MAKE} -C
CC			= gcc
AR			= ar rcs
MKDIR		= mkdir
RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address

TSEP		= ${SEP}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=${RESET}


all:		${NAME}

${NAME}:	${O_DIR} ${OBJS}
			@printf "\n${TSEP}\n"
			@printf "${GREEN} 💻 Successfully compiled ${NAME} .o's${RESET} ✅\n"
			@${AR} ${NAME} ${OBJS}
			@printf "${GREEN} 💻 Successfully created ${NAME} library${RESET} ✅\n"

${O_DIR}:
			@${MKDIR} ${O_DIR}

${O_DIR}%.o:${SRCS_DIR}%.c
			@${CC} ${CFLAGS} -I${HEADS_DIR} -o $@ -c $<
			@printf "\e[1K\r${BUILD} 🚧 $@ from $<${RESET}"

clean :
			@${RM} ${O_DIR}
			@printf "${RED}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-${RESET}\n"
			@printf "${RED} 🧹 Deleted ${NAME} .o's${RESET} ❌\n"
			@printf "${RED}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-${RESET}\n"

fclean :
			@${RM} ${O_DIR}
			@printf "${RED} 🧹 Deleted ${NAME} .o's${RESET} ❌\n"
			@printf "${RED}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-${RESET}\n"
			@${RM} ${NAME}
			@printf "${RED} 💥 Deleted ${NAME} files${RESET} ❌\n"

re : fclean all

norm :
			@printf "${DUCK} 🐥 Checking Norm for ${NAME}${RESET}\n"
			@norminette ${SRCS}

.PHONY : all clean fclean re norm
