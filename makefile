index: 	
		gcc funcao.c -c
		gcc main.c funcao.o -o exec
clear: 
		rm funcao.c
		rm funcao.o 
		rm exec
		
