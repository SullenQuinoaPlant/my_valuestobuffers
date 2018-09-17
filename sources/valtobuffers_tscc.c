/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valtobuffers_tscc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:15:46 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 15:15:48 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static t_s_vtb_bd						make_tbd(
	char const *basestr)
{
	t_s_vtb_bd	ret;

	ret.syms = basestr;
	ret.radius = ft_strlen(basestr);
	return (ret);
}

t_s_vtb_cc								vtb_uv_tscc(
	uintmax_t val,
	char const *const basestr,
	t_vtb_mib *b)
{
	t_s_vtb_cc	ret;
	char		*b_end;
	t_s_vtb_bd	base;

	b_end = (char*)b + VTB_MIB_OFFSET;
	*b_end = 0;
	base = make_tbd(basestr);
	ret.len = vtb_uv_raw(val, &base, b_end - 1);
	ret.c = b_end - ret.len;
	return (ret);
}

/*
**see vtb_lv_raw for restrictions on use of vtb_lv_tscc
*/
t_s_vtb_cc								vtb_lv_tscc(
	uintmax_t val,
	int val_sz,
	char const *const basestr,
	t_vtb_mib *b)
{
	t_s_vtb_cc	ret;
	char		*b_end;
	t_s_vtb_bd	base;

	b_end = (char*)b + VTB_MIB_OFFSET;
	*b_end-- = 0;
	base = make_tbd(basestr);
	ret.len = vtb_lv_raw(val, val_sz, &base, b_end);
	ret.c = b_end - ret.len + 1;
	return (ret);
}

t_s_vtb_cc								vtb_sv_tscc(
	intmax_t val,
	char const *const basestr,
	t_vtb_mib *b,
	t_e_vtb_sp sign_f)
{
	t_s_vtb_cc	ret;
	char		*b_end;
	t_s_vtb_bd	base;

	b_end = (char*)b + VTB_MIB_OFFSET;
	*b_end-- = 0;
	base = make_tbd(basestr);
	ret.len = vtb_sv_raw(val, &base, b_end, sign_f);
	ret.c = b_end - ret.len + 1;
	return (ret);
}
