/*Pablo Ernesto Angusto Delgado 842255 y  Miguel Aréjula Aisa 850068
*/


#ifndef MULTI_HPP
#define MULTI_HPP

using namespace std;

// PREDECLARACIÓN DEL TAD GENÉRICO multicomjuntos

template <typename Elemento>
struct Multi;

//
template <typename Elemento>
void vacio( Multi<Elemento>& m);

//
template <typename Elemento>
void anyadir(Multi<Elemento>& m, const Elemento& e);

//
template <typename Elemento>
void quitar(Multi<Elemento>& m, const Elemento& e);

//
template <typename Elemento>
int multiplicidad(Multi<Elemento>& m, const Elemento& e);

//
template <typename Elemento>
int cardinal(Multi<Elemento>& m );

//
template <typename Elemento>
void iniciarIterdaor(Multi<Elemento>& m );

//
template <typename Elemento>
bool existeSiguiente(Multi<Elemento>& m );

//
template <typename Elemento>
void siguienteElem(Multi<Elemento>& m );

//
template <typename Elemento>
void siguienteNumRep(Multi<Elemento>& m );

//
template <typename Elemento>
void avanza(Multi<Elemento>& m );

//

template <typename Elemento>
struct Multi{

    friend  void vacio<Elemento> (Multi<Elemento>& m );
    friend  void anyadir<Elemento> (Multi<Elemento>& m, const Elemento& e  );
    friend  void quitar<Elemento> (Multi<Elemento>& m, const Elemento& e  );
    friend  int multiplicidad<Elemento> ( Multi<Elemento>& m, const Elemento& e );
    friend  int cardinal<Elemento> (Multi<Elemento>& m  );
    friend  void iniciarIterdaor<Elemento> ( Multi<Elemento>& m );
    friend  bool existeSiguiente<Elemento> ( Multi<Elemento>& m );
    friend  void siguienteElem<Elemento> (Multi<Elemento>& m  );
    friend  void siguienteNumRep<Elemento> ( Multi<Elemento>& m );
    friend  void avanza<Elemento> (Multi<Elemento>& m  );

    private:
        struct Celda{
            Celda* siguiente;
            Elemento clave;
            int valor;
        };
        int tamanyo;
        Celda* primero;
        Celda* iter;
};


template <typename Elemento>
void vacio(Multi<Elemento>& m){
    m.primero==nullptr;
    m.tamanyo = 0;
}
template <typename Elemento>
void anyadir(Multi<Elemento>& m, const Elemento& e){
    Celda aux;
    if(m.tamanyo==0){
        
    }else if(){

    }else{
    
    }
    m.tamanyo++;
}


template <typename Elemento>
void quitar(Multi<Elemento>& m, const Elemento& e);


template <typename Elemento>
int multiplicidad(Multi<Elemento>& m, const Elemento& e){
    
}


template <typename Elemento>
int cardinal(Multi<Elemento>& m ){
    return m.tamanyo;
}


template <typename Elemento>
void iniciarIterdaor(Multi<Elemento>& m ){
    m.iter->siguiente = m.primero;
}


template <typename Elemento>
bool existeSiguiente(Multi<Elemento>& m );


template <typename Elemento>
void siguienteElem(Multi<Elemento>& m );


template <typename Elemento>
void siguienteNumRep(Multi<Elemento>& m );


template <typename Elemento>
void avanza(Multi<Elemento>& m );





#endif

