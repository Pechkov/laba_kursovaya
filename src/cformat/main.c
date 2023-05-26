#include <stdio.h>
#include <stdlib.h>

#include <libcformat/funcformat.h>
#include <libcformat/ctack.h>

int main(int argc, char* argv[]){
    FILE* file = NULL;
    if (argc < 2){
        printf("write the file name after 'cformat'\n");
    }
    else if (argc == 2) {
	//printf("-2");
        if ((file = fopen(argv[1], "r")) == NULL) {
            printf("Error: can't open file \e[1;35m\"%s\"\e[0m\n", argv[1]);
	}
	else {
	    int c = 1;
	    printf("0");
	    int c = check_brackets(file);
            if (c == 1){
		check_tab(file);
		fclose(file);
		file = fopen(argv[1], "w");
		check_len(file);
		fclose(file);
		printf("успех");
            }
	    else
	    {
		printf("проблема в расстановке скобок");
		fclose(file);
	    }
        }
    }
    return 0;
}
