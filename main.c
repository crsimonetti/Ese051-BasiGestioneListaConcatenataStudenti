#include <stdio.h>
#include <stdlib.h>

#define MAX_STRLEN 30
#define MAX_STRLEN_CLASSE 4

struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    char classe[MAX_STRLEN_CLASSE+1];
    int eta;
};
typedef struct s_studente studente;

struct s_elemento{
    studente value;
    struct s_elemento* next;
};
typedef struct s_elemento elemento;

void stampaLista(elemento*primo, int i);
void VuotaLista(elemento *primo);


int main(int argc, char** argv) {
    elemento *primo=NULL;
    elemento *nuovoElemento;
    elemento *scorri;
    char risposta;
    int i;
    
    i=0;
    while(risposta=='s') {
       nuovoElemento=(elemento*)malloc(sizeof(elemento));
        if (nuovoElemento==NULL){
            fprintf(stderr, "Errore nell'allocazione di mememoria.");
            exit(1);
        }
        else{
            printf("Nome: ");
            scanf("\n%[^\n]", nuovoElemento->value.nome);
            printf("Cognome: ");
            scanf("\n%[^\n]", nuovoElemento->value.cognome);
            printf("Classe: ");
            scanf("\n%[^\n]", nuovoElemento->value.classe);
            printf("Eta': ");
            scanf("\n%d", &(nuovoElemento->value.eta));
            nuovoElemento->next=primo;
            primo=nuovoElemento;
        }     
        printf("Vuoi inserire un altro studente? (s/n): ");
        scanf("\n%c", &risposta);
        i++;
    }
    
    scorri=primo;
    while(scorri!=NULL){
        printf("\nStudente %d\n Nome: %s\n Cognome: %s\n Classe: %s\n Eta': %d\n",
        i,
        scorri->value.nome,
        scorri->value.cognome,
        scorri->value.classe,
        scorri->value.eta);
        
        scorri=scorri->next;
        i--;
    }
    
    VuotaLista(primo);
    return (EXIT_SUCCESS);
}

void VuotaLista(elemento *primo){
    elemento *temporanea;
    while(primo!=NULL){
        temporanea=primo->next;
        free(primo);
        primo=temporanea;
    }
    return;
}

