/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valtobuffers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:21:59 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 15:42:41 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_BUFFERS_H
# define MY_BUFFERS_H

# include <stdint.h>

extern char const *const	g_vtb_oct_syms;
extern char const *const	g_vtb_dec_syms;
extern char const *const	g_vtb_hex_syms;
extern char const *const	g_vtb_bhex_syms;
extern char const *const	g_vtb_rawhex;

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

# define BIGGEST_BASE2 (sizeof(uintmax_t) * 8)
# define BIGGEST_SIGNED BIGGEST_BASE2 + 1
# define BIGGEST_SIGNED_STRING BIGGEST_SIGNED + 1

enum						e_vtb_max_buffer_offsets
{
	e_vtb_mbo_mib = BIGGEST_SIGNED_STRING - 1,
};

/*
**max int buffer
*/
typedef char t_mib[BIGGEST_SIGNED_STRING];

typedef enum				e_vtb_sign_policy
{
	e_vtb_neg,
	e_vtb_all,
	e_vtb_abs
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
t_s_vtb_cc						my_lowv_tob(
t_s_vtb_cc						vtb_lv_tscc(
	uintmax_t val,
	int val_sz,
	char const * const basestr,
	t_mib *b);

size_t						my_lowvaltob(
size_t							vtb_lv_raw(
		uintmax_t val,
		int val_sz,
		t_s_vtb_bd const *base,
		char *b_end);

size_t						my_signvaltob(
size_t							vtb_sv_raw(
		intmax_t val,
		t_s_vtb_bd const *base,
		char *b_end,
		t_e_vtb_sp sign_f);

t_s_vtb_cc						my_uv_tob(
t_s_vtb_cc						vtb_uv_tscc(
		uintmax_t val,
		char const * const basestr,
		t_mib *b);

t_s_vtb_cc						my_v_tob(
t_s_vtb_cc						vtb_v_tscc(
		intmax_t val,
		char const * const basestr,
		t_mib *b,
		t_e_vtb_sp sign_f);

size_t						my_valtobuffer(
size_t							vtb_v_raw(
		uintmax_t val,
		t_s_vtb_bd const *base,
		char *b_end);

#endif
