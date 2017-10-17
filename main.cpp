//Brendon Brandolino
#include <iostream>
#include <string>
#include <vector>
#include "bitmap.h"
using namespace std;

const float lumRed = .2126;       // numbers for algorithms
const float lumGreen = .7152;
const float lumBlue = .0722;
const int randomVariance = 50;
const int maxNumVal = 255;


int main() {

  int randomNumber;
  Bitmap image;
  vector<vector<Pixel> > bmp;
  Pixel rgb;
  string im;

  cout<<"please enter the file name"<<endl;
  cin>>im;
  image.open(im);
    do {
      cout<<"please enter a VALID file name"<<endl;  //validate image
      cin>>im;
      image.open(im);
    } while(image.isImage() == false);


  bmp= image.toPixelMatrix();
  cout<<"it is "<<bmp.size()<<" pixels tall"<<endl;
  cout<<"and "<<bmp[0].size()<<" pixels wide"<<endl; // send into the Matrix

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
    srand ( time(NULL) );  // seed random numbers

    cout<<"What algorithm would you like to use?"<<endl;
    cout<<"(A)veraging, (S)ingle Channel, (L)uma, (T)errible"<<endl;
    cin>>style;

        for(int a = 0; a < bmp.size() ;a++)

        {


            for(int b = 0; b < bmp[a].size() ;b++)

            {
              r = bmp[a][b].red;
              g = bmp[a][b].green;
              u = bmp[a][b].blue;
              rgb = bmp[a][b];



                  if (style == 'A') {    // different greyscale algorithms
                    grey = (r+g+u)/3;
                  }
                  if (style == 'S') {
                    grey = g;
                  }
                  if (style == 'L') {
                    grey = (r*lumRed)+(g*lumGreen)+(u*lumBlue);
                  }
                  if (style == 'T') {
                    if ((r+g+u)/3 <(maxNumVal/5) ) {
                      grey = maxNumVal/5;
                    }
                    if ((r+g+u)/3 <(2*maxNumVal/5) && (r+g+u)/3 >=(maxNumVal/5)) {
                      grey = 2*maxNumVal/5;
                    }
                    if ((r+g+u)/3 <(3*maxNumVal/5) && (r+g+u)/3 >=(2*maxNumVal/5)) {
                      grey = 3*maxNumVal/5;
                    }
                    if ((r+g+u)/3 <(4*maxNumVal/5) && (r+g+u)/3 >=(3*maxNumVal/5)) {
                      grey = 4*maxNumVal/5;
                    }
                    if ((r+g+u)/3 <= maxNumVal && (r+g+u)/3 >=(4*maxNumVal/5)) {
                      grey = maxNumVal;
                    }
                  }

                    if (film == 'Y' || film =='y') {  // film grain

                      randomNumber = rand() % randomVariance ;
                        grey = grey-randomNumber;
                        grey = grey + (.5*randomVariance);

                      }

              if (grey > 255) {  //ensure that the pixels are valid numerically
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



        image.fromPixelMatrix(bmp);
        image.save("oldtimey.bmp");

  return 0;
}
/*
ask user to provide a .bmp
if not tell the user to try again


*/
