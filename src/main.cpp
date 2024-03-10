
#include "gameEngine.h"
#include <iostream>

using namespace std;

int main()
{
    // to do
    // oyun hizli olunca paddlelar boundry disina cikabiliyor
    // paddlein kenarina geldiginde topun yonu hem x hem y ekseninde degissin
    // random deger uretmek icin srand kullan
    GameEngine gameController;
    gameController.run();

    return 0;
}
