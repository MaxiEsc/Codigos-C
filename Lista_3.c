#include <stdio.h> /* printf()...           */
#include "set.h"   /* Interfaz del TAD set  */

static void
print_set(set s) {
    /* Muestra por pantalla el contenido de un conjunto de enteros */
    /*
     * Es crucial que las funciones:
     *   - set_copy()
     *   - set_get()
     *   - set_elim()
     *   - set_is_empty()
     *
     * estén bien programadas para que se muestre correctamente.
     */
    set saux=set_copy(s);
    printf("{");
    while (!set_is_empty(saux)) {
        type_elem e;
        e = set_get(saux);
        printf("%i", e);
        saux = set_elim(saux, e);
        if (!set_is_empty(saux))
            printf(", ");
     }
    printf("}");
    saux = set_destroy(saux);
}

static void
show_status(set s, const char *name) {
    /*
     * Muestra por pantalla: - La etiquena 'name'
     *                       - El contendio del conjunto
     *                       - Su longitud
     *                       - Si es o no vacío
     */
    /* Se muestra la etiqueta */
    printf("{ %s == ", name);
    /* Se muestra el contenido del conjunto */
    print_set(s);
    printf(" /\\ ");
    /* Se muestra el cardinal */
    printf("|%s| = %i /\\ ", name, set_cardinal(s));
    /* Se indica si es vacío o no */
    if (set_is_empty(s)) printf("empty"); else printf("not empty");
    printf(" }");
    printf("\n\n");
}

