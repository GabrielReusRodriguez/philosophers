NAME=philo
#CDEBUG = -g3 -fsanitize=address
CDEBUG = -g3
PTHREAD_FLAG = -pthread
CFLAGS=-Wall -Wextra -Werror -MMD -MP ${CDEBUG} ${PTHREAD_FLAG}

SRC_DIR=.
OBJ_DIR=./obj
INC_DIR=./inc


#BONUS_SRC_DIR=./bonus_src
#BONUS_INC_DIR=./bonus_inc

SRC_FILES=	ft_args.c				\
			ft_fork.c				\
			ft_mutex_bflag.c		\
			ft_mutex_meal.c			\
			ft_mutex_meal2.c		\
			ft_philosopher.c		\
			ft_philosopher2.c		\
			ft_philosopher3.c		\
			ft_rules.c				\
			ft_sleep.c				\
			ft_table.c				\
			ft_timestamp.c			\
			ft_thread.c				\
			ft_utils_atoi.c			\
			ft_utils_ctoi.c			\
			ft_utils_contains_num.c	\
			ft_utils_isdigit.c		\
			ft_utils_print.c		\
			ft_utils_strlen.c		\
			philo.c

#BONUS_SRC_FILES=	

OBJ_FILES=$(SRC_FILES:%.c=$(OBJ_DIR)/%.o)
DEP_FILES=$(SRC_FILES:%.c=$(OBJ_DIR)/%.d)

#OBJ_BONUS_FILES=$(BONUS_SRC_FILES:%.c=$(OBJ_DIR)/%.o)
#DEP_BONUS_FILES=$(BONUS_SRC_FILES:%.c=$(OBJ_DIR)/%.d)

all: $(NAME)

#bonus: $(OBJ_DIR) ${LIBFT_LIB} ${OBJ_BONUS_FILES}
#	cc ${OBJ_BONUS_FILES} -o ${NAME} ${LIBFT_LIB}
#	@touch bonus

$(NAME): $(OBJ_DIR) $(OBJ_FILES) 
	cc ${OBJ_FILES} -o ${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	cc $(CFLAGS) -I${INC_DIR} -c $< -o $@

#$(OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c Makefile
#	cc $(CFLAGS) -I${BONUS_INC_DIR} -I${LIBFT_INC_DIR} -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OBJ_DIR)/*.d

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP_FILES)

.PHONY: all clean fclean re