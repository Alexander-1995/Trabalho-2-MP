#include<romano.h>

int roman_to_arab(char nro_rom[30]){

    int aux[30],tam,i,j;

    tam = strlen(nro_rom);
    for(i=0; i<tam; i++){
        if(nro_rom[i] == 'I'){
            aux[i] = 1;
        }else if(nro_rom[i] == 'V'){
            aux[i] = 5;
        }else if (nro_rom[i] == 'X'){
            aux[i] = 10;
        }else if (nro_rom[i] == 'L'){
            aux[i] = 50;
        }else if (nro_rom[i] == 'C'){
            aux[i] = 100;
        }else if (nro_rom[i] == 'D'){
            aux[i] = 500;
        }else if (nro_rom[i] == 'M'){
            aux[i] = 1000;             
        }else{
            return(-1);
        }
    }

    for(i=0; i<tam; i++){
        if (nro_rom[i] == 'X' & nro_rom[i+1] == 'X' & nro_rom[i+2] == 'X' & nro_rom[i+3] == 'X'){  /*Teste nro 1 para impedir 4 X seguidos*/  
            return(-1);
            }
    }

    for(i=0; i<tam; i++){
        if (nro_rom[i] == 'V' & nro_rom[i+1] == 'V'){  /*Teste nro 2 para impedir VV*/  
            return(-1);
            }
    }          

    for(i=0; i<tam; i++){
        if (nro_rom[i] == 'V' & nro_rom[i+1] == 'X'){  /*Teste nro 3 para impedir VX*/  
            return(-1);
            }
    }          

    j = aux[tam-1];
    for(i=tam-1; i>0; i--){
        if(aux[i]>aux[i-1]){
            j = j-aux[i-1];
        }else if(aux[i]<aux[i-1] || aux[i]==aux[i-1]){
            j = aux[i-1] + j;
        }
    }

    return(j);
}