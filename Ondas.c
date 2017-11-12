#include <stdio.h>
#include <stdlib.h>
#include <math.h>
   
int main()
{

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
	uviejo=B;
	
	int i;
	
	int j;
	int k;

	FILE *f = fopen("cuerda.dat", "w");
	
	for(i=0;i<N;i++){
		fprintf(f," %f",uviejo[i] );
		}
	fprintf(f," \n");
	upresente[0]=uviejo[0];
	upresente[N-1]=uviejo[N-1];
	fprintf(f," %f",upresente[0] );
	for(i=1;i<N-1;i++){
		
		upresente[i]=uviejo[i]+pow(r,2)*0.5*(uviejo[i+1]+uviejo[i-1]-2*uviejo[i]);
		fprintf(f," %f",upresente[i] );
		}
	fprintf(f," %f",upresente[N-1] );		
	fprintf(f," \n");



	for(j=2;j<M;j++){
		unuevo[0]=uviejo[0];
		unuevo[N-1]=uviejo[N-1];
		fprintf(f," %f",unuevo[0] );
		for(i=1;i<N-1;i++){
			unuevo[i] = (2.0*(1.0-pow(r,2)))*upresente[i] - uviejo[i] + (pow(r,2)*(upresente[i+1] +  upresente[i-1]));
			fprintf(f," %f",unuevo[i] );
				}
		fprintf(f," %f",unuevo[N-1] );
		fprintf(f," \n");
		for (k=1;k<N-1;k++){	
			uviejo[k]=upresente[k];
			upresente[k]=unuevo[k];
			}
	
	
	//el arreglo generado tiene entonces 71429 datos en t(filas) y 129 datos en x(columnas)

			
		
	

	}
fclose(f);

	

	//parte 2: cuerda perturbada
	FILE *fp = fopen("cuerdaperturbada.dat", "w");
	double pi=3.141592;
	for(i=0;i<N;i++){
		uviejo[i]=0;
		fprintf(fp," %f",uviejo[i] );
		}
	fprintf(fp," \n");
	upresente[0]=uviejo[0];

	for(i=1;i<N-1;i++){
		upresente[i]=uviejo[i]+pow(r,2)*0.5*(uviejo[i+1]+uviejo[i-1]-2*uviejo[i]);
			}
	upresente[N-1]=sin((2*pi*c/0.64)*dt);	
	for(i=0;i<N;i++){
		fprintf(fp," %f",upresente[i] );
		}
	fprintf(fp," \n");
	
	
	for(j=2;j<M;j++){
		unuevo[0]=uviejo[0];
		for(i=1;i<N-1;i++){
				unuevo[i] = (2.0*(1.0-pow(r,2)))*upresente[i] - uviejo[i] + (pow(r,2)*(upresente[i+1] +  upresente[i-1]));
				}
				
		unuevo[N-1]=sin((2*pi*c/0.64)*dt*j);
		
		for (k=0;k<N;k++){	
			fprintf(fp," %f",unuevo[k] );
			uviejo[k]=upresente[k];
			upresente[k]=unuevo[k];
			}
		fprintf(fp," \n");
	//tamanio igual que el anterior, sin embargo este punto comenzaria a partir de la fila 71429.
			
		
	

			}
	fclose(fp);
	// tambor



double** matriz=malloc(101*sizeof(double*));
	for(int i=0;i<101;i++){
		matriz[i]=malloc(101*sizeof(double));
				}

FILE *file1 = fopen("cond_ini_tambor.dat", "r");
for (int i = 0; i < 101; i++)
{
	for (int j = 0; j < 101; j++){
  		if (feof(file1))
        		break;

    		fscanf(file1, " %lf ", &matriz[i][j]);
		//printf(" %lf ", matriz[i][j]);
			}
	//printf(" \n");
}
fclose(file1);

FILE *tb = fopen("tambor.dat", "w");
	double dx2=0.5/101;
	double dy2=0.5/101;
	double dt2=1.38e-5;
	int N2 =101.;
	int M2=0.01/dt2+1.;
	double c2=250.;
	double r2= c2*dt2/dx2;
	double ** uviejo2=malloc(N2*sizeof(double));
		for(int i=0;i<101;i++){
			uviejo2[i]=malloc(101*sizeof(double));
			}
	double ** unuevo2=malloc(N2*sizeof(double));
		for(int i=0;i<101;i++){
			unuevo2[i]=malloc(101*sizeof(double));
			}
	double ** upresente2=malloc(N2*sizeof(double));
		for(int i=0;i<101;i++){
			upresente2[i]=malloc(101*sizeof(double));
			}
	
	
	uviejo2=matriz;
	
	
	int t;
	for(i=0;i<N2;i++){
		for(j=0;j<N2;j++){
			fprintf(tb," %f",uviejo2[i][j] );
				}
		fprintf(tb," \n");
			}
		
	fprintf(tb," \n");
	for(i=0;i<N2;i++){
		upresente2[N2-1,i]=uviejo2[N2-1,i];
		upresente2[0,i]=uviejo2[0,i];
		upresente2[i,0]=uviejo2[i,0];
		upresente2[i,N2-1]=uviejo2[i,N2-1];
		//printf(" %f",upresente[0,i] );
			}
	for(i=1;i<N2-1;i++){
		for(j=1;j<N2-1;j++){
			upresente2[i][j]=uviejo2[i][j]+pow(r2,2)*0.5*(uviejo2[i+1][j]+uviejo2[i][j+1]+uviejo2[i-1][j]+uviejo2[i][j-1]-4*uviejo2[i][j]);
			//printf(" %f",upresente[i][j] );
				}
		//printf(" %f",upresente[N-1] );
		}
	for(i=0;i<N2;i++){
		for(j=0;j<N2;j++){
			fprintf(tb," %f",upresente2[i][j] );
				}
		fprintf(tb," \n");
			}

	
			
	fprintf(tb," \n");



	for(t=2;t<M2;t++){
		for(i=0;i<N2;i++){
			unuevo2[N2-1,i]=uviejo2[N2-1,i];
			unuevo2[0,i]=uviejo2[0,i];
			unuevo2[i,0]=uviejo2[i,0];
			unuevo2[i,N2-1]=uviejo2[i,N2-1];
				}
		
		//printf(" %f",unuevo[0] );
		for(i=1;i<N2-1;i++){
			for(j=1;j<N2-1;j++){
				unuevo2[i][j] = (2.0*(1.0-pow(r2,2)))*upresente2[i][j] - uviejo2[i][j] + (pow(r2,2)*(upresente2[i+1][j]+upresente2[i][j+1]+upresente2[i][j-1] +  upresente2[i-1][j]));
				//printf(" %f",unuevo[i] );
					}
			//printf(" %f",unuevo[N-1] );
			//printf(" \n");
				}

		for(i=0;i<N2;i++){
			for(j=0;j<N2;j++){
				fprintf(tb," %f",unuevo2[i][j] );
					}
			fprintf(tb," \n");
				}
		fprintf(tb," \n");
		for (k=1;k<N2-1;k++){
			for(j=1;j<N2-1;j++){	
				uviejo2[k][j]=upresente2[k][j];
				upresente2[k][j]=unuevo2[k][j];
					}
				}
			}
		
	//printf(" \n");

	fclose(tb);

}

