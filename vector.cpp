const int MAX = 100; //Número máximo de elementos

typedef int tvector[MAX]; //Los elementos son, en este ejemplo, enteros

struct vov {
tvector vector;
int ocupadas;
};

//PRE = {v está formado correctamente, ORDENADO ascendentemente y tiene algún
//espacio libre (V.Ocupadas < MAX)}
//POST = {el nuevo elemento x está en orden ascendente dentro del vector}
// Complejidad: O(n)
void insorden (vov &v, int x) {
int i, pos;
bool enc;
enc = false;
pos = 0;
while ((pos<v.ocupadas) && (!enc)) {
if (v.vector[pos] >= x)
enc = true;
else
pos = pos + 1;
}
//al salir del bucle, pos indica la posición donde deberá
// ir el nuevo elemento x
// hay que desplazar hacia la derecha los mayores que x
for(i=v.ocupadas-1; i>=pos; i--) {
v.vector[i+1] = v.vector[i];
}
v.vector[pos]=x;
v.ocupadas = v.ocupadas +1;
}

//Otra version: empezamos por el final de la parte ocupada del vector,
//desplazando hacia la derecha todos los elementos que sean mayores que el nuevo
//para ir haciéndole hueco
// Complejidad: O(n)
void insorden2 (vov &v, int x) {
int i;
bool enc;
enc=false;
i= v.ocupadas-1;
while ((i>=0) && (!enc)) {
if (v.vector[i] > x) {
v.vector[i+1] = v.vector[i];
i = i - 1;
}
else
enc = true;
}
v.vector[i+1] = x;
v.ocupadas = v.ocupadas +1;
}


//PRE = {v está formado correctamente y tiene, como mínimo, un elemento}
//POST = {v tiene un elemento menos, el del principio}
// Complejidad: O(n)
void borrarprincipio (vov &v) {
int i;
for (i=1;i<v.ocupadas;i++) {
v.vector[i-1] = v.vector[i];
}
v.ocupadas = v.ocupadas - 1;
}

//PRE = {v está formado correctamente}
//POST = {devuelve true si x está en el vector, y por tanto, ha eliminado su
//primera aparición y V tiene un elemento menos; false en caso contrario}
// Complejidad: O(n)
bool borrar (vov &v, int x) {
int i, pos;
bool enc;
enc = buscar(v, x, pos); // buscamos el element x en v
if (enc) {
for(i=pos+1;i<v.ocupadas;i++) {
v.vector[i-1] = v.vector[i];
}
v.ocupadas = v.ocupadas - 1;
}
return enc;
}

//PRE = {v está formado correctamente}
//POST = {borra todas las apariciones de x del vector}
// Complejidad: O(n)
void borrartodos (vov &v, int x) {
int i, iguales;
iguales = 0;
for(i=0;i<v.ocupadas;i++) {
if (v.vector[i] == x)
iguales = iguales + 1;
else
v.vector[i-iguales] = v.vector[i];
}
v.ocupadas = v.ocupadas - iguales;
}



int main()
{
  return 0;
}
