#include <iostream>
extern "C"{
#include <dlfcn.h>
}

int main(){
		auto dll = dlopen("./libmath.so", RTLD_NOW);
		if(dll == NULL) {
				std::cout << dlerror();
				return -1;
		}

		auto add = reinterpret_cast<int(*)(int, int)>(dlsym(dll, "add"));
		if(add == NULL){
				std::cout << dlerror();
				dlclose(dll);
				return -1;
		}

		std::cout << add(2, 3) << std::endl;
		dlclose(dll);

		return 0;
}
