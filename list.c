#include "DS.h"

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, int x)
{
        struct Elm *k = malloc ( sizeof ( Elm ) ) ;
        k -> x = x ;
        k -> next = NULL ;
        if ( p -> head == NULL ) {
            p -> head = k ;
            p -> tail = k ;
        }
        else {
            p -> tail -> next = k ;
            p -> tail = p -> tail -> next ;
        }
        p -> len ++ ;
}

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, int x)
{
        struct Elm *k = malloc ( sizeof ( Elm ) ) ;
        k -> x = x ;
        k -> next = NULL ;
        if ( p -> head == NULL ) {
            p -> head = k ;
            p -> tail = k ;
        }
        else {
            k -> next = p -> head ;
            p -> head = k ;
        }
        p -> len ++ ;
}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, int x, int pos)
{
        if ( pos == 0 ) {
            l_push_front ( p , x ) ;
            return ;
        }
        if ( pos == p -> len ) {
            l_push_back ( p , x ) ;
            return ;
        }
        struct Elm *k ;
        int i ;
        k = p -> head ;
        for ( i = 0 ; i < p -> len ; i ++ ) {
            if ( i == pos - 1 ) {
                struct Elm *y = malloc ( sizeof ( Elm ) ) ;
                y -> x = x ;
                y -> next = k -> next ;
                k -> next = y ;
                p -> len ++ ;
                break ;
            }
            k = k -> next ;
        }
}


/*
  p-ийн зааж буй List-н эхлэлээс гаргана.
  List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p)
{
        struct Elm *k ;
        if ( p -> head == NULL ) return ;
        else {
            if ( p -> len == 1 ) {
                free ( p -> head ) ;
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

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
        struct Elm *k , *temp ;
        if ( p -> len == 1 ) {
            free ( p -> head ) ;
            p -> head = NULL ;
            p -> tail = NULL ;
            p -> len -- ;
            return ;
        }
        k = p -> head ;
        while ( k != NULL ) {
            if ( k -> next == p -> tail ) {
                temp = k ;
                k = p -> tail ;
                p -> tail = temp ;
                p -> tail -> next = NULL ;
                free ( k ) ;
                break ;
            }
            k = k -> next ;
        }
        p -> len -- ;
}

/* p-ийн зааж буй List-н pos байрлалаас гаргана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
   pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos)
{
        if ( pos < 0 || pos >= p -> len || p -> len == 0 ) {
            return ;
        }
        if ( pos == 0 ) {
            l_pop_front ( p ) ;
            return ;
        }
        if ( pos == p -> len - 1 ) {
            l_pop_back ( p ) ;
            return ;
        }
        struct Elm *k , *temp ;
        int i ;
        k = p -> head ;
        for ( i = 0 ; i < p -> len ; i ++ ) {
            if ( i == pos - 1 ) {
                temp = k -> next ;
                k -> next = temp -> next ;
                free ( temp ) ;
                p -> len -- ;
                break ;
            }
            k = k -> next ;
        }
}

/*
  p-ийн зааж буй List-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void l_print(List *p)
{
        struct Elm *k ;
        k = p -> head ;
        while ( k != NULL ) {
            printf ( "%d\n" , k -> x ) ;
            k = k -> next ;
        }
}

/*
  p-ийн зааж буй List-с x тоог хайн олдсон хаягийг буцаана.
  Олдохгүй бол NULL хаяг буцаана.
 */
Elm *l_search(List *p, int x)
{
        struct Elm *k , *y ;
        y = NULL ;
        k = p -> head ;
        while ( k != NULL ) {
            if ( k -> x == x ) {
                y = k ;
                break ;
            }
            k = k -> next ;
        }
        return y ;
}
