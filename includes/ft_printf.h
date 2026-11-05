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

/*******************************************************************************
 *							MAIN FUNCTION GET_NEXT_LINE PROTOTYPE
 ******************************************************************************/
int			ft_printf(char const *, ...);

/*******************************************************************************
 *						STRUCT BUFFER AND CONSTANT BUFFER_SIZE
 ******************************************************************************/
/* MACRO - CONSTANT - BUFFER_SIZE */
# define BUFFER_SIZE 1024

typedef struct s_buffer
{
    char    data[BUFFER_SIZE];
    int     index;          // Posición actual en el buffer
    int     total_len;      // Total de caracteres impresos acumulados
}   t_buffer;

/*******************************************************************************
 *					STRUCT FLAGS & FT_SET_FLAGS
 ******************************************************************************/
typedef struct s_flags
{
    int minus;
    int zero;
    int width;
    int precision;
    int sharp;
    int space;
    int plus;
}   t_flags;

/* FUNCTION - INICIALIZED AND SETTING T_FLAGS */
t_flags		ft_init_flags(void);
t_flags		ft_set_flags(const char *str, int *i);

/*******************************************************************************
 *							BONUS FUNCTIONS - (FLAGS)
 ******************************************************************************/
int			ft_is_specifier(char c);
int			ft_parse_flags_safely(const char *s, int *i, t_flags *flags)

#endif
