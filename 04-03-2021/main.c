#include "listaencadeada.h"

int main() {
    struct list lista;

    lista.data.DDD = -1;
    lista.next     = NULL;

    carregar("in.txt", &lista);
    percorrer(&lista);
    salvar("out.txt", &lista);
}
