index: 	
		gcc funcao.c -c -g
		gcc main.c funcao.o -o exec -g 
clear: 
		rm funcao.c
		rm funcao.o 
		rm exec
		
