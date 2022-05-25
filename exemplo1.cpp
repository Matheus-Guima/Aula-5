//Matheus Guimar�es Rocha - Aula 05 - Exerc�cio 1
//C�digo base em C++
#include <iostream> 
#define MAX 10 // constante n�mero m�ximo de elementos
// ou int Max = (sizeof(vetor))/ sezeof(int))

using namespace std;

//Fun��o Intercala, Interativa

void intercala(int p, int q, int r, int v[]){
	int i, j, k, w[MAX]; //vetor auxiliar 
	i = p; //Posi��o inicial
	j = q; //Posi��o meio 
	k = 0; //Contador
	//percorre cada elemento daposi��o de in�cio pelo meio
	while(i<q && j<r){
		if(v[i] < v[j]){
			w[k] = v[i];
			i++;
		}else{
			w[k] = v[j];
			j++;
		}
		k++;
	}
	//percorre se ainda existem elementos no primeiro vetor
	// que ainda n foram intercalados 
	while(i<q){
		w[k] = v[i];
		i++;
		j++;
	}
	while(j<r){
		w[k] = v[j];
		j++;
		k++;
	}
	for( i = p; i < r; i++){
		v[i] = w[i-p];
	}
}

//Mergesort() recursivo
void mergesort(int p, int r, int v[]){
	int q;
	if(p < r - 1){
		q = (p + r)/2;
		mergesort(p, q, v);
		mergesort(q, r, v);
		intercala(p, q, r, v);
	}
}

//constatnte
// fun��o principal
int main() {
	
	//Configura��o
	setlocale(LC_ALL,"portuguese");
	
	//vetor pseudo-ordenado
	int v[] = {1, 30, 12, 40, 8, 2, 10, 90, 4, 5};
	//intercala (p, q,  r  , v[])
	//intercala(0, MAX/2, MAX-1, vetor);
	mergesort(0, MAX, v);
	
	//exibe vetor ordenado
	for(int i = 0; i < MAX; i++){
		cout<< v[i] << " ";
		//ou printf("%d ",v[]);
	}
	return 0;
} // fim do main()

