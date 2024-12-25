#include "fft/fft.hpp"

#include <klee/klee.h>


#define SIGNAL_SIZE 1024


int main() {
    double in_real[SIGNAL_SIZE];
    double in_imag[SIGNAL_SIZE];

    klee_make_symbolic(&in_real, sizeof(in_real), "in_real");
    klee_make_symbolic(&in_imag, sizeof(in_imag), "in_imag");

    double out_real[SIGNAL_SIZE];
    double out_imag[SIGNAL_SIZE];

    fft(in_real, in_imag, SIGNAL_SIZE, out_real, out_imag);


    double in_inverse_real[SIGNAL_SIZE];
    double in_inverse_imag[SIGNAL_SIZE];

    klee_make_symbolic(&in_inverse_real, sizeof(in_inverse_real), "in_inverse_real");
    klee_make_symbolic(&in_inverse_imag, sizeof(in_inverse_imag), "in_inverse_imag");

    double out_inverse_real[SIGNAL_SIZE];
    double out_inverse_imag[SIGNAL_SIZE];

    ifft(in_inverse_real, in_inverse_imag, SIGNAL_SIZE, out_inverse_real, out_inverse_imag);

    return 0;
}