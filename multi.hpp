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
void iniciarIterador(Multi<Elemento>& m );

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
bool siguiente (Multi<Elemento>& m, Elemento& e, int& num );


template <typename Elemento>
struct Multi{

    friend  void vacio<Elemento> (Multi<Elemento>& m );
    friend  void anyadir<Elemento> (Multi<Elemento>& m, const Elemento& e  );
    friend  void quitar<Elemento> (Multi<Elemento>& m, const Elemento& e  );
    friend  int multiplicidad<Elemento> ( Multi<Elemento>& m, const Elemento& e );
    friend  int cardinal<Elemento> (Multi<Elemento>& m  );
    friend  void iniciarIterador<Elemento> ( Multi<Elemento>& m );
    friend  bool existeSiguiente<Elemento> ( Multi<Elemento>& m );
    friend  bool siguiente<Elemento> (Multi<Elemento>& m, Elemento& e, int& num );

    private:
        struct Celda{
            Celda* siguiente;
            Elemento clave;
            int valor; //multiplicidad
        };
        int tamanyo;
        Celda* primero;
        Celda* iter;
};


template <typename Elemento>
void vacio(Multi<Elemento>& m){
    m.primero=nullptr;
    m.tamanyo = 0;
    m.iter = nullptr;
}

template <typename Elemento>
void anyadir(Multi<Elemento>& m, const Elemento& e){
    if(m.primero==nullptr){ //vacia
        m.primero = new typename Multi<Elemento>::Celda;
        m.primero->clave = e;
        m.primero->valor = 1;
        m.primero->siguiente=nullptr;
    }else{ //no vacia 
        typename Multi<Elemento>::Celda* aux;
        aux = nullptr;
        if(e<m.primero->clave){ //nuevo menor que el primero
        aux=m.primero;
        m.primero = new typename Multi<Elemento>::Celda;
        m.primero->clave=e;
        m.primero->valor=1;
        m.primero->siguiente=aux;
        m.tamanyo++;
        }else{
            if(e==m.primero->clave){
                m.primero->valor++;
            }else{ // buscar punto de insercción
                aux=m.primero;
                while(aux->siguiente!=nullptr && (aux->siguiente)->clave<e){
                    aux = aux->siguiente;
                }
                if(aux->siguiente!=nullptr && e==(aux->siguiente)->clave){
                    ((aux->siguiente)->valor)++;
                }else{
                    typename Multi<Elemento>::Celda* nuevo;
                    nuevo = new typename Multi<Elemento>::Celda;
                     nuevo->clave=e;
                    (nuevo->valor)= 1;
                    nuevo->siguiente= aux->siguiente;
                    aux->siguiente = nuevo;
                    m.tamanyo++;
                 }
            }
        }
    }
    
}


template <typename Elemento>
void quitar(Multi<Elemento>& m, const Elemento& e){
    typename Multi<Elemento>::Celda* aux1;
    typename Multi<Elemento>::Celda* aux2;
    if(m.primero!=nullptr){
        if(!(e<m.primero->clave)){
            if(m.primero->clave==e){
                aux1=m.primero;
                m.primero=m.primero->siguiente;
                delete aux1;
                m.tamanyo--;
            }else{
                bool parar=false;
                aux1=m.primero->siguiente;
                aux2=m.primero;
                while(aux1 != nullptr && !parar){
                    if(e<aux1->clave){
                        parar=true;
                    }else if(e==aux1->clave){
                        aux2->siguiente=aux1->siguiente;
                        delete(aux1);
                        parar = true;
                        m.tamanyo--;
                    }else{
                        aux2=aux1;
                        aux1=aux1->siguiente;
                    }
                }
            }
        }
    }
}


template <typename Elemento>
int multiplicidad(Multi<Elemento>& m, const Elemento& e){
    typename Multi<Elemento>::Celda* aux;
    aux=m.primero;
    while(aux ->siguiente!= nullptr && aux->clave < e){
        aux = aux->siguiente;
    }
    if(aux != nullptr || aux->clave >= e){
        if(aux->clave == e){
            return (aux->valor);
        }
    }
    return 0;
}


template <typename Elemento>
int cardinal(Multi<Elemento>& m ){
    return m.tamanyo;
}


template <typename Elemento>
void iniciarIterador(Multi<Elemento>& m ){
    m.iter = m.primero;
}


template <typename Elemento>
bool existeSiguiente(Multi<Elemento>& m ){
    return m.iter != nullptr;
}


template <typename Elemento>
bool siguiente(Multi<Elemento>& m, Elemento& e, int& num){
    if(existeSiguiente(m)){
        e = m.iter->clave;
        num =  m.iter->valor;
        m.iter = m.iter->siguiente;
        return true;
    }else {
        return false;
    }

}





#endif

