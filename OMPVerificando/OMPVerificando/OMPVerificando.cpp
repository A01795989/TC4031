#include <iostream>
#include <omp.h>

int main()
{
    std::cout << "Verificando la ejecución 23 de las directivas OMP!\n";

#ifdef _OPENMP
    std::cout << "OMP disponible y funcionando!!!!!" << std::endl;
#else
    std::cout << "OMP no está disponible. Habilítalo en el compilador." << std::endl;
#endif

    return 0;
}
