#ifndef FCT
#define FCT

#define NB_NOTE 12

struct Note {
    float freq;
    int duree;
};

struct Note * creerNote(float freq, int duree);
int libNote(struct Note ** note);
void simulerPiano(struct Note ** piano);

#endif