#include "MenuFunciones.h"
#include "../Estructuras/Nodos/NodosDerivados/Administrador/NodoAdmin.h"
#include "../Estructuras/Nodos/NodosDerivados/Inventario/NodoInventario.h"
#include "../Estructuras/Nodos/NodosDerivados/Marca/NodoMarca.h"
#include "../Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "../Estructuras/Nodos/NodosDerivados/Producto/NodoProducto.h"
#include "../Estructuras/Nodos/NodosDerivados/Ciudad/NodoCiudad.h"
#include "../Estructuras/Nodos/NodosDerivados/Clientes/NodoCliente.h"

#pragma region Pasillos
void MenuFunciones::InsertarPasilloABB(ArbolBinario* Arbol)
{
    int CodPasillo;
    string NombreProd;

    cout << "Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    cout << "Ingrese el nombre de pasillo: ";
    cin >> NombreProd;

    if (Arbol->BuscarNodo(Arbol->Raiz, CodPasillo))
    {
        cout<<"El pasillo ya existe"<<endl;
        return;
    }
    
    NodoPasillo* NuevoNodo = new NodoPasillo(NombreProd, CodPasillo);
    Arbol->InsertarNodo(NuevoNodo);

    cout << "Insertado exitosamente!";
}

void MenuFunciones::BuscarPasilloABB(ArbolBinario* Arbol)
{
    int CodPasillo;
    
    cout << "Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    NodoBase* NodoEncontrado = Arbol->BuscarNodo(Arbol->Raiz, CodPasillo);

    if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(NodoEncontrado))
    {
        cout<<"Nodo encontrado!"<<endl;
        Pasillo->Mostrar();
        Pasillo->Vistas++;
        return;
    }
    cout<<"Nodo no encontrado!";
}

void MenuFunciones::ModificarPasilloABB(ArbolBinario* Arbol)
{
    int CodPasillo;
    
    cout << "Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    NodoBase* NodoEncontrado = Arbol->BuscarNodo(Arbol->Raiz, CodPasillo);

    if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(NodoEncontrado))
    {
        cout<<"Nodo encontrado!";
        Pasillo->Mostrar();

        string Nombre;
        cout<<"Ingrese el nuevo nombre del pasillo: ";
        cin>>Nombre;

        Pasillo->Nombre = Nombre;
        Pasillo->Mostrar();
        cout<<"Actualizado correctamente"<<endl;
        return;
    }
    cout<<"Nodo no encontrado!";
}

#pragma endregion 

#pragma region Productos
void MenuFunciones::InsertarProductoAVL(ArbolAVL* Arbol)
{
    cout << "Insertando en la Opción 1." << endl;
    // Código correspondiente a insertar en la opción 1
    int CodPasillo;
    int CodProd;
    string NombreProd;

    cout << "Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    cout << "Ingrese el código de producto: ";
    cin >> CodProd;

    cout << "Ingrese el nombre de producto: ";
    cin >> NombreProd;
    
    NodoProducto* Prod = new NodoProducto(CodPasillo, CodProd, NombreProd);
    if (Arbol->BuscarNodo(Arbol->Raiz, Prod->GetLlave()))
    {
        cout<<"Producto ya existe!"<<endl;
        return;
    }
    
    Arbol->InsertarNodo(Arbol->Raiz, false, Prod);
    cout << "Insertado exitosamente!"<<endl;
}

void MenuFunciones::BuscarProductoAVL(ArbolAVL* Arbol)
{
    string CodPasillo;
    string CodProd;
    
    cout << "Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    cout << "Ingrese el código de producto: ";
    cin >> CodProd;

    NodoBase* Nodo = Arbol->BuscarNodo(Arbol->Raiz, stoi(CodPasillo + CodProd));

    if (NodoProducto* NodoProd = dynamic_cast<NodoProducto*>(Nodo))
    {
        NodoProd->Mostrar();
        cout << "Elemento encontrado!";
        return;
    }
    cout << "Elemento no encontrado!";
}

void MenuFunciones::ModificarProductoAVL(ArbolAVL* Arbol)
{
    string CodPasillo;
    string CodProd;
    
    cout << "Ingrese el código de pasillo: ";
    cin >> CodPasillo;

    cout << "Ingrese el código de producto: ";
    cin >> CodProd;

    NodoBase* Nodo = Arbol->BuscarNodo(Arbol->Raiz, stoi(CodPasillo + CodProd));

    if (NodoProducto* NodoProd = dynamic_cast<NodoProducto*>(Nodo))
    {
        NodoProd->Mostrar();
        cout << "Elemento encontrado!";
        
        string Nombre;
        cout << "Ingrese el nuevo nombre: ";
        cin >> Nombre;
        NodoProd->Nombre = Nombre;
        return;
    }
    cout<<"No se encontro el producto especificado\n";
    
}

#pragma endregion

#pragma region Marca
void MenuFunciones::InsertarMarcaRN(ArbolRN* Arbol)
{
    int codPasillo, codProducto, codMarca, cantidadGondola;
    double precio;
    string nombre;

    cout << "Ingrese el código de pasillo: ";
    cin >> codPasillo;

    cout << "Ingrese el código de producto: ";
    cin >> codProducto;

    cout << "Ingrese el código de marca: ";
    cin >> codMarca;

    cout << "Ingrese el nombre de la marca: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese la cantidad en la góndola: ";
    cin >> cantidadGondola;

    cout << "Ingrese el precio: ";
    cin >> precio;

    cout<<codMarca<<endl;
    if (Arbol->BusquedaM(codMarca))
    {
        cout<<"La marca ya existe"<<endl;
        return;
    }
    
    NodoMarca* NuevaMarca = new NodoMarca(codPasillo, codProducto, codMarca, nombre, cantidadGondola, precio);
    Arbol->insertar(NuevaMarca);
    cout<<"Marca insertada exitosamente"<<endl;
}

void MenuFunciones::EncontrarMarcaRN(ArbolRN* Arbol)
{
    int CodMarca;
    cout << "Ingrese el código de marca: ";
    cin >> CodMarca;

    NodoBase* NodoEncontrado = Arbol->BusquedaM(CodMarca);
    if (NodoMarca* MarcaEncontrada = dynamic_cast<NodoMarca*>(NodoEncontrado))
    {
        MarcaEncontrada->Mostrar();
        cout<<"Encontrado!"<<endl;
        return;
    }
    cout<<"No encontrado!"<<endl;
}

void MenuFunciones::ModificarMarcaRN(ArbolRN* Arbol)
{
}
#pragma endregion

#pragma region Inventario
void MenuFunciones::InsertarInventarioAA(ArbolAA* Arbol)
{
    int CodPasillo, CodProd, CodMarca, CodInventario, Cantidad;
    string Nombre;
    bool CanastaBasica;

    cout<<"Ingrese el codigo de pasillo: ";
    cin>>CodPasillo;

    cout<<"Ingrese el codigo de producto: ";
    cin>>CodProd;

    cout<<"Ingrese el codigo de marca: ";
    cin>>CodMarca;

    cout<<"Ingrese el codigo de inventario: ";
    cin>>CodInventario;

    cout << "Ingrese el nombre: ";
    cin >> Nombre;

    cout<<"Ingrese la cantidad: ";
    cin>>Cantidad;

    cout << "Pertenece a la Canasta basica? true/false";
    cin >> CanastaBasica;

    string Linea = to_string(CodPasillo)+";"+to_string(CodProd)+";"+to_string(CodMarca)+";"+to_string(CodInventario)+";"+Nombre+";"+to_string(Cantidad)+";"+to_string(CanastaBasica);
    NodoInventario* NuevoInventario = new NodoInventario(Linea);
    Arbol->insert(NuevoInventario);
    NuevoInventario->Mostrar();
    cout<<"Inventario ingresado exitosamente";
}

void MenuFunciones::EncontrarInventarioAA(ArbolAA* Arbol)
{
    int CodInv;
    cout<<"Ingrese el codigo del inventario a buscar: "<<endl;
    cin>>CodInv;

    NodoBase* NodoEncontrado = Arbol->Encontrar(CodInv);

    if (NodoInventario* InvEncontrado = dynamic_cast<NodoInventario*>(NodoEncontrado))
    {
        InvEncontrado->Mostrar();
        cout<<"Inventario encontrado!"<<endl;
        return;
    }
    cout<<"Inventario no encontrado!"<<endl;
}

void MenuFunciones::ModificarInventarioAA(ArbolAA* Arbol)
{
    int CodInv;
    cout<<"Ingrese el codigo del inventario a buscar: "<<endl;
    cin>>CodInv;

    NodoBase* NodoEncontrado = Arbol->Encontrar(CodInv);

    if (NodoInventario* InvEncontrado = dynamic_cast<NodoInventario*>(NodoEncontrado))
    {
        InvEncontrado->Mostrar();
        cout<<"Inventario encontrado!"<<endl;

        int Cantidad;
        string Nombre;

        cout<<"Ingrese el nuevo nombre: ";
        cin>>Nombre;
        
        cout<<"Ingrese la nueva cantidad: ";
        cin>>Cantidad;

        InvEncontrado->Nombre = Nombre;
        InvEncontrado->Cantidad = Cantidad;
        InvEncontrado->Mostrar();
        return;
    }
    cout<<"Inventario no encontrado!"<<endl;
}
#pragma endregion 

#pragma region Ciudades
void MenuFunciones::InsertarCiudadABB(ArbolBinario* Arbol)
{
    int CodCiudad;
    string NombreCiudad;

    cout << "Ingrese el código de ciudad: ";
    cin >> CodCiudad;

    cout << "Ingrese el nombre de ciudad: ";
    cin >> NombreCiudad;

    if (Arbol->BuscarNodo(Arbol->Raiz, CodCiudad))
    {
        cout << "La ciudad ya existe" << endl;
        return;
    }

    NodoCiudad* NuevaCiudad = new NodoCiudad(CodCiudad,NombreCiudad);
    Arbol->InsertarNodo(NuevaCiudad);

    cout << "Ciudad insertada exitosamente!" << endl;
}

void MenuFunciones::EncontrarCiudadABB(ArbolBinario* Arbol)
{
    int CodCiudad;

    cout << "Ingrese el código de ciudad: ";
    cin >> CodCiudad;

    NodoBase* NodoEncontrado = Arbol->BuscarNodo(Arbol->Raiz, CodCiudad);

    if (NodoCiudad* Ciudad = dynamic_cast<NodoCiudad*>(NodoEncontrado))
    {
        cout << "Ciudad encontrada!" << endl;
        Ciudad->Mostrar();
        return;
    }
    cout << "Ciudad no encontrada!" << endl;
}

void MenuFunciones::ModificarCiudadABB(ArbolBinario* Arbol)
{
    int CodCiudad;

    cout << "Ingrese el código de ciudad: ";
    cin >> CodCiudad;

    NodoBase* NodoEncontrado = Arbol->BuscarNodo(Arbol->Raiz, CodCiudad);

    if (NodoCiudad* Ciudad = dynamic_cast<NodoCiudad*>(NodoEncontrado))
    {
        cout << "Ciudad encontrada!" << endl;
        Ciudad->Mostrar();

        string Nombre;
        cout << "Ingrese el nuevo nombre de la ciudad: ";
        cin >> Nombre;

        Ciudad->Nombre = Nombre;
        Ciudad->Mostrar();
        cout << "Ciudad actualizada correctamente" << endl;
        return;
    }
    cout << "Ciudad no encontrada!" << endl;
}
#pragma endregion 

#pragma region Administrador

void MenuFunciones::InsertarAdministradorB(ArbolB* Arbol, ListaCircular* ListaCiudades)
{
    int CodAdmin, CodCiudad, Telefono;
    string Nombre, Correo;

    cout<<"Ingrese el codigo de administrador: ";
    cin>>CodAdmin;

    cout<<"Ingrese el nombre: ";
    cin>>Nombre;

    cout<<"Ingrese el codigo de ciudad: ";
    cin>>CodCiudad;

    cout<<"Ingrese el telefono: ";
    cin>>Telefono;

    cout<<"Ingrese el correo: ";
    cin>>Correo;
    
    string LineaAdmin;
    cout << "Ingrese la siguiente información separada por ';'" << endl;
    cout << "Codigo de administrador, Nombre, Codigo de ciudad, Telefono, Correo" << endl;
    cin >> LineaAdmin;

    NodoAdmin* Admin = new NodoAdmin(CodAdmin, Nombre, CodCiudad, Telefono, Correo);
    Arbol->Insertar(Admin);
    //Arbol->Mostrar();
}

void MenuFunciones::EncontrarAdministradorB(ArbolB* Arbol, ListaCircular* ListaCiudades)
{
    int CodAdmin;
    cout << "Ingrese el código del administrador a buscar: " << endl;
    cin >> CodAdmin;

    NodoBase* Nodo = nullptr;
    NodoArbolB* NodoArbol = Arbol->Buscar(CodAdmin, Nodo);
    if (NodoAdmin* Admin = dynamic_cast<NodoAdmin*>(Nodo))
    {
        cout << "Se encontró el administrador: " << endl;
        Admin->Mostrar();
    }
    else
    {
        cout << "No se encontró el administrador solicitado" << endl;
    }
}

void MenuFunciones::ModificarAdministradorB(ArbolB* Arbol, ListaCircular* ListaCiudades)
{
    int CodAdmin;
    cout << "Ingrese el código del administrador a buscar" << endl;
    cin >> CodAdmin;

    NodoBase* Nodo = nullptr;
    Arbol->Buscar(CodAdmin, Nodo);
    if (NodoAdmin* Admin = dynamic_cast<NodoAdmin*>(Nodo)) {
        cout << "Se encontró el administrador: " << endl;
        Admin->Mostrar();
    }
    else {
        cout << "No se encontró el administrador solicitado" << endl;
    }
}

#pragma endregion

#pragma region Cliente

void MenuFunciones::InsertarClienteB(ArbolB* Arbol)
{
    int Cedula, CodCiudad, Telefono;
    string Nombre, Correo;

    cout<<"Ingrese la cedula: ";
    cin>>Cedula;

    cout<<"Ingrese el nombre: ";
    cin>>Nombre;

    cout<<"Ingrese el codigo de ciudad: ";
    cin>>CodCiudad;

    cout<<"Ingrese el telefono: ";
    cin>>Telefono;

    cout<<"Ingrese el correo: ";
    cin>>Correo;
    
    NodoCliente* Cliente = new NodoCliente(Cedula, Nombre, CodCiudad, Telefono, Correo);
    Arbol->Insertar(Cliente);
    Arbol->Recorrer();
}

void MenuFunciones::EncontrarClienteB(ArbolB* Arbol, ListaCircular* ListaCiudades)
{
    int Cedula;
    cout << "Ingrese la cedula del cliente a buscar" << endl;
    cin >> Cedula;

    NodoBase* Nodo = nullptr;
    Arbol->Buscar(Cedula, Nodo);
    if (NodoCliente* Cliente = dynamic_cast<NodoCliente*>(Nodo)) {
        cout << "Se encontró el cliente: " << endl;
        Cliente->Mostrar();
    }
    else {
        cout << "No se encontró el cliente solicitado" << endl;
    }
}

void MenuFunciones::ModificarClienteB(ArbolB* Arbol, ListaCircular* ListaCiudades)
{
    int Cedula;
    cout << "Ingrese la cedula del cliente a modificar" << endl;
    cin >> Cedula;

    NodoBase* Nodo = nullptr;
    Arbol->Buscar(Cedula, Nodo);
    if (!Nodo) {
        cout << "No se encontró el cliente con la cedula " << Cedula << endl;
        return;
    }

    NodoCliente* Cliente = dynamic_cast<NodoCliente*>(Nodo);
    Cliente->Mostrar();
    string Nombre;
    int CodCiudad;
    int Telefono;
    string Correo;

    cout << "Ingrese el nuevo nombre del cliente: ";
    cin >> Nombre;
    cout << "Ingrese el nuevo codigo de ciudad del cliente: ";
    cin >> CodCiudad;
    // Validar que la ciudad exista
    // Si la ciudad no existe, mostrar un mensaje de error y volver al menú
    if (!ListaCiudades->EncontrarPorPredicado([CodCiudad](NodoBase* Nodo)
        {
            if (NodoCiudad* Ciudad = dynamic_cast<NodoCiudad*>(Nodo))
            {
                return Ciudad->CodCiudad == CodCiudad;
            }
            return false;
        }))
    {
        cout << "La ciudad ingresada no existe." << endl;
        return;
    }
    cout << "Ingrese el nuevo telefono del cliente: ";
    cin >> Telefono;
    cout << "Ingrese el nuevo correo del cliente: ";
    cin >> Correo;
    Cliente->Nombre = Nombre;
    Cliente->CodCiudad = CodCiudad;
    Cliente->Telefono = Telefono;
    Cliente->Correo = Correo;
    Cliente->Mostrar();
    cout << "Datos actualizados exitosamente" << endl;
}

#pragma endregion