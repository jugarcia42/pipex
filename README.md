# Pipex

## Descripción

Pipex es un proyecto cuyo objetivo es comprender el funcionamiento de los pipes y la redirección de archivos en sistemas Unix. El programa reproduce el comportamiento de una tubería de comandos en la terminal utilizando llamadas al sistema.

A través de este proyecto se trabaja con procesos, pipes, ejecución de comandos y gestión de archivos.

## Conceptos trabajados

- Procesos (`fork`)
- Pipes (`pipe`)
- Redirecciones de entrada y salida
- Ejecución de programas (`execve`)
- Gestión de descriptores de archivo
- Variables de entorno
- Manejo de errores
- Programación de sistemas Unix

## Compilación

Para compilar el proyecto:

```bash
make
```

Esto generará el ejecutable:

```bash
pipex
```

### Reglas disponibles

```bash
make
make clean
make fclean
make re
```

## Uso

```bash
./pipex infile "cmd1" "cmd2" outfile
```

### Ejemplo

```bash
./pipex infile "grep hello" "wc -l" outfile
```

Este comando reproduce el comportamiento de:

```bash
< infile grep hello | wc -l > outfile
```

## Funcionamiento

El programa:

1. Lee los datos desde el archivo de entrada.
2. Ejecuta el primer comando.
3. Envía la salida del primer comando a través de un pipe.
4. Ejecuta el segundo comando utilizando la salida del primero como entrada.
5. Guarda el resultado final en el archivo de salida.

## Gestión de errores

El programa maneja errores relacionados con:

- Archivos inexistentes o inaccesibles.
- Comandos inválidos.
- Errores de permisos.
- Fallos en llamadas al sistema.
- Problemas de memoria.

## Objetivo

El objetivo principal es entender cómo los procesos se comunican entre sí mediante pipes y cómo funciona internamente la ejecución de comandos encadenados en una shell Unix.

## Autor

Proyecto realizado como parte del programa de formación de 42.
