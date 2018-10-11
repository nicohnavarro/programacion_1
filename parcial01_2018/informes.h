#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/** \brief menu Informes
 *
 * \param cliente->Array de Cliente
 * \param venta->Array de Ventas
 * \param lengthCliente->Limite del Array de Cliente
 * \param lengthVentas->Limite del Array de Ventas
 *
 */
void informes_menu(Cliente* cliente,Ventas* ventas,int lengthCliente,int lengthVentas);

/** \brief Cliente con menos ventas a cobrar
 *
 * \param cliente->Array de Cliente
 * \param venta->Array de Ventas
 * \param lengthCliente->Limite del Array de Cliente
 * \param lengthVentas->Limite del Array de Ventas
 * \return -1 Error // 0 Todo ok
 *
 */
int informes_ClienteMenosVentasAcobrar(Cliente* cliente,Ventas* ventas,int lenghtCliente,int lenghtVentas);

/** \brief Impirime clientes y cantidad de Ventas de cada Cliente
 *
 * \param venta->Array de Ventas
 * \param lengthVentas->Limite del Array de Ventas
 * \param idCliente->Limite del Array de Cliente
 * \param
 * \return -1 Error // 0 Todo ok
 *
 */
int informes_contarVentasDeCliente(Ventas* ventas,int lengthVentas,int idCliente,int estado);
int informes_ClienteMenosVentasCobradas(Cliente* cliente,Ventas* ventas,int lengthCliente,int lengthVentas);
int informes_contarVentasTotal(Ventas* ventas,int lengthVentas,int idCliente);
int informes_menosVentas(Cliente* cliente,Ventas* ventas,int lengthCliente,int lengthVentas);
int informes_cantidadDeAfichesPorZona(Ventas* ventas,int lengthVentas,int zona);
int informes_zonaConMasAfiches(Ventas* ventas,int lengthVentas,int cantidadZonas);
int informes_ClienteMenosAfiches(Cliente* cliente,Ventas* ventas,int lengthClientes,int lengthVentas);
int informes_CantidadAfichesporCliente(Ventas* ventas,int lengthVentas,int idCliente);
#endif // INFORMES_H_INCLUDED
