#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    //-------------your code here-------------

    first(L) = NULL;
    last(L) = NULL;

    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //-------------your code here-------------

    P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;


    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------

    delete P;

    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------

    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
        next(P) = first(L);
        prev(P) = last(L);
    }else{
        next(P) = first(L);
        prev(P) = last(L);
        prev(first(L)) = P;
        next(last(L)) = P;
        last(L) = P;
    }


    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------

   if(first(L) == NULL && last(L) == NULL){
        first(L) = P;
        last(L) = P;
        next(P) = P;
        prev(P) = P;
    }else{
        prev(P) = last(L);
        next(last(L)) = P;
        prev(first(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }


    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------

    if (first(L) != NULL){
        address P = first(L);
        while((next(P)!= first(L)) && ((info(P).ID!= x.ID))){
            P = next(P);
        }
        if(info(P).ID ==x.ID){
            return P;
        }else{
            return NULL;
        }
    }

    //----------------------------------------
    return P;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------

    if (first(L) != NULL){
        address P = first(L);
        while((next(P)!= first(L)) && ((info(P).name!= x.name))){
            P = next(P);
        }
        if(info(P).name ==x.name){
            return P;
        }else{
            return NULL;
        }
    }


    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------

    if(first(L) != NULL && last(L) != NULL){
        if(next(first(L))== first(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
            next(P) = NULL;
            prev(P) = NULL;
        }else{
            P = first(L);
            first(L) = next(P);
            prev(first(L)) = last(L);
            next(last(L)) = first(L);
            next(P) = NULL;
            prev(P) = NULL;
        }
    }

    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    P = last(L);
    if(first(L)== last(L)){
        first(L) = NULL;
        last(L) = NULL;
        next(P) = NULL;
        prev(P) = NULL;
    }else{
        last(L) = prev(P);
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
        next(P) = NULL;
        prev(P) = NULL;
    }



    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------

    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
    prev(next(P)) = P;

    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------

    if(first(L) != NULL && Prec!= NULL){
        P = next(Prec);
        if( P== first(L)){
            deleteFirst(L, P);
        }else if(P == last(L)) {
            deleteLast(L, P);
        }else{
            P = next(Prec);
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }

    }

    //----------------------------------------
}

