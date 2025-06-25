

namespace ireclib
{
    template<typename T>
    void fft(const fft_size& dims, const std::complex<T>* in, std::complex<T>* out, bool is_inverse)
    {
        mkl_fft(dims, in, out, is_inverse);
        kiss_fft(dims, in, out, is_inverse);
    }

    template<typename T>
    void fftr(const fft_size& dims, const T* in, std::complex<T>* out)
    {
        mkl_fftr(dims, in, out);
        kiss_fftr(dims, in, out);
    }

    template<typename T>
    void ifftr(const fft_size& dims, const std::complex<T>* in, T* out)
    {
        mkl_ifftr(dims, in, out);
        kiss_ifftr(dims, in, out);
    }

    template void fft<float>(const fft_size& dims, const std::complex<float>* in, std::complex<float>* out, bool is_inverse);
    template void fft<double>(const fft_size& dims, const std::complex<double>* in, std::complex<double>* out, bool is_inverse);

    template void fftr<float>(const fft_size& dims, const float* in, std::complex<float>* out);
    template void fftr<double>(const fft_size& dims, const double* in, std::complex<double>* out);

    template void ifftr<float>(const fft_size& dims, const std::complex<float>* in, float* out);
    template void ifftr<double>(const fft_size& dims, const std::complex<double>* in, double* out);
}