# ==============================================================================
# 1. NAME OF LIBFTPRINTF.A
# ==============================================================================

NAME        = libftprintf.a

# ==============================================================================
# 2. TOOLS, FLAGS AND VARIABLES 
# ==============================================================================

SHELL      := /bin/bash
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I$(INCLUDES) -I$(LIBFT_DIR)
AR          = ar -rcs
RM          = rm -f
LIBFT_DIR   = libft
INCLUDES	= includes
SRCS		= srcs
LIBFT       = $(LIBFT_DIR)/libft.a
HEADER      = $(INCLUDES)/ft_printf.h

# ==============================================================================
# 3. ANSI COLORS - OUTPUT FORMAT
# ==============================================================================

DEF_COLOR   = \033[0m
GRAY        = \033[38;2;128;128;128m
RED         = \033[38;2;255;85;85m
GREEN       = \033[38;2;80;250;123m
YELLOW      = \033[38;2;255;215;0m
BLUE        = \033[38;2;97;175;239m
MAGENTA     = \033[38;2;189;147;249m
CYAN        = \033[38;2;139;233;253m
WHITE       = \033[38;2;255;255;255m

# ==============================================================================
# 4. ARCHIVOS FUENTE Y OBJETOS
# ==============================================================================

# LIBFTPRINTF.A - Archivos obligatorios (se usan en AMBAS versiones)
SRCS_MANDATORI = ft_print_char.c                ft_print_str.c                \
                 ft_print_ptr.c                ft_print_duble.c              \
                 ft_print_int.c                ft_print_unsigned_duble.c     \
                 ft_print_lower_hex.c          ft_print_upper_hex.c          \
                 ft_print_percent.c

# LIBFTPRINTF.A - Archivos exclusivos del BONUS (parseo y gestión de flags)
SRCS_BONUS     = ft_parse_format_bonus.c       ft_flags_bonus.c

# Variable con todos los SRC_
SRC_MANDATORI_FILES = $(addprefix $(SRCS)/, $(SRCS_MANDATORI))
SRC_BONUS_FILE      = $(addprefix $(SRCS)/, $(SRCS_BONUS))

# Condicional para manejar el bonus o solo el mandatory según la regla ejecutada
ifdef WITH_BONUS
    SRC_FILES = $(SRC_MANDATORI_FILES) $(SRC_BONUS_FILE)
else
    SRC_FILES = $(SRC_MANDATORI_FILES)
endif

OBJS        = $(SRC_FILES:.c=.o)

# ============================================================================== 
# 5. REGLAS PRINCIPALES
# ==============================================================================
 
all: $(NAME)

bonus:
	@$(MAKE) WITH_BONUS=1 all
	@printf "    $(MAGENTA)─────────────────────────────────────────$(DEF_COLOR)\n"
	@printf "    $(MAGENTA) ✔ Versión $(CYAN)BONUS$(MAGENTA) compilada con éxito!$(DEF_COLOR)\n"
	@printf "    $(MAGENTA)─────────────────────────────────────────$(DEF_COLOR)\n"

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(AR) $@ $(OBJS)
	@printf "	$(GREEN)─────────────────────────────────────────$(DEF_COLOR)\n"
	@printf "	$(GREEN) ✔ Librería $(CYAN)%-10s$(GREEN) creada con éxito!$(DEF_COLOR)\n" "$(NAME)"
	@printf "	$(GREEN)─────────────────────────────────────────$(DEF_COLOR)\n"
	
$(LIBFT):
	@make -C $(LIBFT_DIR)
	@printf "	$(GREEN)─────────────────────────────────────────$(DEF_COLOR)\n"
	@printf "	$(GREEN) ✔ Librería $(CYAN)%-10s$(GREEN) creada con éxito!$(DEF_COLOR)\n" "$(LIBFT)"
	@printf "	$(GREEN)─────────────────────────────────────────$(DEF_COLOR)\n"

%.o: $(SRCS)/%.c $(HEADER)
	@printf "$(CYAN)⚙  %-16s$(DEF_COLOR) %-20s $(CYAN)->$(DEF_COLOR) $(GREEN)%s$(DEF_COLOR)\n" "[ COMPILANDO ]" "$<" "$@"
	@$(CC) $(CFLAGS) -c $< -o $@

# ==============================================================================
# 6. REGLAS DE LIMPIEZA ALINEADAS EN COLUMNAS
# ==============================================================================

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@printf "$(RED)	%-20s$(DEF_COLOR) - Objetos temporales (.o) eliminados.\n" "[ LIMPIANDO ]"


fclean: clean 
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@printf "$(RED)	%-20s$(DEF_COLOR) - Librería $(CYAN)%s$(DEF_COLOR) eliminada.\n" "[ LIMPIANDO TODO ]" "$(NAME)"

re: fclean
	@printf "$(YELLOW)	%-20s$(DEF_COLOR) - Recompilando todo el proyecto...\n\n" "[ RECOMPILANDO ]"
	@$(MAKE) all

.PHONY: all clean fclean re 
