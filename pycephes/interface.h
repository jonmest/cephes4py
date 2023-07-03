typedef struct {
  double n; /* numerator */
  double d; /* denominator */
} fract;

typedef struct {
  long double r;
  long double i;
} cmplxl;

typedef struct {
  float r;
  float i;
} cmplxf;

typedef struct {
  double r;
  double i;
} cmplx;

double hcephes_bdtr(int k, int n, double p);
double hcephes_bdtrc(int k, int n, double p);
double hcephes_bdtri(int k, int n, double y);
double hcephes_beta(double a, double b);
double hcephes_btdtr(double a, double b, double x);
double hcephes_cabs(cmplx *z);
double hcephes_cbrt(double x);
double hcephes_chbevl(double x, double array[], int n);
double hcephes_chdtr(double df, double x);
double hcephes_chdtrc(double df, double x);
double hcephes_chdtri(double df, double y);
double hcephes_cosm1(double x);
double hcephes_dawsn(double xx);
double hcephes_ei(double x);
double hcephes_ellie(double phi, double m);
double hcephes_ellik(double phi, double m);
double hcephes_ellpe(double x);
double hcephes_ellpk(double x);
double hcephes_erf(double a);
double hcephes_erfc(double a);
double hcephes_erfce(double x);
double hcephes_euclid(double *num, double *den);
double hcephes_expm1(double x);
double hcephes_expn(int n, double x);
double hcephes_expx2(double x, int sign);
double hcephes_fac(int i);
double hcephes_fdtr(int ia, int ib, double x);
double hcephes_fdtrc(int ia, int ib, double x);
double hcephes_fdtri(int ia, int ib, double y);
double hcephes_gamma(double x);
double hcephes_gdtr(double a, double b, double x);
double hcephes_gdtrc(double a, double b, double x);
double hcephes_hyp2f0(double a, double b, double x, int type, double *err);
double hcephes_hyp2f1(double a, double b, double c, double x);
double hcephes_hyperg(double a, double b, double x);
double hcephes_hypot(double x, double y);
double hcephes_i0(double x);
double hcephes_i0e(double x);
double hcephes_i1(double x);
double hcephes_i1e(double x);
double hcephes_igam(double a, double x);
double hcephes_igamc(double a, double x);
double hcephes_igami(double a, double y0);
double hcephes_incbet(double aa, double bb, double xx);
double hcephes_incbi(double aa, double bb, double yy0);
double hcephes_iv(double v, double x);
double hcephes_j0(double x);
double hcephes_j1(double x);
double hcephes_jn(int n, double x);
double hcephes_jv(double n, double x);
double hcephes_k0(double x);
double hcephes_k0e(double x);
double hcephes_k1(double x);
double hcephes_k1e(double x);
double hcephes_kn(int nn, double x);
double hcephes_kolmogi(double p);
double hcephes_kolmogorov(double y);
double hcephes_lbeta(double a, double b);
double hcephes_lgam_sgn(double x, int *sign);
double hcephes_lgam(double x);
double hcephes_log1p(double x);
double hcephes_nbdtr(int k, int n, double p);
double hcephes_nbdtrc(int k, int n, double p);
double hcephes_nbdtri(int k, int n, double p);
double hcephes_ndtr(double a);
double hcephes_ndtri(double y0);
double hcephes_onef2(double a, double b, double c, double x, double *err);
double hcephes_p1evl(double x, double coef[], int N);
double hcephes_pdtr(int k, double m);
double hcephes_pdtrc(int k, double m);
double hcephes_pdtri(int k, double y);
double hcephes_planckc(double w, double T);
double hcephes_planckd(double w, double T);
double hcephes_plancki(double w, double T);
double hcephes_planckw(double T);
double hcephes_polevl(double x, double coef[], int N);
double hcephes_polylog(int n, double x);
double hcephes_powi(double x, int nn);
double hcephes_psi(double x);
double hcephes_simpsn(double f[], double delta);
double hcephes_smirnov(int n, double e);
double hcephes_smirnovi(int n, double p);
double hcephes_spence(double x);
double hcephes_stdtr(int k, double t);
double hcephes_stdtri(int k, double p);
double hcephes_struve(double v, double x);
double hcephes_threef0(double a, double b, double c, double x, double *err);
double hcephes_y0(double x);
double hcephes_y1(double x);
double hcephes_yn(int n, double x);
double hcephes_yv(double v, double x);
double hcephes_zetac(double x);
int hcephes_airy(double x, double *ai, double *aip, double *bi, double *bip);
int hcephes_drand(double *a);
int hcephes_fresnl(double xxa, double *ssa, double *cca);
int hcephes_mtherr(char *name, int code);
int hcephes_poldiv(double *, int, double *, int, double *);
int hcephes_polrt(double xcof[], double cof[], int m, cmplx root[]);
int hcephes_shichi(double x, double *si, double *ci);
int hcephes_sici(double x, double *si, double *ci);
void hcephes_cadd(cmplx *, cmplx *, cmplx *);
void hcephes_cdiv(cmplx *, cmplx *, cmplx *);
void hcephes_cmov(void *a, void *b);
void hcephes_cmul(cmplx *a, cmplx *b, cmplx *c);
void hcephes_cneg(cmplx *a);
void hcephes_csqrt(cmplx *z, cmplx *w);
void hcephes_csub(cmplx *a, cmplx *b, cmplx *c);
void hcephes_poladd(double a[], int na, double b[], int nb, double c[]);
void hcephes_polclr(double *, int);
void hcephes_polmov(double *, int, double *);
void hcephes_polmul(double *, int, double *, int, double *);
void hcephes_polsbt(double a[], int na, double b[], int nb, double c[]);
void hcephes_polsub(double a[], int na, double b[], int nb, double c[]);
void hcephes_radd(fract *f1, fract *f2, fract *f3);
void hcephes_rdiv(fract *ff1, fract *ff2, fract *ff3);
void hcephes_revers(double y[], double x[], int n);
void hcephes_rmul(fract *ff1, fract *ff2, fract *ff3);
void hcephes_rsub(fract *f1, fract *f2, fract *f3);