/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_descriptions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:16:51 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 15:16:55 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char const *const	g_vtb_oct_syms = "01234567";
char const *const	g_vtb_dec_syms = "0123456789";
char const *const	g_vtb_hex_syms = "0123456789abcdef";
char const *const	g_vtb_bhex_syms = "0123456789ABCDEF";
char const *const	g_vtb_rawhex =\
	(char[]){
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

t_s_bd const		g_oct = {g_vtb_oct_syms, 8};
t_s_bd const		g_dec = {g_vtb_dec_syms, 10};
t_s_bd const		g_hex = {g_vtb_hex_syms, 16};
t_s_bd const		g_bhex = {g_vtb_bhex_syms, 16};
t_s_bd const		g_0x10 = {g_vtb_rawhex, 16};
