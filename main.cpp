//Brendon Brandolino
#include <iostream>
#include <string>
#include <vector>
#include "bitmap.h"
using namespace std;

int main() {
  int randomNumber;
  Bitmap image;
  vector<vector<Pixel> > bmp;
  Pixel rgb;
  string im;

  cout<<"please enter the file name"<<endl;
  cin>>im;
  image.open(im);
  bmp= image.toPixelMatrix();

  cout<<"it is "<<bmp.size()<<" pixels tall"<<endl;
  cout<<"and"<<bmp[0].size()<<" pixels wide"<<endl;

  int r;
  int g;
  int u;
  int grey;
  char film;
  char style;
  char border;
  int borderSize;

    cout<<"Do you want to add film grain?"<<endl;
    cout<<"(Y)es or (N)o"<<endl;
    cin>>film;
    srand ( time(NULL) );

    cout<<"Do you want to add a border?"<<endl;
    cout<<"(Y)es or (N)o"<<endl;
    cin>>border;
        if (border == 'y' || 'Y') {
            cout<<"What size border do you want?"<<endl;
            cin>>borderSize;
        }

    cout<<"What algorithm would you like to use?"<<endl;
    cout<<"(A)veraging, (S)ingle Channel, (L)uma"<<endl;
    cin>>style;

        for(int a = 0; a < bmp.size() ;a++)

        {


            for(int b = 0; b < bmp[a].size() ;b++)

            {
              r = bmp[a][b].red;
              g = bmp[a][b].green;
              u = bmp[a][b].blue;
              rgb = bmp[a][b];



                  if (style == 'A') {
                    grey = (r+g+u)/3;
                  }
                  if (style == 'S') {
                    grey = g;
                  }
                  if (style == 'L') {
                    grey = (r*.2126)+(g*.7152)+(u*.0722);
                  }



                    if (film=='y') {  //fix issue with lowercase y
                        film='Y';
                      }

                    if (film = 'Y' || 'y') {


                      randomNumber = rand() % 20 ;
                        grey = grey-randomNumber;

                      }

              if (grey > 255) {
                grey = 255;
              }
              if (grey < 0) {
                grey = 0;
              }

                rgb.red = grey;
                rgb.blue = grey;
                rgb.green = grey;


                bmp[a][b] = rgb;
            }
        }


}

        image.fromPixelMatrix(bmp);
        image.save("oldtimey.bmp");

  return 0;
}
/*
ask user to provide a .bmp
if not tell the user to try again


*/
