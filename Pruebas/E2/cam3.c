#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <cv.h>
#include <highgui.h>

int main(int argc, char *argv[])
{
	CvCapture *dispositivo = NULL;
	IplImage *fotograma = NULL;
	int tecla = 0, ndispositivo = CV_CAP_ANY;

/* Analizamos los parámetros de entrada */
	if (argc > 2) {
		printf("Uso: %s [#dispositivo]\n", (char*)basename(argv[0]));
		return 1;
	} else if (argc == 2) {
		ndispositivo = atoi(argv[1]);
	}

/* Inicializamos el dispositivo de captura y comprobamos el estado */
	printf("Inicializando dispositivo de captura #%d\n", ndispositivo);
	dispositivo = cvCaptureFromCAM(ndispositivo);
	if (dispositivo == NULL) {
		fprintf(stderr, "Error inicializando dispositivo de captura #%d\n",
			ndispositivo);
		return 1;
	}

/* Creamos una ventana para mostrar el contenido de la webcam */
	printf("Creando ventana\n");
	cvNamedWindow("Fotograma", CV_WINDOW_AUTOSIZE);

/* Entramos en un bucle infinito del que saldremos al pulsar ESC */
	printf("Entrando en el bucle principal (ESC para salir)\n"); 
	while(tecla != 27) {
		printf(".");
		fflush(stdout);

/* Leemos un fotograma y comprobamos que la lectura haya sido correcta */
		fotograma = cvQueryFrame(dispositivo);
		if(fotograma == NULL) {
			break;
		}

/* Mostramos el fotograma y esperamos la pulsación de una tecla 100 ms */
		cvShowImage("Fotograma", fotograma);
		tecla = cvWaitKey(100);
	}

/* Antes de salir liberamos los recursos creados y/o usados */
	printf("\nLiberando recursos\n"); 
	cvDestroyWindow("Fotograma");
	cvReleaseCapture(&dispositivo);
	return 0;
}
