/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_valtobuffers_raw.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:08:12 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 15:09:42 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

size_t							my_valtobuffer(
	uintmax_t val,
	t_s_bd const *base,
	char *b_end)
{
	unsigned char const	r = base->radius;
	char const			*syms = base->syms;
	size_t				i;

	i = 0;
	while (val || i == 0)
	{
		*(b_end - i++) = syms[val % r];
		val /= r;
	}
	return (i);
}

/*
**NOTE ON THE FOLLOWING : (my_lowvaltob)
**displays values encoded as sums of negative powers of 2
**	in which alignment must be done on highest order bit
**	(closest to decimal pivot)
**only works with bases that are powers of 2,
**most significant bits set to 0 should be avoided
**ijk array:
**	i digits are trailing zeros
**	j digits are yummy
**	k digits may represent any uintmax_t
*/

#define I 0
#define J 1
#define K 2

size_t							my_lowvaltob(
	uintmax_t val,
	int val_sz,
	t_s_bd const *base,
	char *b_end)
{
	unsigned char const	r = base->radius;
	char const			*syms = base->syms;
	int					log2;
	size_t				ijk[3];
	uintmax_t			mask;

	log2 = my_flog2(r);
	ijk[K] = (val_sz * CHAR_BIT) / log2;
	mask = ~0 << log2;
	ijk[I] = 0;
	while (!(~mask & val) && (ijk[I] < ijk[K]))
	{
		ijk[I]++;
		val /= r;
	}
	ijk[J] = 0;
	while ((ijk[I] + ijk[J]) < ijk[K] || ijk[J] == 0)
	{
		*(b_end - ijk[J]++) = syms[val % r];
		val /= r;
	}
	return (ijk[J]);
}

#undef I
#undef J
#undef K

size_t							my_signvaltob(
	intmax_t val,
	t_s_bd const *base,
	char *b_end,
	t_e_sp sign_f)
{
	size_t		i;
	int			sign;

	sign = val < 0 ? -1 : 1;
	i = my_valtobuffer((val * sign), base, b_end);
	*(b_end - i) = sign < 0 ? '-' : '+';
	if (val < 0 || sign_f == e_all ||
		(val && sign_f == e_abs))
		i++;
	return (i);
}
