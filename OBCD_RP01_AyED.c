// Carlos Daniel Orozco Bravo 351285 441 L1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

//***************************************************************************************
typedef struct _talu{
                        long matri ;
                        char appat[ 30 ] ;
                        char apmat[ 30 ] ;
                        char nombre[ 30 ] ;
                        int status ;
                    }Talu ;

//***************************************************************************************
int MENU() ;
Talu GeneraRegistro( void );
long validarmatricula( int InfLim , int SupLim , char *msg , char *msgError );
int BUSCARDES( Talu vector[] );
int BUSCARORD( Talu vector[] );
void ORDVECCHABB( Talu vector[] );
void imprReg( Talu vector[] , int num );
void GenArchivo( Talu vector[] , int n );

//***************************************************************************************
int main()
{
    srand( time( 0 ) ) ;
    MENU();
    return 0;
}

//***************************************************************************************
int MENU()
{
    int opcion , i=0 , j=0 , ord , num ;
    char nombre[ 30 ] ;
    Talu nvoreg , vect[ 200 ] ;
    do{
            system( "cls" ) ;
            printf( "M   E   N   U\n" ) ;
            printf( "1- Agregar.\n" ) ;
            printf( "2- Eliminar.\n" ) ;
            printf( "3- Buscar.\n" ) ;
            printf( "4- Ordenar.\n" ) ;
            printf( "5- Imprimir.\n" ) ;
            printf( "6- Archivo texto.\n" ) ;
            printf( "7- Salir.\n" ) ;
            scanf( "%d" , &opcion ) ;
            switch( opcion )
                {
                    case 1 :
                                if( i<=(200-10) )
									{
										for( j=0 ; j<10 ; j++ )
											{
												nvoreg=GeneraRegistro( ) ;
												vect[ i ]=nvoreg ;
												i++;
											}

										ord=FALSE ;
									}
                                    else
                                        {
                                            printf("El registo ya esta lleno.");
                                            system("pause");
                                        }
                                break;
                    case 2:
                                printf("Que registro quieres borrar.\n") ;
                                scanf("%d", &num ) ;
                                if( vect[num].status==1 )
                                    {
                                        vect[num].status=0 ;
                                    }
                                    else
                                        {
                                            printf("El registro %d ya esta dado de baja o no existe.\n", num ) ;
                                            system("pause");
                                        }
                                break;
                    case 3:
                                if ( ord==FALSE )
                                    {
                                        num=BUSCARDES( vect ) ;
                                    }
                                    else{
                                            num=BUSCARORD(vect ) ;
                                        }
                                if( num>=0 )
									{
										imprReg( vect , num );
									}
									else
										{
											printf("La matricula no exixte...\n");
										}
								system("pause");
                                break;
                    case 4:
                                if(ord==FALSE)
                                    {
                                        ORDVECCHABB( vect );
                                        ord=TRUE;
                                    }
                                    else
                                        {
                                            printf("El vector ya esta ordenado.");
                                            system("pause");
                                        }

                                break;
                    case 5:
                                imprVect( vect ) ;    break;
                    case 6 :
                                if(ord==FALSE)
                                    {
                                        printf("Ordena el vector primero");
                                        system("pause");
                                    }
                                    else
                                        {
                                            GenArchivo( vect , 200 );
                                        }
                                break;
                }
    }while( opcion !=7 );
}

//**************************************************GENERAR REGISTRO
Talu GeneraRegistro( void )
{
	int status , sex , num ;
    Talu nvo ;
	char vecNomFem[ 30 ][ 30 ]={ "SOFIA" , "CAMILA" , "VALENTINA" , "ISABELLA" , "XIMENA" , "NATALIA" , "MIA" , "FERNANDA" , "NICOLE" , "MELANIE" , "REGINA" , "RENATA" , "ANTONELLA" , "LUNA" , "CONSTANZA" , "ZOE" , "MICHELLE" , "AITANA" , "STEPHANIE" , "MARIA" , "ANA" , "ADRIANA" , "FERNANDA" , "SHEILA" , "SAMANTHA" , "MARIANA" , "SAMARA" , "JOSEFA" , "ALEXA" , "GUADALUPE" } ;
	char vecNomMas[ 30 ][ 30 ]={ "LUIS" , "MIGUEL" , "JOSE" , "JESUS" , "ALEJANDRO" , "JUAN" , "RICARDO" , "DANIEL" , "FERNANDO" , "JORGE" , "ROBERTO" , "CARLOS" , "FRANCISCO" , "MANUEL" , "SANTIAGO" , "SEBASTIAN" , "JAVIER" , "NICOLAS" , "ELIUD" , "MATEO" , "MATIAS" , "GABRIEL" , "EMILIANO" , "RODRIGO" , "PABLO" , "EMMANUEL" , "EMILIO" , "CHRISTOPHER" , "JONATHAN" , "IKER" } ;
	char vecAp[ 30 ][ 30 ]={ "GONZALEZ" , "RODRIGUEZ" , "GOMEZ" , "HUERTAS" , "LOPEZ" , "DIAZ" , "MARTINEZ" , "PEREZ" , "GARCIA" , "SANCHEZ" , "ROMERO" , "SOSA" , "ALVAREZ" , "TORRES" , "RUIZ" , "RAMIREZ" , "FLORES" , "ACOSTA" , "BENITEZ" , "MEDINA" , "SUAREZ" , "HERRERA" , "AGUIRRE" , "PEREYRA" , "GUTIERREZ" , "JIMENEZ" , "MOLINA" , "SILVA" , "CASTRO" , "ROJAS" } ;
	num=rand()%30 ;
	nvo.matri=(rand()%1000000)+300000;
	sex=( rand()%2 )+1 ;
	num=rand()%30 ;
	fflush( stdin ) ;
	if( sex==1 )
		{
			strcpy( nvo.nombre , vecNomMas[ num ] ) ;
		}
		else
			{
				strcpy( nvo.nombre , vecNomFem[ num ] ) ;
			}
    num=rand()%30 ;
    fflush( stdin ) ;
	strcpy( nvo.appat , vecAp[ num ] ) ;
	num=rand()%30 ;
	fflush( stdin ) ;
	strcpy( nvo.apmat , vecAp[ num ] ) ;
	nvo.status=1 ;
	return nvo ;
}

//**************************************************VALIDAR MATRICULA
long validarmatricula( int InfLim , int SupLim , char *msg , char *msgError )
{
	char strnum[30];
	int num;
	do
	{
		puts( msg ) ;
		fflush( stdin ) ;
		gets( strnum ) ;
		num=atoi( strnum ) ;
		if( num<InfLim || num>SupLim )
		{
			puts( msgError ) ;
			system( "pause" ) ;
		}
	}while( num<InfLim || num>SupLim ) ;
	return num ;
}

//**************************************************BUSCAR DESORDENADO
int BUSCARDES( Talu vector[] )
{
	system("cls");
	printf("Buscar por matricula.\n\n");
	int i ;
	long dato ;
	dato=validarmatricula( 300000 , 1300000 , "Matricula ---> " , "Error escribe una matricula correcta" );
	for( i=0 ; i<200 ; i++ )
		{
			if( vector[i].matri==dato )
				{
					return i;
				}
		}
	return -1;
}

//**************************************************BUSCAR ORDENADO
int BUSCARORD( Talu vector[] )
{
	system("cls");
	printf("Buscar por matricula.\n\n");
	int i , inf=0 , sup=200-1 ;
	long dato , centro ;
	dato=validarmatricula( 300000 , 1300000 , "Matricula ---> " , "Error escribe una matricula correcta" );
	while( inf<=sup )
		{
      		centro=( ( sup-inf )/2 )+inf;
      		if( vector[centro].matri==dato )
				{
					return centro ;
				}
      			else if( dato<vector[centro].matri )
					{
						sup=centro-1;
					}
      				else
						{
							inf=centro+1;
						}
   		}
	printf("\n");
	return -1;
}

//**************************************************ORDENAR METODO BURBUJA
void ORDVECCHABB( Talu vector[] )
{
	system("cls");

	int i , j ;
	Talu aux ;

	for( i=0 ; i<200-1 ; i++ )
		{
			for( j=i+1 ; j<200 ; j++ )
				{
					if( vector[i].matri>vector[j].matri )
						{
						    fflush(stdin);
							aux=vector[i];
							vector[i]=vector[j];
							vector[j]=aux;
						}
				}
		}
	system("pause");
}

//**************************************************IMPRIMIR REGISTRO
void imprReg( Talu vector[] , int num )
{
	system("cls");
	printf("Registro Status Matricula Ap. Paterno Ap. Materno Nombre\n\n") ;
    printf("%d %d %10ld %30s %30s %30s\n", num , vector[num].status , vector[num].matri , vector[num].appat , vector[num].apmat , vector[num].nombre );
}

//**************************************************IMPRIMIR VECTOR
int imprVect( Talu vector[] )
{
	system("cls");
	int i , op ;
	printf("Registro Status Matricula Ap. Paterno Ap. Materno Nombre\n\n");
	for( i=0 ; i<200 ; i++ )
		{
		    printf("%d %d %10ld %30s %30s %30s\n", i , vector[i].status , vector[i].matri , vector[i].appat , vector[i].apmat , vector[i].nombre );
		    if( i!=0 )
                {
                    if( i%40==0 )
                        {
                            do{
                                    printf("Que quieres hacer? - (1) continuar. , (2) retroceder. , (3) salir.\n");
                                    scanf("%d",&op);
                                    if( op!=1 && op!=2 && op!=3 )
                                        {
                                            printf("Selecciona solo... (1) para continuar , (2) para retroceder , (3) para salir.\n");
                                        }
                                        else if( op==2 )
                                            {
                                                if( (i-40)>=0 )
                                                    {
                                                        i=i-80;
                                                    }
                                                    else
                                                        {
                                                            printf("Ya no se puede retroceder.\n") ;
                                                        }
                                            }
                                            else if( op==3 )
                                                {
                                                    return 0 ;
                                                }
                                }while( op!=1 && op!=2 && op!=3 );
                            system( "pause" );
                            system( "cls" );
                            printf( "Registro Status Matricula Ap. Paterno Ap. Materno Nombre\n\n" ) ;
                        }
                }

		}
	printf("\n");
	system("pause");
	return 0;
}

//**************************************************GENERAR ARCHIVO DE TEXTO
void GenArchivo( Talu vector[] , int n )
{
	FILE *fa ;
	int i ;
	fa=fopen( "alumnos.txt" , "r+" );
	if( !fa )
		{
			fa=fopen( "alumnos.txt" , "w+" );
		}
	fprintf( stdout , "Registro Status Matricula Ap. Paterno Ap. Materno Nombre\n\n" );
	for( i=0 ; i<n ; i++ )
		{
			fprintf( stdout , "%d %d %ld %s %s %s\n" , i , vector[i].status , vector[i].matri , vector[i].appat , vector[i].apmat , vector[i].nombre ) ;
			fprintf( fa , "%d %d %ld %s %s %s\n" , i , vector[i].status , vector[i].matri , vector[i].appat , vector[i].apmat , vector[i].nombre ) ;
		}
	fclose(fa);
	system("pause");
}
