/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 20:54:38 by felixrod          #+#    #+#             */
/*   Updated: 2026/11/08 21:33:35 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_out_char(t_out *out, char ch)
{
	if (out->error)
		return ;
	if (write(1, &ch,1) == -1)
		out->error = 1;
	else
		out->len++;
}

void	ft_out_nstr(t_out *out, const char *str, int n)
{
	if (out->error || n <= 0)
		return ;
	if (write(1, str, n) == -1)
		out->error = 1;
	else
		out->len += n;
}

static void ft_out_repeat(t_out *out, char ch, int n)
{
	while (n > 0)
	{
		ft_out_char(out, ch);
		n--;
	}
}

void ft_out_field(t_out *out, t_flags *flag, t_field *field)
{
	int pad;
	int	prefix_len;
	
	prefix_len = ft_strlen(field->prefix);
	pad = flag->width - prefix_len - field->zeros - field->body_len;
	if (flag->zero && pad > 0)
	{
		field->zeros += pad;
		pad = 0;
	}
	if (!flag->minus)
		ft_out_repeat(out, ' ', pad);
	ft_out_nstr(out, field->prefix, prefix_len);
	ft_out_repeat(out, '0', field->zeros);
	ft_out_nstr(out, field->body, field->body_len);
	if (flag->minus)
        ft_out_repeat(out, ' ', pad);
}
