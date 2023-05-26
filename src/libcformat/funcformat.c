#include <ctype.h>
#include <stdlib.h>
#include <libcformat/ctack.h>
int check_brackets(FILE* file)
{
    Stack_t *st = createStack();
    char ch;
    char a;
    push(st, '1');
    while(ch != EOF)
    {
	ch = fgetc(file);
	printf("%c", ch);
	a = peek(st);
        if(ch == '{')
        {
	    push(st, '{');
        }
        if(ch == '(')
        {
            push(st, '(');
        }
        if(ch == '[')
        {
            push(st, '[');

        }
        if((ch == '}') && (a != '{')) {

	    return 0;
	    break;
        }
	else if ((ch == '}') && (a == '{')) {

	    pop(st);
	}
        if((ch == ')') && (a != '(')) {

            return 0;
            break;
	}
        else if ((ch == ')') && (a == '(')) {

            pop(st);
        }
        if((ch == ']') && (a != '[')) {
            return 0;
            break;
	}
        else if ((ch == ']') && (a == '[')) {
            pop(st);
        }
    }
    if (a != '1')
    {
	return 0;
    }
    else
    {
	return 1;
    }
}
void check_tab(FILE* file)
{
    printf("падла");
    FILE* copy;
    copy = fopen("obj/file_1", "w");
    char ch;
    int tab = 0;
    while(ch != EOF)
    {
        ch = fgetc(file);
	    if(ch == '{')
	    {
		fprintf(copy, "{");
		fprintf(copy, "\n");
		tab++;
		for(int i = 0; i < tab; i++){
		    fprintf(copy, " ");
		}
            }
            else if(ch == '}')
            {
		fprintf(copy, "}");
                fprintf(copy, "\n");
                tab--;
                for(int i = 0; i < tab; i++){
                    fprintf(copy, " ");
                }
            }
            else if(ch == ';')
            {
                fprintf(copy, ";");
                fprintf(copy, "\n");
                for(int i = 0; i < tab; i++){
                    fprintf(copy, " ");
                }
            }
	    else
	    {
		fprintf(copy, "%c", ch);
	    }
    }
    fclose(copy);
}

int lexl(char *str)
{
    char ar[] = "+-=/*%";
    int last;
    for(int i = 0; i < 80; i++)
    {
	int count = 0;
	for(int ii = 0; ii < 6; ii++) {
	    if (str[i] == ar[ii]){
		count = 1;
	    }
	}
	if(count == 1)
	{
	    last = i;
	}
    }
    return last;
}
int lexf(char *str, int first)
{
    char ar[] = "+-=/*%";
    for(int i = 0; i < 80; i++)
    {
        int count = 0;
        for(int ii = 0; ii < 6; ii++) {
            if (str[i] == ar[ii]){
                count = 1;
            }
        }
        if((count == 1) && first == 0)
        {
            first = i;
        }
    }
    return first;
}

void check_len(FILE* file)
{
    FILE* copy;
    copy = fopen("obj/file_1", "r");
    char ch;
    char str[80];
    int last;
    while(ch != EOF)
    {
        int i = 0;
        int sh = 0;
	int first = 0;
        ch = fgetc(copy);
        while(ch != '\n')
        {
            if(i - sh == 80)
	    {
	        for(int ii = 0; ii < first; ii++){
                    str[ii] = ' ';
                    fprintf(file, " ");
                }
                first = lexf(str, first);
		last = lexl(str);
		for(int ii = 0; ii < last; ii++){
                    fprintf(file, "%c", str[ii - sh]);
		}
		fprintf(file, "\n");
		sh += last;
	    }
	    str[i - sh] = ch;
	    i++;
	}
	for(int i = 0; i < 80; i++)
	{
	    fprintf(file, "%c", str[i]);
	}
    }
    fclose(copy);
}
