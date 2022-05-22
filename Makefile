# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 18:29:51 by lduboulo          #+#    #+#              #
#    Updated: 2022/05/22 19:51:20 by lduboulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
BUILD	= \e[38;5;225m
SEP		= \e[38;5;120m
DUCK	= \e[38;5;227m
RESET	= \033[0m

# COLORS

##############################  FOLDER  ########################################
O_DIR			:= ./objs/
SRCS_DIR		:= ./src/
READLINE_FOLDER	:= readline/
################################################################################


##############################   FILES  ########################################
MAIN_FILES		= minishell.c
READLINE_FILES	= prompt.c
################################################################################

OBJS_MAIN		= $(addprefix ${O_DIR}, ${MAIN_FILES:.c=.o})
OBJS_READLINE	= $(addprefix ${O_DIR}${READLINE_FOLDER}, ${READLINE_FILES:.c=.o})


OBJS			:= ${OBJS_MAIN} ${OBJS_READLINE}

HEADS_DIR		= ./includes/

NAME			= minishell


LIBUTILS		= ./utils/


MAKELIB			= ${MAKE} -C
CC				= gcc
AR				= ar rcs
MKDIR			= mkdir
RM				= rm -rf

CFLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=address -I~/.brew/opt/readline/include

TSEP			= ${SEP}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=${RESET}



all:			${NAME}

${NAME}:		${OBJS}
				@printf "\n"
				@${MAKELIB} ${LIBUTILS}
				@printf "${TSEP}\n"
				@printf "${GREEN} 💻 Successfully compiled ${NAME} .o's${RESET} ✅\n"
				@${CC} ${CFLAGS} -L ~/.brew/opt/readline/lib -lreadline -o ${NAME} ${OBJS} ${LIBUTILS}/libutils.a
				@printf "${GREEN} 💻 Successfully created ${NAME} executable${RESET} ✅\n"
				@printf "${TSEP}\n"

${O_DIR}%.o : ${SRCS_DIR}%.c
				@${MKDIR} $(dir $@)
				@${CC} ${CFLAGS} -I${HEADS_DIR} -o $@ -c $<
				@printf "\e[1K\r${BUILD} 🚧 $@ from $<${RESET}"

clean :
				@${RM} ${O_DIR}
				@${MAKELIB} ${LIBUTILS} clean
				@printf "${RED} 🧹 Deleted ${NAME} .o's${RESET} ❌\n"

fclean :
				@${RM} ${O_DIR}
				@printf "${RED} 🧹 Deleted ${NAME} .o's${RESET} ❌\n"
				@${RM} ${NAME} ${NAME}.dSYM
				@${MAKELIB} ${LIBUTILS} fclean
				@printf "${RED} 💥 Deleted ${NAME} files${RESET} ❌\n"

re : 			fclean all

norm :
				@${MAKELIB} ${LIBUTILS} norm
				@printf "${DUCK} 🐥 Checking Norm for ${NAME}${RESET}\n"
				@norminette ${SRCS_DIR}
				@norminette ${HEADS_DIR}

.PHONY : all clean fclean re norm
