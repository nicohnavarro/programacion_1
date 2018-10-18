#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
/** \brief Toma una cadena de caracteres
 *
 * \param cadena de caracteres
 * \param limite
 * \return todo ok 0, error -1
 *
 */
int utn_getString(char* pBuffer,int limite,int reintentos,char* msg,char*msgError);


/** \brief Toma un numero entero por pantalla
 *
 * \param puntero donde guarda el valor
 * \param cantidad de reintentos mayor o igual a O
 * \param mensaje inicial
 * \param mensaje de error
 * \param valor minimo
 * \param valor maximo
 * \return 0 todo bien! -1 error
 *
 */
int utn_getEntero(int*pEntero,int reintentos,char* msg,char*msgError,int minimo,int maximo);

/** \brief muestra un array tipo int
 *
 * \param array
 * \param limite del array
 * \return 0
 *
 */
int utn_mostrarArray(int * pArray,int limite);

/** \brief Calcula el maximo en un array tipo int
 *
 * \param array
 * \param limite del array
 * \param variable donde guarda valor
 * \return 0 todo ok! -1 todo mal
 *
 */
int utn_calcularNumeroMaximo(int *pArray,int limite,int *maximo);

/** \brief inicializa todo el array con un valor especifico
 *
 * \param array
 * \param limite del array
 * \param valor
 * \return 0 todo ok! -1 error
 *
 */
int utn_initArray(int * pArray,int limite,int valor);

/** \brief verifica un numero entero
 *
 * \param puntero de la variable
 * \param mensaje inicial
 * \param mensaje error
 * \return 0 todo ok -1 error
 *
 */
int utn_verificarNumeroEntero(int *pEntero,char* texto,char* textoError);

/** \brief verifica un numero float
 *
 * \param puntero de la varible float
 * \param mensaje inicial
 * \param mensaje error
 * \return 0 todo ok -1 error
 *
 */
int utn_verificarNumeroFloat(float *pEntero,char* texto,char* textoError);

/** \brief verifica el caracter
 *
 * \param puntero de la varible
 * \param mensaje inicial
 * \param mensaje error
 * \return 0 todo ok ,-1 error
 *
 */
int utn_verificarNumeroChar(char *pChar,char* texto,char* textoError);

/** \brief carga numero aleatorio en el array
 *
 * \param array tipo int
 * \param limite
 * \param maximo
 * \param minimo
 * \return 0 todo ok, -1 error
 *
 */
int utn_cargaNumeroAleatoriosEnArrays(int* pArray,int len,int min, int max);

/** \brief calcula el promedio de los valores del array tipo int
 *
 * \param array tipo int
 * \param limite
 * \param varible donde guarda promedio
 * \param el valor de la posicion del array cuando esta vacio
 * \return 0 todo ok, -1 error
 *
 */
int utn_promedioArray(int*pArray,int limite,float *promedio,int valorOmision);

/** \brief ordena el array con un burbujeo mejorado
 *
 * \param array
 * \param limite
 * \param flag
 * \return 0 todo ok, -1 error
 *
 */
int utn_ordenarArray(int *pArray,int limite,int flagMaxMin);

/** \brief Toma un flotante por pantalla y verifica
 *
 * \param puntero de la variable float
 * \param cantidad de reintentos
 * \param mensaje inicial
 * \param mensaje de error
 * \param minimo
 * \param maximo
 * \return 0 todo bien , -1 error
 *
 */
int utn_getFloat(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max);

/** \brief Toma un array de caracteres de solo letras por pantalla y verifica
 *
 * \param array char
 * \param limite
 * \param reintentos
 * \param mensaje inicial
 * \param mensaje error
 * \return 0 todo bien , -1 error
 *
 */
int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

/** \brief ordenamiento insercion
 *
 * \param array
 * \param limite
 * \return 0 todo bien, -1 error
 *
 */
int ordenarInsertion(int* pArray,int limite);

/** \brief toma un telefono
 *
 * \param array de char
 * \param limite
 * \param reintentos
 * \param mensaje inicial
 * \param mensaje error
 * \return 0 todo ok, -1 error
 *
 */
int utn_getTelefono(char* pBuffer,int limite,int reintentos,char* msg,char* msgError);

/** \brief toma un cuit
 *
 * \param array de char
 * \param limite
 * \param reintentos
 * \param mensaje inicial
 * \param mensaje error
 * \return 0 todo ok, -1 error
 *
 */
int utn_getCuit(char* pbuffer,int limite, int reintentos,char* msg,char*msgError);

/** \brief toma un DNI
 *
 * \param array de char
 * \param limite
 * \param reintentos
 * \param mensaje inicial
 * \param mensaje error
 * \return 0 todo ok, -1 error
 *
 */
int utn_getDni(char* pBuffer,int limite, int reintentos,char* msg,char*msgError);

/** \brief Ordena array de Estructuras
 *
 * \param Array de Estructura
 * \param limite del Array
  * \param orden (1)Ascendente (0)Descendente
 * \return 0 Ok || (-1) Error
 *
 */
//int ordenarBurbujeoMejorado(Estructura* Array,int limite, int orden);


#endif // UTN_H_INCLUDED
