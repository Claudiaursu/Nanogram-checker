    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {   int numar,k;
        printf("Cate puzzle-uri vreti sa verificati? ");
        scanf("%d",&numar);


        for(k=0; k<numar; k++)
        {
        int lin[100][100]={0};
        int col[100][100]={0};

        int nl,nc,i=0,j=0;
        printf("\nDati numarul de linii si de coloane: ");
        scanf("%d",&nl);
        scanf("%d",&nc);
         int v[nl][nc];

        while(i<nl)
        {   int nr,aux;
            scanf("%d",&nr);
            lin[i][0]=nr;
            for(j=1; j<=nr; j++)
            {
                scanf("%d",&aux);
                lin[i][j]=aux;
            }

            i++;
        }
        i=0;
         while(i<nc)
        {   int nr2,aux2;
            scanf("%d",&nr2);
            col[i][0]=nr2;
            for(j=1; j<=nr2; j++)
            {
                scanf("%d",&aux2);
                col[i][j]=aux2;
            }

            i++;
        }

        for(i=0; i<nl; i++)   ///afisare matrice pt linii
           {
            for(j=0; j<=lin[i][0]; j++)
            printf("%d ",lin[i][j]);
             printf("\n");
           }

        printf("\n");

           for(i=0; i<nc; i++)  /// afisare matrice pt coloane
          {
            for(j=0; j<=col[i][0]; j++)
            printf("%d ",col[i][j]);
            printf("\n");
          }
        printf("\nDati matricea acum:\n");

        for(i=0; i<nl; i++)
         {
            for(j=0; j<nc; j++)
            scanf("%d",&v[i][j]);
         }

       printf("\n");

        for(i=0; i<nl; i++)
           {
            for(j=0; j<nc; j++)
            printf("%d ",v[i][j]);
             printf("\n");
           }
        ///verificarea liniilor
        int corect=1;
        for(i=0; i<nl; i++)
        {
            int nr_gr=0;
            int lung=0;
            for(j=0; j<nc; j++)
            {
               if(j==0 && v[i][j]==1)
               {
                 nr_gr++;
               }
               else if(j>0 && v[i][j-1]==0 && v[i][j]==1)
               {
                 nr_gr++;
               }

               if(v[i][j])
               {
                   lung++;

                   if(j==nc-1 && lung != lin[i][nr_gr])
                   {
                     corect=0;
                   }
                   if(j==nc-1 && nr_gr!= lin[i][0])
                   {
                     corect=0;
                   }
               }
               else
               {
                   if(lung != lin[i][nr_gr] && j > 0 && v[i][j-1] == 1)
                   {
                      corect=0;
                      break;
                   }
                   else
                   {
                     lung=0;
                   }
               }

            }

             if(nr_gr!= lin[i][0]) {
               corect=0;
             }
        }

         ///verificarea coloanelor
        int corect2=1;
        for(j=0; j<nc; j++)
        {   int nr_gr=0; //nr de grupari
            int lung=0;  //lunginea fiecarei grupare
            for(i=0; i<nl; i++)
            {
             if(i==0 && v[i][j]==1)
             nr_gr++;
             else if(i>0 && v[i-1][j]==0 && v[i][j]==1) nr_gr++;
             if(v[i][j])
             {
                 lung++;

                 if(i==nl-1 && lung != col[j][nr_gr]) corect2=0;
                 if(i==nl-1 && nr_gr!= col[j][0]) corect2=0;

             }
             else
             {
               if(lung!= col[j][nr_gr] && i > 0 && v[i-1][j] == 1)
               {
                 printf("%d %d %d %d\n", i, j, lung, col[j][nr_gr]);
                 corect2=0;
                 break;

               }
               else lung=0;
               }

            }
             if(nr_gr!= col[j][0]) corect2=0;
        }

      if(corect && corect2) printf("\nCorect");
      else printf("\nIncorect");
        }
        return 0;
    }
