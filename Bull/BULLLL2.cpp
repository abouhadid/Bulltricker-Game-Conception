#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

void DonnerDeplacementPossible(int piece,int i, int j,int v,int h);
int checkroi();
int pieceDetecte(int tabpos[5]);
void ClickPositionDetection(SDL_Event click);
void effacerselection();
int joueur=0;
int I=0,J=0,X=0,Y=0,I1=0,J1=0,I2=0,J2=0;
int X1=0,Y1=0,X2=0,Y2=0;
int select=0;
int selected=0;
int oldSelect[5]= {0};
int R0i=3, R0j=0, R1i=3, R1j=6;
int gg = 0;
//0=blanc,noir=1



int possibleDeplacementRectH[7][8]=
{
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}
};

int possibleDeplacementRectV[7][8]=
{
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}
};

int possibleDeplacementCarre[7][7]=
{
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};

int Carres[7][7]=
{
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {1,0,0,0,0,0,2},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};

int RectHoriz[7][8]=
{
    {0,1,0,0,0,0,2,0},
    {0,1,0,0,0,0,2,0},
    {0,1,0,0,0,0,2,0},
    {0,1,0,0,0,0,2,0},
    {0,1,0,0,0,0,2,0},
    {0,1,0,0,0,0,2,0},
    {0,1,0,0,0,0,2,0}
};

int RectVert[7][8]=
{
    {3,3,3,3,3,3,3,3},
    {1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2},
    {4,4,4,4,4,4,4,4}
};

int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *Window= SDL_CreateWindow("BULLTRICKER", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 735, 570, SDL_WINDOW_OPENGL);

    int running=1;

    SDL_Renderer *renderer= SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Event event;

    while (running)
    {
        int boardOn=1;
        while(SDL_PollEvent(&event))
        {
            if (event.type==SDL_QUIT)
            {
                running=0;
            }
        }
        SDL_Rect BoardSquareMatrix[7][7];
        SDL_Rect BoardHorizontalRectMatrix[7][8];
        SDL_Rect BoardVerticalRectMatrix[8][7];
        SDL_Rect SquareKingBlack;
        SDL_Rect SquareKingWhite;

        SDL_Rect BoardSquareDepMatrix[7][7];
        SDL_Rect BoardHorizontalRectDepMatrix[7][8];
        SDL_Rect BoardVerticalRectDepMatrix[8][7];


        //Drawing the board
        SDL_SetRenderDrawColor(renderer, 255, 153, 0, 255);
        SDL_RenderClear(renderer);
        //Initialisation des Carrées
        for (int i=0; i<7; i++)
        {
            for (int j=0; j<7; j++)
            {
                int x=175+(i*80);
                int y=10+(j*80);
                SDL_SetRenderDrawColor(renderer,214, 151, 62,255);
                BoardSquareMatrix[i][j].x = x;
                BoardSquareMatrix[i][j].y = y;
                BoardSquareMatrix[i][j].w = 70;
                BoardSquareMatrix[i][j].h = 70;






                if (possibleDeplacementCarre[i][j]==1)
                {


                    int x=175+(i*80);
                    int y=10+(j*80);
                    SDL_SetRenderDrawColor(renderer,176, 242, 182,255);
                    BoardSquareDepMatrix[i][j].x = x;
                    BoardSquareDepMatrix[i][j].y = y;
                    BoardSquareDepMatrix[i][j].w = 70;
                    BoardSquareDepMatrix[i][j].h = 70;
                }





                SDL_RenderFillRect(renderer, &BoardSquareMatrix[i][j]);
                switch (Carres[i][j])
                {
                case 1:
                {
                    SDL_SetRenderDrawColor(renderer,0, 0, 0,255);
                    SquareKingBlack.x = x+10;
                    SquareKingBlack.y = y+10;
                    SquareKingBlack.w = 50;
                    SquareKingBlack.h = 50;
                    SDL_RenderFillRect(renderer, &SquareKingBlack);
                }
                break;
                case 2:
                {
                    SDL_SetRenderDrawColor(renderer,255, 255, 255,255);
                    SquareKingWhite.x = x+10;
                    SquareKingWhite.y = y+10;
                    SquareKingWhite.w = 50;
                    SquareKingWhite.h = 50;
                    SDL_RenderFillRect(renderer, &SquareKingWhite);
                }
                break;
                }


            }

        }
        //Initialisation des Rectangles Horizontaux
        {
            for (int i=0; i<7; i++)
            {
                for (int j=0; j<8; j++)
                {
                    int x=175+(i*80);
                    int y=(j*80);
                    switch (RectHoriz[i][j])
                    {
                    case 0:
                    {
                        SDL_SetRenderDrawColor(renderer, 173, 123, 52,255);
                        BoardHorizontalRectMatrix[i][j].x = x;
                        BoardHorizontalRectMatrix[i][j].y = y;
                        BoardHorizontalRectMatrix[i][j].w = 70;
                        BoardHorizontalRectMatrix[i][j].h = 10;
                        SDL_RenderFillRect(renderer, &BoardHorizontalRectMatrix[i][j]);
                    }
                    break;
                    case 1:
                    {
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0,255);
                        BoardHorizontalRectMatrix[i][j].x = x;
                        BoardHorizontalRectMatrix[i][j].y = y;
                        BoardHorizontalRectMatrix[i][j].w = 70;
                        BoardHorizontalRectMatrix[i][j].h = 10;
                        SDL_RenderFillRect(renderer, &BoardHorizontalRectMatrix[i][j]);
                    }
                    break;
                    case 2:
                    {
                        SDL_SetRenderDrawColor(renderer, 255, 255, 255,255);
                        BoardHorizontalRectMatrix[i][j].x = x;
                        BoardHorizontalRectMatrix[i][j].y = y;
                        BoardHorizontalRectMatrix[i][j].w = 70;
                        BoardHorizontalRectMatrix[i][j].h = 10;
                        SDL_RenderFillRect(renderer, &BoardHorizontalRectMatrix[i][j]);
                    }
                    break;
                    case 3:
                    {
                        SDL_SetRenderDrawColor(renderer, 97, 97, 97,255);
                        BoardHorizontalRectMatrix[i][j].x = x;
                        BoardHorizontalRectMatrix[i][j].y = y;
                        BoardHorizontalRectMatrix[i][j].w = 70;
                        BoardHorizontalRectMatrix[i][j].h = 10;
                        SDL_RenderFillRect(renderer, &BoardHorizontalRectMatrix[i][j]);
                    }
                    break;
                    case 4:
                    {
                        SDL_SetRenderDrawColor(renderer, 194, 194, 194,255);
                        BoardHorizontalRectMatrix[i][j].x = x;
                        BoardHorizontalRectMatrix[i][j].y = y;
                        BoardHorizontalRectMatrix[i][j].w = 70;
                        BoardHorizontalRectMatrix[i][j].h = 10;
                        SDL_RenderFillRect(renderer, &BoardHorizontalRectMatrix[i][j]);
                    }
                    break;
                    case 5:
                    {
                        SDL_SetRenderDrawColor(renderer, 11, 252, 3,255);
                        BoardHorizontalRectMatrix[i][j].x = x;
                        BoardHorizontalRectMatrix[i][j].y = y;
                        BoardHorizontalRectMatrix[i][j].w = 70;
                        BoardHorizontalRectMatrix[i][j].h = 10;
                        SDL_RenderFillRect(renderer, &BoardHorizontalRectMatrix[i][j]);
                    }
                    break;
                    }

                    switch (possibleDeplacementRectH[i][j])
                    {

                    case 1 : // prise: 2, déplacement: 1
                        SDL_SetRenderDrawColor(renderer,176, 242, 182,255);
                        BoardHorizontalRectDepMatrix[i][j].x = x;
                        BoardHorizontalRectDepMatrix[i][j].y = y;
                        BoardHorizontalRectDepMatrix[i][j].w = 70;
                        BoardHorizontalRectDepMatrix[i][j].h = 10;
                        SDL_RenderFillRect(renderer, &BoardHorizontalRectDepMatrix[i][j]);
                        break ;
                    case 2:
                        SDL_SetRenderDrawColor(renderer,220, 20, 60,255);
                        BoardHorizontalRectDepMatrix[i][j].x = x;
                        BoardHorizontalRectDepMatrix[i][j].y = y;
                        BoardHorizontalRectDepMatrix[i][j].w = 70;
                        BoardHorizontalRectDepMatrix[i][j].h = 10;
                        SDL_RenderFillRect(renderer, &BoardHorizontalRectDepMatrix[i][j]);
                        break;
                    }
                }
            }

        }
        //Initialisation des Rectangles Verticaux
        {
            for (int i=0; i<7; i++)
            {
                for (int j=0; j<8; j++)
                {
                    int x=165+(j*80);
                    int y=10+(i*80);
                    switch (RectVert[i][j])
                    {
                    case 0:
                    {
                        SDL_SetRenderDrawColor(renderer, 173, 123, 52,255);
                        BoardVerticalRectMatrix[i][j].x = x;
                        BoardVerticalRectMatrix[i][j].y = y;
                        BoardVerticalRectMatrix[i][j].w = 10;
                        BoardVerticalRectMatrix[i][j].h = 70;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectMatrix[i][j]);
                    }
                    break;
                    case 1:
                    {
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0,255);
                        BoardVerticalRectMatrix[i][j].x = x;
                        BoardVerticalRectMatrix[i][j].y = y;
                        BoardVerticalRectMatrix[i][j].w = 10;
                        BoardVerticalRectMatrix[i][j].h = 70;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectMatrix[i][j]);
                    }
                    break;
                    case 2:
                    {
                        SDL_SetRenderDrawColor(renderer, 255, 255, 255,255);
                        BoardVerticalRectMatrix[i][j].x = x;
                        BoardVerticalRectMatrix[i][j].y = y;
                        BoardVerticalRectMatrix[i][j].w = 10;
                        BoardVerticalRectMatrix[i][j].h = 70;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectMatrix[i][j]);
                    }
                    break;
                    case 3:
                    {
                        SDL_SetRenderDrawColor(renderer, 97, 97, 97,255);
                        BoardVerticalRectMatrix[i][j].x = x;
                        BoardVerticalRectMatrix[i][j].y = y;
                        BoardVerticalRectMatrix[i][j].w = 10;
                        BoardVerticalRectMatrix[i][j].h = 70;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectMatrix[i][j]);
                    }
                    break;
                    case 4:
                    {
                        SDL_SetRenderDrawColor(renderer, 194, 194, 194,255);
                        BoardVerticalRectMatrix[i][j].x = x;
                        BoardVerticalRectMatrix[i][j].y = y;
                        BoardVerticalRectMatrix[i][j].w = 10;
                        BoardVerticalRectMatrix[i][j].h = 70;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectMatrix[i][j]);
                    }
                    break;
                    case 5:
                    {
                        SDL_SetRenderDrawColor(renderer, 11, 252, 3,255);
                        BoardVerticalRectMatrix[i][j].x = x;
                        BoardVerticalRectMatrix[i][j].y = y;
                        BoardVerticalRectMatrix[i][j].w = 10;
                        BoardVerticalRectMatrix[i][j].h = 70;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectMatrix[i][j]);
                    }
                    break;
                    }

                    switch (possibleDeplacementRectV[i][j])
                    {
                    case 1 :

                        SDL_SetRenderDrawColor(renderer,176, 242, 182,255);
                        BoardVerticalRectDepMatrix[i][j].x = x;
                        BoardVerticalRectDepMatrix[i][j].y = y;
                        BoardVerticalRectDepMatrix[i][j].w = 10;
                        BoardVerticalRectDepMatrix[i][j].h = 70;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectDepMatrix[i][j]);
                        break ;
                    case 2 :
                        SDL_SetRenderDrawColor(renderer,220, 20, 60,255);
                        BoardVerticalRectDepMatrix[i][j].x = x;
                        BoardVerticalRectDepMatrix[i][j].y = y;
                        BoardVerticalRectDepMatrix[i][j].w = 10;
                        BoardVerticalRectDepMatrix[i][j].h = 70;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectDepMatrix[i][j]);
                        break;
                    }

                }
            }

        }




        SDL_RenderPresent(renderer);







        SDL_WaitEvent(&event);

        if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
        {
            ClickPositionDetection(event);
            if (checkroi()==1)
            {


                printf("Joueur %d gagne la partie", gg);
                running=0;
            }
        }

    }



    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(Window);

    SDL_Quit();

    return EXIT_SUCCESS;
}


void ClickPositionDetection(SDL_Event click)
{
    int piece, k=0,l=0;
    int detected=0;
    int i=0,j=0,v=0,h=0,c=0;
    int i1=0,j1=0;
    int result[5]= {0};
    result[5]= {0}; // le retour de cette fonction est un tableau de taille 4 (i,j,v,h,c)
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {


            if (click.button.x<165)
            {
                i,j=-1;
                break; //un clique dans la zone neutre à gauche
            }
            else
            {
                //verticale
                if(165+(j*80)<click.button.x&&click.button.x<165+(j*80)+10 && 80*i+10<click.button.y && click.button.y<80*(i)+80 )
                {
                    result[2]=1;
                    result[0]=i;
                    result[1]=j;
                    detected=1;
                    break;
                }
                else if(175+(i*80)<click.button.x && click.button.x<175+(i*80)+70 && (j*80)<click.button.y && (j*80)+10>click.button.y  )
                {

                    result[3]=1;
                    result[0]=i;
                    result[1]=j;
                    detected=1;
                    break;
                }
                else if (175+(80*i)<click.button.x && click.button.x<175+(80*i)+70 && 10+(80*j)<click.button.y && click.button.y<10+(80*j)+70)
                {

                    result[4]=1;
                    result[0]=i;
                    result[1]=j;
                    detected=1;

                    break;
                }
            }

        }
    }

    k=result[0];
    l=result[1];
    piece=pieceDetecte(result);



    if ((possibleDeplacementRectV[k][l]==1 && result[2]==1) || (possibleDeplacementRectH[k][l]==1 && result[3]==1) || (possibleDeplacementCarre[k][l]==1 && result[4]==1) )
    {
        if (result[4]==1) //déplacement du roi noir
        {

            Carres[k][l]=Carres[oldSelect[0]][oldSelect[1]];
            Carres[oldSelect[0]][oldSelect[1]]=0;

            if(joueur==0)
            {
                R0i=k;
                R0j=l;
            }
            else
            {
                R1i=k;
                R1j=l;
            }



            effacerselection(); //effacer matrices selection

            select=0; //select=0 fin du tour

            if (joueur==0) //0:blanc, 1:noir
            {
                joueur=1;
            }
            else
            {
                joueur=0;
            }

        }
        else if (result[2]==1)
        {
            if (oldSelect[2]==1)  //déplacement du pion noir vertical vers vertical
            {
                RectVert[k][l]=RectVert[oldSelect[0]][oldSelect[1]];
                RectVert[oldSelect[0]][oldSelect[1]]=0;
                effacerselection(); //effacer matrices selection

                select=0; //select=0 fin du tour

                if (joueur==0) //0blanc1noir
                {
                    joueur=1;
                }
                else
                {
                    joueur=0;
                }
            }
            else if (oldSelect[3]==1) //déplacement du pion noir horizontal vers vertical
            {
                RectVert[k][l]=RectHoriz[oldSelect[0]][oldSelect[1]];
                RectHoriz[oldSelect[0]][oldSelect[1]]=0;
                effacerselection();

                select=0;

                if (joueur==0)
                {
                    joueur=1;
                }
                else
                {
                    joueur=0;
                }
            }
        }
        else if (result[3]==1)
        {

            if (oldSelect[2]==1) //déplacement pion noir vertical vers horizontal
            {

                RectHoriz[k][l]=RectVert[oldSelect[0]][oldSelect[1]];
                RectVert[oldSelect[0]][oldSelect[1]]=0;

                effacerselection();

                select=0;

                if (joueur==0)
                {
                    joueur=1;
                }
                else
                {
                    joueur=0;
                }

            }
            else if (oldSelect[3]==1) // déplacement pion noir horizontal vers horizontal
            {

                RectHoriz[k][l]=RectHoriz[oldSelect[0]][oldSelect[1]];
                RectHoriz[oldSelect[0]][oldSelect[1]]=0;

                effacerselection();

                select=0;

                if (joueur==0)
                {
                    joueur=1;
                }
                else
                {
                    joueur=0;
                }


            }

        }


    }
    else if ( (possibleDeplacementRectV[k][l]==2 && result[2]==1) || (possibleDeplacementRectH[k][l] ==2 && result[3]==1))
    {



        if (result[2]==1)
        {
            if (oldSelect[2]==1)
            {
                if (l==Y1 && k==X1)
                {
                    RectVert[I1][J1]=RectVert[oldSelect[0]][oldSelect[1]];
                    RectVert[oldSelect[0]][oldSelect[1]]=0;
                    RectVert[k][l]=0;

                }

                else if (l==Y2 && k==X2)
                {
                    RectVert[I2][J2]=RectVert[oldSelect[0]][oldSelect[1]];
                    RectVert[oldSelect[0]][oldSelect[1]]=0;
                    RectVert[k][l]=0;

                }
                else
                {
                    RectVert[k][l]=RectVert[oldSelect[0]][oldSelect[1]];
                    RectVert[oldSelect[0]][oldSelect[1]]=0;
                }


                effacerselection();

                select=0;

                if (joueur==0)
                {
                    joueur=1;
                }
                else
                {
                    joueur=0;
                }
            }

        }
        else if (result[3]==1)
        {


            if (oldSelect[3]==1)
            {


                if (l==Y1 && k==X1)
                {
                    RectHoriz[I1][J1]=RectHoriz[oldSelect[0]][oldSelect[1]];

                    RectHoriz[oldSelect[0]][oldSelect[1]]=0;
                    RectHoriz[X1][Y1]=0;
                    RectHoriz[k][l]=0;
                }
                else if (l==Y2 && k==X2)
                {
                    RectHoriz[I2][J2]=RectHoriz[oldSelect[0]][oldSelect[1]];

                    RectHoriz[oldSelect[0]][oldSelect[1]]=0;
                    RectHoriz[X2][Y2]=0;
                    RectHoriz[k][l]=0;
                }
                else
                {
                    RectHoriz[k][l]=RectHoriz[oldSelect[0]][oldSelect[1]];
                    RectHoriz[oldSelect[0]][oldSelect[1]]=0;
                }
                effacerselection();

                select=0;

                if (joueur==0)
                {
                    joueur=1;
                }
                else
                {
                    joueur=0;
                }


            }

        }



    }
    else
    {



        DonnerDeplacementPossible(piece,result[0],result[1],result[2],result[3]);
        oldSelect[0]=result[0];
        oldSelect[1]=result[1];
        oldSelect[2]=result[2];
        oldSelect[3]=result[3];
        oldSelect[4]=result[4];

    }






}

void effacerselection() // réinitialisation des 3 tableaux de déplacements possibles
{

    for (int m=0; m<7; m++)
    {
        for (int p=0; p<8; p++)
        {
            possibleDeplacementRectH[m][p]=0;
            possibleDeplacementRectV[m][p]=0;

        }
    }
    for (int m=0; m<7; m++)
    {
        for (int p=0; p<7; p++)
        {

            possibleDeplacementCarre[m][p]=0;
        }
    }
}

int pieceDetecte(int tabpos[5]) //nature de la case 0:vide 1:roi 2:dame 3:pion
{
    int i = tabpos[0];
    int j = tabpos[1];
    if (tabpos[2]==1)
    {

        switch (RectVert[i][j])
        {
        case 0:
            selected=0;
            return 0;
            break;
        case 4:
            selected=4;
            return 2;
            break;
        case 3:
            selected=3;
            return 2;
            break;
        case 1:
            selected=1;
            return 3;
            break;
        case 2:
            selected=2;
            return 3;
            break;
        }

    }
    else if (tabpos[3]==1)
    {
        switch (RectHoriz[i][j])
        {
        case 0:
            selected=0;
            return 0;
            break;
        case 4:
            selected=4;
            return 2;
            break;
        case 3:
            selected=3;
            return 2;
            break;
        case 1:
            selected=1;
            return 3;
            break;
        case 2:
            selected=2;
            return 3;
            break;
        }
    }
    else if (tabpos[4]==1)
    {
        if (Carres[i][j]==2)
        {


            selected=2;
            return 1;
        }

        else if (Carres[i][j]==1)
        {
            selected=1;
            return 1;
        }
    }
    else
    {
        return 0;
    }
    //0=vide,1=roi,2=dame,3=pion
}

void DonnerDeplacementPossible(int piece,int i, int j, int v, int h)
{

    int t1=0,t2=0;

    if (joueur == 0)
    {
        t1=1;
        t2=3;
    }
    else
    {
        t1=2;
        t2=4;
    }

    effacerselection();

    if ( (joueur==0 && (selected==2 || selected ==4)) || (joueur==1 && (selected==1 || selected==3) )  )
    {



        int k=0, c=0;
        if (piece == 2)
        {



            if (v==1)
            {
                for (c=j+1; c<8; c++)
                {
                    //if ( (((RectVert[i][c]==1) || (RectVert[i][c]==3)) && joueur ==0)|| (((RectVert[i][c]==2) || (RectVert[i][c]==4)) && joueur ==1))
                    if  (RectVert[i][c]==t1 || RectVert[i][c]==t2 )
                    {
                        if (RectVert[i][c+1]==0 && c!=7)
                        {
                            possibleDeplacementRectV[i][c]=2;
                            possibleDeplacementRectV[i][c+1]=3;
                            I1=i;
                            J1=c+1;
                            X1=i;
                            Y1=c;
                            break;
                        }
                        break;
                    }
                    else if (RectVert[i][c]!=0)
                    {
                        break;
                    }
                    else
                    {
                        possibleDeplacementRectV[i][c]=1;
                    }
                }


                for (c=j-1; c>=0; c--)
                {
                    //   if ( (((RectVert[i][c]==1) || (RectVert[i][c]==3)) && joueur ==0)|| (((RectVert[i][c]==2) || (RectVert[i][c]==4)) && joueur ==1))
                    if (RectVert[i][c]==t1 || RectVert[i][c]==t2)
                    {
                        if (RectVert[i][c-1]==0 && c!=0)
                        {

                            possibleDeplacementRectV[i][c]=2;
                            possibleDeplacementRectV[i][c-1]=3;
                            I2=i;
                            J2=c-1;
                            X2=i;
                            Y2=c;
                            break;
                        }
                        break;
                    }
                    else if (RectVert[i][c]!=0)
                    {
                        break;
                    }
                    else
                    {
                        possibleDeplacementRectV[i][c]=1;

                    }
                }


                for (k=i+1; k<7; k++)
                {
                    if (RectVert[k][j]==t1 || RectVert[k][j]==t2)
                        // if ( (((RectVert[k][j]==1) || (RectVert[k][j]==3)) && joueur ==0) || (((RectVert[k][j]==2) || (RectVert[k][j]==4)) && joueur ==1))
                    {
                        if (k==i+1)
                        {
                            possibleDeplacementRectV[k][j]=2;

                            I=k;
                            J=j;
                            break;
                        }
                        break;
                    }
                    else if (RectVert[k][j]!=0)
                    {
                        break;
                    }


                    else
                    {
                        possibleDeplacementRectV[k][j]=1;
                    }
                }


                for (k=i-1; k>=0; k--)
                {
                    //   if ( (((RectVert[k][j]==1) || (RectVert[k][j]==3)) && joueur ==0)|| (((RectVert[k][j]==2) || (RectVert[k][j]==4)) && joueur ==1))
                    if (RectVert[k][j]==t1 ||RectVert[k][j]==t2)
                    {
                        if (k==i-1)
                        {

                            possibleDeplacementRectV[k][j]=2;
                            I=k;
                            J=j;
                            break;
                        }
                        break;

                    }
                    else if (RectVert[k][j]!=0)
                    {
                        break;
                    }

                    else
                    {
                        possibleDeplacementRectV[k][j]=1;

                    }
                }

                switch (RectHoriz[j][i])
                {
                case 0 :
                    possibleDeplacementRectH[j][i]=1;
                    break;

                }

                switch (RectHoriz[j-1][i])
                {
                case 0 :
                    possibleDeplacementRectH[j-1][i]=1;
                    break;

                }

                switch (RectHoriz[j-1][i+1])
                {
                case 0 :
                    possibleDeplacementRectH[j-1][i+1]=1;
                    break;

                }
                switch (RectHoriz[j][i+1])
                {
                case 0 :
                    possibleDeplacementRectH[j][i+1]=1;
                    break;
                }

            }
            else if (h==1)
            {

                for (c=j+1; c<8; c++)
                {
                    //if ( (((RectHoriz[i][c]==1) || (RectHoriz[i][c]==3)) && joueur ==0)|| (((RectHoriz[i][c]==2) || (RectHoriz[i][c]==4)) && joueur ==1))
                    if (RectHoriz[i][c]==t1 || RectHoriz[i][c]==t2 )
                    {
                        if (c==7)
                        {
                            break;
                        }
                        else if (RectHoriz[i][c+1]==0)
                        {


                            possibleDeplacementRectH[i][c]=2;
                            possibleDeplacementRectH[i][c+1]=3;
                            I1=i;
                            J1=c+1;
                            X1=i;
                            Y1=c;
                            break;

                        }
                        break;

                    }
                    else if (RectHoriz[i][c]!=0)
                    {
                        break;
                    }
                    else
                    {
                        possibleDeplacementRectH[i][c]=1;

                    }
                }


                for (c=j-1; c>=0; c--)
                {
                    // if ( (((RectHoriz[i][c]==1) || (RectHoriz[i][c]==3)) && joueur ==0)|| (((RectHoriz[i][c]==2) || (RectHoriz[i][c]==4)) && joueur ==1))
                    if (RectHoriz[i][c]==t1 ||RectHoriz[i][c]==t2)
                    {
                        if (c==0)
                        {
                            break;
                        }
                        else if (RectHoriz[i][c-1]==0)
                        {


                            possibleDeplacementRectH[i][c]=2;
                            possibleDeplacementRectH[i][c-1]=3;

                            I2=i;
                            J2=c-1;
                            X2=i;
                            Y2=c;
                            break;
                        }
                        break;

                    }
                    else if (RectHoriz[i][c]!=0)
                    {
                        break;
                    }
                    else
                    {



                        possibleDeplacementRectH[i][c]=1;


                    }
                }


                for (k=i+1; k<7; k++)
                {

                    // if ( (((RectHoriz[k][j]==1) || (RectHoriz[k][j]==3)) && joueur ==0)|| (((RectHoriz[k][j]==2) || (RectHoriz[k][j]==4)) && joueur ==1))
                    if (RectHoriz[k][j]==t1 || RectHoriz[k][j]==t2 )
                    {
                        if (k==i+1)
                        {
                            possibleDeplacementRectH[k][j]=2;
                            I=k;
                            J=j;
                            break;
                        }
                        break;
                    }

                    else if (RectHoriz[k][j]!=0)
                    {
                        break;
                    }
                    else
                    {
                        possibleDeplacementRectH[k][j]=1;

                    }
                }

                for (k=i-1; k>=0; k--)
                {
                    //if ( (((RectHoriz[k][j]==1) || (RectHoriz[k][j]==3)) && joueur ==0)|| (((RectHoriz[k][j]==2) || (RectHoriz[k][j]==4)) && joueur ==1))
                    if (RectHoriz[k][j]==t1 || RectHoriz[k][j]==t2 )
                    {
                        if (k==i-1)
                        {
                            possibleDeplacementRectH[k][j]=2;
                            I=k;
                            J=j;
                            break;
                        }
                        break;
                    }
                    else if (RectHoriz[k][j]!=0)
                    {
                        break;
                    }
                    else
                    {
                        possibleDeplacementRectH[k][j]=1;

                    }
                }

                if (RectVert[j-1][i+1]==0)
                {
                    if(j!=0 && i!=7)
                    {


                        possibleDeplacementRectV[j-1][i+1]=1;
                    }

                }

                if (RectVert[j-1][i]==0)
                {
                    if (j!=0)
                    {

                        possibleDeplacementRectV[j-1][i]=1;
                    }

                }

                if (RectVert[j][i]==0)
                {
                    if (j!=7)
                    {


                        possibleDeplacementRectV[j][i]=1;

                    }
                }

                if (RectVert[j][i+1]==0)
                {
                    if (j!=7)
                    {

                        possibleDeplacementRectV[j][i+1]=1;

                    }


                }



            }


        }
        else if (piece ==3)
        {
            if (joueur==0)
            {


                if (h==1)
                {
                    switch(RectVert[j-1][i+1])
                    {
                    case 0:
                        possibleDeplacementRectV[j-1][i+1]=1;


                    }
                    switch(RectVert[j-1][i])
                    {
                    case 0:
                        possibleDeplacementRectV[j-1][i]=1;
                        break;

                    }

                    switch(RectHoriz[i][j-1])
                    {
                    case 0:
                        possibleDeplacementRectH[i][j-1]=1;
                        break;
                    case 1 :
                        if (possibleDeplacementRectH[i][j-2]==0)
                        {

                            possibleDeplacementRectH[i][j-1]=2;
                            possibleDeplacementRectH[i][j-2]=3;
                            I1=i;
                            J1=j-2;
                            X1=i;
                            Y1=j-1;
                            break;
                        }

                        else
                        {


                            break;
                        }
                    case 3:

                        possibleDeplacementRectH[i][j-1]=2;
                        possibleDeplacementRectH[i][j-2]=3;
                        I1=i;
                        J1=j-2;
                        X1=i;
                        Y1=j-1;



                        break;
                    }




                }

                else if (v==1)
                {



                    switch(RectHoriz[j][i])
                    {
                    case 0:
                        possibleDeplacementRectH[j][i]=1;

                        break;


                    }
                    switch(RectHoriz[j-1][i])
                    {
                    case 0:
                        possibleDeplacementRectH[j-1][i]=1;
                        break;

                    }

                    switch(RectVert[i-1][j])
                    {
                    case 0:
                        possibleDeplacementRectV[i-1][j]=1;
                        break;
                    case 1 :

                        possibleDeplacementRectV[i-1][j]=2;
                        I2=i-1;
                        J2=j;
                        break;


                    case 3:

                        possibleDeplacementRectV[i-1][j]=2;
                        I2=i-1;
                        J2=j;

                        break;



                    }






                }

            }

            else if(joueur==1)

            {





                if (h==1)
                {
                    switch(RectVert[j][i])
                    {
                    case 0:
                        possibleDeplacementRectV[j][i]=1;

                        break;


                    }
                    switch(RectVert[j][i+1])
                    {
                    case 0:
                        possibleDeplacementRectV[j][i+1]=1;
                        break;

                    }

                    switch(RectHoriz[i][j+1])
                    {
                    case 0:
                        possibleDeplacementRectH[i][j+1]=1;
                        break;
                    case 2 :
                        if (RectHoriz[i][j+2]==0)
                        {
                            possibleDeplacementRectH[i][j+1]=2;
                            possibleDeplacementRectH[i][j+2]=3;
                            I1=i;
                            J1=j+2;
                            X1=i;
                            Y1=j+1;
                            break;
                        }

                        break;
                    case 4:
                        if (RectHoriz[i][j+2]==0)
                        {
                            possibleDeplacementRectH[i][j+1]=2;
                            possibleDeplacementRectH[i][j+2]=3;
                            I1=i;
                            J1=j+2;
                            X1=i;
                            Y1=j+1;
                            break;
                        }

                        break;
                    }




                }

                else if (v==1)
                {



                    switch(RectHoriz[j-1][i+1])
                    {
                    case 0:
                        possibleDeplacementRectH[j-1][i+1]=1;

                        break;


                    }
                    switch(RectHoriz[j][i+1])
                    {
                    case 0:
                        possibleDeplacementRectH[j][i+1]=1;
                        break;

                    }

                    switch(RectVert[i+1][j])
                    {
                    case 0:
                        possibleDeplacementRectV[i+1][j]=1;
                        break;
                    case 2 :

                        possibleDeplacementRectV[i+1][j]=2;
                        I=i+1;
                        J=j;

                        break;
                    case 4:

                        possibleDeplacementRectV[i+1][j]=2;
                        I=i+1;
                        J=j;
                        break;
                    }






                }






            }




        }

        else if (piece==1)
        {
            if (Carres[i+1][j]==0)
            {
                if(i!=6)
                {


                    possibleDeplacementCarre[i+1][j]=1;
                }
            }
            if (Carres[i-1][j]==0)
            {
                if (i!=0)
                {


                    possibleDeplacementCarre[i-1][j]=1;
                }
            }
            if (Carres[i][j+1]==0)
            {
                if (j!=6)
                {


                    possibleDeplacementCarre[i][j+1]=1;
                }
            }
            if (Carres[i][j-1]==0)
            {
                if (j!=0)
                {


                    possibleDeplacementCarre[i][j-1]=1;
                }
            }
        }
    }
    select=1;
}

int checkroi() //joueur 1: blanc, joueur 2: noir
{
    if (RectHoriz[R0i][R0j]!=0 && RectHoriz[R0i][R0j+1]!=0 && RectVert[R0j][R0i]!=0 && RectVert[R0j][R0i+1]!=0 )
    {
        if ((RectHoriz[R0i][R0j]==1 || RectHoriz[R0i][R0j+1]==1 || RectVert[R0j][R0i]==1 || RectVert[R0j][R0i+1]==1 ) || (RectHoriz[R0i][R0j]==3 || RectHoriz[R0i][R0j+1]==3 || RectVert[R0j][R0i]==3 || RectVert[R0j][R0i+1]==3 ))
        {
            gg=2;
            return 1;

        }
    }


    if (RectHoriz[R1i][R1j]!=0 && RectHoriz[R1i][R1j+1]!=0 && RectVert[R1j][R1i]!=0 && RectVert[R1j][R1i+1]!=0 )
    {
        if ((RectHoriz[R1i][R1j]==2 || RectHoriz[R1i][R1j+1]==2 || RectVert[R1j][R1i]==2 || RectVert[R1j][R1i+1]==2 ) || (RectHoriz[R1i][R1j]==4 || RectHoriz[R1i][R1j+1]==4 || RectVert[R1j][R1i]==4 || RectVert[R1j][R1i+1]==4 ))
        {
            gg=1;
            return 1;

        }
    }
    return 0;
}

