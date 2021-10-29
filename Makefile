################################################################################
# Makefile
################################################################################

# Makefile by mvaldeta (tired of !understanting makefiles)
# Version 0.0 made with minor changes from @fletcher97 Version: 1.2.1

# The goal is to iterate this Makefile with the help from my friends @fletcher97 
# & @DimitriDaSilva into my own version.

# changed ${AT}rm -r ${OBJ_ROOT} on clean targets to delete tmp folders

# helps to read the manual -> https://www.gnu.org/software/make/manual

################################################################################
# Variables
################################################################################

NAME1			= server
NAME2			= client
NAMES			= ${NAME1} #${NAME2}
#AR				= ar rcs

################################################################################
# Configs
################################################################################

# Verbose levels
# 0: Make will be totaly silenced
# 1: Make will print echos and printf
# 2: Make will not be silenced but target commands will not be printed
# 3: Make will print each command
# 4: Make will print all debug info
#
# If no value is specified or an incorrect value is given make will print each
# command like if VERBOSE was set to 3.
VERBOSE = 1

################################################################################
# Compiler & Flags
# ":=" / "=" explanation bellow.
# @43 calls multiple vars turned into a "one-time" expandible var.
# https://www.gnu.org/software/make/manual/html_node/Flavors.html#Flavors
################################################################################

CC = gcc -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror #-Wvla
DFLAGS = -g
SANITIZE = -fsanitize=address

################################################################################
# Folders & Files
################################################################################

BIN_ROOT 		= bin/
DEP_ROOT 		= dep/
INC_ROOT		= includes/
LIB_ROOT		= libft/
SRC_ROOT		= srcs/
OBJ_ROOT		= obj/

# Libft
LIBFT_ROOT := ${LIB_ROOT}
LIBFT_INC := ${LIBFT_ROOT}includes/
LIBFT := ${LIBFT_ROOT}bin/libft.a
LIBS := -L${LIBFT_ROOT}bin -lft

DIRS			= srcs

SRC_DIRS		:= $(addprefix ${SRC_ROOT}, ${DIRS})
OBJ_DIRS		:= $(addprefix ${OBJ_ROOT}, ${DIRS})
DEP_DIRS 		:= $(addprefix ${DEP_ROOT}, ${DIRS})
INC_DIRS		:= ${INC_ROOT} ${LIBFT_INC}

SRCS_MAIN 		:= $(foreach dir, $(filter-out ${SRC_ROOT}server/%, ${SRC_DIRS}), \
	$(wildcard ${dir}*.c))
OBJS_MAIN 		:= $(subst ${SRC_ROOT}, ${OBJ_ROOT}, ${SRCS_MAIN:.c=.o})
SRCS 			:= $(foreach dir, ${SRC_DIRS}, $(wildcard ${dir}*.c))
OBJS 			:= $(subst ${SRC_ROOT}, ${OBJ_ROOT}, ${SRCS:.c=.o})
DEPS 			:= $(subst ${SRC_ROOT}, ${DEP_ROOT}, ${SRCS:.c=.d})

INCS			:= ${addprefix -I, ${INC_DIRS}}
BINS			:= ${addprefix ${BIN_ROOT}, ${NAMES}}

################################################################################
# VPATHS
# vpath is a list of directories to be searched for missing source files
# -> https://www.cmcrossroads.com/article/basics-vpath-and-vpath
################################################################################

vpath %.o $(OBJ_ROOT)
vpath %.h $(INC_ROOT)
vpath %.c $(SRC_DIRS)
vpath %.d $(DEP_DIRS)

################################################################################
# Conditions
################################################################################

ifeq ($(shell uname), Linux)
	SED := sed -i.tmp --expression
	SED_END = && rm -f $@.tmp
else ifeq ($(shell uname), Darwin)
	SED = sed -i.tmp
	SED_END = && rm -f $@.tmp
endif

ifeq ($(VERBOSE),0)
	MAKEFLAGS += --silent
	BLOCK = >/dev/null
else ifeq ($(VERBOSE),1)
	MAKEFLAGS += --silent
else ifeq ($(VERBOSE),2)
	AT = @
else ifeq ($(VERBOSE),4)
	MAKEFLAGS += --debug=v
endif

################################################################################
# Colors & Template code
################################################################################

_YELLOW				:=		\e[38;5;184m
_GREEN				:=		\e[38;5;46m
_RESET				:=		\e[0m
_INFO				:=		[$(_YELLOW)INFO$(_RESET)]
_DONE				:=		[$(_GREEN)DONE$(_RESET)]

################################################################################
# Target
################################################################################

all: ${BINS}

${NAME1}: ${LIBFT} ${OBJS_MAIN}
	${AT}printf "\033[38;5;46m[CREATING ${NAME1}]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${BIN_ROOT}
	${AT}${CC} ${CFLAGS} ${INCS} ${OBJS_MAIN} ${LIBS} -o ${BIN_ROOT}$@

${LIBFT}:
	${AT}make -C ${LIBFT_ROOT} ${BLOCK}


################################################################################
# Setup Target
################################################################################

.init:
	${AT}printf "\033[33m[CREATING FOLDER STRUCTURE]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${BIN_ROOT}
	${AT}mkdir -p ${DEP_ROOT}
	${AT}mkdir -p ${INC_ROOT}
	${AT}mkdir -p ${OBJ_ROOT}
	${AT}mkdir -p ${SRC_ROOT}
	${AT}mkdir -p ${TESTS_ROOT}
	${AT}echo *.o\n*.d\n.vscode\na.out\n.init > .gitignore
	${AT}date > $@

################################################################################
# General Targets
################################################################################

clean:
	@ printf "$(_INFO) Deleted objects: OK!\n"
	${AT}mkdir -p ${OBJ_ROOT}
	${AT}find ${OBJ_ROOT} -type f -delete 2>/dev/null
	${AT}make -C ${LIBFT_ROOT} clean${BLOCK}
	${AT}rm -r ${OBJ_ROOT}

fclean: clean
	@ printf "$(_INFO) Deleted binaries: OK!\n"
	${AT}mkdir -p ${BIN_ROOT}
	${AT}find ${BIN_ROOT} -type f -delete
	${AT}make -C ${LIBFT_ROOT} fclean${BLOCK}
	${AT}rm -r ${BIN_ROOT}

clean_dep:
	@ printf "$(_INFO) Deleted dependencies: OK!\n"
	${AT}mkdir -p ${DEP_ROOT}
	${AT}find ${DEP_ROOT} -type f -delete 2>/dev/null
	${AT}make -C ${LIBFT_ROOT} clean_dep${BLOCK}
	${AT}rm -r ${DEP_ROOT}

clean_all: clean_dep fclean
	${AT}make -C ${LIBFT_ROOT} clean_all${BLOCK}

re: fclean all

################################################################################
# .PHONY
################################################################################

.PHONY : clean fclean clean_dep clean_all re all 

################################################################################
# Function
################################################################################

define make_bin
${1} : ${2}
endef

define make_obj
${1} : ${2} ${3}
	$${AT}printf "\033[38;5;14m[OBJ]: \033[38;5;47m$$@\033[0m\n" ${BLOCK}
	$${AT}mkdir -p $${@D}
	$${AT}$${CC} $${CFLAGS} $${INCS} -c $$< -o $$@
endef

define make_dep
${1} : ${2}
	$${AT}printf "\033[38;5;13m[DEP]: \033[38;5;47m$$@\033[0m\n" ${BLOCK}
	$${AT}mkdir -p $${@D} $${BLOCK}
	$${AT}$${CC} -MM $$< $${INCS} -MF $$@ $${BLOCK}
	$${AT}$${SED} 's|:| $$@ :|' $$@ $${SED_END} $${BLOCK}
	$${AT}$${SED} '1 s|^|$${@D}/|' $$@ $${SED_END} $${BLOCK}
endef

################################################################################
# Function Generator
################################################################################

$(foreach bin, $(BINS), $(eval \
$(call make_bin, $(bin), $(notdir $(bin)))))

$(foreach src, $(SRCS), $(eval \
$(call make_dep, $(subst ${SRC_ROOT}, ${DEP_ROOT}, $(src:.c=.d)), $(src))))

$(foreach src, $(SRCS), $(eval \
$(call make_obj, $(subst ${SRC_ROOT}, ${OBJ_ROOT}, $(src:.c=.o)), \
$(src), \
$(subst ${SRC_ROOT}, ${DEP_ROOT}, $(src:.c=.d)))))

################################################################################
# Includes 
################################################################################
-include ${DEPS}
