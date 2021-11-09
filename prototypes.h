#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED
void DonnerDeplacementPossible(int piece,int i, int j,int v,int h);
int checkroi();
int pieceDetecte(int tabpos[5]);
void ClickPositionDetection(SDL_Event click);
void effacerselection();



#endif // PROTOTYPES_H_INCLUDED

