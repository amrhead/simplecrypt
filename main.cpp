
    





#include <stdio.h>
#include <stdlib.h>
 
char *enigma(char *buf, long cnt, const char *pwd){
    char *pBuf;
    const char *pPwd;
    for ( pBuf = buf, pPwd = pwd; cnt; ++pBuf, --cnt ){
        *pBuf ^= *pPwd++;
        if ( !*pPwd )
            pPwd = pwd;
    }
    return buf;
}



    int var = 123; // инициализация переменной var числом 123
    int *ptrvar = &var; // указатель на переменную var
    
    
    int **ptr_ptrvar = &ptrvar; // указатель на указатель на переменную var


 
int main(int argc, char **argv){
    char *buf, pwd[32] = { 0 };
    long len;
    FILE *fin, *fout;
    
    
    if ( argc < 3 ){
        printf("Usage: %s <input_file> <output_file>\n", *argv);
        exit(1);
    }
    
    if ( ( fin = fopen(argv[1], "rb") ) == NULL ){
        printf("Can't open file <%s> for input!\n", argv[1]);
        exit(1);
    }
    fseek(fin, 0, SEEK_END);
    len = ftell(fin);
    if ( !len ){
        printf("Input file is empty!\n");
        exit(1);
    }
    rewind(fin);
    if ( ( buf = (char*)malloc(len) ) == NULL ){
        printf("Memory error!\n");
        exit(1);
    }
    if ( fread(buf, 1, len, fin) != len ){
        printf("Can't read input file!\n");
        exit(1);
    }
    fclose(fin);
    
    printf("Password: ");
    if ( scanf("%31s", pwd) != 1 ){
        printf("Input error!\n");
        exit(1);
    }
    
    if ( ( fout = fopen(argv[2], "wb") ) == NULL ){
        printf("Can't open file <%s> for output!\n", argv[2]);
        exit(1);
    }
    if ( fwrite(enigma(buf, len, pwd), 1, len, fout) != len ){
        printf("Can't write to output file!\n");
        exit(1);
    }
    fclose(fout);
    printf("Done.\n");
    
    exit(0);
}



