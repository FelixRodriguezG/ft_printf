/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:25:16 by felixrod          #+#    #+#             */
/*   Updated: 2026/11/04 16:25:21 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_flag ft_inti_flags(t_flags *flags)                                      
{                                                                                
	t_flag	flag;                                                                
	flag.minus = 0;                                                              
	flag.zero = 0;                                                               
	flag.width = 0;                                                              
	flag.precision= -1;                                                          
	flag.sharp = 0;                                                              
	flag.space = 0;                                                              
	flag.plus = 0;                                                               
	flag.spec = 0;
	return (flag);                                                               
}

int	ft_printf(char const *format, ...)
{

}

int	main()
{
	ft_printf("hola");

	return (0);
}

