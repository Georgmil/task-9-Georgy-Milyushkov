#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define maxsize 100



void task1(){

	int lenc, lenr;

	int A[maxsize][maxsize];
	int B[maxsize];



	printf("How many columns do you want?\n");
		scanf_s("%d", &lenc);

	printf("How many elemts in a row, do you want?\n");
		scanf_s("%d", &lenr);


	for (int i = 0; i < lenc; i++) {
		printf("Please enter %d st row of %d elemtnts\n", i + 1, lenr);
		for (int j = 0; j < lenr; j++) {
			scanf_s("%d", &A[i][j]);
		}
	}
	
	printf("Our original array is:\n");
	for (int a = 0; a < lenc; a++) {
		for (int b= 0; b < lenr; b++) {
			printf(" %d ", A[a][b]);
			if (b == lenr-1)
				printf("\n");
		}
	}
	
	//int t = 0, g = 0;
	for(int q = 0; q < lenc; q++) {
		for (int w = 0; w < lenr; w++) {
			B[(q * lenr) + w] = A[q][w];
		}
	}

	printf("\n");
	printf("Converted to one dimenssional array is:\n");
	for (int i = 0; i < (lenc * lenr); i++) {
		printf("%d ", B[i]);
	}
	
	for (int i = 0; i < lenc * lenr; i++) {
		A[i / lenr][i % lenr] = B[i];
	}

	printf("\n");
	printf("Converted back is:\n");
	for (int i = 0; i < lenc; i++) {
		for (int j = 0; j < lenr; j++) {
			printf("%d  ", A[i][j]);
			if (j == lenr - 1)
				printf("\n");
		}
	}

}



void task2(){

	int A1[maxsize][maxsize];
	int B[maxsize][maxsize];

	int col, row;
	printf("how many rows do you want?\n");
		scanf_s("%d", &col);
	
	printf("how many elemts in a row, do you want?\n");
		scanf_s("%d", &row);

		

		int i = 0, j = 0;
		int colin = 0, rowin = 0, d = 1;
		int row2, col2;

		row2 = row;
		col2 = col;





		 



		for (int i = 0; i < col; i++) {
			bool x = true;
			for (int j = 0; j < row; j++) {
				if (i == 0 || j == 0)
					A1[i][j] = j + 1 + i;
				else if (x) {
					A1[i][j] = A1[i][j-1] - 1;
					if (A1[i][j] == 1) {
						x = false;
					}
				}
				else
					A1[i][j] = A1[i][j-1] + 1;
			}
		}




		while (colin < col && rowin < row) {

			for (i = rowin; i < row; ++i) {
				B[colin][i]=d;
				d++;
			}
			colin++;
			for (j = colin; j < col; ++j) {
				B[j][row - 1]=d;
				d++;
			}
			row--;

			if (colin < col) {
				
				for (i = row - 1; i >= rowin; --i) {
					B[col - 1][i] = d;
					d++;
				}
				col--;
			}
			if (rowin < row) {

				for (i = col - 1; i >= colin; --i) {
					B[i][rowin] = d;
					d++;
				} rowin++;
			}

		}



	printf("Our array is:\n");
	for (int a = 0; a < col2; a++) {
		for (int b = 0; b < row2; b++) {
			printf(" %d ", A1[a][b]);
			if (b == row2 - 1)
				printf("\n");
		}
	}


	printf("\n");
	printf("Our matrix is:\n");
	for (int a = 0; a < col2; a++) {
		for (int b= 0; b < row2; b++) {
			printf(" %d ", B[a][b]);
			if (b == row2-1)
				printf("\n");
		}
	}

}




void task5() {

	float list1[10][10], list2[10], perem;
	int n;

	printf("How many unknows do you want:\n");
	scanf_s("%d", &n);
	printf("We will write the equation in form ax1 +bx2 + ...+nxn=const\n");

	for (int i = 1; i <=n; i++) {
		printf("\n Values for equetion %d\n", i);

		for (int j = 1; j <=n; j++) {
			printf("Enter the coefficient of x%d:  ", j);
			scanf_s("%f", &list1[i][j]);
		}
		printf("Enter the const(result):      ");
		scanf_s("%f", &list1[i][n+1]);
	}


	int max,c;
	for (int i = 1; i <= n; i++) {
		max = 0;
		if (list1[i][i] == 0) {

			for (int j = 1; j <= n; j++) {
				if (list1[j][i] > max)
					max = j;
			}
			for (int t = 1; t <= n + 1; t++) {
				c = list1[i][t];
				list1[i][t] = list1[max][t];
				list1[max][t] = c;
			}
		}

	}







	for (int i = 1; i <=n-1; i++) {

		if (list1[i][i]==0.0) {
			printf("cannot slove");
			break;
		}
		for (int j = i + 1; j <= n; j++) {

			perem = list1[j][i] / list1[i][i];
			for (int l = 1; l <= n+1; l++) {
				list1[j][l] = list1[j][l] - perem * list1[i][l];
			}
		}
	}
	list2[n] = list1[n][n + 1] /(list1[n][n]);

	for (int i = n - 1; i >= 1; i--) {
		list2[i] = list1[i][n + 1];
		for (int j = i + 1; j <= n; j++) {

			list2[i] = list2[i] - (list1[i][j] * list2[j]);
		}
		list2[i] = list2[i] / list1[i][i];
	}


	for (int i = 1; i <= n; i++) {
		printf(" x%d is %0.2f", i, list2[i]);
	}
}

void task6() {

	float** ori, ** obr, ** resu, ** dop, pereme,sum,q;
	int n;

	printf("enter the size n of how big our matrix will be. We will take n^2 of it");
	scanf_s("%d", &n);

	ori = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++) {
		ori[i] = (float*)malloc(n * sizeof(float));
	}

	obr = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++) {
		obr[i] = (float*)malloc(n * sizeof(float));
	}

	resu = (float**)malloc(n*sizeof(float*));
	for (int i = 0; i < n; i++) {
		resu[i] = (float*)malloc(n*sizeof(float));
	}

	// Eto sovsem v principi ne nuzhno, no ja ne uveren chto vi hotite dla proverki, iznachalnaja matrica s tolko edinitsami i nulami tozhe proverka. 
	dop = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++) {
		dop[i] = (float*)malloc(n * sizeof(float));
	}





	for (int i = 0; i < n; i++) {
		printf("Please enter the %d st row of n elements:\n", i + 1);
		for (int j = 0; j < n; j++) {
			scanf_s("%f", &q);
			ori[i][j] = q;
			dop[i][j] = q;
		}
	}
	printf("Iznachalnaja matrica:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.f  ", ori[i][j]);
			if (j == n - 1)
				printf("\n");
		}
	}

	






	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (i == j)
				obr[i][j] = 1;
			else
				obr[i][j] = 0;
		}
	}

	int max1, c1,c2;
	for (int i = 0; i < n; i++) {
		max1 = 0;
		if (ori[i][i] == 0) {

			for (int j = 0; j < n; j++) {
				if (ori[j][i] > max1)
					max1 = j;
			}
			for (int t = 0; t < n; t++) {
				c1 = ori[i][t];
				c2 = obr[i][t]; //
				ori[i][t] = ori[max1][t];
				//dop[i][t] = dop[max1][t]; //
				obr[i][t] = obr[max1][t];
				ori[max1][t] = c1;
				//dop[max1][t] = c1; // 
				obr[max1][t] = c2;
			}
		}

	}
	
	for (int a = 0; a < n; a++) {


		pereme = ori[a][a];
		for (int b = 0; b < n; b++) {
			ori[a][b] = ori[a][b] / pereme;
			obr[a][b] = obr[a][b] / pereme;
		}

		for (int i = 0; i < n; i++) {
			pereme = ori[i][a];

			for (int j = 0; j < n; j++) {
				if (i == a)
					break;
				ori[i][j] = ori[i][j] - (ori[a][j] * pereme);
				obr[i][j] = obr[i][j] - (obr[a][j] * pereme);
			}
		}

	}


	/*printf("matrica posle perestanovki(ulutsjaem ee):\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.f  ", dop[i][j]);
			if (j == n - 1)
				printf("\n");
		}
	}*/
	printf("\n");
	printf("Obratnaja matrica:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%f  ", obr[i][j]);
			if (j == n - 1)
				printf("\n");
		}
	}

	sum = 0.0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int t = 0; t < n; t++) {
				sum = sum + (dop[i][t] * obr[t][j]);
			}
			resu[i][j] = sum;
			sum = 0;
		}
	}
	printf("\n");
	printf("Proverka(smotrim chto ostalos ot originalnoj matrici):\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.2f  ", ori[i][j]);
			if (j == n - 1)
				printf("\n");
		}
	}

	printf("\n");
	printf("Proverka2(Umnozhaem iznachaluju matricu na obratnuju):\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.2f  ", resu[i][j]);
			if (j == n - 1)
				printf("\n");
		}
	}




	
} 



int main() {
	int n = 1;
	while (n) {
		printf("\n\n");
		printf("Which task do you want to slove, task 1, 2, 5 or 6. (Type 0 to exit):\n");
		scanf_s("%d", &n);
		printf("\n");
		switch (n) {
		case 1: task1(); break;
		case 2: task2(); break;
		case 5: task5(); break;
		case 6: task6(); break;

		}
	}


	return 0;
}



