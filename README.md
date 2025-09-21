# Práctica 2: Cadenas y Lenguajes

## Descripción

Este proyecto implementa clases para el manejo de cadenas y lenguajes formales como parte de la asignatura **Computabilidad y Algoritmia** del Grado en Ingeniería Informática de la Universidad de La Laguna.

## Autor

- **Nombre**: Hector Luis Mariño Fernandez
- **Correo**: alu0100595604@ull.edu.es
- **Fecha**: 21 de septiembre de 2025

## Clases Implementadas

### 1. Alphabet
Representa un alfabeto finito (conjunto de símbolos) para operaciones con cadenas y lenguajes formales.

**Características principales:**
- Almacenamiento de símbolos en `std::set<char>`
- Verificación de pertenencia de símbolos
- Operadores de entrada y salida

### 2. String
Representa una cadena (secuencia finita de símbolos) sobre un alfabeto específico.

**Operaciones soportadas:**
- Cálculo de longitud
- Generación de cadena inversa
- Obtención de prefijos y sufijos
- Validación respecto al alfabeto

### 3. Language
Representa un lenguaje formal como conjunto de cadenas.

**Características principales:**
- Almacenamiento ordenado de cadenas
- Ordenación por longitud y lexicográfica
- Operaciones de conjunto básicas

## Compilación

```bash
# Compilar el proyecto
make

# Compilar con formato automático
make build

# Aplicar formato Google C++ Style
make format
```

## Ejecución

```bash
./cadenas_lenguajes input.txt output.txt opcode
```

### Códigos de Operación

- `1`: Mostrar alfabeto de cada cadena
- `2`: Mostrar longitud de cada cadena
- `3`: Mostrar cadena inversa
- `4`: Mostrar prefijos de cada cadena
- `5`: Mostrar sufijos de cada cadena

### Formato de Archivo de Entrada

Cada línea debe contener:
```
<cadena> <alfabeto>
```

Ejemplos:
```
abbab ab
6793836 123456789
hola ahlo
```

## Documentación

### Generar Documentación

```bash
# Generar documentación HTML con Doxygen
make docs

# Ver documentación en el navegador
make view-docs

# Limpiar documentación
make clean-docs
```

### Acceder a la Documentación

La documentación se genera en formato HTML y se puede acceder a través de:
- **Archivo principal**: `docs/html/index.html`
- **Navegador web**: Abrir el archivo index.html en cualquier navegador

### Contenido de la Documentación

La documentación incluye:

1. **Descripción de clases**: Documentación completa de cada clase con sus responsabilidades
2. **Métodos y funciones**: Descripción detallada de parámetros, valores de retorno y comportamiento
3. **Diagramas de clases**: Representación gráfica de las relaciones entre clases
4. **Gráficos de dependencias**: Visualización de las dependencias entre archivos
5. **Índices**: Búsqueda rápida de clases, métodos y archivos

### Características de la Documentación

- **Idioma**: Español
- **Formato**: HTML con navegación interactiva
- **Gráficos**: Diagramas UML generados con Graphviz
- **Búsqueda**: Motor de búsqueda integrado
- **Enlaces cruzados**: Navegación entre documentación relacionada

## Herramientas de Desarrollo

### Formateo de Código
El proyecto sigue el **Google C++ Style Guide**:
- Configuración automática con `clang-format`
- Formateo integrado en el proceso de compilación
- Verificación de formato con `make format-check`

### Documentación Automática
- **Doxygen**: Generación automática de documentación
- **Graphviz**: Generación de diagramas y gráficos
- **Comentarios estándar**: Documentación inline siguiendo estándares Doxygen

## Comandos Útiles

```bash
# Desarrollo
make build          # Formatear y compilar
make run            # Ejecutar (requiere argumentos)
make format         # Aplicar formato de código

# Documentación  
make docs           # Generar documentación
make view-docs      # Ver documentación en navegador
make clean-docs     # Limpiar documentación

# Limpieza
make clean          # Limpiar ejecutable
make clean-all      # Limpiar todo (ejecutable + documentación)
```

## Estructura del Proyecto

```
P2- Cadenas y lenguajes/
├── src/                    # Código fuente
│   ├── Alphabet.h/.cc     # Clase Alphabet
│   ├── String.h/.cc       # Clase String  
│   ├── Language.h/.cc     # Clase Language
│   └── Main.cc            # Programa principal
├── docs/                   # Documentación generada
│   └── html/              # Documentación HTML
├── examples/              # Archivos de ejemplo
├── Doxyfile               # Configuración Doxygen
├── .clang-format          # Configuración formato
├── Makefile               # Sistema de compilación
└── README.md              # Este archivo
```

## Referencias

- [Teoría de Lenguajes Formales](https://en.wikipedia.org/wiki/Formal_language)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [Documentación Doxygen](https://www.doxygen.nl/manual/)

## Licencia

Este proyecto es material académico para la Universidad de La Laguna.