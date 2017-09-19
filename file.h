#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

int abrir_archivo ( FILE **fp, char *modo, char *ruta, int msg);

// Apareamiento:
int fusionar_archivos (FILE *fa, FILE *fb, FILE *fp);

#endif // FILE_H_INCLUDED
