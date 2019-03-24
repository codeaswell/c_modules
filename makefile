popo.exe : test_module.o intarray.o tools.o jstr.o stringarray.o charray2d.o
	gcc test_module.o intarray.o tools.o jstr.o stringarray.o charray2d.o -o popo.exe
	
intarray.o : intarray/intarray.c intarray/intarray.h
	gcc -c intarray/intarray.c

tools.o : tools/tools.c tools/tools.h
	gcc -c tools/tools.c

jstr.o : jstr/jstr.c jstr/jstr.h
	gcc -c jstr/jstr.c

charray2d.o : charray2d/charray2d.c charray2d/charray2d.h
	gcc -c charray2d/charray2d.c

stringarray.o : stringarray/stringarray.c stringarray/stringarray.h
	gcc -c stringarray/stringarray.c

test_module.o : test_module.c intarray/intarray.h tools/tools.h jstr/jstr.h stringarray/stringarray.h charray2d/charray2d.h
	gcc -c test_module.c
