#include "DS.h"
/*
  p-ийн зааж буй Stack-т x утгыг оруулна
 */
void s_push(Stack *p, int x)
{
        struct Elm *k = malloc ( sizeof ( Elm ) ) ;
        k -> x = x ;
        k -> next = p -> top ;
        p -> top = k ;
        p -> len ++ ;

}
/*
  p-ийн зааж буй Stack-аас гарах функц
 */
void s_pop(Stack *p)
{
        struct Elm *k ;
        if ( p -> top == NULL ) return ;
        else {
            k = p -> top ;
            p -> top = p -> top -> next ;
            free ( k ) ;
        }
        p -> len -- ;

}
/*
    p-ийн зааж буй Stack-д байгаа элементүүдийг хэвлэх функц.
    Хамгийн сүүлд орсон элементээс эхлэн дарааллаар, нэг мөрөнд
    нэг л элемент хэвлэнэ.
 */
void s_print(Stack *p)
{
        struct Elm *k ;
        k = p -> top ;
        while ( k != NULL ) {
            printf ( "%d\n" , k -> x ) ;
            k = k -> next ;
        }
}
