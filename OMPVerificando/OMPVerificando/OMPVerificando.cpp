#include <iostream>
#include <omp.h>

int main()
{
    std::cout << "Verificando la ejecuci�n 23 de las directivas OMP!\n";

#ifdef _OPENMP
    std::cout << "OMP disponible y funcionando!!!!!" << std::endl;
#else
    std::cout << "OMP no est� disponible. Habil�talo en el compilador." << std::endl;
#endif

    return 0;
}
