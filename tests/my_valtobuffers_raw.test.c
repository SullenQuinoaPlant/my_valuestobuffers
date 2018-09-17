#define HOW_MANY_TESTS 10
#include "cmocka/my_overlay.h"

#include "libmyvaltobuffers.h"
#include "libmystupidmath.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	#define B_LEN 20
	T(vtb_uv_raw0,
		char			*tst_b;
			(tst_b = (char[B_LEN]){0xff, 0xff});
			//printf("tst_b initialized at : %s\n", tst_b);
		char			*ref_b;
			(ref_b = (char[B_LEN]){0xff, 0xff});
			//printf("ref_b initialized at : %s\n", tst_b);
		unsigned int	const pos = 2;
		unsigned int	a;

		for (a = 0; a < 10; a++) {
			vtb_uv_raw(a, &g_vtb_dec, tst_b + pos);
			sprintf(ref_b + pos, "%1d", a);
			assert_string_equal(tst_b, ref_b);
		}
		for (a = 10; a < 100; a++) {
			vtb_uv_raw(a, &g_vtb_dec, tst_b + pos + 1);
			sprintf(ref_b + pos, "%2d", a);
			assert_string_equal(tst_b, ref_b);
		}
	)
	#undef B_LEN

	T(vtb_lv_raw0,
		char	b[10];
		int		i;

		for (i = 0; i < sizeof(b); i++) {
			b[i] = 0;
		}
		vtb_lv_raw(1 << 3, sizeof(int), &g_vtb_oct, b);
		//printf("b is now : %s\n", b);
		assert_true(1);
	)

	#define B_LEN 20
	T(vtb_lv_raw1,
		char			*tst_b;
			(tst_b = (char[B_LEN]){0xff, 0xff});
		char			*ref_b;
			(ref_b = (char[B_LEN]){0xff, 0xff});
		unsigned int	const pos = B_LEN - 1;
		int				a;
		int				const a_sz = sizeof(a);

		for (a = 0; a < 10; a++) {
			vtb_lv_raw(a, a_sz, &g_vtb_hex, tst_b + pos);
			sprintf(ref_b + pos, "%1x", a);
			//printf("tst is : %s, ref is : %s\n", tst_b, ref_b);
			assert_string_equal(tst_b, ref_b);
		}
		for (a = 0; a < 10; a++) {
			vtb_lv_raw(a << 16, a_sz,
				&g_vtb_hex, tst_b + pos);
			sprintf(ref_b + pos, "%1x", a);
			//printf("tst is : %s, ref is : %s\n", tst_b, ref_b);
			assert_string_equal(tst_b, ref_b);
		}
		for (a = 17; a < 100; a++) {
			vtb_lv_raw(a << 16, a_sz,
				&g_vtb_hex, tst_b + pos);
			sprintf(ref_b + pos - 1, "%x", a);
			//printf("tst is : %s, ref is : %s\n", tst_b, ref_b);
			assert_string_equal(tst_b, ref_b);
		}
	)
	#undef B_LEN

	#define B_LEN 20
	T(vtb_sv_raw_allsigned,
		char			*tst_b;
			(tst_b = (char[B_LEN]){0xff, 0xff});
		char			*ref_b;
			(ref_b = (char[B_LEN]){0xff, 0xff});
		unsigned int	const pos = 2;
		int				a;

		for (a = -9; a < 10; a++) {
			vtb_sv_raw(a, &g_vtb_dec, tst_b + pos + 1, e_vtb_spall);
			sprintf(ref_b + pos, "%+1d", a);
			assert_string_equal(tst_b, ref_b);
		}
	)
	#undef B_LEN

	#define B_LEN 20
	T(vtb_sv_saw_negsigned,
		char			*tst_b;
			(tst_b = (char[B_LEN]){0xff, 0xff});
		char			*ref_b;
			(ref_b = (char[B_LEN]){0xff, 0xff});
		unsigned int	const pos = 2;
		int				a;
		size_t			ret;

		for (a = 0; a < 10; a++) {
			ret = vtb_sv_raw(a, &g_vtb_dec, tst_b + B_LEN - 2, e_vtb_spneg);
			sprintf(ref_b + pos, "%1d", a);
			assert_string_equal(tst_b + B_LEN - 1 - ret, ref_b + pos);
		}
		for (a = -9; a < 0; a++) {
			ret = vtb_sv_raw(a, &g_vtb_dec, tst_b + B_LEN - 2, e_vtb_spneg);
			sprintf(ref_b + pos, "%1d", a);
			assert_string_equal(tst_b + B_LEN - 1 - ret, ref_b + pos);
		}
	)
	#undef B_LEN
	return(run_test_arr(all_of, these));
}
