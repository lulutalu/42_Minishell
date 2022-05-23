# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo && lzima				            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 18:29:51 by lduboulo          #+#    #+#              #
#    Updated: 2022/05/23 23:14:11 by lduboulo         ###   ########.fr        #
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
MEMORY_FOLDER	:= memory/
ERROR_FOLDER	:= error/
BUILTS_FOLDER	:= built-ins/
################################################################################


##############################   FILES  ########################################
MAIN_FILES		= minishell.c
READLINE_FILES	= prompt.c
MEMORY_FILES	= 
ERROR_FILES		=
BUILTS_FILES	=
################################################################################

OBJS_MAIN		= $(addprefix ${O_DIR}, ${MAIN_FILES:.c=.o})
OBJS_READLINE	= $(addprefix ${O_DIR}${READLINE_FOLDER}, ${READLINE_FILES:.c=.o})
OBJS_MEMORY		= $(addprefix ${O_DIR}${MEMORY_FOLDER}, ${MEMORY_FILES:.c=.o})
OBJS_ERROR		= $(addprefix ${O_DIR}${ERROR_FOLDER}, ${ERROR_FILES:.c=.o})
OBJS_BUILTS		= $(addprefix ${O_DIR}${BUILTS_FOLDER}, ${BUILTS_FILES:.c=.o})

OBJS			:= ${OBJS_MAIN} ${OBJS_READLINE} ${OBJS_MEMORY} ${OBJS_ERROR} \
				   ${OBJS_BUILTS}

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
				@printf "\n${BUILD}\t\e[4m$(dir $@) Directory Created 📎${RESET}\n"
				@${CC} ${CFLAGS} -I${HEADS_DIR} -o $@ -c $<
				@printf "\e[1K\r${BUILD} 🚧 $@ from $<${RESET}"
				@printf "\n"

clean :
				@${RM} ${O_DIR}
				@${MAKELIB} ${LIBUTILS} clean
				@printf "${RED} 🧹 Deleted ${NAME} .o's${RESET} ❌\n"
				@printf "${RED}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-${RESET}\n"

fclean :
				@${RM} ${O_DIR}
				@printf "${RED}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-${RESET}\n"
				@printf "${RED} 🧹 Deleted ${NAME} .o's${RESET} ❌\n"
				@${RM} ${NAME} ${NAME}.dSYM
				@${MAKELIB} ${LIBUTILS} fclean
				@printf "${RED} 💥 Deleted ${NAME} files${RESET} ❌\n"
				@printf "${RED}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-${RESET}\n"

re : 			fclean all

norm :
				@${MAKELIB} ${LIBUTILS} norm
				@printf "${DUCK} 🐥 Checking Norm for ${NAME}${RESET}\n"
				@norminette ${SRCS_DIR}
				@norminette ${HEADS_DIR}

.PHONY : all clean fclean re norm
