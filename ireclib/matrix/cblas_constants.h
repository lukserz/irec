// Copyright (C) 2010  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


// Setting this tells other headers to define their own copy of the cblas API so we can
// call it.  We only do this if some other cblas API hasn't already been included.  



namespace ireclib
{
    namespace blas_bindings
    {
        enum CBLAS_ORDER {CblasRowMajor=101, CblasColMajor=102};
        enum CBLAS_TRANSPOSE {CblasNoTrans=111, CblasTrans=112, CblasConjTrans=113};
        enum CBLAS_UPLO {CblasUpper=121, CblasLower=122};
        enum CBLAS_DIAG {CblasNonUnit=131, CblasUnit=132};
        enum CBLAS_SIDE {CblasLeft=141, CblasRight=142};

    }
}


