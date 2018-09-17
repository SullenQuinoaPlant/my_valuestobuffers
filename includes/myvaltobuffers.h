/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myvaltobuffers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:21:59 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 15:42:41 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYVALTOBUFFERS_H
# define MYVALTOBUFFERS_H

# include <stddef.h>
# include <stdint.h>

# define VTB_OCT_SYMS "01234567"
# define VTB_DEC_SYMS "0123456789"
# define VTB_HEX_SYMS "0123456789abcdef"
# define VTB_BHEX_SYMS "0123456789ABCDEF"
# define VTB_RAWH (char[]){0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}

typedef struct				s_vtb_base_descriptor
{
	char const	*syms;
	char		radius;
}							t_s_vtb_bd;

extern t_s_vtb_bd const		g_vtb_oct;
extern t_s_vtb_bd const		g_vtb_dec;
extern t_s_vtb_bd const		g_vtb_hex;
extern t_s_vtb_bd const		g_vtb_bhex;
extern t_s_vtb_bd const		g_vtb_0x10;

# define VTB_BIGGEST_BASE2 (sizeof(uintmax_t) * 8)
# define VTB_BIGGEST_SIGNED VTB_BIGGEST_BASE2 + 1
# define VTB_BIGGEST_SIGNED_STRING VTB_BIGGEST_SIGNED + 1

# define VTB_MIB_OFFSET VTB_BIGGEST_SIGNED_STRING - 1

/*
**max int buffer
*/
typedef char t_vtb_mib[VTB_BIGGEST_SIGNED_STRING];

typedef enum				e_vtb_sign_policy
{
	e_vtb_spneg,
	e_vtb_spall,
	e_vtb_spabs
}							t_e_vtb_sp;

typedef struct				s_vtb_contiguous_chars
{
	char	*c;
	size_t	len;
}							t_s_vtb_cc;

/*
**only works with bases that are powers of 2,
**most significant bits set to 0 should be avoided
*/
size_t							vtb_lv_raw(
		uintmax_t val,
		int val_sz,
		t_s_vtb_bd const *base,
		char *b_end);

t_s_vtb_cc						vtb_lv_tscc(
	uintmax_t val,
	int val_sz,
	char const * const basestr,
	t_vtb_mib *b);

size_t							vtb_sv_raw(
		intmax_t val,
		t_s_vtb_bd const *base,
		char *b_end,
		t_e_vtb_sp sign_f);

t_s_vtb_cc						vtb_sv_tscc(
		intmax_t val,
		char const * const basestr,
		t_vtb_mib *b,
		t_e_vtb_sp sign_f);

size_t							vtb_uv_raw(
		uintmax_t val,
		t_s_vtb_bd const *base,
		char *b_end);

t_s_vtb_cc						vtb_uv_tscc(
		uintmax_t val,
		char const * const basestr,
		t_vtb_mib *b);

#endif
