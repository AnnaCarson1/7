#include "DS.h"

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void q_push(Queue *p, int x)
{
        struct Elm *k = malloc ( sizeof ( struct Elm ) ) ;
        k -> x = x ;
        k -> next = NULL ;
        if ( p -> tail == NULL ) {
            p -> head = k ;
            p -> tail = k ;
        }
        else {
            p -> tail -> next = k ;
            p -> tail = p -> tail -> next ;
        }
        p -> len ++ ;
}

/* p-ийн зааж буй Queue-с гаргана */
void q_pop(Queue *p)
{
        struct Elm *k ;
        if ( p -> head == NULL ) return ;
        else {
            if ( p -> len == 1 ) {
                p -> head = NULL ;
                p -> tail = NULL ;
            }
            else {
                k = p -> head ;
                p -> head = p -> head -> next ;
                free ( k ) ;
            }
        }
        p -> len -- ;

}

/*
  p-ийн зааж буй Queue-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void q_print(Queue *p)
{
        struct Elm *k ;
        k = p -> head ;
        while ( k != NULL ) {
            printf ( "%d\n" , k -> x ) ;
            k = k -> next ;
        }
}
