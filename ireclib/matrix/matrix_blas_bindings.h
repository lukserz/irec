// Copyright (C) 2008  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.




//#include <iostream>
//using namespace std;

namespace ireclib
{


    namespace blas_bindings 
    {

        int& counter_gemm();
        int& counter_gemv();
        int& counter_ger();
        int& counter_dot();
        int& counter_axpy();
        int& counter_scal();


        extern "C"
        {
            // Here we declare the prototypes for the CBLAS calls used by the BLAS bindings below

            void cblas_saxpy(const CBLAS_INT_TYPE N, const float alpha, const float *X,
                            const CBLAS_INT_TYPE incX, float *Y, const CBLAS_INT_TYPE incY);
            void cblas_daxpy(const CBLAS_INT_TYPE N, const double alpha, const double *X,
                            const CBLAS_INT_TYPE incX, double *Y, const CBLAS_INT_TYPE incY);
            void cblas_caxpy(const CBLAS_INT_TYPE N, const void *alpha, const void *X,
                            const CBLAS_INT_TYPE incX, void *Y, const CBLAS_INT_TYPE incY);
            void cblas_zaxpy(const CBLAS_INT_TYPE N, const void *alpha, const void *X,
                            const CBLAS_INT_TYPE incX, void *Y, const CBLAS_INT_TYPE incY);

            void cblas_sscal(const CBLAS_INT_TYPE N, const float alpha, float *X, const CBLAS_INT_TYPE incX);
            void cblas_dscal(const CBLAS_INT_TYPE N, const double alpha, double *X, const CBLAS_INT_TYPE incX);
            void cblas_cscal(const CBLAS_INT_TYPE N, const void *alpha, void *X, const CBLAS_INT_TYPE incX);
            void cblas_zscal(const CBLAS_INT_TYPE N, const void *alpha, void *X, const CBLAS_INT_TYPE incX);

            void cblas_sgemm(const CBLAS_ORDER Order, const CBLAS_TRANSPOSE TransA,
                             const CBLAS_TRANSPOSE TransB, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                             const CBLAS_INT_TYPE K, const float alpha, const float *A,
                             const CBLAS_INT_TYPE lda, const float *B, const CBLAS_INT_TYPE ldb,
                             const float beta, float *C, const CBLAS_INT_TYPE ldc);
            void cblas_dgemm(const CBLAS_ORDER Order, const CBLAS_TRANSPOSE TransA,
                             const CBLAS_TRANSPOSE TransB, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                             const CBLAS_INT_TYPE K, const double alpha, const double *A,
                             const CBLAS_INT_TYPE lda, const double *B, const CBLAS_INT_TYPE ldb,
                             const double beta, double *C, const CBLAS_INT_TYPE ldc);
            void cblas_cgemm(const CBLAS_ORDER Order, const CBLAS_TRANSPOSE TransA,
                             const CBLAS_TRANSPOSE TransB, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                             const CBLAS_INT_TYPE K, const void *alpha, const void *A,
                             const CBLAS_INT_TYPE lda, const void *B, const CBLAS_INT_TYPE ldb,
                             const void *beta, void *C, const CBLAS_INT_TYPE ldc);
            void cblas_zgemm(const CBLAS_ORDER Order, const CBLAS_TRANSPOSE TransA,
                             const CBLAS_TRANSPOSE TransB, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                             const CBLAS_INT_TYPE K, const void *alpha, const void *A,
                             const CBLAS_INT_TYPE lda, const void *B, const CBLAS_INT_TYPE ldb,
                             const void *beta, void *C, const CBLAS_INT_TYPE ldc);
            void cblas_sgemv(const CBLAS_ORDER order,
                             const CBLAS_TRANSPOSE TransA, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                             const float alpha, const float *A, const CBLAS_INT_TYPE lda,
                             const float *X, const CBLAS_INT_TYPE incX, const float beta,
                             float *Y, const CBLAS_INT_TYPE incY);
            void cblas_dgemv(const CBLAS_ORDER order,
                             const CBLAS_TRANSPOSE TransA, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                             const double alpha, const double *A, const CBLAS_INT_TYPE lda,
                             const double *X, const CBLAS_INT_TYPE incX, const double beta,
                             double *Y, const CBLAS_INT_TYPE incY);
            void cblas_cgemv(const CBLAS_ORDER order,
                             const CBLAS_TRANSPOSE TransA, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                             const void *alpha, const void *A, const CBLAS_INT_TYPE lda,
                             const void *X, const CBLAS_INT_TYPE incX, const void *beta,
                             void *Y, const CBLAS_INT_TYPE incY);
            void cblas_zgemv(const CBLAS_ORDER order,
                             const CBLAS_TRANSPOSE TransA, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                             const void *alpha, const void *A, const CBLAS_INT_TYPE lda,
                             const void *X, const CBLAS_INT_TYPE incX, const void *beta,
                             void *Y, const CBLAS_INT_TYPE incY);
            void cblas_sger(const CBLAS_ORDER order, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                            const float alpha, const float *X, const CBLAS_INT_TYPE incX,
                            const float *Y, const CBLAS_INT_TYPE incY, float *A, const CBLAS_INT_TYPE lda);
            void cblas_dger(const CBLAS_ORDER order, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                            const double alpha, const double *X, const CBLAS_INT_TYPE incX,
                            const double *Y, const CBLAS_INT_TYPE incY, double *A, const CBLAS_INT_TYPE lda);
            void cblas_cgerc(const CBLAS_ORDER order, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                             const void *alpha, const void *X, const CBLAS_INT_TYPE incX,
                             const void *Y, const CBLAS_INT_TYPE incY, void *A, const CBLAS_INT_TYPE lda);
            void cblas_zgerc(const CBLAS_ORDER order, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                             const void *alpha, const void *X, const CBLAS_INT_TYPE incX,
                             const void *Y, const CBLAS_INT_TYPE incY, void *A, const CBLAS_INT_TYPE lda);
            float  cblas_sdot(const CBLAS_INT_TYPE N, const float  *X, const CBLAS_INT_TYPE incX,
                              const float  *Y, const CBLAS_INT_TYPE incY);
            double cblas_ddot(const CBLAS_INT_TYPE N, const double *X, const CBLAS_INT_TYPE incX,
                              const double *Y, const CBLAS_INT_TYPE incY);
            void   cblas_cdotu_sub(const CBLAS_INT_TYPE N, const void *X, const CBLAS_INT_TYPE incX,
                                   const void *Y, const CBLAS_INT_TYPE incY, void *dotu);
            void   cblas_zdotu_sub(const CBLAS_INT_TYPE N, const void *X, const CBLAS_INT_TYPE incX,
                                   const void *Y, const CBLAS_INT_TYPE incY, void *dotu);
            void   cblas_cdotc_sub(const CBLAS_INT_TYPE N, const void *X, const CBLAS_INT_TYPE incX,
                                   const void *Y, const CBLAS_INT_TYPE incY, void *dotc);
            void   cblas_zdotc_sub(const CBLAS_INT_TYPE N, const void *X, const CBLAS_INT_TYPE incX,
                                   const void *Y, const CBLAS_INT_TYPE incY, void *dotc);
            void cblas_cgeru(const CBLAS_ORDER order, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                             const void *alpha, const void *X, const CBLAS_INT_TYPE incX,
                             const void *Y, const CBLAS_INT_TYPE incY, void *A, const CBLAS_INT_TYPE lda);
            void cblas_zgeru(const CBLAS_ORDER order, const CBLAS_INT_TYPE M, const CBLAS_INT_TYPE N,
                             const void *alpha, const void *X, const CBLAS_INT_TYPE incX,
                             const void *Y, const CBLAS_INT_TYPE incY, void *A, const CBLAS_INT_TYPE lda);
        }

    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------

        inline void cblas_axpy(const int N, const float alpha, const float *X,
                        const int incX, float *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_AXPY;
            cblas_saxpy(N, alpha, X, incX, Y, incY);
        }

        inline void cblas_axpy(const int N, const double alpha, const double *X,
                        const int incX, double *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_AXPY;
            cblas_daxpy(N, alpha, X, incX, Y, incY);
        }

        inline void cblas_axpy(const int N, const std::complex<float>& alpha, const std::complex<float> *X,
                        const int incX, std::complex<float> *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_AXPY;
            cblas_caxpy(N, (float*)&alpha, (float*)X, incX, (float*)Y, incY);
        }

        inline void cblas_axpy(const int N, const std::complex<double>& alpha, const std::complex<double> *X,
                        const int incX, std::complex<double> *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_AXPY;
            cblas_zaxpy(N, (double*)&alpha, (double*)X, incX, (double*)Y, incY);
        }

    // ----------------------------------------------------------------------------------------

        inline void cblas_scal(const int N, const float alpha, float *X)
        {
            IRECLIB_TEST_BLAS_BINDING_SCAL;
            cblas_sscal(N, alpha, X, 1);
        }

        inline void cblas_scal(const int N, const double alpha, double *X)
        {
            IRECLIB_TEST_BLAS_BINDING_SCAL;
            cblas_dscal(N, alpha, X, 1);
        }

        inline void cblas_scal(const int N, const std::complex<float>& alpha, std::complex<float> *X)
        {
            IRECLIB_TEST_BLAS_BINDING_SCAL;
            cblas_cscal(N, (float*)&alpha, (float*)X, 1);
        }

        inline void cblas_scal(const int N, const std::complex<double>& alpha, std::complex<double> *X)
        {
            IRECLIB_TEST_BLAS_BINDING_SCAL;
            cblas_zscal(N, (double*)&alpha, (double*)X, 1);
        }

    // ----------------------------------------------------------------------------------------

        inline void cblas_gemm( const CBLAS_ORDER Order, const CBLAS_TRANSPOSE TransA,
                                const CBLAS_TRANSPOSE TransB, const int M, const int N,
                                const int K, const float alpha, const float *A,
                                const int lda, const float *B, const int ldb,
                                const float beta, float *C, const int ldc)
        {
            IRECLIB_TEST_BLAS_BINDING_GEMM;
            cblas_sgemm( Order, TransA, TransB,  M,  N,
                          K,  alpha, A, lda, B,  ldb, beta, C,  ldc);
        }

        inline void cblas_gemm(const CBLAS_ORDER Order, const CBLAS_TRANSPOSE TransA,
                         const CBLAS_TRANSPOSE TransB, const int M, const int N,
                         const int K, const double alpha, const double *A,
                         const int lda, const double *B, const int ldb,
                         const double beta, double *C, const int ldc)
        {
            IRECLIB_TEST_BLAS_BINDING_GEMM;
            cblas_dgemm( Order, TransA, TransB,  M,  N,
                          K,  alpha, A, lda, B,  ldb, beta, C,  ldc);
        }

        inline void cblas_gemm(const CBLAS_ORDER Order, const CBLAS_TRANSPOSE TransA,
                         const CBLAS_TRANSPOSE TransB, const int M, const int N,
                         const int K, const std::complex<float>& alpha, const std::complex<float> *A,
                         const int lda, const std::complex<float> *B, const int ldb,
                         const std::complex<float>& beta, std::complex<float> *C, const int ldc)
        {
            IRECLIB_TEST_BLAS_BINDING_GEMM;
            cblas_cgemm( Order, TransA, TransB,  M,  N,
                          K,  (float*)&alpha, (float*)A, lda, (float*)B,  ldb, (float*)&beta, (float*)C,  ldc);
        }

        inline void cblas_gemm(const CBLAS_ORDER Order, const CBLAS_TRANSPOSE TransA,
                         const CBLAS_TRANSPOSE TransB, const int M, const int N,
                         const int K, const std::complex<double>& alpha, const std::complex<double> *A,
                         const int lda, const std::complex<double> *B, const int ldb,
                         const std::complex<double>& beta, std::complex<double> *C, const int ldc)
        {
            IRECLIB_TEST_BLAS_BINDING_GEMM;
            cblas_zgemm( Order, TransA, TransB,  M,  N,
                          K,  (double*)&alpha, (double*)A, lda, (double*)B,  ldb, (double*)&beta, (double*)C,  ldc);
        }

    // ----------------------------------------------------------------------------------------

        inline void cblas_gemv(const CBLAS_ORDER order,
                        const CBLAS_TRANSPOSE TransA, const int M, const int N,
                        const float alpha, const float *A, const int lda,
                        const float *X, const int incX, const float beta,
                        float *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_GEMV;
            cblas_sgemv(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        }

        inline void cblas_gemv(const CBLAS_ORDER order,
                        const CBLAS_TRANSPOSE TransA, const int M, const int N,
                        const double alpha, const double *A, const int lda,
                        const double *X, const int incX, const double beta,
                        double *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_GEMV;
            cblas_dgemv(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        }

        inline void cblas_gemv(const CBLAS_ORDER order,
                        const CBLAS_TRANSPOSE TransA, const int M, const int N,
                        const std::complex<float>& alpha, const std::complex<float> *A, const int lda,
                        const std::complex<float> *X, const int incX, const std::complex<float>& beta,
                        std::complex<float> *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_GEMV;
            cblas_cgemv(order, TransA, M, N, (float*)&alpha, (float*)A, lda, (float*)X, incX, (float*)&beta, (float*)Y, incY);
        }

        inline void cblas_gemv(const CBLAS_ORDER order,
                        const CBLAS_TRANSPOSE TransA, const int M, const int N,
                        const std::complex<double>& alpha, const std::complex<double> *A, const int lda,
                        const std::complex<double> *X, const int incX, const std::complex<double>& beta,
                        std::complex<double> *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_GEMV;
            cblas_zgemv(order, TransA, M, N, (double*)&alpha, (double*)A, lda, (double*)X, incX, (double*)&beta, (double*)Y, incY);
        }

    // ----------------------------------------------------------------------------------------

        inline void cblas_ger(const CBLAS_ORDER order, const int M, const int N,
                        const std::complex<float>& alpha, const std::complex<float> *X, const int incX,
                        const std::complex<float> *Y, const int incY, std::complex<float> *A, const int lda)
        {
            IRECLIB_TEST_BLAS_BINDING_GER;
            cblas_cgeru (order,  M, N, (float*)&alpha, (float*)X, incX, (float*)Y, incY, (float*)A, lda);
        }

        inline void cblas_ger(const CBLAS_ORDER order, const int M, const int N,
                        const std::complex<double>& alpha, const std::complex<double> *X, const int incX,
                        const std::complex<double> *Y, const int incY, std::complex<double> *A, const int lda)
        {
            IRECLIB_TEST_BLAS_BINDING_GER;
            cblas_zgeru (order,  M, N, (double*)&alpha, (double*)X, incX, (double*)Y, incY, (double*)A, lda);
        }

        inline void cblas_ger(const CBLAS_ORDER order, const int M, const int N,
                        const float alpha, const float *X, const int incX,
                        const float *Y, const int incY, float *A, const int lda)
        {
            IRECLIB_TEST_BLAS_BINDING_GER;
            cblas_sger (order,  M, N, alpha, (float*)X, incX, (float*)Y, incY, (float*)A, lda);
        }

        inline void cblas_ger(const CBLAS_ORDER order, const int M, const int N,
                        const double alpha, const double *X, const int incX,
                        const double *Y, const int incY, double *A, const int lda)
        {
            IRECLIB_TEST_BLAS_BINDING_GER;
            cblas_dger (order,  M, N, alpha, (double*)X, incX, (double*)Y, incY, (double*)A, lda);
        }

    // ----------------------------------------------------------------------------------------

        inline void cblas_gerc(const CBLAS_ORDER order, const int M, const int N,
                        const std::complex<float>& alpha, const std::complex<float> *X, const int incX,
                        const std::complex<float> *Y, const int incY, std::complex<float> *A, const int lda)
        {
            IRECLIB_TEST_BLAS_BINDING_GER;
            cblas_cgerc (order,  M, N, (float*)&alpha, (float*)X, incX, (float*)Y, incY, (float*)A, lda);
        }

        inline void cblas_gerc(const CBLAS_ORDER order, const int M, const int N,
                        const std::complex<double>& alpha, const std::complex<double> *X, const int incX,
                        const std::complex<double> *Y, const int incY, std::complex<double> *A, const int lda)
        {
            IRECLIB_TEST_BLAS_BINDING_GER;
            cblas_zgerc (order,  M, N, (double*)&alpha, (double*)X, incX, (double*)Y, incY, (double*)A, lda);
        }

    // ----------------------------------------------------------------------------------------

        inline float cblas_dot(const int N, const float  *X, const int incX,
                        const float  *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_DOT;
            return cblas_sdot(N, X, incX, Y, incY);
        }

        inline double cblas_dot(const int N, const double *X, const int incX,
                        const double *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_DOT;
            return cblas_ddot(N, X, incX, Y, incY);
        }

        inline std::complex<float> cblas_dot(const int N, const std::complex<float> *X, const int incX,
                            const std::complex<float> *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_DOT;
            std::complex<float> result;
            cblas_cdotu_sub(N, (float*)X, incX, (float*)Y, incY, (float*)&result);
            return result;
        }

        inline std::complex<double> cblas_dot(const int N, const std::complex<double> *X, const int incX,
                            const std::complex<double> *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_DOT;
            std::complex<double> result;
            cblas_zdotu_sub(N, (double*)X, incX, (double*)Y, incY, (double*)&result);
            return result;
        }

    // ----------------------------------------------------------------------------------------

        inline std::complex<float> cblas_dotc(const int N, const std::complex<float> *X, const int incX,
                            const std::complex<float> *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_DOT;
            std::complex<float> result;
            cblas_cdotc_sub(N, (float*)X, incX, (float*)Y, incY, (float*)&result);
            return result;
        }

        inline std::complex<double> cblas_dotc(const int N, const std::complex<double> *X, const int incX,
                            const std::complex<double> *Y, const int incY)
        {
            IRECLIB_TEST_BLAS_BINDING_DOT;
            std::complex<double> result;
            cblas_zdotc_sub(N, (double*)X, incX, (double*)Y, incY, (double*)&result);
            return result;
        }

    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------
    // Helpers for determining the data pointer, LDA, and incX arguments to BLAS functions.

        template <typename T, long NR, long NC, typename MM>
        int get_ld (const matrix<T,NR,NC,MM,row_major_layout>& m) { return m.nc(); }

        template <typename T, long NR, long NC, typename MM>
        int get_ld (const matrix<T,NR,NC,MM,column_major_layout>& m) { return m.nr(); }


        template <typename T, long NR, long NC, typename MM>
        int get_ld (const matrix_op<op_subm<matrix<T,NR,NC,MM,row_major_layout> > >& m) { return m.op.m.nc(); }

        template <typename T, long NR, long NC, typename MM>
        int get_ld (const matrix_op<op_subm<matrix<T,NR,NC,MM,column_major_layout> > >& m) { return m.op.m.nr(); }

        template <typename T, long NR, long NC, typename MM>
        int get_ld (const assignable_sub_matrix<T,NR,NC,MM,row_major_layout>& m) { return m.m.nc(); }

        template <typename T, long NR, long NC, typename MM>
        int get_ld (const assignable_sub_matrix<T,NR,NC,MM,column_major_layout>& m) { return m.m.nr(); }

        template <typename T, long NR, long NC, typename MM>
        int get_ld (const assignable_col_matrix<T,NR,NC,MM,row_major_layout>& m) { return m.m.nc(); }

        template <typename T, long NR, long NC, typename MM>
        int get_ld (const assignable_col_matrix<T,NR,NC,MM,column_major_layout>& m) { return m.m.nr(); }

        template <typename T, long NR, long NC, typename MM>
        int get_ld (const assignable_row_matrix<T,NR,NC,MM,row_major_layout>& m) { return m.m.nc(); }

        template <typename T, long NR, long NC, typename MM>
        int get_ld (const assignable_row_matrix<T,NR,NC,MM,column_major_layout>& m) { return m.m.nr(); }

        template <typename T>
        int get_ld (const assignable_ptr_matrix<T>& m) { return m.nc(); }

        template <typename T, typename MM>
        int get_ld (const matrix_op<op_array2d_to_mat<array2d<T,MM> > >& m) { return m.nc(); }
        template <typename T, typename MM>
        int get_ld (const matrix_op<op_array_to_mat<array<T,MM> > >& m) { return m.nc(); }
        template < typename value_type, typename alloc >
        int get_ld (const matrix_op<op_std_vect_to_mat<std::vector<value_type,alloc> > >& m) { return m.nc(); }
        template < typename value_type, typename alloc >
        int get_ld (const matrix_op<op_std_vect_to_mat<std_vector_c<value_type,alloc> > >& m) { return m.nc(); }
        template <typename T>
        int get_ld (const matrix_op<op_pointer_to_col_vect<T> >& m) { return m.nc(); }
        template <typename T>
        int get_ld (const matrix_op<op_pointer_to_mat<T> >& m) { return m.op.stride; }

        // --------

        // get_inc() returns the offset from one element to another.  If an object has a
        // non-uniform offset between elements then returns 0 (e.g. a subm() view could
        // have a non-uniform offset between elements).

        template <typename T, typename MM>
        int get_inc (const matrix_op<op_array2d_to_mat<array2d<T,MM> > >& ) { return 1; }
        template <typename T, typename MM>
        int get_inc (const matrix_op<op_array_to_mat<array<T,MM> > >& ) { return 1; }
        template < typename value_type, typename alloc >
        int get_inc (const matrix_op<op_std_vect_to_mat<std::vector<value_type,alloc> > >& ) { return 1; }
        template < typename value_type, typename alloc >
        int get_inc (const matrix_op<op_std_vect_to_mat<std_vector_c<value_type,alloc> > >& ) { return 1; }
        template <typename T>
        int get_inc (const matrix_op<op_pointer_to_col_vect<T> >& ) { return 1; }
        template <typename T>
        int get_inc (const matrix_op<op_pointer_to_mat<T> >& m) { return m.op.stride==m.op.cols ? 1 : 0; }

        template <typename T, long NR, long NC, typename MM, typename L>
        int get_inc (const matrix<T,NR,NC,MM,L>& ) { return 1; }

        template <typename T, long NR, long NC, typename MM>
        int get_inc (const matrix_op<op_subm<matrix<T,NR,NC,MM,row_major_layout> > >& m) 
        { 
            // if the sub-view doesn't cover all the columns then it can't have a uniform
            // layout.
            if (m.nc() < m.op.m.nc())
                return 0;
            else
                return 1;
        }

        template <typename T, long NR, long NC, typename MM>
        int get_inc (const matrix_op<op_subm<matrix<T,NR,NC,MM,column_major_layout> > >& m) 
        { 
            if (m.nr() < m.op.m.nr())
                return 0;
            else
                return 1;
        }

        template <typename T, long NR, long NC, typename MM>
        int get_inc (const assignable_sub_matrix<T,NR,NC,MM,row_major_layout>& m) 
        { 
            if (m.nc() < m.m.nc())
                return 0;
            else
                return 1;
        }
        template <typename T, long NR, long NC, typename MM>
        int get_inc (const assignable_sub_matrix<T,NR,NC,MM,column_major_layout>& m) 
        {
            if (m.nr() < m.m.nr())
                return 0;
            else
                return 1;
        }

        template <typename T>
        int get_inc (const assignable_ptr_matrix<T>& ) { return 1; }

        template <typename T, long NR, long NC, typename MM>
        int get_inc(const matrix_op<op_colm<matrix<T,NR,NC,MM,row_major_layout> > >& m)
        {
            return m.op.m.nc();
        }

        template <typename T, long NR, long NC, typename MM>
        int get_inc(const matrix_op<op_rowm<matrix<T,NR,NC,MM,row_major_layout> > >& )
        {
            return 1;
        }

        template <typename T, long NR, long NC, typename MM>
        int get_inc(const matrix_op<op_colm2<matrix<T,NR,NC,MM,row_major_layout> > >& m)
        {
            return m.op.m.nc();
        }

        template <typename T, long NR, long NC, typename MM>
        int get_inc(const matrix_op<op_rowm2<matrix<T,NR,NC,MM,row_major_layout> > >& )
        {
            return 1;
        }



        template <typename T, long NR, long NC, typename MM>
        int get_inc(const matrix_op<op_colm<matrix<T,NR,NC,MM,column_major_layout> > >& )
        {
            return 1;
        }

        template <typename T, long NR, long NC, typename MM>
        int get_inc(const matrix_op<op_rowm<matrix<T,NR,NC,MM,column_major_layout> > >& m)
        {
            return m.op.m.nr();
        }

        template <typename T, long NR, long NC, typename MM>
        int get_inc(const matrix_op<op_colm2<matrix<T,NR,NC,MM,column_major_layout> > >& )
        {
            return 1;
        }

        template <typename T, long NR, long NC, typename MM>
        int get_inc(const matrix_op<op_rowm2<matrix<T,NR,NC,MM,column_major_layout> > >& m)
        {
            return m.op.m.nr();
        }



        template <typename T, long NR, long NC, typename MM>
        int get_inc(const assignable_row_matrix<T,NR,NC,MM,row_major_layout>& )
        {
            return 1;
        }

        template <typename T, long NR, long NC, typename MM>
        int get_inc(const assignable_row_matrix<T,NR,NC,MM,column_major_layout>& m)
        {
            return m.m.nr();
        }

        template <typename T, long NR, long NC, typename MM>
        int get_inc(const assignable_col_matrix<T,NR,NC,MM,row_major_layout>& m)
        {
            return m.m.nc();
        }

        template <typename T, long NR, long NC, typename MM>
        int get_inc(const assignable_col_matrix<T,NR,NC,MM,column_major_layout>& )
        {
            return 1;
        }

        // --------

        template <typename T, long NR, long NC, typename MM, typename L>
        const T* get_ptr (const matrix<T,NR,NC,MM,L>& m) { return &m(0,0); }

        template <typename T, long NR, long NC, typename MM, typename L>
        T* get_ptr (matrix<T,NR,NC,MM,L>& m) { return &m(0,0); }

        template <typename T, long NR, long NC, typename MM, typename L>
        const T* get_ptr (const matrix_op<op_subm<matrix<T,NR,NC,MM,L> > >& m) { return &m.op.m(m.op.r_,m.op.c_); }

        template <typename T, long NR, long NC, typename MM, typename L>
        const T* get_ptr (const matrix_op<op_colm<matrix<T,NR,NC,MM,L> > >& m) { return &m.op.m(0,m.op.col); }

        template <typename T, long NR, long NC, typename MM, typename L>
        const T* get_ptr (const matrix_op<op_rowm<matrix<T,NR,NC,MM,L> > >& m) { return &m.op.m(m.op.row,0); }

        template <typename T, long NR, long NC, typename MM, typename L>
        const T* get_ptr (const matrix_op<op_colm2<matrix<T,NR,NC,MM,L> > >& m) { return &m.op.m(0,m.op.col); }

        template <typename T, long NR, long NC, typename MM, typename L>
        const T* get_ptr (const matrix_op<op_rowm2<matrix<T,NR,NC,MM,L> > >& m) { return &m.op.m(m.op.row,0); }


        template <typename T, long NR, long NC, typename MM, typename L>
        T* get_ptr (assignable_col_matrix<T,NR,NC,MM,L>& m) { return &m(0,0); }

        template <typename T, long NR, long NC, typename MM, typename L>
        T* get_ptr (assignable_row_matrix<T,NR,NC,MM,L>& m) { return &m(0,0); }

        template <typename T, long NR, long NC, typename MM, typename L>
        T* get_ptr (assignable_sub_matrix<T,NR,NC,MM,L>& m) { return &m(0,0); }

        template <typename T>
        T* get_ptr (assignable_ptr_matrix<T>& m) { return m.ptr; }

        template <typename T, typename MM>
        const T* get_ptr (const matrix_op<op_array2d_to_mat<array2d<T,MM> > >& m) { return &m.op.array[0][0]; }
        template <typename T, typename MM>
        const T* get_ptr (const matrix_op<op_array_to_mat<array<T,MM> > >& m) { return &m.op.vect[0]; }
        template < typename T, typename alloc >
        const T* get_ptr (const matrix_op<op_std_vect_to_mat<std::vector<T,alloc> > >& m) { return &m.op.vect[0]; }
        template < typename T, typename alloc >
        const T* get_ptr (const matrix_op<op_std_vect_to_mat<std_vector_c<T,alloc> > >& m) { return &m.op.vect[0]; }
        template <typename T>
        const T* get_ptr (const matrix_op<op_pointer_to_col_vect<T> >& m) { return m.op.ptr; }
        template <typename T>
        const T* get_ptr (const matrix_op<op_pointer_to_mat<T> >& m) { return m.op.ptr; }

    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------

        // Here we declare some matrix objects for use in the IRECLIB_ADD_BLAS_BINDING macro.  These
        // extern declarations don't actually correspond to any real matrix objects.  They are
        // simply here so we can build matrix expressions with the IRECLIB_ADD_BLAS_BINDING marco.


        // Note that the fact that these are double matrices isn't important, it is just a placeholder in this case.  
        extern matrix<double> m;     // general matrix 
        extern matrix<double,1,0> rv;  // general row vector
        extern matrix<double,0,1> cv;  // general column vector
        extern const double s;

    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------
    //                       AXPY/SCAL overloads
    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------

        IRECLIB_ADD_BLAS_BINDING(m)
        {

            const int N = static_cast<int>(src.size());
            if (transpose == false && N != 0)
            {
                if (add_to)
                {
                    if (get_inc(src) && get_inc(dest))
                        cblas_axpy(N, alpha, get_ptr(src), get_inc(src), get_ptr(dest), get_inc(dest));
                    else
                        matrix_assign_default(dest, src, alpha, add_to);
                }
                else
                {
                    if (get_ptr(src) == get_ptr(dest))
                        cblas_scal(N, alpha, get_ptr(dest));
                    else
                        matrix_assign_default(dest, src, alpha, add_to);
                }
            }
            else
            {
                matrix_assign_default(dest, trans(src), alpha, add_to);
            }

        } IRECLIB_END_BLAS_BINDING

        IRECLIB_ADD_BLAS_BINDING(rv)
        {

            const int N = static_cast<int>(src.size());
            if (transpose == false && N != 0)
            {
                if (add_to)
                {
                    if (get_inc(src) && get_inc(dest))
                        cblas_axpy(N, alpha, get_ptr(src), get_inc(src), get_ptr(dest), get_inc(dest));
                    else
                        matrix_assign_default(dest, src, alpha, add_to);
                }
                else
                {
                    if (get_ptr(src) == get_ptr(dest))
                        cblas_scal(N, alpha, get_ptr(dest));
                    else
                        matrix_assign_default(dest, src, alpha, add_to);
                }
            }
            else
            {
                matrix_assign_default(dest, trans(src), alpha, add_to);
            }

        } IRECLIB_END_BLAS_BINDING

        IRECLIB_ADD_BLAS_BINDING(cv)
        {

            const int N = static_cast<int>(src.size());
            if (transpose == false && N != 0)
            {
                if (add_to)
                {
                    if (get_inc(src) && get_inc(dest))
                        cblas_axpy(N, alpha, get_ptr(src), get_inc(src), get_ptr(dest), get_inc(dest));
                    else
                        matrix_assign_default(dest, src, alpha, add_to);
                }
                else
                {
                    if (get_ptr(src) == get_ptr(dest))
                        cblas_scal(N, alpha, get_ptr(dest));
                    else
                        matrix_assign_default(dest, src, alpha, add_to);
                }
            }
            else
            {
                matrix_assign_default(dest, trans(src), alpha, add_to);
            }

        } IRECLIB_END_BLAS_BINDING

    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------
    //                       GEMM overloads
    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------

        IRECLIB_ADD_BLAS_BINDING(m*m)
        {
            //cout << "BLAS GEMM: m*m" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const int M = static_cast<int>(src.nr());
            const int N = static_cast<int>(src.nc());
            const int K = static_cast<int>(src.lhs.nc());
            const T* A = get_ptr(src.lhs);
            const int lda = get_ld(src.lhs);
            const T* B = get_ptr(src.rhs);
            const int ldb = get_ld(src.rhs);

            const T beta = static_cast<T>(add_to?1:0);
            T* C = get_ptr(dest);
            const int ldc = get_ld(dest);

            if (transpose == false)
                cblas_gemm(Order, CblasNoTrans, CblasNoTrans, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
            else
                cblas_gemm(Order, CblasTrans, CblasTrans, N, M, K, alpha, B, ldb, A, lda, beta, C, ldc);

        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(m)*m)
        {
            //cout << "BLAS GEMM: trans(m)*m" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasTrans;
            const CBLAS_TRANSPOSE TransB = CblasNoTrans;
            const int M = static_cast<int>(src.nr());
            const int N = static_cast<int>(src.nc());
            const int K = static_cast<int>(src.lhs.nc());
            const T* A = get_ptr(src.lhs.op.m);
            const int lda = get_ld(src.lhs.op.m);
            const T* B = get_ptr(src.rhs);
            const int ldb = get_ld(src.rhs);

            const T beta = static_cast<T>(add_to?1:0);
            T* C = get_ptr(dest);
            const int ldc = get_ld(dest);

            if (transpose == false)
                cblas_gemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
            else
                cblas_gemm(Order, TransA, TransB, N, M, K, alpha, B, ldb, A, lda, beta, C, ldc);

        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(m*trans(m))
        {
            //cout << "BLAS GEMM: m*trans(m)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasNoTrans;
            const CBLAS_TRANSPOSE TransB = CblasTrans;
            const int M = static_cast<int>(src.nr());
            const int N = static_cast<int>(src.nc());
            const int K = static_cast<int>(src.lhs.nc());
            const T* A = get_ptr(src.lhs);
            const int lda = get_ld(src.lhs);
            const T* B = get_ptr(src.rhs.op.m);
            const int ldb = get_ld(src.rhs.op.m);

            const T beta = static_cast<T>(add_to?1:0);
            T* C = get_ptr(dest);
            const int ldc = get_ld(dest);

            if (transpose == false)
                cblas_gemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
            else
                cblas_gemm(Order, TransA, TransB, N, M, K, alpha, B, ldb, A, lda, beta, C, ldc);

        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(m)*trans(m))
        {
            //cout << "BLAS GEMM: trans(m)*trans(m)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const int M = static_cast<int>(src.nr());
            const int N = static_cast<int>(src.nc());
            const int K = static_cast<int>(src.lhs.nc());
            const T* A = get_ptr(src.lhs.op.m);
            const int lda = get_ld(src.lhs.op.m);
            const T* B = get_ptr(src.rhs.op.m);
            const int ldb = get_ld(src.rhs.op.m);

            const T beta = static_cast<T>(add_to?1:0);
            T* C = get_ptr(dest);
            const int ldc = get_ld(dest);

            if (transpose == false)
                cblas_gemm(Order, CblasTrans, CblasTrans, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
            else
                cblas_gemm(Order, CblasNoTrans, CblasNoTrans, N, M, K, alpha, B, ldb, A, lda, beta, C, ldc);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------
        // --------------------------------------
        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(conj(m))*m)
        {
            //cout << "BLAS GEMM: trans(conj(m))*m" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasConjTrans;
            const CBLAS_TRANSPOSE TransB = CblasNoTrans;
            const int M = static_cast<int>(src.nr());
            const int N = static_cast<int>(src.nc());
            const int K = static_cast<int>(src.lhs.nc());
            const T* A = get_ptr(src.lhs.op.m);
            const int lda = get_ld(src.lhs.op.m);
            const T* B = get_ptr(src.rhs);
            const int ldb = get_ld(src.rhs);

            const T beta = static_cast<T>(add_to?1:0);
            T* C = get_ptr(dest);
            const int ldc = get_ld(dest);

            if (transpose == false)
                cblas_gemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
            else
                matrix_assign_default(dest, trans(src), alpha, add_to);

        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(conj(m))*trans(m))
        {
            //cout << "BLAS GEMM: trans(conj(m))*trans(m)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasConjTrans;
            const CBLAS_TRANSPOSE TransB = CblasTrans;
            const int M = static_cast<int>(src.nr());
            const int N = static_cast<int>(src.nc());
            const int K = static_cast<int>(src.lhs.nc());
            const T* A = get_ptr(src.lhs.op.m);
            const int lda = get_ld(src.lhs.op.m);
            const T* B = get_ptr(src.rhs.op.m);
            const int ldb = get_ld(src.rhs.op.m);

            const T beta = static_cast<T>(add_to?1:0);
            T* C = get_ptr(dest);
            const int ldc = get_ld(dest);

            if (transpose == false)
                cblas_gemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
            else
                matrix_assign_default(dest, trans(src), alpha, add_to);

        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(m*trans(conj(m)))
        {
            //cout << "BLAS GEMM: m*trans(conj(m))" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasNoTrans;
            const CBLAS_TRANSPOSE TransB = CblasConjTrans;
            const int M = static_cast<int>(src.nr());
            const int N = static_cast<int>(src.nc());
            const int K = static_cast<int>(src.lhs.nc());
            const T* A = get_ptr(src.lhs);
            const int lda = get_ld(src.lhs);
            const T* B = get_ptr(src.rhs.op.m);
            const int ldb = get_ld(src.rhs.op.m);

            const T beta = static_cast<T>(add_to?1:0);
            T* C = get_ptr(dest);
            const int ldc = get_ld(dest);

            if (transpose == false)
                cblas_gemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
            else
                matrix_assign_default(dest, trans(src), alpha, add_to);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(m)*trans(conj(m)))
        {
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasTrans;
            const CBLAS_TRANSPOSE TransB = CblasConjTrans;
            const int M = static_cast<int>(src.nr());
            const int N = static_cast<int>(src.nc());
            const int K = static_cast<int>(src.lhs.nc());
            const T* A = get_ptr(src.lhs.op.m);
            const int lda = get_ld(src.lhs.op.m);
            const T* B = get_ptr(src.rhs.op.m);
            const int ldb = get_ld(src.rhs.op.m);

            const T beta = static_cast<T>(add_to?1:0);
            T* C = get_ptr(dest);
            const int ldc = get_ld(dest);

            if (transpose == false)
                cblas_gemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
            else
                matrix_assign_default(dest, trans(src), alpha, add_to);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(conj(m))*trans(conj(m)))
        {
            //cout << "BLAS GEMM: trans(conj(m))*trans(conj(m))" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasConjTrans;
            const CBLAS_TRANSPOSE TransB = CblasConjTrans;
            const int M = static_cast<int>(src.nr());
            const int N = static_cast<int>(src.nc());
            const int K = static_cast<int>(src.lhs.nc());
            const T* A = get_ptr(src.lhs.op.m);
            const int lda = get_ld(src.lhs.op.m);
            const T* B = get_ptr(src.rhs.op.m);
            const int ldb = get_ld(src.rhs.op.m);

            const T beta = static_cast<T>(add_to?1:0);
            T* C = get_ptr(dest);
            const int ldc = get_ld(dest);

            if (transpose == false)
                cblas_gemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
            else
                matrix_assign_default(dest, trans(src), alpha, add_to);
        } IRECLIB_END_BLAS_BINDING

    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------
    //                       GEMV overloads
    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------

        IRECLIB_ADD_BLAS_BINDING(m*cv)
        {
            //cout << "BLAS GEMV: m*cv" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasNoTrans;
            const int M = static_cast<int>(src.lhs.nr());
            const int N = static_cast<int>(src.lhs.nc());
            const T* A = get_ptr(src.lhs);
            const int lda = get_ld(src.lhs);
            const T* X = get_ptr(src.rhs);
            const int incX = get_inc(src.rhs);

            const T beta = static_cast<T>(add_to?1:0);
            T* Y = get_ptr(dest);
            const int incY = get_inc(dest);

            cblas_gemv(Order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(rv*m)
        {
            // Note that rv*m is the same as trans(m)*trans(rv)

            //cout << "BLAS GEMV: rv*m" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasTrans;
            const int M = static_cast<int>(src.rhs.nr());
            const int N = static_cast<int>(src.rhs.nc());
            const T* A = get_ptr(src.rhs);
            const int lda = get_ld(src.rhs);
            const T* X = get_ptr(src.lhs);
            const int incX = get_inc(src.lhs);

            const T beta = static_cast<T>(add_to?1:0);
            T* Y = get_ptr(dest);
            const int incY = get_inc(dest);

            cblas_gemv(Order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(cv)*m)
        {
            // Note that trans(cv)*m is the same as trans(m)*cv

            //cout << "BLAS GEMV: trans(cv)*m" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasTrans;
            const int M = static_cast<int>(src.rhs.nr());
            const int N = static_cast<int>(src.rhs.nc());
            const T* A = get_ptr(src.rhs);
            const int lda = get_ld(src.rhs);
            const T* X = get_ptr(src.lhs.op.m);
            const int incX = get_inc(src.lhs.op.m);

            const T beta = static_cast<T>(add_to?1:0);
            T* Y = get_ptr(dest);
            const int incY = get_inc(dest);

            cblas_gemv(Order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(m*trans(rv))
        {
            //cout << "BLAS GEMV: m*trans(rv)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasNoTrans;
            const int M = static_cast<int>(src.lhs.nr());
            const int N = static_cast<int>(src.lhs.nc());
            const T* A = get_ptr(src.lhs);
            const int lda = get_ld(src.lhs);
            const T* X = get_ptr(src.rhs.op.m);
            const int incX = get_inc(src.rhs.op.m);

            const T beta = static_cast<T>(add_to?1:0);
            T* Y = get_ptr(dest);
            const int incY = get_inc(dest);

            cblas_gemv(Order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------
        // --------------------------------------
        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(m)*cv)
        {
            //cout << "BLAS GEMV: trans(m)*cv" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasTrans;
            const int M = static_cast<int>(src.lhs.op.m.nr());
            const int N = static_cast<int>(src.lhs.op.m.nc());
            const T* A = get_ptr(src.lhs.op.m);
            const int lda = get_ld(src.lhs.op.m);
            const T* X = get_ptr(src.rhs);
            const int incX = get_inc(src.rhs);

            const T beta = static_cast<T>(add_to?1:0);
            T* Y = get_ptr(dest);
            const int incY = get_inc(dest);

            cblas_gemv(Order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(rv*trans(m))
        {
            // Note that rv*trans(m) is the same as m*trans(rv)

            //cout << "BLAS GEMV: rv*trans(m)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasNoTrans;
            const int M = static_cast<int>(src.rhs.op.m.nr());
            const int N = static_cast<int>(src.rhs.op.m.nc());
            const T* A = get_ptr(src.rhs.op.m);
            const int lda = get_ld(src.rhs.op.m);
            const T* X = get_ptr(src.lhs);
            const int incX = get_inc(src.lhs);

            const T beta = static_cast<T>(add_to?1:0);
            T* Y = get_ptr(dest);
            const int incY = get_inc(dest);

            cblas_gemv(Order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(cv)*trans(m))
        {
            // Note that trans(cv)*trans(m) is the same as m*cv

            //cout << "BLAS GEMV: trans(cv)*trans(m)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasNoTrans;
            const int M = static_cast<int>(src.rhs.op.m.nr());
            const int N = static_cast<int>(src.rhs.op.m.nc());
            const T* A = get_ptr(src.rhs.op.m);
            const int lda = get_ld(src.rhs.op.m);
            const T* X = get_ptr(src.lhs.op.m);
            const int incX = get_inc(src.lhs.op.m);

            const T beta = static_cast<T>(add_to?1:0);
            T* Y = get_ptr(dest);
            const int incY = get_inc(dest);

            cblas_gemv(Order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(m)*trans(rv))
        {
            //cout << "BLAS GEMV: trans(m)*trans(rv)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasTrans;
            const int M = static_cast<int>(src.lhs.op.m.nr());
            const int N = static_cast<int>(src.lhs.op.m.nc());
            const T* A = get_ptr(src.lhs.op.m);
            const int lda = get_ld(src.lhs.op.m);
            const T* X = get_ptr(src.rhs.op.m);
            const int incX = get_inc(src.rhs.op.m);

            const T beta = static_cast<T>(add_to?1:0);
            T* Y = get_ptr(dest);
            const int incY = get_inc(dest);

            cblas_gemv(Order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------
        // --------------------------------------
        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(cv)*conj(m))
        {
            // Note that trans(cv)*conj(m) == conj(trans(m))*cv
            //cout << "BLAS GEMV: trans(cv)*conj(m)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasConjTrans;
            const int M = static_cast<int>(src.rhs.op.m.nr());
            const int N = static_cast<int>(src.rhs.op.m.nc());
            const T* A = get_ptr(src.rhs.op.m);
            const int lda = get_ld(src.rhs.op.m);
            const T* X = get_ptr(src.lhs.op.m);
            const int incX = get_inc(src.lhs.op.m);

            const T beta = static_cast<T>(add_to?1:0);
            T* Y = get_ptr(dest);
            const int incY = get_inc(dest);

            cblas_gemv(Order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(rv*conj(m))
        {
            // Note that rv*conj(m) == conj(trans(m))*cv
            //cout << "BLAS GEMV: rv*conj(m)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasConjTrans;
            const int M = static_cast<int>(src.rhs.op.m.nr());
            const int N = static_cast<int>(src.rhs.op.m.nc());
            const T* A = get_ptr(src.rhs.op.m);
            const int lda = get_ld(src.rhs.op.m);
            const T* X = get_ptr(src.lhs);
            const int incX = get_inc(src.lhs);

            const T beta = static_cast<T>(add_to?1:0);
            T* Y = get_ptr(dest);
            const int incY = get_inc(dest);

            cblas_gemv(Order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(conj(m))*cv)
        {
            //cout << "BLAS GEMV: trans(conj(m))*cv" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasConjTrans;
            const int M = static_cast<int>(src.lhs.op.m.nr());
            const int N = static_cast<int>(src.lhs.op.m.nc());
            const T* A = get_ptr(src.lhs.op.m);
            const int lda = get_ld(src.lhs.op.m);
            const T* X = get_ptr(src.rhs);
            const int incX = get_inc(src.rhs);

            const T beta = static_cast<T>(add_to?1:0);
            T* Y = get_ptr(dest);
            const int incY = get_inc(dest);

            cblas_gemv(Order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(conj(m))*trans(rv))
        {
            //cout << "BLAS GEMV: trans(conj(m))*trans(rv)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const CBLAS_TRANSPOSE TransA = CblasConjTrans;
            const int M = static_cast<int>(src.lhs.op.m.nr());
            const int N = static_cast<int>(src.lhs.op.m.nc());
            const T* A = get_ptr(src.lhs.op.m);
            const int lda = get_ld(src.lhs.op.m);
            const T* X = get_ptr(src.rhs.op.m);
            const int incX = get_inc(src.rhs.op.m);

            const T beta = static_cast<T>(add_to?1:0);
            T* Y = get_ptr(dest);
            const int incY = get_inc(dest);

            cblas_gemv(Order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
        } IRECLIB_END_BLAS_BINDING

    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------
    //                       GER overloads
    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------

        IRECLIB_ADD_BLAS_BINDING(cv*rv)
        {
            //cout << "BLAS GER: cv*rv" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const int M = static_cast<int>(dest.nr());
            const int N = static_cast<int>(dest.nc());
            const T* X = get_ptr(src.lhs);
            const int incX = get_inc(src.lhs);
            const T* Y = get_ptr(src.rhs);
            const int incY = get_inc(src.rhs);

            if (add_to == false)
                zero_matrix(dest);

            T* A = get_ptr(dest);
            const int lda = get_ld(dest);

            if (transpose == false)
                cblas_ger(Order, M, N, alpha, X, incX, Y, incY, A, lda);
            else
                cblas_ger(Order, M, N, alpha, Y, incY, X, incX, A, lda);

        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(rv)*rv)
        {
            //cout << "BLAS GER: trans(rv)*rv" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const int M = static_cast<int>(dest.nr());
            const int N = static_cast<int>(dest.nc());
            const T* X = get_ptr(src.lhs.op.m);
            const int incX = get_inc(src.lhs.op.m);
            const T* Y = get_ptr(src.rhs);
            const int incY = get_inc(src.rhs);

            if (add_to == false)
                zero_matrix(dest);

            T* A = get_ptr(dest);
            const int lda = get_ld(dest);

            if (transpose == false)
                cblas_ger(Order, M, N, alpha, X, incX, Y, incY, A, lda);
            else
                cblas_ger(Order, M, N, alpha, Y, incY, X, incX, A, lda);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(cv*trans(cv))
        {
            //cout << "BLAS GER: cv*trans(cv)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const int M = static_cast<int>(dest.nr());
            const int N = static_cast<int>(dest.nc());
            const T* X = get_ptr(src.lhs);
            const int incX = get_inc(src.lhs);
            const T* Y = get_ptr(src.rhs.op.m);
            const int incY = get_inc(src.rhs.op.m);

            if (add_to == false)
                zero_matrix(dest);

            T* A = get_ptr(dest);
            const int lda = get_ld(dest);

            if (transpose == false)
                cblas_ger(Order, M, N, alpha, X, incX, Y, incY, A, lda);
            else
                cblas_ger(Order, M, N, alpha, Y, incY, X, incX, A, lda);
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(rv)*trans(cv))
        {
            //cout << "BLAS GER: trans(rv)*trans(cv)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const int M = static_cast<int>(dest.nr());
            const int N = static_cast<int>(dest.nc());
            const T* X = get_ptr(src.lhs.op.m);
            const int incX = get_inc(src.lhs.op.m);
            const T* Y = get_ptr(src.rhs.op.m);
            const int incY = get_inc(src.rhs.op.m);

            if (add_to == false)
                zero_matrix(dest);

            T* A = get_ptr(dest);
            const int lda = get_ld(dest);

            if (transpose == false)
                cblas_ger(Order, M, N, alpha, X, incX, Y, incY, A, lda);
            else
                cblas_ger(Order, M, N, alpha, Y, incY, X, incX, A, lda);
        } IRECLIB_END_BLAS_BINDING

    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------
    //                       GERC overloads
    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------

        /*
        IRECLIB_ADD_BLAS_BINDING(cv*conj(rv))
        {
            //cout << "BLAS GERC: cv*conj(rv)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const int M = static_cast<int>(dest.nr());
            const int N = static_cast<int>(dest.nc());
            const T* X = get_ptr(src.lhs);
            const int incX = get_inc(src.lhs);
            const T* Y = get_ptr(src.rhs.op.m);
            const int incY = get_inc(src.rhs.op.m);

            if (add_to == false)
                zero_matrix(dest);

            T* A = get_ptr(dest);
            const int lda = get_ld(dest);

            if (transpose == false)
                cblas_gerc(Order, M, N, alpha, X, incX, Y, incY, A, lda);
            else
                cblas_gerc(Order, M, N, alpha, Y, incY, X, incX, A, lda);
        } IRECLIB_END_BLAS_BINDING
        */

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(cv*conj(trans(cv)))
        {
            //cout << "BLAS GERC: cv*conj(trans(cv))" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const int M = static_cast<int>(dest.nr());
            const int N = static_cast<int>(dest.nc());
            const T* X = get_ptr(src.lhs);
            const int incX = get_inc(src.lhs);
            const T* Y = get_ptr(src.rhs.op.m);
            const int incY = get_inc(src.rhs.op.m);


            if (transpose == false)
            {
                T* A = get_ptr(dest);
                const int lda = get_ld(dest);

                if (add_to == false)
                    zero_matrix(dest);

                cblas_gerc(Order, M, N, alpha, X, incX, Y, incY, A, lda);
            }
            else
            {
                matrix_assign_default(dest,trans(src),alpha,add_to);
                //cblas_gerc(Order, M, N, alpha, Y, incY, X, incX, A, lda);
            }
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(rv)*conj(trans(cv)))
        {
            //cout << "BLAS GERC: trans(rv)*conj(trans(cv))" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const int M = static_cast<int>(dest.nr());
            const int N = static_cast<int>(dest.nc());
            const T* X = get_ptr(src.lhs.op.m);
            const int incX = get_inc(src.lhs.op.m);
            const T* Y = get_ptr(src.rhs.op.m);
            const int incY = get_inc(src.rhs.op.m);


            if (transpose == false)
            {
                if (add_to == false)
                    zero_matrix(dest);

                T* A = get_ptr(dest);
                const int lda = get_ld(dest);

                cblas_gerc(Order, M, N, alpha, X, incX, Y, incY, A, lda);
            }
            else
            {
                matrix_assign_default(dest,trans(src),alpha,add_to);
                //cblas_gerc(Order, M, N, alpha, Y, incY, X, incX, A, lda);
            }
        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        /*
        IRECLIB_ADD_BLAS_BINDING(trans(rv)*conj(rv))
        {
            //cout << "BLAS GERC: trans(rv)*conj(rv)" << endl;
            const bool is_row_major_order = is_same_type<typename dest_exp::layout_type,row_major_layout>::value;  
            const CBLAS_ORDER Order = is_row_major_order ? CblasRowMajor : CblasColMajor;
            const int M = static_cast<int>(dest.nr());
            const int N = static_cast<int>(dest.nc());
            const T* X = get_ptr(src.lhs.op.m);
            const int incX = get_inc(src.lhs.op.m);
            const T* Y = get_ptr(src.rhs.op.m);
            const int incY = get_inc(src.rhs.op.m);

            if (add_to == false)
                zero_matrix(dest);

            T* A = get_ptr(dest);
            const int lda = get_ld(dest);

            if (transpose == false)
                cblas_gerc(Order, M, N, alpha, X, incX, Y, incY, A, lda);
            else
                cblas_gerc(Order, M, N, alpha, Y, incY, X, incX, A, lda);
        } IRECLIB_END_BLAS_BINDING
        */

    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------
    //                       DOT overloads
    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------

        IRECLIB_ADD_BLAS_BINDING(rv*cv)
        {
            //cout << "BLAS DOT: rv*cv" << endl;
            const int N = static_cast<int>(src.lhs.size());
            const T* X = get_ptr(src.lhs);
            const int incX = get_inc(src.lhs);
            const T* Y = get_ptr(src.rhs);
            const int incY = get_inc(src.rhs);

            if (add_to == false)
                dest(0) = alpha*cblas_dot(N, X, incX, Y, incY);
            else
                dest(0) += alpha*cblas_dot(N, X, incX, Y, incY);

        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(cv)*cv)
        {
            //cout << "BLAS DOT: trans(cv)*cv" << endl;
            const int N = static_cast<int>(src.lhs.size());
            const T* X = get_ptr(src.lhs.op.m);
            const int incX = get_inc(src.lhs.op.m);
            const T* Y = get_ptr(src.rhs);
            const int incY = get_inc(src.rhs);

            if (add_to == false)
                dest(0) = alpha*cblas_dot(N, X, incX, Y, incY);
            else
                dest(0) += alpha*cblas_dot(N, X, incX, Y, incY);

        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(rv*trans(rv))
        {
            //cout << "BLAS DOT: rv*trans(rv)" << endl;
            const int N = static_cast<int>(src.lhs.size());
            const T* X = get_ptr(src.lhs);
            const int incX = get_inc(src.lhs);
            const T* Y = get_ptr(src.rhs.op.m);
            const int incY = get_inc(src.rhs.op.m);

            if (add_to == false)
                dest(0) = alpha*cblas_dot(N, X, incX, Y, incY);
            else
                dest(0) += alpha*cblas_dot(N, X, incX, Y, incY);

        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(cv)*trans(rv))
        {
            //cout << "BLAS DOT: trans(cv)*trans(rv)" << endl;
            const int N = static_cast<int>(src.lhs.op.m.size());
            const T* X = get_ptr(src.lhs.op.m);
            const int incX = get_inc(src.lhs.op.m);
            const T* Y = get_ptr(src.rhs.op.m);
            const int incY = get_inc(src.rhs.op.m);

            if (add_to == false)
                dest(0) = alpha*cblas_dot(N, X, incX, Y, incY);
            else
                dest(0) += alpha*cblas_dot(N, X, incX, Y, incY);

        } IRECLIB_END_BLAS_BINDING

    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------
    //                       DOTC overloads
    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------

        IRECLIB_ADD_BLAS_BINDING(conj(rv)*cv)
        {
            //cout << "BLAS DOTC: conj(rv)*cv" << endl;
            const int N = static_cast<int>(src.lhs.op.m.size());
            const T* X = get_ptr(src.lhs.op.m);
            const int incX = get_inc(src.lhs.op.m);
            const T* Y = get_ptr(src.rhs);
            const int incY = get_inc(src.rhs);

            if (add_to == false)
                dest(0) = alpha*cblas_dotc(N, X, incX, Y, incY);
            else
                dest(0) += alpha*cblas_dotc(N, X, incX, Y, incY);

        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(conj(trans(cv))*cv)
        {
            //cout << "BLAS DOTC: conj(trans(cv))*cv" << endl;
            const int N = static_cast<int>(src.lhs.op.m.size());
            const T* X = get_ptr(src.lhs.op.m);
            const int incX = get_inc(src.lhs.op.m);
            const T* Y = get_ptr(src.rhs);
            const int incY = get_inc(src.rhs);

            if (add_to == false)
                dest(0) = alpha*cblas_dotc(N, X, incX, Y, incY);
            else
                dest(0) += alpha*cblas_dotc(N, X, incX, Y, incY);

        } IRECLIB_END_BLAS_BINDING

        // --------------------------------------

        IRECLIB_ADD_BLAS_BINDING(trans(conj(cv))*trans(rv))
        {
            //cout << "BLAS DOTC: trans(conj(cv))*trans(rv)" << endl;
            const int N = static_cast<int>(src.lhs.op.m.size());
            const T* X = get_ptr(src.lhs.op.m);
            const int incX = get_inc(src.lhs.op.m);
            const T* Y = get_ptr(src.rhs.op.m);
            const int incY = get_inc(src.rhs.op.m);

            if (add_to == false)
                dest(0) = alpha*cblas_dotc(N, X, incX, Y, incY);
            else
                dest(0) += alpha*cblas_dotc(N, X, incX, Y, incY);

        } IRECLIB_END_BLAS_BINDING

    }

// ----------------------------------------------------------------------------------------

}


