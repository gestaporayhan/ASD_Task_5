#include "player.h"
#include <ctime>

int randomInt(int  max_int) {
    srand(time(NULL));
    return (rand() % max_int) + 1;
}

void printInfo(List L) {
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    */

    address Q = first(L);
    do {
        cout<<"name    : "<<info(Q).name<<endl
            <<"ID      : "<<info(Q).ID<<endl
            <<"location: "<<info(Q).location<<endl;
        Q = next(Q);
    } while(Q!=first(L));
    cout<<"==============================================="<<endl;
}


void playMusic(address P) {
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    */

    string filename = info(P).location+"/"+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(500); //delay 0.5 second
}


void shuffleList(List &L) {
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    //-------------your code here-------------

        if(first(L)!= NULL){
            address P = first(L);
            int n = randomInt(5);
            for (int i = 0; i<n; i+1){
                deleteFirst(L, P);
                if(info(P).ID%2==1){
                    insertAfter(L, first(L), P);
                }else{
                    insertLast(L, P);
                }
            }
        }

    //----------------------------------------
}

void sortListByID(List &L) {
    /**
    * PR : mengurutkan isi (elemen) dari list L berdasarkan ID
    * FS : isi (elemen) dari list L terurut
    */
    //-------------your code here-------------

    if(first(L) != NULL){
        List L2;
        createList(L2);
        address P;
        while(first(L) != NULL){
            deleteFirst(L ,P);
            if(first(L2) == NULL && last(L2) == NULL){
                insertFirst(L2, P);
            }else if(info(P).ID <= info(first(L2)).ID){
                insertFirst(L2, P);
            }else if(info(P).ID >= info(last(L2)).ID){
                insertLast(L2, P);
            }else{
                address Q = first(L2);
                while(info(next(Q)).ID < info(P).ID){
                    Q = next(Q);
                }
                insertAfter(L2, Q, P);
            }
    }
    L = L2;
    //----------------------------------------
    }
}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //-------------your code here-------------

    if(first(L)!= NULL){
        for(int i = 0; i<n; i+1){
            address P = first(L);
            do{
                playMusic(P);
                P = next(P);
            }
            while (P!= first(L));
        }
    }

    //----------------------------------------
}

void deleteMusicByID(List &L, infotype x) {
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (deallocate) lagu dari list
    * FS : elemen dengan ID yang dicari dideallocate
    */
    //-------------your code here-------------

    address Prec, P;
    if(first(L)!= NULL){
        P = findElmByID(L,x);
        if(P == NULL){
            cout<<"Music Empty"<<endl;
            return;
        }
        if(first(L) == P){
            deleteFirst(L, P);
        }else if(last(L) == P){
            deleteLast(L, P);
        } else{
            Prec = first(L);
            while(next(Prec) != P){
                Prec = next(Prec);
            }
            deleteAfter(L, Prec, P);
        }
        deallocate(P);
        cout<<"Delete success"<<endl;
    }


    //----------------------------------------
}
