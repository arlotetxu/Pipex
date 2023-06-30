//
// Created by Jose Manuel Florido Perena on 6/30/23.
//
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
# include <sys/wait.h>

#define SIZE 512

//int main()
//{
//	pid_t pid;
//	int p[2], readbytes;
//	char buffer[SIZE];
//
//	pipe( p );
//
//	if ( (pid=fork()) == 0 )
//	{ // hijo
//		printf("Hijo\n");
//		close( p[1] ); /* cerramos el lado de escritura del pipe */
//
//		while( (readbytes=read( p[0], buffer, SIZE )) > 0)
//			write( 1, buffer, readbytes );
//
//		close( p[0] );
//	}
//	else
//	{ // padre
//		printf("Padre\n");
//		close( p[0] ); /* cerramos el lado de lectura del pipe */
//
//		strcpy( buffer, "Esto llega a traves de la tuberia\n" );
//		write( p[1], buffer, strlen( buffer ) );
//
//		close( p[1] );
//	}
//	wait(NULL);
//	return ( 0 );
//}

int main(void)
{
	pid_t pid;
	int a[2], b[2], readbytes;
	char buffer[SIZE];

	pipe( a );
	pipe( b );

	if ( (pid=fork()) == 0 )
	{ // hijo
		close( a[1] ); /* cerramos el lado de escritura del pipe */
		close( b[0] ); /* cerramos el lado de lectura del pipe */

		while( (readbytes=read( a[0], buffer, SIZE ) ) > 0)
			write( 1, buffer, readbytes );
		close( a[0] );

		strcpy( buffer, "Soy tu hijo hablandote por la otra tuberia.\n" );
				write( b[1], buffer, strlen( buffer ) );
		close( b[1] );
	}
	else
	{ // padre
		close( a[0] ); /* cerramos el lado de lectura del pipe */
		close( b[1] ); /* cerramos el lado de escritura del pipe */

		strcpy( buffer, "Soy tu padre hablandote por una tuberia.\n" );
				write( a[1], buffer, strlen( buffer ) );
		close( a[1]);

		while( (readbytes=read( b[0], buffer, SIZE )) > 0)
			write( 1, buffer, readbytes );
		close( b[0]);
	}
	waitpid( pid, NULL, 0 );
	return ( 0 );
}