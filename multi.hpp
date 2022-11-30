/*Pablo Ernesto Angusto Delgado 842255 y  Miguel Aréjula Aisa 850068
 */

#ifndef MULTI_HPP
#define MULTI_HPP

using namespace std;

// PREDECLARACIÓN DEL TAD GENÉRICO multicomjuntos

// Sus valores multiconjuntos de elementos, es decir, colecciones de elementos
// en las que puede haber ejemplares repetidos
template <typename Elemento> struct Multi;

// Devuelve un multiconjunto vacío, sin elementos
template <typename Elemento> void vacio(Multi<Elemento> &m);

// Devuelve el multiconjunto igual al resultante de añadir un ejemplar del
// elemento "e" a "m"
template <typename Elemento>
void anyadir(Multi<Elemento> &m, const Elemento &e);

// Devuelve el multiconjunto igual al resultante de extraer un ejemplar del
// elemento "e" a "m"; si no hay ningún elemento de "e" en "m", devuelve el
// multiconjunto igual a m
template <typename Elemento> void quitar(Multi<Elemento> &m, const Elemento &e);

// Devuelve el número de ejemplares del elemento "e" en "m" (0 si no hay
// ninguno)
template <typename Elemento>
int multiplicidad(Multi<Elemento> &m, const Elemento &e);

// Devuelve el número total de elementos en "m", contando los repetidos
template <typename Elemento> int cardinal(Multi<Elemento> &m);

// Prepara el iterador para que el siguiente elemento a visitar sea el menor de
// todo el multiconjunto "m" (según la operación menor del parámetro formal
// elemento), si existe
template <typename Elemento> void iniciarIterador(Multi<Elemento> &m);

// Devuelve falso si ya se han visitado todos los elementos de "m", devuelve
// verdad en caso contrario
template <typename Elemento> bool existeSiguiente(Multi<Elemento> &m);

//cambiar

// Implementación en un único procedimiento de las operaciones "siguienteElem",
// "siguienteNumRep" y "avanza". Operacion siguienteElem: multi m -> natural
// {Devuelve el siguiente elemento a visitar de m (según el orden establecido
// por la operación menor). Parcial, la operación no está definida si no
// existeSiguiente(m). } Operación siguienteNumRep: multi m -> natural
//{ Devuelve la multiplicidad del siguiente elemento distinto a visitar de m
//(según el orden establecido por
// la operación menor). Parcial, la operación no está definida si no
// existeSiguiente(m). } Operación avanza: multi m -> multi
//{ Devuelve el multiconjunto resultante de avanzar el iterador de "m" al
//siguiente elemento distinto a visitar (según el orden establecido por la
// operación menor).} Parcial: la operación no está definida si no
// existeSiguiente(m). }
template <typename Elemento>
void siguiente(Multi<Elemento> &m, Elemento &e, int &num);

// Sus valores multiconjuntos de elementos, es decir, colecciones de elementos
// en las que puede haber ejemplares repetidos
template <typename Elemento> struct Multi {

  friend void vacio<Elemento>(Multi<Elemento> &m);
  friend void anyadir<Elemento>(Multi<Elemento> &m, const Elemento &e);
  friend void quitar<Elemento>(Multi<Elemento> &m, const Elemento &e);
  friend int multiplicidad<Elemento>(Multi<Elemento> &m, const Elemento &e);
  friend int cardinal<Elemento>(Multi<Elemento> &m);
  friend void iniciarIterador<Elemento>(Multi<Elemento> &m);
  friend bool existeSiguiente<Elemento>(Multi<Elemento> &m);
  friend void siguiente<Elemento>(Multi<Elemento> &m, Elemento &e,
                                  int &num); // preguntar si es mejor bool

private:
  struct Celda {
    Celda *siguiente;
    Elemento clave;
    int valor; // multiplicidad
  };
  int tamanyo;
  Celda *primero;
  Celda *iter;

};

// Devuelve un multiconjunto vacío, sin elementos
template <typename Elemento> void vacio(Multi<Elemento> &m) {
  m.primero = nullptr;
  m.tamanyo = 0;
  m.iter = nullptr;
}
// Devuelve el multiconjunto igual al resultante de añadir un ejemplar del
// elemento "e" a "m"
template <typename Elemento>
void anyadir(Multi<Elemento> &m, const Elemento &e) {
  if (m.primero == nullptr) { // vacia
    m.primero = new typename Multi<Elemento>::Celda;
    m.primero->clave = e;
    m.primero->valor = 1;
    m.primero->siguiente = nullptr;
    m.tamanyo++;
  } else { // no vacia
    typename Multi<Elemento>::Celda *aux;
    aux = nullptr;
    if (e < m.primero->clave) { // nuevo menor que el primero
      aux = m.primero;
      m.primero = new typename Multi<Elemento>::Celda;
      m.primero->clave = e;
      m.primero->valor = 1;
      m.primero->siguiente = aux;
      m.tamanyo++;
    } else {
      if (e == m.primero->clave) {
        m.primero->valor++;
        m.tamanyo++;
      } else { // buscar punto de insercción
        aux = m.primero;
        while (aux->siguiente != nullptr && (aux->siguiente)->clave < e) {
          aux = aux->siguiente;
        }
        if (aux->siguiente != nullptr && e == (aux->siguiente)->clave) {
          ((aux->siguiente)->valor)++;
          m.tamanyo++;
        } else {
          typename Multi<Elemento>::Celda *nuevo;
          nuevo = new typename Multi<Elemento>::Celda;
          nuevo->clave = e;
          (nuevo->valor) = 1;
          nuevo->siguiente = aux->siguiente;
          aux->siguiente = nuevo;
          m.tamanyo++;
        }
      }
    }
  }
}

// Devuelve el multiconjunto igual al resultante de extraer un ejemplar del
// elemento "e" a "m"; si no hay ningún elemento de "e" en "m", devuelve el
// multiconjunto igual a m
template <typename Elemento>
void quitar(Multi<Elemento> &m, const Elemento &e) {
  typename Multi<Elemento>::Celda *aux1;
  typename Multi<Elemento>::Celda *aux2;
  if (m.primero != nullptr) {      // no vacia
    if (!(e < m.primero->clave)) { // mayor igual que el primer elemento
      if (m.primero->clave == e) { // igual que el primer elemento
        aux1 = m.primero;
        m.primero = m.primero->siguiente;
        delete aux1;
        m.tamanyo--;
      } else { // distinto que el primer elemento
        bool parar = false;
        aux1 = m.primero->siguiente;
        aux2 = m.primero;
        while (aux1 != nullptr && !parar) {
          if (e < aux1->clave) {
            parar = true;
          } else if (e == aux1->clave) {

            if (aux1->valor == 1) { // si valor == 1 elimina la celda
              aux2->siguiente = aux1->siguiente;
              delete (aux1);
              m.tamanyo--;
            } else { // sino decrementa valor
              (aux1->valor)--;
              m.tamanyo--;
            }
            parar = true;
          } else {
            aux2 = aux1;
            aux1 = aux1->siguiente;
          }
        }
      }
    }
  }
}

// Devuelve el número de ejemplares del elemento "e" en "m" (0 si no hay
// ninguno)
template <typename Elemento>
int multiplicidad(Multi<Elemento> &m, const Elemento &e) {
  typename Multi<Elemento>::Celda *aux;
  aux = m.primero;
  while (aux->siguiente != nullptr && aux->clave < e) {
    aux = aux->siguiente;
  }
  if (aux != nullptr || aux->clave >= e) {
    if (aux->clave == e) {
      return (aux->valor);
    }
  }
  return 0;
}

// Devuelve el número total de elementos en "m", contando los repetidos //cambiar 
template <typename Elemento> int cardinal(Multi<Elemento> &m) {
  

  return m.tamanyo;
}

// Prepara el iterador para que el siguiente elemento a visitar sea el menor de
// todo el multiconjunto "m" (según la operación menor del parámetro formal
// elemento), si existe
template <typename Elemento> void iniciarIterador(Multi<Elemento> &m) {
  m.iter = m.primero;
}

// Devuelve falso si ya se han visitado todos los elementos de "m", devuelve
// verdad en caso contrario
template <typename Elemento> bool existeSiguiente(Multi<Elemento> &m) {
  return m.iter != nullptr;
}

// Implementación en un único procedimiento de las operaciones "siguienteElem",
// "siguienteNumRep" y "avanza". Operacion siguienteElem: multi m -> natural
// {Devuelve el siguiente elemento a visitar de m (según el orden establecido
// por la operación menor). Parcial, la operación no está definida si no
// existeSiguiente(m). } Operación siguienteNumRep: multi m -> natural
//{ Devuelve la multiplicidad del siguiente elemento distinto a visitar de m
//(según el orden establecido por
// la operación menor). Parcial, la operación no está definida si no
// existeSiguiente(m). } Operación avanza: multi m -> multi
//{ Devuelve el multiconjunto resultante de avanzar el iterador de "m" al
//siguiente elemento distinto a visitar (según el orden establecido por la
// operación menor).} Parcial: la operación no está definida si no
// existeSiguiente(m). }
template <typename Elemento>
void siguiente(Multi<Elemento> &m, Elemento &e, int &num) {
  if (existeSiguiente(m)) {
    e = m.iter->clave;
    num = m.iter->valor;
    m.iter = m.iter->siguiente;
  }
}

#endif
