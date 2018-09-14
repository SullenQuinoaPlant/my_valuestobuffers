/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_valtobuffers_tscc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:09:59 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 15:12:50 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static t_s_bd						make_tbd(
	char const *basestr)
{
	t_s_bd	ret;

	ret.syms = basestr;
	ret.radius = ft_strlen(basestr);
	return (ret);
}

t_s_cc								my_uv_tob(
	uintmax_t val,
	char const *const basestr,
	t_mib *b)
{
	t_s_cc	ret;
	char	*b_end;
	t_s_bd	base;

	b_end = (char*)b + e_mbo_mib;
	*b_end = 0;
	base = make_tbd(basestr);
	ret.len = my_valtobuffer(val, &base, b_end - 1);
	ret.c = b_end - ret.len;
	return (ret);
}

t_s_cc								my_lowv_tob(
	uintmax_t val,
	int val_sz,
	char const *const basestr,
	t_mib *b)
{
	t_s_cc	ret;
	char	*b_end;
	t_s_bd	base;

	b_end = (char*)b + e_mbo_mib;
	*b_end-- = 0;
	base = make_tbd(basestr);
	ret.len = my_lowvaltob(val, val_sz, &base, b_end);
	ret.c = b_end - ret.len + 1;
	return (ret);
}

t_s_cc								my_v_tob(
	intmax_t val,
	char const *const basestr,
	t_mib *b,
	t_e_sp sign_f)
{
	t_s_cc	ret;
	char	*b_end;
	t_s_bd	base;

	b_end = (char*)b + e_mbo_mib;
	*b_end-- = 0;
	base = make_tbd(basestr);
	ret.len = my_signvaltob(val, &base, b_end, sign_f);
	ret.c = b_end - ret.len + 1;
	return (ret);
}
