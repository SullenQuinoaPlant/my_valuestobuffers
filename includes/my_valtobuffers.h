#ifndef MY_BUFFERS_H
# define MY_BUFFERS_H

# include <stdint.h>
# include "libft.h"
# include "libmystupidmath.h"

extern char const	* const g_oct_syms;
extern char const	* const g_dec_syms;
extern char const	* const g_hex_syms;
extern char const	* const g_bhex_syms;

typedef struct	s_base_descriptor {
	char const	*syms;
	char 		radius;
}				t_s_bd;

extern t_s_bd const	g_oct;
extern t_s_bd const	g_dec;
extern t_s_bd const	g_hex;
extern t_s_bd const	g_bhex;
extern t_s_bd const	g_0x10;

# define BIGGEST_BASE2 (sizeof(uintmax_t) * 8)
# define BIGGEST_SIGNED BIGGEST_BASE2 + 1
# define BIGGEST_SIGNED_STRING BIGGEST_SIGNED + 1

enum			e_max_buffer_offsets {
	e_mbo_mib = BIGGEST_SIGNED_STRING - 1,
};

/*max int buffer*/
typedef char	t_mib[BIGGEST_SIGNED_STRING];

typedef enum	e_sign_policy {
	e_neg,
	e_all,
	e_abs
}				t_e_sp;

typedef struct	s_contiguous_chars {
	char	*c;
	size_t	len;
}				t_s_cc;

/*only works with bases that are powers of 2,
**most significant bits set to 0 should be avoided
*/
t_s_cc
	my_lowv_tob(
		uintmax_t val,
		int val_sz,
		char const * const basestr,
		t_mib *b);

size_t
	my_lowvaltob(
		uintmax_t val,
		int val_sz,
		t_s_bd const *base,
		char *b_end);

size_t
	my_signvaltob(
		intmax_t val,
		t_s_bd const *base,
		char *b_end,
		t_e_sp sign_f);

t_s_cc
	my_uv_tob(
		uintmax_t val,
		char const * const basestr,
		t_mib *b);

t_s_cc
	my_v_tob(
		intmax_t val,
		char const * const basestr,
		t_mib *b,
		t_e_sp sign_f);

size_t
	my_valtobuffer(
		uintmax_t val,
		t_s_bd const *base,
		char *b_end);

#endif
