/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_descriptions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:16:51 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 15:36:05 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myvaltobuffers.h"

t_s_vtb_bd const	g_vtb_bin = {VTB_BIN_SYMS, 2};
t_s_vtb_bd const	g_vtb_oct = {VTB_OCT_SYMS, 8};
t_s_vtb_bd const	g_vtb_dec = {VTB_DEC_SYMS, 10};
t_s_vtb_bd const	g_vtb_hex = {VTB_HEX_SYMS, 16};
t_s_vtb_bd const	g_vtb_bhex = {VTB_BHEX_SYMS, 16};
t_s_vtb_bd const	g_vtb_0x10 = {VTB_RAWH, 16};
