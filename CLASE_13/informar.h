typedef struct{
    char cuit[50];
    int cantidadContra;
    float precio;
}Cliente;

int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);
int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);

int informar_ListarPantallas(Pantalla* array,int limitePantalla,int orden);
int informarPantallasPorPrecio(Pantalla* panta,int lengthPantalla,float precio,int orden);
float informarCalcularPromedio(Pantalla* panta,int lengthPantalla);
int informarRepeticionCuit(Contratacion*contra,int lengthContra,char* cuit);
int informarClientes(/*Cliente* client,int lengthCliente, */Contratacion* contra,int lengthContra, Pantalla* panta,int lengthPanta);
