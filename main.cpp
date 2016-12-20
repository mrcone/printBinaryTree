#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;

class Nodo{
public:
	Nodo *Derecha;
	Nodo *Izquierda;
	int dato;
	Nodo(int dat, Nodo *iz, Nodo *der){
		this->dato=dat;
		this->Izquierda=iz;
		this->Derecha=der;
	}
};

class Arbol{
public:
	int tamanyo(Nodo *nodo) const {
	    return (nodo == NULL)? 0 : tamanyo(nodo->Izquierda) + tamanyo(nodo->Derecha) + 1;
	}

	void printArbol(Nodo *root, int factorAnchura=1){
	    std::queue<Nodo *> colaNodos;
	    int techo=log2(tamanyo(root)+1);
	    colaNodos.push(root);
	    int pot=0;
	    while(colaNodos.size() > 0){
	      int niveles = colaNodos.size();
		      while(niveles > 0){
		        Nodo *nodoAux = colaNodos.front(); 
		        colaNodos.pop();
		        cout <<setw( (niveles==pow(2,pot))?pow(2, (techo-pot+factorAnchura)):pow(2, (techo-pot+factorAnchura+1)));
		        cout<< nodoAux->dato;
		        if(nodoAux->Izquierda != NULL) colaNodos.push(nodoAux->Izquierda);
		        if(nodoAux->Derecha != NULL) colaNodos.push(nodoAux->Derecha);
		        niveles--;
		      }
		      pot++;
		      cout << endl;
	    }
  	}
};

int
main(int argc, char **argv){
	Arbol *abb=new Arbol();
	//Arbol izq
	Nodo *nodo10=new Nodo(10, NULL, NULL);
	Nodo *nodo30=new Nodo(30, NULL, NULL);
	Nodo *nodo20=new Nodo(20, nodo10, nodo30);
	Nodo *nodo39=new Nodo(39, NULL, NULL);
	Nodo *nodo49=new Nodo(49, NULL, NULL);
	Nodo *nodo45=new Nodo(45, nodo39, nodo49);
	Nodo *nodo40=new Nodo(40, nodo20, nodo45);

	//Arbol dcho
	Nodo *nodo60=new Nodo(60, NULL, NULL);
	Nodo *nodo69=new Nodo(69, NULL, NULL);
	Nodo *nodo65=new Nodo(65, nodo60, nodo69);
	Nodo *nodo80=new Nodo(80, NULL, NULL);
	Nodo *nodo100=new Nodo(100, NULL, NULL);
	Nodo *nodo90=new Nodo(90, nodo80, nodo100);
	Nodo *nodo70=new Nodo(70, nodo65, nodo90);	

	//Raiz
	Nodo *nodo50=new Nodo(50, nodo40, nodo70);

	abb->printArbol(nodo50);
}
