/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmystupidmath.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:55:38 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/14 12:58:23 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMYSTUPIDMATH_H
# define LIBMYSTUPIDMATH_H

# include <stdint.h>

/*
** computation options :
**# define LNL_SERIES_DEPTH xxx //see lnl.c
**# define EXP_SERIES_DEPTH xxx //see expl.c
*/

/*
**mathematical constants :
*/
# define M_EL 2.718281828459045235360287471352662498L
# define M_LN2L 0.693147180559945309417232121458176568L
# define M_LN10L 2.302585092994045684017991454684364208L

/*
**functions :
*/
long double						my_expl(
	long double x);

int								my_flog2(
	uintmax_t x);

long double						my_intpowl(
	long double x, intmax_t n);

long double						my_lnl(
	long double x);

long double						my_powl(
	long double x, long double y);

long double						my_uintpowl(
	long double x,
	uintmax_t n);

#endif
