#include <unistd.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

typedef int FUNC(int, int);

void testDllLoadDynamic() {

    void *handle;
    int (*fnc)(int, int);
    const char *errmsg;

    handle = dlopen("libdynamic_lib.so", RTLD_NOW);
    if (handle == NULL)
    {
        std::cout << "Failed to load libdynamic_lib.so " << std::endl;
        return;
    }

    dlerror();

    // fnc = reinterpret_cast<int(*)(int, int)>(dlsym(handle, "d_add"));

    // int (*fnc)(int, int) = dlsym(handle, "d_add");

    // FUNC* fnc = reinterpret_cast<FUNC*> (dlsym(handle, "d_add"));

    *(void **) fnc = dlsym(handle, "d_add");

    if ((errmsg = dlerror()) != NULL)
    {
	    std::cout<< "error : " << errmsg << std::endl;
	    return;
    }

    printf("d_add(1, 2) == %d\n", fnc(1, 2));

    dlclose(handle);
    return;
}
