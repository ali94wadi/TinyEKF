#define N 8
#define M 4

#include "linalg.h"


typedef struct {

    double X[N];    // state

    mat_t  P;   // prediction error covariance
    mat_t  Q;   // process noise covariance
    mat_t  R;   // measurement error covariance

    mat_t  G;   // Kalman gain; a.k.a. K

    double   Xp[N];  // output of state-transition function
    mat_t  fy;  // Jacobean of process model
    mat_t  H;   // Jacobean of measurement model
    double   gXp[N];

    mat_t  Ht;
    mat_t  fyt;
    mat_t  Pp;

    mat_t  eye_n_n;

    // temporary storage
    mat_t  tmp_n_m;
    mat_t  tmp_n_n;
    mat_t  tmp_m_n;
    double   tmp_m[M];
    mat_t  tmp2_n_m;
    mat_t  tmp_m_m;
    mat_t  tmp2_m_m;

} ekf_t; 

void ekf_init(ekf_t * ekf, int n, int m);

void ekf_free(ekf_t ekf);

void ekf_setP(ekf_t * ekf, int i, int j, double value);

void ekf_setQ(ekf_t * ekf, int i, int j, double value);

void ekf_setR(ekf_t * ekf, int i, int j, double value);

void ekf_setX(ekf_t * ekf, int i, double value);

void ekf_update(
        ekf_t * ekf, 
        double * Z, 
        void (*f)(double *, double *, double **), 
        void (*g)(double *, double *, double **));

void ekf_post_update(ekf_t * ekf, double * Z);
