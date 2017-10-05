//Brendon Brandolino
#include <iostream>
#include <string>
#include <vector>
#include "bitmap.h"
using namespace std;

int main() {
  Bitmap image;
  vector<vector<Pixel> > bmp;
  Pixel rgb;
  string im;

  cout<<"please enter the file name"<<endl;
  cin>>im;
  image.open(im);
  bmp= image.toPixelMatrix();

  cout<<bmp.size()<<endl;
  cout<<bmp[0].size()<<endl;

        for(int a = 0; a < bmp.size() ;a++)

        {


            for(int b = 0; b < bmp[a].size() ;b++)

            {
              cout<<bmp[a][b].red;
              cout<<bmp[a][b].blue;
              cout<<bmp[a][b].green;


            }

        }


  return 0;
}
/*
ask user to provide a .bmp
if not tell the user to try again


*/
