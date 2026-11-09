/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 12:32:12 by felixrod          #+#    #+#             */
/*   Updated: 2026/11/05 14:03:10 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

# define MAX_DIGITS 64

/*******************************************************************************
 *							TYPEDEF T_OUT - T_FLAGS - T_FIELD
 ******************************************************************************/
typedef struct s_out
{
    int	len;      /* caracteres escritos hasta ahora: lo que devuelve ft_printf */
    int	error;    /* 1 en cuanto un write devuelva -1 */
}	t_out;

typedef struct s_flags
{
    int		minus;      /* '-'  alinear a la izquierda */
    int		zero;       /* '0'  rellenar con ceros */
    int		width;      /* ancho mínimo del campo */
    int		precision;  /* '.'  -1 = no se ha escrito '.' */
    int		sharp;      /* '#'  0x / 0X */
    int		space;      /* ' '  espacio delante de positivos */
    int		plus;       /* '+'  signo delante de positivos */
    char	spec;       /* la letra: c s p d i u x X % */
}	t_flags;

typedef struct s_field
{
    const char	*prefix;    /* "", "-", "+", " ", "0x", "0X" */
    const char	*body;      /* los dígitos o el texto (no tiene por qué acabar en '\0') */
    int			body_len;   /* cuántos caracteres de body se imprimen */
    int			zeros;      /* ceros entre el prefijo y el cuerpo */
}	t_field;



/*******************************************************************************
 *							MAIN FUNCTION GET_NEXT_LINE PROTOTYPE
 ******************************************************************************/
int		ft_printf(char const *str, ...);
t_flags	ft_init_flags(void);
t_flags	ft_set_flags(const char *str, int *i);
void	ft_out_char(t_out *out, char ch);
void	ft_out_nstr(t_out *out, const char *str, int n);
void	ft_out_field(t_out *out, t_flags *flag, t_field *fl);
void	ft_print_char(t_out *out, t_flags *flag, int ch);
void	ft_print_str(t_out *out, t_flags *flag, const char *str);
void	ft_print_ptr(t_out *out, t_flags *flag, void *ptr);
void	ft_print_int(t_out *out, t_flags *flag, int n);
void	ft_print_unsigned(t_out *out, t_flags *flag, unsigned int n);
void	ft_print_number(t_out *out, t_flags *flag, unsigned long n,
            const char *prefix);
#endif
