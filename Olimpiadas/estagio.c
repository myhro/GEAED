#include <stdio.h>

#define MAX_ALUNOS 1000

int main()
{
  int i, indice_melhor, n;
  int turma=0;
  struct
  {
    int codigo, media;
  } alunos[MAX_ALUNOS];
  /* le numero de alunos da primeira turma */
  scanf("%d", &n);
  while (n > 0)
    {
    	turma++;
      /* le dados dos alunos */
      for (i = 0; i < n; i++)
        scanf("%d %d", &alunos[i].codigo, &alunos[i].media);
      /* procura aluno de maior media */
      indice_melhor = 0;
      for (i = 1; i < n; i++)
        if (alunos[i].media > alunos[indice_melhor].media)
            indice_melhor = i;
      /* escreve resposta */
      //printf("Turma %d\n%d\n\n", turma++, alunos[indice_melhor].codigo);
      printf("Turma %d\n", turma);
      for (i = 0; i < n; i++) {
		if (alunos[i].media == alunos[indice_melhor].media) {
			printf("%d ", alunos[i].codigo);
		}
      }
      printf("\n\n");
      /* le numero de alunos da proxima turma */
      scanf("%d", &n);
    }
  return 0;
}
