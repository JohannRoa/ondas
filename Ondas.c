#include <stdio.h>
#include <stdlib.h>
#include <math.h>
   
int main()
{
/*
//extraigo datos iniciales de la cuerda y los pongo en arrays
static const int MAX_FILE_ROWS = 129;
double A[MAX_FILE_ROWS],B[MAX_FILE_ROWS];

double lines[MAX_FILE_ROWS][2];
FILE *file = fopen("cond_ini_cuerda.dat", "r");

for (int i = 0; i < MAX_FILE_ROWS; i++)
{
    if (feof(file))
        break;

    fscanf(file, " %lf %lf", &(lines[i][0]), &(lines[i][1]));
	//printf(" %f %f\n", lines[i][0], lines[i][1]);
A[i]=(lines[i][0]);
B[i]=(lines[i][1]);
}

fclose(file);
//printf("%f\n", A[128]);
// ahora si soluciono la ecuacion de onda para la cuerda

	double dx=A[1]-A[0];
	double dt=0.000014 ;
	int N =0.64/dx+1.;
	int M=1./dt+1.;
	double c=250.;
	double r= c*dt/dx;
	double * uviejo=malloc(N*sizeof(double));
	double * unuevo=malloc(N*sizeof(double));
	double * upresente=malloc(N*sizeof(double));
	
	int i;
	uviejo=B;
	int j;
	int k;
	/*for(i=0;i<N;i++){
		printf(" %f",uviejo[i] );
		}
	printf(" \n");
	upresente[0]=uviejo[0];
	upresente[N-1]=uviejo[N-1];
	printf(" %f",upresente[0] );
	for(i=1;i<N-1;i++){
		
		upresente[i]=uviejo[i]+pow(r,2)*0.5*(uviejo[i+1]+uviejo[i-1]-2*uviejo[i]);
		printf(" %f",upresente[i] );
		}
	printf(" %f",upresente[N-1] );		
	printf(" \n");



	for(j=2;j<M;j++){
		unuevo[0]=uviejo[0];
		unuevo[N-1]=uviejo[N-1];
		printf(" %f",unuevo[0] );
		for(i=1;i<N-1;i++){
			unuevo[i] = (2.0*(1.0-pow(r,2)))*upresente[i] - uviejo[i] + (pow(r,2)*(upresente[i+1] +  upresente[i-1]));
			printf(" %f",unuevo[i] );
				}
		printf(" %f",unuevo[N-1] );
		printf(" \n");
		for (k=1;k<N-1;k++){	
			uviejo[k]=upresente[k];
			upresente[k]=unuevo[k];
			}
	printf(" \n");
	//el arreglo generado tiene entonces 71429 datos en t(filas) y 129 datos en x(columnas)

			
		
	

	}



	//parte 2: cuerda perturbada
	
	double pi=3.141592;
	for(i=0;i<N;i++){
		uviejo[i]=0;
		printf(" %f",uviejo[i] );
		}
	printf(" \n");
	upresente[0]=uviejo[0];

	for(i=1;i<N-1;i++){
		upresente[i]=uviejo[i]+pow(r,2)*0.5*(uviejo[i+1]+uviejo[i-1]-2*uviejo[i]);
			}
	upresente[N-1]=sin((2*pi*c/0.64)*dt);	
	for(i=0;i<N;i++){
		printf(" %f",upresente[i] );
		}
	printf(" \n");
	
	
	for(j=2;j<M;j++){
		unuevo[0]=uviejo[0];
		for(i=1;i<N-1;i++){
				unuevo[i] = (2.0*(1.0-pow(r,2)))*upresente[i] - uviejo[i] + (pow(r,2)*(upresente[i+1] +  upresente[i-1]));
				}
				
		unuevo[N-1]=sin((2*pi*c/0.64)*dt*j);
		
		for (k=0;k<N;k++){	
			printf(" %f",unuevo[k] );
			uviejo[k]=upresente[k];
			upresente[k]=unuevo[k];
			}
		printf(" \n");
	//tamanio igual que el anterior, sin embargo este punto comenzaria a partir de la fila 71429.
			
		
	

	}
*/
	// tambor



double** matriz=malloc(101*sizeof(double*));
	for(int i=0;i<101;i++){
		matriz[i]=malloc(101*sizeof(double));
				}

FILE *file = fopen("cond_ini_tambor.dat", "r");
for (int i = 0; i < 101; i++)
{
	for (int j = 0; j < 101; j++){
  		if (feof(file))
        		break;

    		fscanf(file, " %lf ", &matriz[i][j]);
		//printf(" %lf ", matriz[i][j]);
			}
	//printf(" \n");
}
fclose(file);

	double dx=0.5/101;
	double dy=0.5/101;
	double dt=1.38e-5;
	int N =101.;
	int M=0.01/dt+1.;
	double c=250.;
	double r= c*dt/dx;
	double ** uviejo=malloc(N*sizeof(double));
		for(int i=0;i<101;i++){
			uviejo[i]=malloc(101*sizeof(double));
			}
	double ** unuevo=malloc(N*sizeof(double));
		for(int i=0;i<101;i++){
			unuevo[i]=malloc(101*sizeof(double));
			}
	double ** upresente=malloc(N*sizeof(double));
		for(int i=0;i<101;i++){
			upresente[i]=malloc(101*sizeof(double));
			}
	
	int i;
	uviejo=matriz;
	int j;
	int k;
	int t;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf(" %f",uviejo[i][j] );
				}
		printf(" \n");
			}
		
	printf(" \n");
	for(i=0;i<N;i++){
		upresente[N-1,i]=uviejo[N-1,i];
		upresente[0,i]=uviejo[0,i];
		upresente[i,0]=uviejo[i,0];
		upresente[i,N-1]=uviejo[i,N-1];
		//printf(" %f",upresente[0,i] );
			}
	for(i=1;i<N-1;i++){
		for(j=1;j<N-1;j++){
			upresente[i][j]=uviejo[i][j]+pow(r,2)*0.5*(uviejo[i+1][j]+uviejo[i][j+1]+uviejo[i-1][j]+uviejo[i][j-1]-4*uviejo[i][j]);
			//printf(" %f",upresente[i][j] );
				}
		//printf(" %f",upresente[N-1] );
		}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf(" %f",upresente[i][j] );
				}
		printf(" \n");
			}

	
			
	printf(" \n");



	for(t=2;t<M;t++){
		for(i=0;i<N;i++){
			unuevo[N-1,i]=uviejo[N-1,i];
			unuevo[0,i]=uviejo[0,i];
			unuevo[i,0]=uviejo[i,0];
			unuevo[i,N-1]=uviejo[i,N-1];
				}
		
		//printf(" %f",unuevo[0] );
		for(i=1;i<N-1;i++){
			for(j=1;j<N-1;j++){
				unuevo[i][j] = (2.0*(1.0-pow(r,2)))*upresente[i][j] - uviejo[i][j] + (pow(r,2)*(upresente[i+1][j]+upresente[i][j+1]+upresente[i][j-1] +  upresente[i-1][j]));
				//printf(" %f",unuevo[i] );
					}
			//printf(" %f",unuevo[N-1] );
			//printf(" \n");
				}

		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				printf(" %f",unuevo[i][j] );
					}
			printf(" \n");
				}
		printf(" \n");
		for (k=1;k<N-1;k++){
			for(j=1;j<N-1;j++){	
				uviejo[k][j]=upresente[k][j];
				upresente[k][j]=unuevo[k][j];
					}
				}
			}
		
	//printf(" \n");

	

}

