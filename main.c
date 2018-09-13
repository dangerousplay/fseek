#include <stdio.h>
#include <stdlib.h>

struct threeNum
{
   int n1, n2, n3;
};

/*
 * Lendo informações de trás para frente do arquivo binário gerado no exemplo 3
 * */
int main()
{
   int n;
   struct threeNum num;
   FILE *fptr;

   if ((fptr = fopen("program.bin","rb")) == NULL){
       printf("Erro ao abrir o arquivo.");

       // O programa irá finalizar caso não consiga abrir o arquivo.
       exit(1);
   }

   // Move o cursos para a última posição no arquivo binário.
   fseek(fptr, sizeof(struct threeNum), SEEK_END);

   for(n = 1; n < 5; ++n)
   {
      fread(&num, sizeof(struct threeNum), 1, fptr);
      printf("n1: %d\tn2: %d\tn3: %d", num.n1, num.n2, num.n3);
   }
   fclose(fptr);

   return 0;
}